<?php

/**
 * @file
 * Provide gift aid form to Panels.
 */
  $plugin = array(
  'title' => t('Gift Aid form'),
  'category' => t('Miscellaneous'),
);

/**
 * Gift aid pane configuration form.
 */
function cr_donate_giftaid_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['giftaid_checkbox'] = array(
    '#type' => 'textfield',
    '#title' => t('Gift Aid checkbox text'),
    '#default_value' => isset($conf['giftaid_checkbox']) ? $conf['giftaid_checkbox'] : 'Yes, I would like Comic Relief to claim Gift Aid on my text donation/s',
  );
  $form['giftaid_text'] = array(
    '#type' => 'textarea',
    '#title' => t('Gift Aid help text'),
    '#description' => t('HTML is allowed.'),
    '#default_value' => isset($conf['giftaid_text']) ? $conf['giftaid_text'] : CR_DONATE_GIFTAID_TEXT,
  );

  return $form;
}

/**
 * Submit callback for gift aid pane configuration form.
 */
function cr_donate_giftaid_content_type_edit_form_submit($form, &$form_state) {
  $form_state['conf']['giftaid_checkbox'] = $form_state['values']['giftaid_checkbox'];
  $form_state['conf']['giftaid_text'] = $form_state['values']['giftaid_text'];
}

/**
 * Output function for the gift aid form content type.
 */
function cr_donate_giftaid_content_type_render($subtype, $conf) {
  $block = new stdClass();
  $block->content = drupal_get_form('cr_donate_giftaid_form', $conf);
  return $block;
}

/**
 * Form builder for text donation gift aid.
 */
function cr_donate_giftaid_form($form, &$form_state, $conf) {
  drupal_add_js(drupal_get_path('module', 'cr_donate') . '/cr_donate.giftaid.js', 'file');

  $form['main'] = array(
    '#type' => 'fieldset',
  );
  $form['main']['phone'] = array(
    '#type' => 'textfield',
    '#title' => '<h2>Enter your mobile number ' . theme('form_required_marker') . '</h2>' .
      '<span>the one you used for your text donation...</span>',
    '#maxlength' => 16,
  );

  $form['main']['donate-giftaid'] = array (
    '#type' => 'fieldset',
    '#theme' => 'cr_donate_giftaid',
  );
  $form['main']['donate-giftaid']['giftaid'] = array(
    '#type' => 'checkbox',
    '#title' => check_plain($conf['giftaid_checkbox']) . ' ' . theme('form_required_marker'),
    '#description' => filter_xss_admin($conf['giftaid_text']),
  );
  $form['billing'] = array(
    '#type' => 'fieldset',
    '#description' => '<h2>Your details</h2><p>Fields marked with a <span class="form-required">*</span> are mandatory</p>',
    '#theme' => 'cr_donate_giftaid_billing',
  );
  $form['billing']['title'] = array(
    '#type' => 'select',
    '#title' => 'Title',
    '#options' => drupal_map_assoc(array('', 'Mr', 'Mrs', 'Ms', 'Miss', 'Dr')),
  );
  $form['billing']['first_name'] = array(
    '#type' => 'textfield',
    '#title' => 'First name' . ' ' . theme('form_required_marker'),
    '#maxlength' => 25,
  );
  $form['billing']['last_name'] = array(
    '#type' => 'textfield',
    '#title' => 'Last name' . ' ' . theme('form_required_marker'),
    '#maxlength' => 50,
  );
  $form['billing']['address'] = array(
    '#type' => 'cr_plus',
    '#after_build' => array('cr_donate_form_address_parsley_validate'),
  );

  // Desktop or mobile platform flag.
  $form['platform'] = array(
    '#type' => 'hidden',
    '#default_value' => 'desktop',
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );

  // Use parsley.js for validation.
  $form['#attached']['js'][] = drupal_get_path('module', 'cr_donate') . '/parsley1.2.3.js';
  $form['#attached']['js'][] = drupal_get_path('module', 'cr_donate') . '/cr_donate.validate.js';
  $form['#attributes']['parsley-validate'] = 'parsley';

  $form['main']['phone']['#attributes'] = array(
    'parsley-required' => 'true',
    'parsley-required-message' => t('Please enter a valid mobile phone number - it must be the same number that you used to make your donation.'),
    'parsley-regexp' => '^[0+][ \d]{10,15}$',
    'parsley-regexp-message' => t('Please enter a valid mobile phone number - it must be the same number that you used to make your donation.'),
    'parsley-validation-minlength' => 0,
    'parsley-trigger' => 'blur',
  );
  $form['main']['donate-giftaid']['giftaid']['#attributes'] = array(
    'parsley-required' => 'true',
    'parsley-required-message' => t('Please tick the Gift Aid tickbox'),
  );
  $form['billing']['first_name']['#attributes'] = array(
    'parsley-required' => 'true',
    'parsley-required-message' => t('Please fill in your first name'),
    'parsley-validation-minlength' => 0,
    'parsley-trigger' => 'blur',
  );
  $form['billing']['last_name']['#attributes'] = array(
    'parsley-required' => 'true',
    'parsley-required-message' => t('Please fill in your last name'),
    'parsley-validation-minlength' => 0,
    'parsley-trigger' => 'blur',
  );

  return $form;
}

