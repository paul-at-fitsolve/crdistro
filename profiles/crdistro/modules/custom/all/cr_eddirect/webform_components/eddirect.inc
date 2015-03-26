<?php

/**
 * Specify the default properties of a component.
 *
 * @return
 *   An array defining the default structure of a component.
 */
function _webform_defaults_cr_eddirect_est() {
  return array(
    'name' => '',
    'form_key' => NULL,
    'mandatory' => 0,
    'pid' => 0,
    'weight' => 0,
    'extra' => array(
      // need at least one key in 'extra' array to prevent php notice as webform_component_edit_form expects this
      // array to exist and only creates it if there are default settings that include an 'extra' key that itslef
      // contains at least one key
      'description' => '',
    ),
  );
}


/**
 * Render a Webform component to be part of a form.
 *
 * @param $component
 *   A Webform component array.
 * @param $value
 *   If editing an existing submission or resuming a draft, this will contain
 *   an array of values to be shown instead of the default in the component
 *   configuration. This value will always be an array, keyed numerically for
 *   each value saved in this field.
 * @param $filter
 *   Whether or not to filter the contents of descriptions and values when
 *   rendering the component. Values need to be unfiltered to be editable by
 *   Form Builder.
 *
 * @see _webform_client_form_add_component()
 */
function _webform_render_cr_eddirect_est($component, $value = NULL, $filter = TRUE) {
  $description = $component['extra']['description'];
  $form_item = array(
    '#type' => 'cr_eddirect_establishment',
    '#title' => $filter ? _webform_filter_xss($component['name']) : $component['name'],
    '#required' => $component['mandatory'],
    '#weight' => $component['weight'],
    '#description'   => $filter ? _webform_filter_descriptions($description) : $description,
    '#default_value' => $filter ? _webform_filter_values($component['value']) : $component['value'],
    '#prefix' => '<div class="webform-component-textfield" id="webform-component-' . $component['form_key'] . '">',
    '#suffix' => '</div>',
  );

  return $form_item;
}


/**
 * Display the result of a submission for a component.
 *
 * The output of this function will be displayed under the "Results" tab then
 * "Submissions". This should output the saved data in some reasonable manner.
 *
 * @param $component
 *   A Webform component array.
 * @param $value
 *   An array of information containing the submission result, directly
 *   correlating to the webform_submitted_data database table schema.
 * @param $format
 *   Either 'html' or 'text'. Defines the format that the content should be
 *   returned as. Make sure that returned content is run through check_plain()
 *   or other filtering functions when returning HTML.
 * @return
 *   A renderable element containing at the very least these properties:
 *    - #title
 *    - #weight
 *    - #component
 *    - #format
 *    - #value
 *   Webform also uses #theme_wrappers to output the end result to the user,
 *   which will properly format the label and content for use within an e-mail
 *   (such as wrapping the text) or as HTML (ensuring consistent output).
 */
function _webform_display_cr_eddirect_est($component, $value, $format = 'html') {
  return array(
    '#title' => $component['name'],
    '#weight' => $component['weight'],
    '#theme' => 'webform_display_cr_eddirect_address',
    '#theme_wrappers' => $format == 'html' ? array('webform_element') : array('webform_element_text'),
    '#post_render' => array('webform_element_wrapper'),
    '#component' => $component,
    '#format' => $format,
    '#value' => $value ? $value : array(),
  );
}


/**
 * Return the result of a component value for display in a table.
 *
 * The output of this function will be displayed under the "Results" tab then
 * "Table".
 *
 * @param $component
 *   A Webform component array.
 * @param $component_value
 *   An array of information containing the submission result, directly
 *   correlating to the webform_submitted_data database schema.
 * @return
 *   Textual output formatted for human reading.
 */
function _webform_table_cr_eddirect_est($component, $component_value) {
  $address = $component_value;
  $address = cr_eddirect_prepare_loaded_address_data($address);
  $address_formatted = cr_eddirect_format_address('html', $address);

  return $address_formatted;
}

/**
 * Return the header for this component to be displayed in a CSV file.
 *
 * The output of this function will be displayed under the "Results" tab then
 * "Download".
 *
 * @param $component
 *   A Webform component array.
 * @param $export_options
 *   An array of options that may configure export of this field.
 * @return
 *   An array of data to be displayed in the first three rows of a CSV file, not
 *   including either prefixed or trailing commas.
 */
function _webform_csv_headers_cr_eddirect_est($component, $export_options) {
  $header = array();
  $header[0] = '';
  $header[1] = $component['name'];
  $header[2] = cr_eddirect_get_address_fields();

  return $header;
}

