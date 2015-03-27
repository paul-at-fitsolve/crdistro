<?php


/**
 * @file
 * Definition of the 'Tabs' panel style.
 */

// Plugin definition
$plugin = array(
  'title' => t('Tabs'),
  'description' => t('Show panel panes in a region as tabs.'),
  'render region' => 'panels_tabs_style_render_region',
  'settings form' => 'panels_tabs_style_render_region_settings_form',
);

/**
 * Render callback.
 *
 * @ingroup themeable
 */
function theme_panels_tabs_style_render_region($vars) {

  $display = $vars['display'];
  $region_id = $vars['region_id'];
  $owner_id = $vars['owner_id'];
  $panes = $vars['panes'];
  $settings = $vars['settings'];
  $variant_class = $settings['style'];
  $transition = $settings['transition'];
  $open_tab = $settings['open_tab'];
  $full_width_tabs = (isset($settings['full_width_tabs'])) ? $settings['full_width_tabs'] : false;
  $tabs_pane_title = strlen($settings['tabs_pane_title']) > 0 ? '<a name="tab-top"><h2 class="tabs-title">'.$settings['tabs_pane_title'].'</h2></a>' : '<a name="tab-top"></a>';
  $tab_id = 'tabs-' . $owner_id . '-' . $region_id;
  $ehe_option = isset($settings['equal_height_element']) ? $settings['equal_height_element'] : '';

  // Dirty; to improve
  if ($ehe_option == 1) {
    $ehe_class1 = "equal-height-container";
    $ehe_class2  = "equal-height-element";
  } else { $ehe_class1 = ''; $ehe_class2 = '';}

  // Each flexslider instance gets a unique id
  $flexslider_id = &drupal_static('flexslider_id', 0);
  ++$flexslider_id;

  // Build classes from settings
  // Should be using the render array insted of prefix/suffix
  $classes = 'js-tabs tabs';
  $classes .= ' tabs--' . $variant_class;
  $element = array(
    '#prefix' => '<div id="flexslider-' . $flexslider_id . '" class="'. $classes .'">',
    '#suffix' => '</div>',
    '#attached' => array(

      'js' => array(
        drupal_get_path('module', 'cr_panels_tabs') . '/js/cr_panels_tabs.js' => array('type' => 'file'),
      ),
      'css' => array(
        drupal_get_path('theme', 'cr_layout') . '/css/components/tabs.less' => array('type' => 'file'),
      ),
    ),
  );

  libraries_load('flexslider');

  $jsSettings = array();
  $jsSettings['panelsTabs']['flexslider-' . $flexslider_id] = $settings;

  $element['#attached']['js'][] = array(
    'type' => 'setting',
    'data' => $jsSettings,
  );

  // Get the pane titles.
  $items = array();
  $delta = 0;
  if(isset($display->panels[$region_id])) {
    foreach ($display->panels[$region_id] as $pane_id) {
      // Make sure the pane exists.
      if (!empty($panes[$pane_id])) {
        $classes = 'tab-link';
        $classes .= ($delta == $open_tab) ? ' tabs-active' : '';
        $title = cr_panels_tabs_pane_titles($pane_id);

        $tab_item = array(
          'data' => '<a class="'. $classes .'" href="#'. $tab_id . '-' . $delta .'">' . $title . '</a>',
          'class' => array('tab-nav-item'),
        );

        if($full_width_tabs) {
          $tab_item['class'][] = 'grid-' . (string)(ceil(24 / count($panes)));
        }

        $items[] = $tab_item;

        ++$delta;
      }
    }
  }

  $element['tabs_title'] = array('#theme' => 'item_list', '#items' => $items);
  $element['tabs_title']['#prefix'] = '<div name="tab-wrapper" class="tab-wrapper--'.$variant_class.'">'.$tabs_pane_title;
  $element['tabs_title']['#suffix'] = '</div>';

  if ($variant_class == "button-style") {
    $element['tabs_selectbox']['#prefix'] = '<div class="tabs-selectbox--wrapper"><select id="tabs-selectbox" class="tabs-selectbox form-select">';
    $element['tabs_selectbox']['#suffix'] = '</select></div>';
  }

  $items = array();
  $delta = 0;
  $element['tabs_content']['#prefix'] = '<div class="tab-contents '.$ehe_class1.'">';
  $element['tabs_content']['#suffix'] = '</div>';

  foreach ($panes as $pane_id => $item) {
    $element['tabs_content'][$pane_id] = array(
      '#prefix' => '<div class="tab-content '.$ehe_class2.'" id="' . $tab_id . '-' . $delta . '">',
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
function panels_tabs_style_render_region_settings_form($style_settings) {
  // Content.

  $title_default_value = isset($style_settings['tabs_pane_title']) ? $style_settings['tabs_pane_title'] : "";

  $form['tabs_pane_title'] = array (
    '#title' => t('Title used above the tabs'),
    '#type' => 'textfield',
    '#default_value' => $title_default_value,
    '#description' => t('Title used above the tabs'),
    );

  $style_default_value = isset($style_settings['style']) ? $style_settings['style'] : 'main';

  $form['style'] = array(
    '#title' => t('Style'),
    '#type' => 'select',
    '#options' => array(
      'main' => t('Main tabs'),
      'light' => t('Light tabs'),
      'dark' => t('Dark tabs'),
      'promo' => t('Promo tabs'),
      'side' => t('Side tabs'),
      'bottom' => t('Bottom tabs'),
      'button-style' => t('Button-style tabs'),
    ),
    '#default_value' => $style_default_value,
    '#description' => t('The visual style of the tabs.'),
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
  $open_tab_default_value = isset($style_settings['open_tab']) ? $style_settings['open_tab'] : 0;
  $form['open_tab'] = array(
    '#title' => t('Default Tab'),
    '#type' => 'select',
    '#options' => array(
      0 => t('First'),
      1 => t('Second'),
      2 => t('Third'),
      3 => t('Fourth'),
    ),
    '#default_value' => $open_tab_default_value,
    '#description' => t('The default open tab.'),
  );
  $direction_nav_default_value = isset($style_settings['direction_nav']) ? $style_settings['direction_nav'] : 'false';
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
  $full_width_tabs_default_value = isset($style_settings['full_width_tabs']) ? $style_settings['full_width_tabs'] : 0;
  $form['full_width_tabs'] = array(
    '#title' => t('Full Width Tabs'),
    '#type' => 'select',
    '#options' => array(
      0 => t('False'),
      1 => t('True'),
    ),
    '#default_value' => $full_width_tabs_default_value,
    '#description' => t('Makes the tab nav full width based on the number of tab buttons.'),
  );

  $direction_nav_text_prev_default_value = isset($style_settings['direction_nav_text_prev']) ? $style_settings['direction_nav_text_prev'] : "";

  $form['direction_nav_text_prev'] = array(
    '#title' => t('Previous link text'),
    '#type' => 'textfield',
    '#default_value' => $direction_nav_text_prev_default_value,
    '#description' => t('Text/HTML for the \'Previous\' link. (Only applies if directional navigation is set to true)'),
    );

    $direction_nav_text_next_default_value = isset($style_settings['direction_nav_text_next']) ? $style_settings['direction_nav_text_next'] : "";
    $form['direction_nav_text_next'] = array(
    '#title' => t('Next link text'),
    '#type' => 'textfield',
    '#default_value' => $direction_nav_text_next_default_value,
    '#description' => t('Text/HTML for the \'Next\' link. (Only applies if directional navigation is set to true)'),
    );

    $equal_height_element_default_value = isset($style_settings['equal_height_element']) ? $style_settings['equal_height_element'] : 1;
    $form['equal_height_element'] = array(
    '#title' => t('Equal Height Element'),
    '#type' => 'checkbox',
    '#default_value' => $equal_height_element_default_value,
    '#description' => 'Adds the Equal Height Element to each pane',
    );

    return $form;
}
