<?php
/**
 * @file
 * downloadable.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function downloadable_filter_default_formats() {
  $formats = array();

  // Exported format: links.
  $formats['links'] = array(
    'format' => 'links',
    'name' => 'links',
    'cache' => 0,
    'status' => 1,
    'weight' => 0,
    'filters' => array(
      'filter_html' => array(
        'weight' => -10,
        'status' => 1,
        'settings' => array(
          'allowed_html' => '<a> <em> <strong> <cite> <blockquote> <code> <ul> <ol> <li> <dl> <dt> <dd> <span>',
          'filter_html_help' => 1,
          'filter_html_nofollow' => 0,
        ),
      ),
      'cr_general_filter_downloadables' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_tokens' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  return $formats;
}
