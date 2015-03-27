<?php

/**
 * @file
 * Provide donate form blocks to Panels.
 */
$plugin = array(
  'title'     => t('Donate pay in form'),
  'category'  => t('Miscellaneous'),
  'edit form' => 'cr_donate_donate_pay_in_content_type_edit_form',
  'defaults'  => cr_donate_donate_pay_in_get_all_default_values(),
  'render first' => TRUE,
);


function cr_donate_donate_pay_in_radio_button_keys() {
  return array('general', 'schools', 'corporate');
}


/**
 * Settings form for the pane's settings.
 */
function cr_donate_donate_pay_in_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $defaults = $form_state['plugin']['defaults'];

  $form['event_type_config'] = array(
    '#type' => 'fieldset',
    '#title' => t('Event type config'),
  );

  $radio_button_keys = cr_donate_donate_pay_in_radio_button_keys();
  foreach ($radio_button_keys as $key) {
    $form['event_type_config']["radio_label_{$key}"] = array(
      '#type' => 'textfield',
      '#title' => t('Label for !type radio button', array('!type' => $key)),
      '#default_value' => cr_donate_donate_pay_in_get_default_value($conf, "radio_label_{$key}"),
    );
  }

  // General tab config
  $form['general_event_config'] = array(
    '#type' => 'fieldset',
    '#title' => t('General event config'),
  );

  $form['general_event_config']['general_about_fundraising_intro_copy'] = array(
    '#type' => 'textarea',
    '#title' => t('About your fundraising intro copy'),
    '#default_value' => cr_donate_donate_pay_in_get_default_value($conf, "general_about_fundraising_intro_copy"),
  );

  $form['general_event_config']['general_contact_disclaimer_copy'] = array(
    '#type' => 'textarea',
    '#title' => t('Contact disclaimer copy'),
    '#default_value' => cr_donate_donate_pay_in_get_default_value($conf, "general_contact_disclaimer_copy"),
  );



  // No schools tab config necessary


  // Organisation tab config
  $form['org_config'] = array(
    '#type' => 'fieldset',
    '#title' => t('Organisation config'),
  );

  $form['org_config']['org_list_options'] = array(
    '#type' => 'textarea',
    '#title' => t('Organisation dropdown contents'),
    '#default_value' => cr_donate_donate_pay_in_get_default_value($conf, "org_list_options"),
  );

  $form['org_config']['org_list_title_copy'] = array(
    '#type' => 'textfield',
    '#title' => t('Organisation list title copy'),
    '#default_value' => cr_donate_donate_pay_in_get_default_value($conf, 'org_list_title_copy'),
  );

  $form['org_config']['org_list_help_copy'] = array(
    '#type' => 'textfield',
    '#title' => t('Organisation list help copy'),
    '#default_value' => cr_donate_donate_pay_in_get_default_value($conf, 'org_list_help_copy'),
  );

  $form['org_config']['org_about_fundraising_intro_copy'] = array(
    '#type' => 'textarea',
    '#title' => t('About your fundraising intro copy'),
    '#default_value' => cr_donate_donate_pay_in_get_default_value($conf, "org_about_fundraising_intro_copy"),
  );

  $form['org_config']['org_contact_disclaimer_copy'] = array(
    '#type' => 'textarea',
    '#title' => t('Contact disclaimer copy'),
    '#default_value' => cr_donate_donate_pay_in_get_default_value($conf, "org_contact_disclaimer_copy"),
  );



  return $form;
}

/**
 * Submit handler for settings form
 */
function cr_donate_donate_pay_in_content_type_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}


/**
 * render function for the pay in content type.
 */
function cr_donate_donate_pay_in_content_type_render($subtype, $conf) {
  $block = new stdClass();
  drupal_add_js(drupal_get_path('module', 'cr_donate') . '/cr_donate.paying_in.js', 'file');

  $block->content['#prefix'] = "<div id='pay-in-fundraising-money'>";
  $block->content['#suffix'] = "</div>";

  $block->content['form'] = drupal_get_form('cr_donate_pay_in_form', (object) $conf);
  return $block;
}

