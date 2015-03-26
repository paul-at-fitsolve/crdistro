<?php
/**
 * @file
 * ideas_and_tools.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function ideas_and_tools_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ideas_and_tools';
  $context->description = 'prototype, any update will across multi sites';
  $context->tag = 'Fundraise';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'prototype/ideas-and-tools' => 'prototype/ideas-and-tools',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-ideas_and_tools-page' => array(
          'module' => 'views',
          'delta' => '-exp-ideas_and_tools-page',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-tools-block' => array(
          'module' => 'views',
          'delta' => 'tools-block',
          'region' => 'content',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Fundraise');
  t('prototype, any update will across multi sites');
  $export['ideas_and_tools'] = $context;

  return $export;
}
