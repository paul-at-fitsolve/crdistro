<?php


/**
 * @file
 * 
 * Allows a Panels region to be configured to be:
 *
 * - Default container
 *  or
 * - Full-width section (likely to be used with the slideshow component)
 *
 */

// Plugin definition
$path = drupal_get_path('module', 'crl2_panel_styles') . '/plugins/styles/section';
$plugin = array(
  'title' => t('Section'),
  'description' => t('Create a full-width section'),
  'settings form' => 'crl2_panes_styles_section_style_settings_form',
  'render region' => 'crl2_panes_styles_section_style_render_region',
  'hook theme' => array(
    'section_default' => array(
      'template' => 'section--default',
      'path' => $path,
      'variables' => array('panes' => NULL, 'custom_classes' => 'NULL'),
    ),
    'section_full_width' => array(
      'template' => 'section--full-width',
      'path' => $path,
      'variables' => array('panes' => NULL, 'custom_classes' => 'NULL', 'bg_pane' => NULL),
    ),
    'section_default_background' => array(
      'template' => 'section--default--background',
      'path' => $path,
      'variables' => array('panes' => NULL, 'custom_classes' => 'NULL'),
    ),
    'section_full_width_background' => array(
      'template' => 'section--full-width--background',
      'path' => $path,
      'variables' => array('panes' => NULL, 'custom_classes' => 'NULL', 'bg_pane' => NULL),
    ),
  ),
);


/**
 * Region settings form callback.
 */