/**
 * Form builder for fundraising paying in form.
 */
function cr_donate_pay_in_form($form, &$form_state, $conf) {
  if (empty($form_state['step'])) {
    $form_state['step'] = 1;
  }
  $step = $form_state['step'];

  $func = 'cr_donate_pay_in_form_step_' . $step;
  if (isset($form_state['multistep_values']['step'][$step])) {
    $form_state['values'] = $form_state['multistep_values']['step'][$step];
    // Now remove multistep values for this step, so that in the event of a validation error, the form reloads with
    // the lastest values entered, not the last successfully save multistep values
    unset($form_state['multistep_values']['step'][$step]);
  }

  $form = $func($form, $form_state, $conf);

  $form['#attributes']['class'][] = 'cr-fundraising-form';

  $form['#after_build'][] = 'cr_donate_pay_in_form_step_context';

  $form['#attached']['js']['parsley'] = drupal_get_path('module', 'cr_donate') . '/parsley1.2.3.js';
  $form['#attached']['js'][] = drupal_get_path('module', 'cr_donate') . '/cr_donate.validate.js';
  $form['#attached']['js'][] = drupal_get_path('module', 'cr_donate') . '/cr_donate.paying_in.js';

  return $form;
}

/**
 * Ensures the context is set correctly.
 */
function cr_donate_pay_in_form_step_context($form, &$form_state) {
  context_set('cr_donate', 'fundraising_step', $form_state['step']);

  return $form;
}

/**
 * Form builder for fundraising paying in form, step 1.
 */