/**
 * Format the submitted data of a component for CSV downloading.
 *
 * The output of this function will be displayed under the "Results" tab then
 * "Download".
 *
 * @param $component
 *   A Webform component array.
 * @param $export_options
 *   An array of options that may configure export of this field.
 * @param $value
 *   An array of information containing the submission result, directly
 *   correlating to the webform_submitted_data database schema.
 * @return
 *   An array of items to be added to the CSV file. Each value within the array
 *   will be another column within the file. This function is called once for
 *   every row of data.
 */
function _webform_csv_data_cr_eddirect_est($component, $export_options, $value) {
  $address_fields = cr_eddirect_get_address_fields();
  $field_keys_to_store = array_keys($address_fields);

  $csv_data = array();
  foreach($field_keys_to_store as $field_key_to_store) {
    $csv_data []= isset($value[$field_key_to_store]) ? $value[$field_key_to_store] : NULL;
  }

  return $csv_data;
}

/**
 * Modify a Webform submission, prior to saving it in the database.
 *
 * @param $node
 *   The Webform node on which this submission was made.
 * @param $submission
 *   The Webform submission that is about to be saved to the database.
 */
function cr_eddirect_webform_submission_presave($node, &$submission, $EdDirect = NULL) {
  // for any eddirect components...
  // If establishment field is populated then store that, otherwise construct data by joining populated name/address fields
  foreach($submission->data as &$component) {
    $value = &$component['value'];
    if (!isset($value['eddirect_flag'])) {
      continue;
    }

    // if we have not been passed an instance of EdDirect then get one
    if (!is_object($EdDirect) || !$EdDirect instanceof EdDirect) {
      $EdDirect = new EdDirect();
    }

    $establishment_id = $value['establishment_id'];
    if ($establishment_id) {
      // Get address from edDirect.
      $address = $EdDirect->getAddressFromId($establishment_id);
      $address['edDirectID'] = $establishment_id;
    }
    else {
      // Use supplied address.
      $address = $value['establishment_address_container'];
    }

    $component['value'] = $address;
  }
}

// theme implementation for webform_display_cr_eddirect_address
function theme_webform_display_cr_eddirect_address($variables) {
  $element = $variables['element'];
  $address = $element['#value'];
  $address = cr_eddirect_prepare_loaded_address_data($address);
  $address_formatted = cr_eddirect_format_address($element['#format'], $address);
  return $address_formatted;
}

/**
 * Format an address for displaying on screen
 *
 * @param $format
 *   The format to use, html or text
 * @param $address
 *   The address array containing the address lines
 * @return string
 */
function cr_eddirect_format_address($format, $address) {
  // If edDirect field is present then this was looked up rather than manually
  // entered.  We don't just want to add the ID at the end of the address as
  // this is confusing, so bracket and label it.  Alternatively we could omit it?
  if (!empty($address['edDirectID'])) {
    $address['edDirectID'] = "(edDirect ID: {$address['edDirectID']})";
  }

  if ($format === 'html') {
    $glue = "<br />";
    $prefix = '<div>';
    $suffix = '</div>';
  }
  else {
    $glue = "\n";
    $prefix = '';
    $suffix = '';
  }

  $address_formatted = $prefix . implode($glue, $address) . $suffix;

  return $address_formatted;
}

/**
 * Takes loaded address data and applies various clean up operations
 *
 * @param $address
 * @return array
 */
function cr_eddirect_prepare_loaded_address_data($address) {
  // Remove elements with no data
  $address = array_filter($address);

  // filter out any fields that don't comply to our expected fields and
  // sort the fields into proper address order
  $address_fields = cr_eddirect_get_address_fields();
  $field_keys_to_store = array_keys($address_fields);

  // temporary storage for address with unexpected fields stripped out
  $address2 = array();

  foreach($field_keys_to_store as $field_key_to_store) {
    if (isset($address[$field_key_to_store])) {
      $address2[$field_key_to_store] = $address[$field_key_to_store];
    }
  }

  // put stripped address array back into $address;
  $address = $address2;

  // run check_plain on remaining data
  $address = array_map("check_plain", $address);
  return $address;
}

/**
 * Return the address fields we want to save, display etc
 *
 * This function supplies a consistent collection of address fields in an
 * appropriate order for display
 *
 * @return array of address fields
 */
function cr_eddirect_get_address_fields() {
  return array(
    'schoolName'  => 'School Name',
    'address1'    => 'Address 1',
    'address2'    => 'Address 2',
    'address3'    => 'Address 3',
    'town'        => 'Town / City',
    'county'      => 'County',
    'postcode'    => 'Postcode',
    'edDirectID'  => 'edDirect ID',
  );
}