function crl2_panes_styles_section_style_settings_form($style_settings, $panel_display, $region) {
  $form['section_full_width'] = array(
    '#type' => 'checkbox',
    '#title' => t('Full-width section?'),
    '#default_value' => (isset($style_settings['section_full_width'])) ? $style_settings['section_full_width'] : '',
    '#description' => t('Removes the .container class from &lt;section&gt; and the inner .row. The required row and column classes are added via the component/s you add to this region.'),
  );

  // Wrap HTML output in a container so we can use 
  // Form states - https://api.drupal.org/comment/11049#comment-11049
  $form['output_section_full_width'] = array(
    '#type' => 'container',
    '#states' => array(
      'visible' => array(
        ':input[name="settings[section_full_width]"]' => array('checked' => TRUE),
      ),
    ),
  );
  
  $form['output_section_full_width']['markup'] = array(
    '#markup' => '<strong>Output:</strong>
      <pre>
&lt;section&gt;                   &lt;-- Full-width section (add custom classes below)
  &lt;?php print $panes ?&gt;     &lt;-- Components as Fieldable Panels Panes
&lt;/section&gt;
      </pre>',
  );


  // Wrap HTML output in a container so we can use 
  // Form states - https://api.drupal.org/comment/11049#comment-11049
  $form['output_section_container'] = array(
    '#type' => 'container',
    '#states' => array(
      'visible' => array(
        ':input[name="settings[section_full_width]"]' => array('checked' => FALSE),
      ),
    ),
  );

  $form['output_section_container']['markup'] = array(
    '#markup' => '<strong>Output:</strong>
      <pre>
&lt;section&gt;                       &lt;-- Full width section (add custom classes below)
  &ltdiv class=&quot;container&quot;&gt;       &lt;-- Default section container (add custom classes below)
    &lt;div class=&quot;row&quot;&gt;           &lt;-- Row to hold columns IE. Panels panes (add custom classes below)
      &lt;?php print $panes ?&gt;     &lt;-- Panels panes with responsive column settings
    &lt;/div&gt;
  &lt;/div&gt;    
&lt;/section&gt;
      </pre>',
      '#states' => array(
        'visible' => array(
          ':input[name="settings[section_full_width]"]' => array('checked' => FALSE),
        ),
      ),      
  );

  $form['classes_section'] = array(
    '#type' => 'textfield', 
    '#title' => t('Custom classes for <em>&lt;section&gt;</em>'), 
    '#description' => t('A space-separated list of classes to add to the full-width &lt;section&gt; wrapper. Use custom classes here for full-width background images or solid background colours.'),
    '#default_value' => (isset($style_settings['classes_section'])) ? $style_settings['classes_section'] : '',
    );
  $form['classes_container'] = array(
    '#type' => 'textfield', 
    '#title' => t('Custom classes for <em>div.container</em>'), 
    '#description' => t('A space-separated list of classes to add to the container.'),
    '#default_value' => (isset($style_settings['classes_container'])) ? $style_settings['classes_container'] : '',
    );
  $form['classes_row'] = array(
    '#type' => 'textfield', 
    '#title' => t('Custom classes for <em>div.row</em>'), 
    '#size' => 3,
    '#description' => t('A space-separated list of classes to add to the .row column wrapper.'),
    '#default_value' => (isset($style_settings['classes_row'])) ? $style_settings['classes_row'] : '',
    '#states' => array(
      'visible' => array(
        ':input[name="settings[section_full_width]"]' => array('checked' => FALSE),
      ),
    ),
  );

  /* 
   * Background functionality
   * Provides a checkbox and drop down to select a pane as background
   */
  
  // Provide an array of current pane options in this region
  $pane_bg_options = crl2_panes_styles_pane_options($panel_display, $region);

  $pane_bg_default = (isset($style_settings['background_pane_container']['background_pane'])) ? $style_settings['background_pane_container']['background_pane'] : '_none';

  if(count($pane_bg_options) > 1 && isset($pane_bg_options[$pane_bg_default])) {
    $form['use_background_pane'] = array(
      '#type' => 'checkbox',
      '#title' => t('Background Pane?'),
      '#default_value' => (isset($style_settings['use_background_pane'])) ? $style_settings['use_background_pane'] : '',
      '#description' => t('Allows you to define a background pane which is positioned beneath the other panes.'),
    );
    $form['background_pane_container'] = array(
      '#type' => 'container',
      '#states' => array(
        'visible' => array(
          ':input[name="settings[use_background_pane]"]' => array('checked' => TRUE),
        ),
      ),
    );
    $form['background_pane_container']['background_pane'] = array(
      '#type' => 'select',
      '#title' => t('Pane'),
      '#description' => t('Select the pane you wish to set as the background.'),
      '#options' => $pane_bg_options,
      '#default_value' => $pane_bg_default,
    );
    $form['background_pane_container']['use_match_height'] = array(
      '#type' => 'checkbox',
      '#title' => t('Use match height'),
      '#default_value' => (isset($style_settings['background_pane_container']['use_match_height'])) ? $style_settings['background_pane_container']['use_match_height'] : '',
      '#description' => t('If you want the section to expand according to the content, pushing the panes beneath the background check this option. Use this option only if you have to as it is a front end performance hit.'),
    );

    // Breakpoints that are available
    $overlay_content_breakpoint_options = array(
      'xs' => 'Extra Small',
      'sm' => 'Small',
      'md' => 'Medium',
      'lg' => 'Large',
    );
    $overlay_content_breakpoint_options_default = (isset($style_settings['background_pane_container']['overlay_content_breakpoint'])) ? $style_settings['background_pane_container']['overlay_content_breakpoint'] : 'md';
    $form['background_pane_container']['overlay_content_breakpoint'] = array(
      '#type' => 'select',
      '#title' => t('Overlay Content Breakpoint'),
      '#description' => t('Select the breakpoint <strong>from</strong> which you want the content to be over the background. By default it is on the medium breakpoint.'),
      '#options' => $overlay_content_breakpoint_options,
      '#default_value' => $overlay_content_breakpoint_options_default,
    );
  }

  return $form;
}


/**
 * Render a region callback.
 *
 * @ingroup themeable
 */