function cr_donate_pay_in_form_step_1($form, &$form_state, $conf) {
  $data = isset($form_state['data']) ? $form_state['data'] : array();
  $values = isset($form_state['values']) ? $form_state['values'] : array();

  $form['#attributes']['class'][] = 'cr-fundraising-form-step-1';

  $form['options'] = array(
    '#type' => 'fieldset',
  );

  $form['options']['type'] = array(
    '#type' => 'radios',
    '#title' => "I'm paying in money on behalf of...",
    '#options' => array(
      'general' => cr_donate_donate_pay_in_get_default_value($conf, 'radio_label_general'),
      'schools' => cr_donate_donate_pay_in_get_default_value($conf, 'radio_label_schools'),
      'corporate' => cr_donate_donate_pay_in_get_default_value($conf, 'radio_label_corporate'),
    ),
    '#default_value' => isset($values['type']) ? $values['type'] : NULL,
  );

  $form['container'] = array(
    '#type' => 'container'
  );

  $form['container']['disabled'] = array(
    '#type' => 'item',
    '#states' => array(
      'visible' => array(
        ':input[name="type"]' => array('value' => FALSE),
      ),
    ),
  );

  $form['container']['general'] = array(
    '#type' => 'fieldset',
    '#attributes' => array('class' => array('general')),
    '#states' => array(
      'visible' => array(
        ':input[name="type"]' => array(
          array('value' => FALSE),
          array('value' => 'general'),
        ),
      ),
    ),
  );

  $form['container']['general']['image'] = array(
    '#prefix' => '<div class="fundraise-promo-image">',
    '#suffix' => '</div>',
    '#markup' => theme('image',
      array(
        'path' => drupal_get_path('theme', 'sport_relief') . '/images/components/fundraise/cut_myself.jpg',
      )
    ),
  );


  // this container div is user to add a fixed width around the actual fields
  // but not the promo-image
  $form['container']['general']['general_fields_container'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => 'general-fields-container',
    ),
  );

  $form['container']['general']['general_fields_container']['general_event'] = array(
    '#type' => 'select',
    '#title' => "What event did you do?" . theme('form_required_marker'),
    '#options' => array(
      'select'  => "Select your event",
      'mile'    => "Mile",
      'swim'    => "Swim",
      'cycle'   => "Cycle",
      'other'   => "Other",
    ),
    '#default_value' => isset($values['general_event']) ? $values['general_event'] : 'select',
    '#attributes' => array(
      'parsley-regexp' => '(mile|swim|cycle|other)',
      'parsley-trigger' => 'blur change',
      'parsley-error-message' => 'Please choose an event type',
    ),
  );

  $form['container']['general']['general_fields_container']['general_about'] = array(
    '#type' => 'textarea',
    '#title' => cr_donate_donate_pay_in_get_default_value($conf, 'general_about_fundraising_intro_copy'),
    '#default_value' => isset($values['general_about']) ? $values['general_about'] : '',
    '#maxlength' => 400,
    '#maxlength_js' => TRUE,
    '#attributes' => array(
      'maxlength_js_label' => '@remaining characters remaining',
    ),
  );

  $form['container']['general']['general_fields_container']['general_contact'] = array(
    '#type' => 'checkbox',
    '#title' => cr_donate_donate_pay_in_get_default_value($conf, 'general_contact_disclaimer_copy'),

    '#default_value' => isset($values['general_contact']) ? $values['general_contact'] : FALSE,
  );

  // using same submit button per fieldset rather than one shared submit button
  // to solve a styling issue whereby button could not be easily aligned as per
  // the design
  $form['container']['general']['general_fields_container']['submit'] = cr_donate_pay_in_form_submit_button();



  $form['container']['schools'] = array(
    '#type' => 'fieldset',
    '#attributes' => array('class' => array('schools')),
    '#states' => array(
      'visible' => array(
        ':input[name="type"]' => array('value' => 'schools'),
      ),
    ),
  );

  $form['container']['schools']['image'] = array(
    '#prefix' => '<div class="fundraise-promo-image">',
    '#suffix' => '</div>',
    '#markup' => theme('image',
      array(
        'path' => drupal_get_path('theme', 'sport_relief') . '/images/components/fundraise/cut_schools.jpg',
      )
    ),
  );


  // this container div is user to add a fixed width around the actual fields
  // but not the promo-image
  $form['container']['schools']['schools_fields_container'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => 'schools-fields-container',
    ),
  );

  $form['container']['schools']['schools_fields_container']['establishment'] = array(
    '#type' => 'cr_eddirect_establishment',
    '#default_value' => array(
      'id' => isset($data['edDirectID']) ? $data['edDirectID'] : NULL,
      'address' => isset($data['schoolContactDetails']) ? $data['schoolContactDetails'] : NULL,
    ),
    '#after_build' => array('cr_donate_add_establishment_parsley_validation'),
  );


  $form['container']['schools']['schools_fields_container']['area_job'] = array(
    '#type' => 'cr_eddirect_area_job',
    '#default_value' => array(
      'area' => isset($data['phase']) ? $data['phase'] : NULL,
      'role' => isset($data['role']) ? $data['role'] : NULL,
    ),
    '#after_build' => array('cr_donate_add_area_job_parsley_validation'),
  );

  // using same submit button per fieldset rather than one shared submit button
  // to solve a styling issue whereby button could not be easily aligned as per
  // the design
  $form['container']['schools']['schools_fields_container']['submit'] = cr_donate_pay_in_form_submit_button();



  $form['container']['corporate'] = array(
    '#type' => 'fieldset',
    '#attributes' => array('class' => array('corporate')),
    '#states' => array(
      'visible' => array(
        ':input[name="type"]' => array('value' => 'corporate'),
      ),
    ),
  );

  $form['container']['corporate']['image'] = array(
    '#prefix' => '<div class="fundraise-promo-image">',
    '#suffix' => '</div>',
    '#markup' => theme('image',
      array(
        'path' => drupal_get_path('theme', 'sport_relief') . '/images/components/fundraise/cut_organization.jpg',
      )
    ),
  );

  // this container div is user to add a fixed width around the actual fields
  // but not the promo-image
  $form['container']['corporate']['corporate_fields_container'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => 'corporate-fields-container',
    ),
  );

  $form['container']['corporate']['corporate_fields_container']['corporate_event'] = array(
    '#type' => 'select',
    '#title' => "What event did you do?" . theme('form_required_marker'),
    '#options' => array(
      'select'  => "Select your event",
      'mile'    => "Mile",
      'swim'    => "Swim",
      'cycle'   => "Cycle",
      'other'   => "Other",
    ),
    '#default_value' => isset($values['corporate_event']) ? $values['corporate_event'] : 'select',
    '#attributes' => array(
      'parsley-regexp' => '(mile|swim|cycle|other)',
      'parsley-trigger' => 'blur change',
      'parsley-error-message' => 'Please choose an event type',
    ),
  );

  $form['container']['corporate']['corporate_fields_container']['organisation'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('select-organisation-container')),
  );

  $label_theme_params = array(
    'element' => array(
      '#title' =>  cr_donate_donate_pay_in_get_default_value($conf, 'org_list_title_copy')  . ' ' . theme('form_required_marker'),
      '#title_display' => 'before',
      '#id' => 'edit-organisation-dropdown',
    ),
  );
  $form['container']['corporate']['corporate_fields_container']['organisation']['dropdown_label'] = array(
    '#markup' => theme('form_element_label', $label_theme_params),
  );

  $org_list_options_conf = cr_donate_donate_pay_in_get_default_value($conf, 'org_list_options');
  $org_options = drupal_map_assoc(explode("\n", $org_list_options_conf));
  $form['container']['corporate']['corporate_fields_container']['organisation']['organisation_dropdown'] = array(
    '#type' => 'select',
    '#options' => $org_options,
    '#default_value' => isset($values['organisation_dropdown']) ? $values['organisation_dropdown'] : 'Other',
  );

  $form['container']['corporate']['corporate_fields_container']['organisation']['organisation_other'] = array(
    '#type' => 'textfield',
    '#maxlength' => 100,
    '#states' => array(
      'visible' => array(
        array(
          ':input[name="organisation_dropdown"]' => array('value' => 'Other'),
        ),
      ),
    ),
    '#attributes' => array(
      'parsley-trigger' => 'blur',
      'parsley-validation-minlength' => 0,
      'parsley-error-message' => 'Please fill in your organisation',
      'parsley-required' => "true",
    ),
    '#default_value'  => isset($values['organisation_other']) ? $values['organisation_other'] : '',
  );

  $form['container']['corporate']['corporate_fields_container']['organisation']['organisation_youth_group'] = array(
    '#type' => 'textfield',
    '#maxlength' => 100,
    '#states' => array(
      'visible' => array(
        array(
          ':input[name="organisation_dropdown"]' => array('value' => 'Youth Group'),
        ),
      ),
    ),
    '#default_value'  => isset($values['organisation_youth_group']) ? $values['organisation_youth_group'] : '',
  );

  $form['container']['corporate']['corporate_fields_container']['organisation']['organisation_tip'] = array(
    '#prefix' => '<p class="form-tip">',
    '#suffix' => '</p>',
    '#markup' =>  cr_donate_donate_pay_in_get_default_value($conf, 'org_list_help_copy'),
  );

  $form['container']['corporate']['corporate_fields_container']['corporate_about'] = array(
    '#type' => 'textarea',
    '#title' => cr_donate_donate_pay_in_get_default_value($conf, 'org_about_fundraising_intro_copy'),
    '#default_value' => isset($values['corporate_about']) ? $values['corporate_about'] : '',
    '#maxlength' => 400,
    '#maxlength_js' => TRUE,
    '#attributes' => array(
      'maxlength_js_label' => '@remaining characters remaining',
    ),
  );

  $form['container']['corporate']['corporate_fields_container']['corporate_contact'] = array(
    '#type' => 'checkbox',
    '#title' => cr_donate_donate_pay_in_get_default_value($conf, 'org_contact_disclaimer_copy'),

    '#default_value' => isset($values['corporate_contact']) ? $values['corporate_contact'] : FALSE,
  );

  // using same submit button per fieldset rather than one shared submit button
  // to solve a styling issue whereby button could not be easily aligned as per
  // the design
  $form['container']['corporate']['corporate_fields_container']['submit'] = cr_donate_pay_in_form_submit_button();

