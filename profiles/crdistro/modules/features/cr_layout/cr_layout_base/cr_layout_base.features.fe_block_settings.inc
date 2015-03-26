<?php
/**
 * @file
 * cr_layout_base.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function cr_layout_base_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['boxes-global_simple_nav'] = array(
    'cache' => -2,
    'css_class' => 'header-back-home',
    'custom' => 0,
    'delta' => 'global_simple_nav',
    'module' => 'boxes',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'sport_relief' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'sport_relief',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
