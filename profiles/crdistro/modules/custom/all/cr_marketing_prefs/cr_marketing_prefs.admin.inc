<?php

function cr_marketing_prefs_settings_form() {
  $form['cr_marketing_prefs_header_general_intro'] = array(
    '#type' => 'textarea',
    '#title' => t('ESU header intro text'),
    '#description' => t('HTML is allowed.'),
    '#default_value' => variable_get('cr_marketing_prefs_header_general_intro', ''),
  );

  $form['cr_marketing_prefs_header_step1_thankyou_intro'] = array(
    '#type' => 'textarea',
    '#title' => t('ESU header step 1 thankyou text'),
    '#description' => t('HTML is allowed.'),
    '#default_value' => variable_get('cr_marketing_prefs_header_step1_thankyou_intro', CR_MARKETING_PREFS_HEADER_STEP1_THANKYOU_INTRO),
  );

  $form['cr_marketing_prefs_header_teacher_select_title'] = array(
    '#type' => 'textarea',
    '#title' => t('ESU header step 1 thankyou text'),
    '#description' => t('HTML is allowed.'),
    '#default_value' => variable_get('cr_marketing_prefs_header_teacher_select_title', CR_MARKETING_PREFS_HEADER_TEACHER_SELECT_TITLE),
  );

  $form['cr_marketing_prefs_header_thankyou_intro'] = array(
    '#type' => 'textarea',
    '#title' => t('ESU header thankyou text'),
    '#description' => t('HTML is allowed.'),
    '#default_value' => variable_get('cr_marketing_prefs_header_thankyou_intro', CR_MARKETING_PREFS_HEADER_THANKYOU_INTRO),
  );

  $form['cc'] = array(
    '#type' => 'fieldset',
    '#title' => t('Campaign Commander email settings'),
    '#description' => t('If these fields are filled in, an email will automatically be sent when a user completes an email signup form.'),
  );
  $form['cc']['cr_marketing_prefs_cc_random'] = array(
    '#type' => 'textfield',
    '#title' => t('Unique random tag'),
    '#default_value' => variable_get('cr_marketing_prefs_cc_random', ''),
  );
  $form['cc']['cr_marketing_prefs_cc_security'] = array(
    '#type' => 'textfield',
    '#title' => t('Security tag'),
    '#default_value' => variable_get('cr_marketing_prefs_cc_security', ''),
  );

  $form['cr_marketing_prefs_esu_transport_backend'] = array (
    '#type' => 'radios',
    '#title' => t('Marketing Prefs ESU transport backend'),
    '#description' => t('How the email sign ups are sendt'),
    '#default_value' => variable_get('cr_marketing_prefs_esu_transport_backend', CR_MARKETING_PREFS_ESU_DEFAULT_TRANSPORT_BACKEND),
    '#options' => array(
      'message_queues' => t('Message Queues'),
      'webservices' => t('Web Services')
    ),
  );

  if (module_exists('cr_message_queues') === FALSE) {
    $form['cr_marketing_prefs_esu_transport_backend']['message_queues'] = array(
      '#disabled' => TRUE,
    );
  }
  if (module_exists('cr_webservices') === FALSE) {
    $form['cr_marketing_prefs_esu_transport_backend']['webservices'] = array(
      '#disabled' => TRUE,
    );
  }

  return system_settings_form($form);
}
