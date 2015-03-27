<?php
/**
 * @file
 * ideas_and_tools.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function ideas_and_tools_taxonomy_default_vocabularies() {
  return array(
    'fundraising_categories_1' => array(
      'name' => 'Fundraising Categories 1',
      'machine_name' => 'fundraising_categories_1',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'fundraising_categories_2' => array(
      'name' => 'Fundraising Categories 2',
      'machine_name' => 'fundraising_categories_2',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