// Desktop or mobile platform flag.
  $form['platform'] = array(
    '#type' => 'hidden',
    '#default_value' => 'desktop',
  );

  $form['#validate'][] = 'cr_donate_pay_in_form_validate_step_1';
  $form['#submit'][] = 'cr_donate_pay_in_form_submit_step_1';
  return $form;
}

function cr_donate_add_establishment_parsley_validation($element) {
  if (isset($element['establishment_lookup']['#attributes'])) {
    $element['establishment_lookup']['#attributes'] += array(
      'parsley-trigger' => 'blur',
      'parsley-validation-minlength' => 0,
      'parsley-error-message' => 'Please fill in your school',
      'parsley-required' => "true",
    );
  }

  if (isset($element['establishment_address_container']['schoolName']['#attributes'])) {
    $element['establishment_address_container']['schoolName']['#attributes'] += array(
      'parsley-trigger' => 'blur',
      'parsley-validation-minlength' => 0,
      'parsley-error-message' => 'Please fill in your establishment name',
      'parsley-required' => "true",
    );
  }

  if (isset($element['establishment_address_container']['address1']['#attributes'])) {
    $element['establishment_address_container']['address1']['#attributes'] += array(
      'parsley-trigger' => 'blur',
      'parsley-validation-minlength' => 0,
      'parsley-error-message' => 'Please fill in your address',
      'parsley-required' => "true",
    );
  }

  if (isset($element['establishment_address_container']['town']['#attributes'])) {
    $element['establishment_address_container']['town']['#attributes'] += array(
      'parsley-trigger' => 'blur',
      'parsley-validation-minlength' => 0,
      'parsley-error-message' => 'Please fill in your town/city',
      'parsley-required' => "true",
    );
  }

  if(isset($element['establishment_address_container']['postcode']['#attributes'])) {
    $element['establishment_address_container']['postcode']['#attributes'] += array(
        'parsley-trigger' => 'blur',
        'parsley-validation-minlength' => 0,
        'parsley-error-message' => 'Please fill in your post code',
        'parsley-required' => "true",
    );
  }

  return $element;
}