function theme_crl2_panes_styles_section_style_render_region($vars) {
  $panes = $vars['panes'];
  if(!$panes) return;

  $panes = '';
  
  // Handle background pane logic
  // Setup initial vars
  $bg_pane = '';
  $bg_pane_id = isset($vars['settings']['use_background_pane']) ? $vars['settings']['background_pane_container']['background_pane'] : FALSE;

  // Loop through panes but exclude the background pane
  foreach ($vars['panes'] as $pane_id => $pane) {
    if($pane_id == $bg_pane_id) {
      $bg_pane = $pane;
    } else {
      $panes .= $pane;
    }
  }

  // Prefix a space to custom classes
  $custom_classes = $vars['settings'];
  $custom_classes = crl2_panes_styles_separate_classes($custom_classes);

  // Hmm, something going on with the styles settings for regions when
  // the region styles are automatically applied.
  // Need to make sure the key exists at least to avoid undefined index warnings
  if (!isset($vars['settings']['section_full_width'])) { $vars['settings']['section_full_width'] = ''; }
  if (!isset($custom_classes['classes_section']))      { $custom_classes['classes_section'] = 'clearfix'; }
  if (!isset($custom_classes['classes_container']))    { $custom_classes['classes_container'] = ''; }
  if (!isset($custom_classes['classes_row']))          { $custom_classes['classes_row'] = ''; }

  // In case we end up with leading or trailing spaces on the <section> class
  $custom_classes['classes_section'] = trim($custom_classes['classes_section']);

  // Render the region through either
  // - section--default.tpl.php or
  // - section--full-width.tpl.php
  // based on the status of the 'full-width section' checkbox
  $section_type = $vars['settings']['section_full_width'] ? 'section_full_width' : 'section_default';
  $section_options = array('panes' => $panes, 'custom_classes' => $custom_classes);

  // Extend the template class with background to cover the background variation of these templates
  // - section--default--background.tpl.php or
  // - section--full-width--background.tpl.php
  if(!empty($bg_pane)) {
    $use_match_height = isset($vars['settings']['background_pane_container']['use_match_height']) ? $vars['settings']['background_pane_container']['use_match_height'] : FALSE;
    $section_type = $section_type . '_background';

    /* 
     * In some cases we need to overlay the content, by default this happens on the SM breakpoint
     * CSS to handle this is located in RND15 theme.
     */
    $overlay_content_breakpoint = isset($vars['settings']['background_pane_container']['overlay_content_breakpoint']) ? $vars['settings']['background_pane_container']['overlay_content_breakpoint'] : 'md';
    if($overlay_content_breakpoint) {
      $section_options['custom_classes']['classes_section'] .= ' section--full-width-bg-overlay-'.$overlay_content_breakpoint;
    }

    // Prepare match height group in case we use it
    $section_options['matchheight_group'] = '';
    
    // Prepare the theme var for the bg pane
    $section_options['bg_pane'] = $bg_pane;

    $section_options['custom_classes']['classes_section'] .= ' section--full-width-bg';

    // This is an exception where if we have a pane style applied to the background pane..
    // we want to wrap that bg pane in a container
    $section_options['bg_pane_needs_container'] = isset($vars['display']->content[$bg_pane_id]->style['settings']['use_columns']) ? $vars['display']->content[$bg_pane_id]->style['settings']['use_columns'] : FALSE;

    // Handle match height
    // This applies the match height group to both, the background and pane container
    // It is mainly used in case you want to push the content beneath the background on smaller breakpoints
    // Please use this option sparingly
    if($use_match_height) {
      $section_options['matchheight_group'] = 'data-mh="'.$vars['region_id'] . '-mh-region"';
      // Prepare the BG pane, add a matchheight group wrapper
      $section_options['bg_pane'] = '<div class="section__bg-pane" '.$section_options['matchheight_group'].'>'.$section_options['bg_pane'].'</div>';
    } else {
      $section_options['bg_pane'] = '<div class="section__bg-pane">'.$section_options['bg_pane'].'</div>';
    }
    
  }

  return theme($section_type, $section_options);
}

/**
 * Helper function to ensure custom classes are
 * space-separated.
 *
 * @param array $classes Class array to space-separate
 * @return array $classes Class array - each value is prefixed with a space
 *
 * The classes string is trimmed later so we don't need to worry about
 * the first value having a space prefixed for now.
 */
function crl2_panes_styles_separate_classes($classes) {

  foreach ($classes as $key => &$class) {
    if(!is_array($class) && strpos('classes', $key) !== FALSE) {
      $class != '' ? $class = ' ' . $class : $class;
    }
  }

  return $classes;
}

/**
 * Helper function to ensure to provide panes as a select option
 *
 * @param array $panes Passed in array of pane objects
 * @return array $options Options array, 
 *
 * We supply an options array with the title, admin title or pane id as value and pane id as key
 */
function crl2_panes_styles_pane_options($panel_display, $region) {

  // Get the panes that belong to this region
  $region_pane_ids = isset($panel_display->panels[$region]) ? array_flip($panel_display->panels[$region]) : array();

  // Get the panes belonging to this region
  $region_panes = isset($panel_display->content) ? array_intersect_key($panel_display->content, $region_pane_ids) : array();

  // Create default option
  $options = array('_none' => 'Select a pane...');

  // Loop through and return panes as an option
  foreach ($region_panes as $pane_id => $pane_object) {
    if($pane_object->type === 'fieldable_panels_pane') {
      $title = !empty($pane_object->configuration['title']) ? $pane_object->configuration['title'] : $pane_id;
      $title = !empty($pane_object->configuration['admin_title']) ? $pane_object->configuration['admin_title'] : $title;
      $options[$pane_id] = $title;
    }
  }

  return $options;
}