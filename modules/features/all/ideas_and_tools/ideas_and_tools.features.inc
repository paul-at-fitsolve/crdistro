<?php
/**
 * @file
 * ideas_and_tools.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ideas_and_tools_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ideas_and_tools_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function ideas_and_tools_node_info() {
  $items = array(
    'fundraising_ideas' => array(
      'name' => t('Fundraising Ideas'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
