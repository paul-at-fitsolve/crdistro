<?php
/**
 * @file
 * cr_layout_base.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function cr_layout_base_filter_default_formats() {
  $formats = array();

  // Exported format: Full HTML.
  $formats['full_html'] = array(
    'format' => 'full_html',
    'name' => 'Full HTML',
    'cache' => 0,
    'status' => 1,
    'weight' => -9,
    'filters' => array(
      'picture' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_tokens' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_fbshare' => array(
        'weight' => -20,
        'status' => 1,
        'settings' => array(
          'allowed_html' => '<span>',
        ),
      ),
    ),
  );

  // Exported format: Plain text.
  $formats['plain_text'] = array(
    'format' => 'plain_text',
    'name' => 'Plain text',
    'cache' => 1,
    'status' => 1,
    'weight' => -7,
    'filters' => array(
      'filter_html_escape' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_url' => array(
        'weight' => 1,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'filter_autop' => array(
        'weight' => 2,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  // Exported format: wysiwyg.
  $formats['wysiwyg'] = array(
    'format' => 'wysiwyg',
    'name' => 'wysiwyg',
    'cache' => 0,
    'status' => 1,
    'weight' => -10,
    'filters' => array(
      'filter_tokens' => array(
        'weight' => -50,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_html' => array(
        'weight' => -49,
        'status' => 1,
        'settings' => array(
          'allowed_html' => '<u> <a> <em> <strong> <cite> <blockquote> <code> <ul> <ol> <li> <dl> <dt> <dd> <img> <div> <p> <h1> <h2> <h3> <h4> <h5> <h6> <video> <source><span><br>',
          'filter_html_help' => 1,
          'filter_html_nofollow' => 0,
        ),
      ),
      'filter_fbshare' => array(
        'weight' => -20,
        'status' => 1,
        'settings' => array(
          'allowed_html' => '<span>',
        ),
      ),
      'picture' => array(
        'weight' => -46,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  return $formats;
}