/**
 * Validation callback for text donation gift aid form.
 */
function cr_donate_giftaid_form_validate($form, &$form_state) {
  // Phone number format: 0 or +, followed by 9-15 digits or spaces
  if (!preg_match('/^[0+][ \d]{10,15}$/', $form_state['values']['phone'])) {
    form_set_error('phone', t('Please enter a valid mobile phone number - it must be the same number that you used to make your donation.'));
  }

  if (empty($form_state['values']['giftaid'])) {
    form_set_error('giftaid', t('Please tick the Gift Aid tickbox'));
  }

  if (empty($form_state['values']['first_name'])) {
    form_set_error('first_name', t('Please fill in your first name'));
  }

  if (empty($form_state['values']['last_name'])) {
    form_set_error('last_name', t('Please fill in your last name'));
  }
}

/**
 * Submit callback for text donation gift aid form.
 */
function cr_donate_giftaid_form_submit($form, &$form_state, &$broker) {
  // Convert phone number to international format.
  $phone = str_replace(' ', '', $form_state['values']['phone']);
  if (substr($phone, 0, 1) == '0') {
    $phone = '+44' . substr($phone, 1);
  }

  // Generate unique email based on phone number.
  $email = substr($phone, 1) . '@text-donate-giftaid.comicrelief.com';

  // Data to send to /donation/gift-aid web service.
  $data = array(
    'email' => $email,
    'prefix' => $form_state['values']['title'],
    'firstName' => $form_state['values']['first_name'],
    'lastName' => $form_state['values']['last_name'],
    'address1' => $form_state['values']['address1'],
    'address2' => $form_state['values']['address2'],
    'address3' => $form_state['values']['address3'],
    'town' => $form_state['values']['town'],
    'postcode' => $form_state['values']['postcode'],
    'country' => $form_state['values']['country'],
    'mobile' => $phone,
    'campaign' => CR_CAMPAIGN_ID,
    'giftAid' => TRUE,
    'transSource' => CR_CAMPAIGN_ID  . ($form_state['values']['platform'] == 'mobile' ? '_Mobile_GiftAid' : '_GiftAid'),
    'transSourceUrl' => url(current_path(), array('absolute' => TRUE)),
    'transType' => CR_DONATE_GIFTAID_MSG_TYPE,
    'timestamp' => time(),
  );

  try {
    switch(variable_get('cr_donate_giftaid_transport_backend', CR_DONATE_GIFTAID_DEFAULT_TRANSPORT_BACKEND)) {
      case 'message_queues':
        if (!is_object($broker) || !$broker instanceof MessageBrokerInterface) {
          $broker = message_broker_get();
        }
        $message_body = json_encode($data);
        $exchange = variable_get('cr_message_queues_exchange', CR_MESSAGE_QUEUES_DEFAULT_EXCHANGE);
        $broker->sendMessage($message_body,  $exchange, array('routing_key' => $exchange.'.giftaid', 'content_type' => 'application/json'));
        break;
      case 'webservices':
        if (is_object($broker) && $broker instanceof WSClientServiceDescription) {
          $service = $broker;
        }
        else {
          $service = wsclient_service_load('cr_marketing_preferences');
        }
        $result = $service->invoke('donate_giftaid', $data);
        // @TODO: process $result and use the transaction ID for later
        break;
    }
    $form_state['redirect'] = 'giftaid/thankyou';
  }
  catch (MessageBrokerException $mbe) {
    watchdog('cr_donate_giftaid', 'Message Queues: @error', array('@error' => $mbe->getMessage(), WATCHDOG_ERROR));
    drupal_set_message(CR_DONATE_GIFTAID_ERROR_MESSAGE, 'error');
    $form_state['rebuild'] = TRUE;
  }
  catch (WSClientException $e) {
    watchdog('cr_donate_giftaid', 'Web Services: @error', array('@error' => $e->getMessage(), WATCHDOG_ERROR));
    drupal_set_message(CR_DONATE_GIFTAID_ERROR_MESSAGE, 'error');
    $form_state['rebuild'] = TRUE;
  }
}