function cr_donate_add_area_job_parsley_validation($element) {
  if (isset($element['job_title_other']['job_title_other']['#attributes'])) {
    $element['job_title_other']['job_title_other']['#attributes'] += array(
      'parsley-trigger' => 'blur',
      'parsley-validation-minlength' => 0,
      'parsley-error-message' => 'Please fill in your job title',
      'parsley-required' => "true",
    );
  }

  return $element;
}

/**
 * Validation callback for fundraising paying in form, step 1.
 */
function cr_donate_pay_in_form_validate_step_1($form, &$form_state) {
  switch ($form_state['values']['type']) {
    case 'general':
      if ($form_state['values']['general_event'] === 'select') {
        form_set_error('general_event', "Please choose an event type");
      }
      break;
    case 'schools':
      // All validation done inside cr_eddirect module
     $establishment_element = $form['container']['schools']['schools_fields_container']['establishment'];
     $area_job_element = $form['container']['schools']['schools_fields_container']['area_job'];
     $element_state = array();
      cr_eddirect_establishment_element_validate($establishment_element, $element_state);
      cr_eddirect_area_job_element_validate($area_job_element, $element_state);
      break;

    case 'corporate':
      if ($form_state['values']['corporate_event'] === 'select') {
        form_set_error('corporate_event', "Please choose an event type");
      }

      if ($form_state['values']['organisation_dropdown'] === 'Other') {
        if (trim($form_state['values']['organisation_other']) === '') {
          form_set_error('organisation_other', "Please fill in your organisation");
        }

      }
      break;
  }
}

