<?php


/**
 * @file
 * Definition of the 'Tabs' panel style.
 */

// Plugin definition
$plugin = array(
  'title' => t('Slider'),
  'description' => t('Show panel panes in a region as a slider.'),
  'render region' => 'panels_slider_style_render_region',
  'settings form' => 'panels_slider_style_render_region_settings_form',
);

/**
 * Render callback.
 *
 * @ingroup themeable
 */
function theme_panels_slider_style_render_region($vars) {
  $display = $vars['display'];
  $region_id = $vars['region_id'];
  $owner_id = $vars['owner_id'];
  $panes = $vars['panes'];
  $settings = $vars['settings'];
  $transition = $settings['transition'];

  $tab_id = 'tabs-' . $owner_id . '-' . $region_id;

  //Unique class
  $unique_class = 'flexslider-identifier-' . time() . '-' . rand(0, 100);

  // Buid classes from settings
  $classes = 'js-slider ';
  if(!empty($vars['settings']['extraClasses'])) {
    $classes .= ' ' . $vars['settings']['extraClasses'];
  }

  $element = array(
    '#prefix' => '<div class="'. $unique_class. ' ' . $classes .'">',
    '#suffix' => '</div>',
    '#attached' => array(
      'js' => array(
        drupal_get_path('module', 'cr_panels_slider') . '/js/cr_panels_slider.js' => array('type' => 'file'),
      ),
    ),
  );

  libraries_load('flexslider');

  $settings['flexsliderIdentifier'] = $unique_class;

  //Flexslider class exposed in settings so other modules can hook into it
  $settings['flexsliderSlideClass'] = "slider-contents";

  $jsSettings = array();
  $jsSettings['panelsSlider'][] = $settings;

  $element['#attached']['js'][] = array(
    'type' => 'setting',
    'data' => $jsSettings,
  );

  $items = array();
  $delta = 0;
  $element['tabs_content']['#prefix'] = '<div class="' . $settings['flexsliderSlideClass'] . ' equal-height-container">';
  $element['tabs_content']['#suffix'] = '</div>';
  foreach ($panes as $pane_id => $item) {
    $element['tabs_content'][$pane_id] = array(
      '#prefix' => '<div class="slider-content equal-height-element" id="' . $tab_id . '-' . $delta . '">',
      '#suffix' => '</div>',
      '#markup' => $item,
    );
    ++$delta;
  }

  return drupal_render($element);
}

/**
 * Region settings form callback.
 */
function panels_slider_style_render_region_settings_form($style_settings) {
  // Content.

  $title_default_value = isset($style_settings['slider_pane_title']) ? $style_settings['slider_pane_title'] : "";

  $form['slider_pane_title'] = array (
    '#title' => t('Title used above the Slider'),
    '#type' => 'textfield',
    '#default_value' => $title_default_value,
    '#description' => t('Title used above the Slider'),
    );

  $transition_default_value = isset($style_settings['transition']) ? $style_settings['transition'] : 'slide';
  $form['transition'] = array(
    '#title' => t('Transition'),
    '#type' => 'select',
    '#options' => array(
      'fade' => t('Fade'),
      'slide' => t('Slide'),
    ),
    '#default_value' => $transition_default_value,
    '#description' => t('The transition to use for the tabs.'),
  );
  // @TODO Actually check how many panes there are.
  $open_tab_default_value = isset($style_settings['open_slide']) ? $style_settings['open_slide'] : 0;
  $form['open_slide'] = array(
    '#title' => t('Default Slide'),
    '#type' => 'select',
    '#options' => array(
      0 => t('First'),
      1 => t('Second'),
      2 => t('Third'),
      3 => t('Fourth'),
    ),
    '#default_value' => $open_tab_default_value,
    '#description' => t('The default open slide.'),
  );
  $direction_nav_default_value = isset($style_settings['direction_nav']) ? $style_settings['direction_nav'] : 'true';
  $form['direction_nav'] = array(
    '#title' => t('Directional navigation'),
    '#type' => 'select',
    '#options' => array(
      'false' => t('False'),
      'true' => t('True'),
    ),
    '#default_value' => $direction_nav_default_value,
    '#description' => t('Whether to enable/disable directional controls for the tabs.'),
  );

  $direction_nav_text_prev_default_value = isset($style_settings['direction_nav_text_prev']) ? $style_settings['direction_nav_text_prev'] : "";
  $form['direction_nav_text_prev'] = array (
    '#title' => t('Previous link text'),
    '#type' => 'textfield',
    '#default_value' => $direction_nav_text_prev_default_value,
    '#description' => t('Text/HTML for the \'Previous\' link. (Only applies if directional navigation is set to true)'),
    );

    $direction_nav_text_next_default_value = isset($style_settings['direction_nav_text_next']) ? $style_settings['direction_nav_text_next'] : "";
  $form['direction_nav_text_next'] = array (
    '#title' => t('Next link text'),
    '#type' => 'textfield',
    '#default_value' => $direction_nav_text_next_default_value,
    '#description' => t('Text/HTML for the \'Next\' link. (Only applies if directional navigation is set to true)'),
    );
  $pause_play_default_value = isset($style_settings['pause_play']) ? $style_settings['pause_play'] : 'false';
  $form['pause_play'] = array (
    '#title' => t('Add Pause/Play Button'),
    '#type' => 'select',
    '#options' => array(
      'false' => t('False'),
      'true' => t('True'),
    ),
    '#default_value' => $pause_play_default_value,
    '#description' => t('Whether to enable/disable pause/play button.'),
  );
  $pause_play_default_value = isset($style_settings['auto_play']) ? $style_settings['auto_play'] : 'false';
  $form['auto_play'] = array (
    '#title' => t('Auto Play (Only in Pause/Play is enabled)'),
    '#type' => 'select',
    '#options' => array(
      'false' => t('False'),
      'true' => t('True'),
    ),
    '#default_value' => $auto_play_default_value,
    '#description' => t('Whether to enable/disable pause/play button.'),
  );
  $extra_classes_default_value = isset($style_settings['extraClasses']) ? $style_settings['extraClasses'] : '';
  $form['extraClasses'] = array(
    '#title' => 'Extra Classes',
    '#description' => 'Drop any classes you want in here.',
    '#type' => 'textfield',
    '#default_value' => $extra_classes_default_value,
  );

  return $form;
}
