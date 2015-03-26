<?php
/**
 * @file
 * cr_layout_base.box.inc
 */

/**
 * Implements hook_default_box().
 */
function cr_layout_base_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'global_simple_nav';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Simple Nav Buttons';
  $box->options = array(
    'body' => array(
      'value' => '<p><a class="button button--large" href="/">Back to home</a></p>',
      'format' => 'wysiwyg',
    ),
    'additional_classes' => '',
  );
  $export['global_simple_nav'] = $box;

  return $export;
}