/**
 * Submit callback for fundraising paying in form, step 1.
 */
function cr_donate_pay_in_form_submit_step_1($form, &$form_state) {
  $data = array(
    'option' => $form_state['values']['type'],
  );

  $this_step = 1;
  $next_step = 2;
  $form_state['multistep_values']['step'][$this_step] = $form_state['values'];
  $form_state['step'] = $next_step;
  $form_state['rebuild'] = TRUE;

  switch ($form_state['values']['type']) {
    case 'general':
      $data += array(
        'event' => $form_state['values']['general_event'],
        'whatYouDid' => $form_state['values']['general_about'],
        'permission' => $form_state['values']['general_contact'],
      );
      break;

    case 'schools':
      $ed_direct = new EdDirect();
      $establishment_id = $form_state['values']['establishment_id'];
      if ($establishment_id) {
        // Get address from edDirect.
        $address = $ed_direct->getAddressFromId($establishment_id);
      }
      else {
        // Use supplied address.
        $address = $form_state['values']['establishment_address_container'];
      }

      $role = $form_state['values']['job_title'];
      if ($role == 'Other') {
        $role = $form_state['values']['job_title_other'];
      }

      $data += array(
        'edDirectID' => $form_state['values']['establishment_id'],
        'schoolContactDetails' => $address,
        'role' => $role,
      );
      break;

    case 'corporate':
      switch ($form_state['values']['organisation_dropdown']) {
        case 'Other':
          $data['group_affiliation'] = $form_state['values']['organisation_other'];
          break;

        case 'Youth Group':
          $data['group_affiliation'] = $form_state['values']['organisation_dropdown'] . '|' . $form_state['values']['organisation_youth_group'];
          break;

        default:
          $data['group_affiliation'] = $form_state['values']['organisation_dropdown'];
      }

      $data += array(
        'event' => $form_state['values']['corporate_event'],
        'whatYouDid' => $form_state['values']['corporate_about'],
        'permission' => $form_state['values']['corporate_contact'],
      );
      break;
  }

  $form_state['data'] = $data;
}

/**
 * Form builder for fundraising paying in form, step 2.
 */
function cr_donate_pay_in_form_step_2($form, &$form_state) {
  $step1_data = $form_state['multistep_values']['step'][1];
  $conf = new stdClass;

  // Only allow WorldPay as a payment method.
  $conf->methods = array('worldpay' => TRUE);

  // WorldPay payment description text.
  $conf->desc = 'Fundraising';

  // Force redirect after payment.
  $conf->redirect_url = 'pay-in-fundraising-money/thankyou';

  // Allow marketing preferences to be set.
  $conf->allow_subscribe = TRUE;

  // Map option values to cart ID strings.
  $map = array(
    'general' => 'General',
    'schools' => 'Schools',
    'corporate' => 'Organisation',
  );
  $conf->cart_id = CR_CAMPAIGN_ID . '_PayingIn_' . $map[$step1_data['type']];
  $conf->cart_id_mobile = $conf->cart_id . '_Mob';

  $form = cr_donate_form($form, $form_state, $conf);

  $form['#attributes']['class'][] = 'cr-fundraising-form-step-2';

  $form['amount']['#description'] = '<h2>Enter the amount you are paying in ' . theme('form_required_marker') . '</h2>';
  $form['amount']['amount']['#placeholder'] = '00.00';

  $form['giftaid']['#access'] = FALSE;

  $form['previous'] = array(
    '#type' => 'submit',
    '#value' => 'Previous',
    '#attributes' => array(
      'class' => array('gray'),
    ),
    '#submit' => array('cr_donate_pay_in_form_previous'),
    '#weight' => 99,
  );

  // Store step 1 data before redirecting to WorldPay.
  array_unshift($form['submit']['#submit'], 'cr_donate_pay_in_form_submit_step_2');

  return $form;
}

