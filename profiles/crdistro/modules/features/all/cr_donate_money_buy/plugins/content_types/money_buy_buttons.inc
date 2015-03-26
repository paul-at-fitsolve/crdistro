<?php

/**
 * @file
 * Provide email signup blocks to Panels.
 */

$plugin = array(
  'title' => t('Donate money buy buttons'),
  'category' => t('Fielded panes'),
);

/**
 * Configuration form.
 */
function cr_donate_money_buy_money_buy_buttons_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['#tree'] = TRUE;

  for ($i = 1; $i <= 6; $i++) {
    $form['amount'][$i] = array(
      '#type' => 'textfield',
      '#title' => 'Amount ' . $i,
      '#field_prefix' => '£',
      '#default_value' => isset($conf['amount'][$i]) ? $conf['amount'][$i] : '',
      '#required' => TRUE,
      '#size' => 5,
    );
  }

  return $form;
}

/**
 * Submit callback for promo configuration form.
 */
function cr_donate_money_buy_money_buy_buttons_content_type_edit_form_submit($form, &$form_state) {
  $form_state['conf']['amount'] = $form_state['values']['amount'];
}

/**
 * Output function for the 'esu' content type.
 */
function cr_donate_money_buy_money_buy_buttons_content_type_render($subtype, $conf) {
  $block = new stdClass;
  $block->content = array(
    '#theme' => 'cr_donate_money_buy_buttons',
    '#amounts' => $conf['amount'],
    '#attached' => array(
      'js' => array(drupal_get_path('module', 'cr_donate_money_buy') . '/cr_donate_money_buy.js'),
    ),
  );
  return $block;
}
