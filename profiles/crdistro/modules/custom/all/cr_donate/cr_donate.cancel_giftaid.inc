<?php

function cr_donate_confirm_cancel_giftaid($email, $hash, $gavinID) {
  cr_donate_add_giftaid_cancellation_css();

  $hash_valid = cr_donate_GA_cancellation_url_is_valid($email, $gavinID, $hash);

  if (!$hash_valid) {
    $messages = array(
      'for_user' => array(
        'message' => 'There was a problem with the Gift Aid cancellation link, please contact us.',
        'args'    => array(),
      ),
      'for_watchdog' => array(
        'message' => 'Invalid Gift Aid Cancellation url path: !url_path.',
        'args'    => array('!url_path' => current_path()),
      ),
    );

    cr_donate_handle_cancel_giftaid_error($messages);
  }

  $form = drupal_get_form('cr_donate_confirm_cancel_giftaid_form', $email, $hash, $gavinID);

  $output = array(
    'confirm_cancel_giftaid' => array(
      '#theme'  => 'cr_donate_confirm_cancel_giftaid',
      '#theme_wrappers' => array('cr_general_callback_content_wrapper'),
      '#form'  => $form,
    ),
  );

  return $output;
}

/**
 * Validate we have a valid hash
 *
 * @param $email
 * @param $hash
 * @return boolean
 */
function cr_donate_GA_cancellation_url_is_valid($email, $gavinID, $hash) {
  $valid_hash = md5("gift_aid_sr14_dasp_{$gavinID}_{$email}");
  return $hash === $valid_hash;
}

function cr_donate_confirm_cancel_giftaid_form($form, &$form_state, $email, $hash, $gavinID) {
  $form = array();
  $form['email'] = array(
    '#type' => 'value',
    '#value'  => $email,
  );

  $form['hash'] = array(
    '#type' => 'value',
    '#value'  => $hash,
  );

  $form['gavidID'] = array(
    '#type' => 'value',
    '#value'  => $gavinID,
  );

  $form['confirm'] = array(
    '#type' => 'submit',
    '#value'  => 'Yes',
  );
  return $form;
}


function cr_donate_confirm_cancel_giftaid_form_submit($form, &$form_state) {
  $values = $form_state['values'];

  $record = array(
    'gavin_id' => $values['gavidID'],
    'email' => $values['email'],
    'timestamp' => time(),
  );

  $db_update_error = FALSE;
  try {
    $db_result = drupal_write_record('cr_donate_giftaid_cancel', $record);
  }
  catch (Exception $e) {
    // See if the exception was due to trying a duplicate insert
    // if so, just show the thank you page again.
    $error_message = $e->getMessage();
    if (strpos($error_message, "1062 Duplicate entry '{$record['gavin_id']}' for key 'PRIMARY'")) {
      drupal_goto('gift-aid/cancel/thankyou');
    }
    else {
      $db_update_error = TRUE;
    }
  }

  // If we have an error either via drupal_write_record's return value or an
  // exception other than "Duplicate entry" then handle this with a generic message
  if ($db_update_error || $db_result === FALSE) {
    $messages = array(
      'for_user' => array(
        'message' => 'A problem occurred whilst updating your data, please contact us.',
        'args' => array(),
      ),
      'for_watchdog' => array(
        'message' => 'Failed to write Gift Aid cancellation record: !record.',
        'args' => array('!record' => print_r($record, TRUE)),
      ),
    );

    // If we caught an exception and got an error message, add it to the watchdog call
    if (isset($error_message)) {
      $messages['for_watchdog']['message'] .= " DB Error: $error_message";
    }
  }

  // if a message has been set then hand off to the error handling function
  if (isset($messages)) {
    cr_donate_handle_cancel_giftaid_error($messages, array());
  }
  else {
    $form_state['redirect'] = 'gift-aid/cancel/thankyou';
  }
}

function cr_donate_confirm_cancel_giftaid_thankyou() {
  cr_donate_add_giftaid_cancellation_css();

  $output = array(
    'confirm_cancel_giftaid_thankyou' => array(
      '#theme'  => 'cr_donate_confirm_cancel_giftaid_thankyou',
      '#theme_wrappers' => array('cr_general_callback_content_wrapper')
    ),
  );

  return $output;
}

// callback for when an error occurred related to cancelling Gift Aid
// drupal_set_message and / or watchdog will have been called at this point
// so we just want to return a page with some static error content
function cr_donate_confirm_cancel_giftaid_error() {
  cr_donate_add_giftaid_cancellation_css();

  $output = array(
    'confirm_cancel_giftaid_error' => array(
      '#theme'  => 'cr_donate_confirm_cancel_giftaid_error',
      '#theme_wrappers' => array('cr_general_callback_content_wrapper')
    ),
  );

  return $output;
}

function cr_donate_handle_cancel_giftaid_error($messages) {
  $user_message = isset($messages['for_user']) ? $messages['for_user'] : NULL;
  if ($user_message) {
    $message = $user_message['message'];
    $args = $user_message['args'];
    $type = isset($user_message['type']) ? $user_message['type'] : 'error';
    drupal_set_message(t($message, $args), $type);
  }

  $watchdog_message = isset($messages['for_watchdog']) ? $messages['for_watchdog'] : NULL;
  if ($watchdog_message) {
    $message = $watchdog_message['message'];
    $args = $watchdog_message['args'];
    $severity = isset($watchdog_message['severity']) ? $watchdog_message['severity'] : WATCHDOG_ERROR;
    watchdog('cr_donate', $message, $args, $severity);
  }

  drupal_goto('gift-aid/cancel/error');

}

function cr_donate_add_giftaid_cancellation_css() {
  $current_theme = variable_get('theme_default', 'cr_layout');
  $path_to_css = drupal_get_path('theme', $current_theme) .
    '/css/giftaid_cancellation.less';
  drupal_add_css($path_to_css);
}
