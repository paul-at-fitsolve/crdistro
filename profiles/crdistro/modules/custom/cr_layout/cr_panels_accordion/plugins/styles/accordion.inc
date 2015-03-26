<?php


/**
 * @file
 * Definition of the 'accordion' panel style.
 */

// Plugin definition
$plugin = array(
  'title' => t('Accordion'),
  'description' => t('Show panel panes in a region as accordion.'),
  'render region' => 'panels_accordion_style_render_region',
  'settings form' => 'panels_accordion_style_render_region_settings_form',
);

/**
 * Render callback.
 *
 * @ingroup themeable
 */
function theme_panels_accordion_style_render_region($vars) {
  $display = $vars['display'];
  $region_id = $vars['region_id'];
  $owner_id = $vars['owner_id'];
  $panes = $vars['panes'];
  $settings = $vars['settings'];
  $variant_class = $settings['style'];
  $open_accordion = $settings['open_accordion'];
  $desktop_state = $settings['desktop_state'];
  $accordion_id = 'accordion-' . $owner_id . '-' . $region_id;

  // Buid classes from settings
  $classes = 'js-accordion accordion';
  $classes .= ' accordion--' . $variant_class;
  if(!empty($desktop_state)) {
    $classes .= ' is-mobile-only';
  }
  $element = array(
    '#prefix' => '<div class="'. $classes .'">',
    '#suffix' => '</div>',
  );

  $jsSettings = array();
  $jsSettings['panelsaccordion'] = $settings;

  $element['#attached']['js'][] = array(
    'type' => 'setting',
    'data' => $jsSettings,
  );

  $items = array();
  $delta = 0;
  foreach ($panes as $pane_id => $item) {
    $open = '';
    if($delta == $open_accordion) {
      $open = ' open';
    }
    $pane_title = cr_panels_accordion_pane_titles($pane_id);
    $title = '<summary class="accordion-title">' . $pane_title . '</summary>';
    $element['accordion_content'][$pane_id] = array(
      '#prefix' => '<details class="accordion-item"' . $open . '>' . $title,
      '#suffix' => '</details>',
      '#markup' => $item,
    );
    ++$delta;
  }

  $content = drupal_render($element);

  if(!empty($desktop_state)) {
    $vars['settings'] = $settings[$desktop_state . '_form'];
    $content .= '<div class="is-not-mobile">';
    $content .= theme($desktop_state, $vars);
    $content .= '</div>';
  }

  return $content;
}

/**
 * Region settings form callback.
 */
function panels_accordion_style_render_region_settings_form($style_settings) {
  // Content.
  $style_default_value = isset($style_settings['style']) ? $style_settings['style'] : 'basic';
  $form['style'] = array(
    '#title' => t('Style'),
    '#type' => 'select',
    '#options' => array(
      'basic' => t('Basic accordion'),
      'color' => t('Colour'),
    ),
    '#default_value' => $style_default_value,
    '#description' => t('The visual style of the accordion.'),
  );
  // @TODO Actually check how many panes there are.
  $open_accordion_default_value = isset($style_settings['open_accordion']) ? $style_settings['open_accordion'] : 0;
  $form['open_accordion'] = array(
    '#title' => t('Default open pane'),
    '#type' => 'select',
    '#options' => array(
      0 => t('First'),
      1 => t('Second'),
      2 => t('Third'),
      3 => t('Fourth'),
    ),
    '#default_value' => $open_accordion_default_value,
    '#description' => t('The default open accordion.'),
  );
  $desktop_state_default_value = isset($style_settings['desktop_state_default_value']) ? $style_settings['desktop_state_default_value'] : '';
  $form['desktop_state'] = array(
    '#title' => t('When I grow up I want to be...'),
    '#type' => 'select',
    '#options' => array(
      // The values must match the theme function name exactly
      '' => t('Accordion'),
      'panels_tabs_style_render_region' => t('Tabs'),
      'panels_list_style_render_region' => t('Basic List'),
    ),
    '#default_value' => $desktop_state_default_value,
  );

  // Implement the tabs settings form here.
  module_load_include('inc', 'cr_panels_tabs', 'plugins/styles/tabs');
  $panels_tabs_style_render_region_form = panels_tabs_style_render_region_settings_form($style_settings['panels_tabs_style_render_region_form']);
  $form['panels_tabs_style_render_region_form'] = $panels_tabs_style_render_region_form;
  $form['panels_tabs_style_render_region_form']['#type'] = 'fieldset';
  $form['panels_tabs_style_render_region_form']['#states'] = array(
    // Only show this fieldset when the 'desktop_state' selectbox is 'tabs'.
    'visible' => array(
      ':input[name="settings[desktop_state]"]' => array('value' => 'panels_tabs_style_render_region'),
    ),
  );
  module_load_include('inc', 'panels', 'plugins/styles/list');
  $panels_list_style_render_region_form = panels_list_style_settings_form($style_settings['panels_list_style_render_region_form']);
  $form['panels_list_style_render_region_form'] = $panels_list_style_render_region_form;
  $form['panels_list_style_render_region_form']['#type'] = 'fieldset';
  $form['panels_list_style_render_region_form']['#states'] =  array(
    // Only show this fieldset when the 'desktop_state' selectbox is 'base_list'.
    'visible' => array(
      ':input[name="settings[desktop_state]"]' => array('value' => 'panels_list_style_render_region'),
    ),
  );

  return $form;
}
