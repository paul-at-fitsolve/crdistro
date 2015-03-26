<?php
/**
 * @file
 * cr_layout_base.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function cr_layout_base_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'site_layout';
  $context->description = 'Logo, site name, copyright, footer etc';
  $context->tag = 'Global';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '*' => '*',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Global');
  t('Logo, site name, copyright, footer etc');
  $export['site_layout'] = $context;

  return $export;
}
