<?php
/**
 * @file
 * cr_donate_money_buy.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function cr_donate_money_buy_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_amount'
  $field_bases['field_amount'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_amount',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'number_integer',
  );

  return $field_bases;
}
