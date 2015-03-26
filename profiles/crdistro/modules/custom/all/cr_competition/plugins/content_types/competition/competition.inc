<?php
/**
 * @file
 * Provide competition form blocks to Panels.
 */

$plugin = array(
  'title' => t('Competition form'),
  'category' => t('DASP'),
);

/**
 * Donate form pane configuration form.
 */
function cr_competition_competition_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['#tree'] = TRUE;
  $form['trans_source_child'] = array(
    '#type' => 'textfield',
    '#title' => 'TransSource: Child / Under 16s (desktop)',
    '#default_value' => isset($conf['trans_source_child']) ? $conf['trans_source_child'] : '',
    '#maxlength' => 80,
    '#required' => TRUE,
  );
  $form['trans_source_child_mob'] = array(
    '#type' => 'textfield',
    '#title' => 'TransSource: Child / Under 16s (mobile)',
    '#default_value' => isset($conf['trans_source_child_mob']) ? $conf['trans_source_child_mob'] : '',
    '#maxlength' => 80,
    '#required' => TRUE,
  );
  $form['trans_source_adult'] = array(
    '#type' => 'textfield',
    '#title' => 'TransSource: Adult / Over 16s (desktop)',
    '#default_value' => isset($conf['trans_source_adult']) ? $conf['trans_source_adult'] : '',
    '#maxlength' => 80,
    '#required' => TRUE,
  );
  $form['trans_source_adult_mob'] = array(
    '#type' => 'textfield',
    '#title' => 'TransSource: Adult / Over 16s (mobile)',
    '#default_value' => isset($conf['trans_source_adult_mob']) ? $conf['trans_source_adult_mob'] : '',
    '#maxlength' => 80,
    '#required' => TRUE,
  );

  $form = array_merge($form, cr_transaction_emails_get_fieldset($conf));

  $form['redirect_url'] = array(
    '#type' => 'textfield',
    '#title' => 'URL for Adult / Over-16s redirection after competition entry',
    '#default_value' => isset($conf['redirect_url']) ? $conf['redirect_url'] : '',
    '#field_prefix' => url('<front>', array('absolute' => TRUE)),
    '#maxlength' => 100,
  );

  $form['redirect_child_url'] = array(
    '#type' => 'textfield',
    '#title' => 'URL for Children / Under-16s redirection after competition entry',
    '#default_value' => isset($conf['redirect_child_url']) ? $conf['redirect_child_url'] : '',
    '#field_prefix' => url('<front>', array('absolute' => TRUE)),
    '#maxlength' => 100,
  );

  $form['cancel_url'] = array(
    '#type' => 'textfield',
    '#title' => 'Redirect URL for entry cancellation',
    '#default_value' => isset($conf['cancel_url']) ? $conf['cancel_url'] : '',
    '#field_prefix' => url('<front>', array('absolute' => TRUE)),
    '#maxlength' => 100,
  );

  return $form;
}

/**
 * Submit callback for competition setup form.
 */
function cr_competition_competition_content_type_edit_form_submit($form, &$form_state) {
  $form_state['conf']['trans_source_child'] = $form_state['values']['trans_source_child'];
  $form_state['conf']['trans_source_child_mob'] = $form_state['values']['trans_source_child_mob'];
  $form_state['conf']['trans_source_adult'] = $form_state['values']['trans_source_adult'];
  $form_state['conf']['trans_source_adult_mob'] = $form_state['values']['trans_source_adult_mob'];

  $form_state['conf']['trans_email_unique'] = $form_state['values']['trans_emails']['trans_email_unique'];
  $form_state['conf']['trans_email_security'] = $form_state['values']['trans_emails']['trans_email_security'];

  $form_state['conf']['redirect_url'] = $form_state['values']['redirect_url'];
  $form_state['conf']['redirect_child_url'] = $form_state['values']['redirect_child_url'];
  $form_state['conf']['cancel_url'] = $form_state['values']['cancel_url'];
}

/**
 * Render the competition form content type.
 */
function cr_competition_competition_content_type_render($subtype, $conf) {
  // Render form.
  $block = new stdClass();
  $block->content = drupal_get_form('cr_competition_form', (object) $conf);
  return $block;
}