<?php

/**
 * @file
 * Provide donate form blocks to Panels.
 */

$plugin = array(
  'title' => t('Donate form'),
  'category' => t('Miscellaneous'),
);

/**
 * Donate form pane configuration form.
 */
function cr_donate_donate_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['cart_id'] = array(
    '#type' => 'textfield',
    '#title' => 'WorldPay cart ID (desktop)',
    '#default_value' => isset($conf['cart_id']) ? $conf['cart_id'] : '',
    '#maxlength' => 30,
  );
  $form['cart_id_mobile'] = array(
    '#type' => 'textfield',
    '#title' => 'WorldPay cart ID (mobile)',
    '#default_value' => isset($conf['cart_id_mobile']) ? $conf['cart_id_mobile'] : '',
    '#maxlength' => 30,
  );
  $form['redirect_url'] = array(
    '#type' => 'textfield',
    '#title' => 'Redirect URL for thank you page',
    '#default_value' => isset($conf['redirect_url']) ? $conf['redirect_url'] : 'donate/thankyou',
    '#field_prefix' => url('<front>', array('absolute' => TRUE)),
  );
  $form['worldpay_installation'] = array(
    '#type' => 'textfield',
    '#title' => 'WorldPay installation ID',
    '#description' => 'Leave blank to use the default for this site.',
    '#default_value' => isset($conf['worldpay_installation']) ? $conf['worldpay_installation'] : '',
  );
  $form['worldpay_account'] = array(
    '#type' => 'textfield',
    '#title' => 'WorldPay merchant code',
    '#description' => 'Leave blank to use the default for this site.',
    '#default_value' => isset($conf['worldpay_account']) ? $conf['worldpay_account'] : '',
  );

  return $form;
}

/**
 * Submit callback for promo configuration form.
 */
function cr_donate_donate_content_type_edit_form_submit($form, &$form_state) {
  $form_state['conf']['cart_id'] = $form_state['values']['cart_id'];
  $form_state['conf']['cart_id_mobile'] = $form_state['values']['cart_id_mobile'];
  $form_state['conf']['redirect_url'] = $form_state['values']['redirect_url'];
  $form_state['conf']['worldpay_installation'] = $form_state['values']['worldpay_installation'];
  $form_state['conf']['worldpay_account'] = $form_state['values']['worldpay_account'];
}

/**
 * Output function for the donate form content type.
 */
function cr_donate_donate_content_type_render($subtype, $conf) {
  // Donate forms show the "keep me posted" section
  $conf['allow_subscribe'] = TRUE;

  // Render form.
  $block = new stdClass();
  $block->content = drupal_get_form('cr_donate_form', (object) $conf);
  return $block;
}
