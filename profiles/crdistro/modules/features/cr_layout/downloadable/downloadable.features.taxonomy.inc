<?php
/**
 * @file
 * downloadable.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function downloadable_taxonomy_default_vocabularies() {
  return array(
    'dl_category' => array(
      'name' => 'Downloadable Category',
      'machine_name' => 'dl_category',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
