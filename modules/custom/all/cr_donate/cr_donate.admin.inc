<?php

/**
 * Site wide donation settings.
 */
function cr_donate_settings_form($form, $form_state) {
  global $base_url;
  $form['cr_donate_currency_option'] = array(
    '#type' => 'radios',
    '#title' => t('Currency selector'),
    '#options' => array(
      'select' => t('Dropdown'),
      'radios' => t('Radio buttons'),
    ),
    '#default_value' => variable_get('cr_donate_currency_option', 'select'),
  );
  $form['cr_donate_giftaid_calculator'] = array(
    '#type' => 'textarea',
    '#title' => t('Gift Aid calculator text'),
    '#description' => t('HTML is allowed. Use AMOUNT for the Gift Aid amount and DONATION for the donation amount.'),
    '#default_value' => variable_get('cr_donate_giftaid_calculator', ''),
  );
  $form['cr_donate_giftaid_text'] = array(
    '#type' => 'textarea',
    '#title' => t('Gift Aid help text'),
    '#description' => t('HTML is allowed.'),
    '#default_value' => variable_get('cr_donate_giftaid_text', CR_DONATE_GIFTAID_TEXT),
  );
  $form['cr_donate_marketing_prefs_email_text'] = array(
    '#type' => 'textarea',
    '#title' => t('Marketing preferences email option text'),
    '#default_value' => variable_get('cr_donate_marketing_prefs_email_text', CR_DONATE_MARKETING_PREFS_EMAIL_TEXT),
    '#rows' => 2,
  );
  $form['cr_donate_marketing_prefs_post_text'] = array(
    '#type' => 'textarea',
    '#title' => t('Marketing preferences postal option text'),
    '#description' => t('Leave this blank to disable this option.'),
    '#default_value' => variable_get('cr_donate_marketing_prefs_post_text', CR_DONATE_MARKETING_PREFS_POST_TEXT),
    '#rows' => 2,
  );
  $form['cr_donate_methods'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Payment gateways'),
    '#description' => t('Select which payment methods should be available for donations.'),
    '#options' => array(
      'worldpay' => t('WorldPay'),
      'paypal' => t('PayPal'),
    ),
    '#default_value' => variable_get('cr_donate_methods', array('worldpay' => TRUE, 'paypal' => TRUE)),
  );
  $form['cr_donate_worldpay_installation'] = array(
    '#type' => 'textfield',
    '#title' => t('WorldPay installation ID'),
    '#description' => t('A 5 or 6 digit number that identifies the WorldPay installation in use.'),
    '#size' => 6,
    '#default_value' => variable_get('cr_donate_worldpay_installation', ''),
  );
  $form['cr_donate_worldpay_account'] = array(
    '#type' => 'textfield',
    '#title' => t('WorldPay merchant code'),
    '#description' => t('Leave blank to use the default.'),
    '#size' => 15,
    '#default_value' => variable_get('cr_donate_worldpay_account', ''),
  );

  $form['cr_donate_worldpay_callback_password'] = array(
    '#type' => 'textfield',
    '#title' => t('WorldPay callback password'),
    '#description' => t('The password WorldPay uses when performing it\'s callback after processing a payment'),
    '#size' => 15,
    '#default_value' => variable_get('cr_donate_worldpay_callback_password', ''),
  );

  $form['cr_donate_worldpay_description'] = array(
    '#type' => 'textfield',
    '#title' => t('WorldPay transaction description'),
    '#description' => t('Displayed to the user during checkout at WorldPay.'),
    '#default_value' => variable_get('cr_donate_worldpay_description', 'Comic Relief donation'),
  );

  $form['cr_donate_giftaid_transport_backend'] = array (
    '#type' => 'radios',
    '#title' => t('Standalone GiftAid Transport backend'),
    '#description' => t('How the giftaid submissions from the standalone page are sent'),
    '#default_value' => variable_get('cr_donate_giftaid_transport_backend', CR_DONATE_GIFTAID_DEFAULT_TRANSPORT_BACKEND),
    '#options' => array(
      'message_queues' => t('Message Queues'),
      'webservices' => t('Web Services')
    ),
  );

  $form['cr_donate_transport_backend'] = array (
    '#type' => 'radios',
    '#title' => t('Donate Transport backend'),
    '#description' => t('How the donation submissions are sent'),
    '#default_value' => variable_get('cr_donate_transport_backend', CR_DONATE_DEFAULT_TRANSPORT_BACKEND),
    '#options' => array(
      'message_queues' => t('Message Queues'),
      'webservices' => t('Web Services')
    ),
  );


  if (module_exists('cr_message_queues') === FALSE) {
    $form['cr_donate_giftaid_transport_backend']['message_queues'] = array(
      '#disabled' => TRUE,
    );
    $form['cr_donate_transport_backend']['message_queues'] = array(
      '#disabled' => TRUE,
    );
  }
  if (module_exists('cr_webservices') === FALSE) {
    $form['cr_donate_giftaid_transport_backend']['webservices'] = array(
      '#disabled' => TRUE,
    );
    $form['cr_donate_transport_backend']['webservices'] = array(
      '#disabled' => TRUE,
    );
  }

  $form['cr_donate_redirect_to_alt'] = array (
    '#type' => 'checkbox',
    '#title' => t('Redirect all /donate to comicrelief.com/donate'),
    '#description' => t('Will redirect users to comicrelief.com/donate if they go to @base_url/donate. Either directly or via a link', array('@base_url' => $base_url)),
    '#default_value' => variable_get('cr_donate_redirect_to_alt', FALSE)
  );
  $form = system_settings_form($form);
  $form['#submit'][] = 'cr_donate_settings_form_submit';
  return $form;
}

function cr_donate_settings_form_validate($form, &$form_state) {
  if (!count(array_filter($form_state['values']['cr_donate_methods']))) {
    form_set_error('cr_donate_methods', 'You must enable at least one payment gateway.');
  }
}

/**
 * Invalidate the cache here
 */
function cr_donate_settings_form_submit($form, &$form_State) {
  //Reload the menu, so the /donate redirect is picked up
  menu_rebuild();

  if (variable_get('cr_donate_redirect_to_alt', FALSE)) {
    drupal_set_message(t('The redirect will not work if a page has the /donate alias already set'));
  }

  drupal_set_message('You might have to clear page cache and javascript cache before the donate buttons show the popup');
}