/**
 * "Previous" button callback for fundraising paying in form, step 2.
 */
function cr_donate_pay_in_form_previous($form, &$form_state) {
  $this_step = 2;
  $next_step = 1;
  $form_state['multistep_values']['step'][$this_step] = $form_state['values'];
  $form_state['step'] = $next_step;
  $form_state['rebuild'] = TRUE;
  context_set('cr_donate', 'fundraising_step', $next_step);
}

/**
 * Submit callback for fundraising paying in form, step 2.
 *
 * Store data from step 1 attached to the email address from step 2.
 */
function cr_donate_pay_in_form_submit_step_2($form, &$form_state) {
  ctools_include('object-cache');
  ctools_object_cache_set('donate_pay_in', $form_state['values']['email'], $form_state['data'], 'donate_pay_in');
}

function cr_donate_pay_in_form_submit_button() {
  return array(
    '#type' => 'submit',
    '#value' => t('Next'),
    '#states' => array(
      'disabled' => array(
        ':input[name="type"]' => array('value' => FALSE),
      ),
    ),
  );
}

function cr_donate_donate_pay_in_get_all_default_values() {
  $org_list_options = <<<ORG_LIST_OPTIONS
Other
Amazon
BBC
British Airways
BT
Cisco
Claire's
Disney
Ernst & Young
Emma Bridgewater
Hewlett Packard
Jackpot Joy
Kia
Mars
Menu Relief
Mini Babybel
Oracle
Oxfam
PayPal
PEZ
Premiership Rugby
RBS
Robert Dyas
Ryman
Sainsbury's
TJX Europe
Tragus
WorldPay
Youth Group
ORG_LIST_OPTIONS;

  return array(
    'allow_subscribe'       => TRUE,
    // page level defaults
    'page_title'            => "Pay in fundraising money",
    'page_intro_copy'       =>  "You've come to the right place to pay in your fundraising money" .
      " - we promise it won't take a jiffy",
    'radio_label_general'   => 'Myself, friends or family',
    'radio_label_schools'   => 'My school or early years group',
    'radio_label_corporate' => 'My organisation, workplace or university',

    // General tab defaults
    'general_about_fundraising_intro_copy' => "If you've got a second we'd love you to tell us a bit more about what your Sport Relief fundraising involved",
    'general_contact_disclaimer_copy' => "We're always on the lookout for fantastic fundraising stories to feature. If you're happy for us to contact you about what you did please tick the box.",

    // organisation tab defaults
    'org_list_options'      => $org_list_options,
    'org_list_title_copy'   => "Organisation, establishment or Sport Relief corporate partner",
    'org_list_help_copy'   => "if the organisation or establishment you fundraised for is not listed, please select 'other' and type it in the box.",
    'org_about_fundraising_intro_copy'   => "If you've got a second we'd love you to tell us a bit more about what your Sport Relief fundraising involved",
    'org_contact_disclaimer_copy'   => "We're always on the lookout for fantastic fundraising stories to feature. If you're happy for us to contact you about what you did please tick the box.",
  );
}

function cr_donate_donate_pay_in_get_default_value($conf, $key) {
  // ensure $conf is an array
  $conf_array = (is_object($conf)) ? get_object_vars($conf) : $conf;

  $defaults = cr_donate_donate_pay_in_get_all_default_values();

  if (!isset($conf_array[$key])) {
    if (!isset($defaults[$key])) {
      return "";
    }
    else {
      return $defaults[$key];
    }
  }
  else {
    return $conf_array[$key];
  }
}
