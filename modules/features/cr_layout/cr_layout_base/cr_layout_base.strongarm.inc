<?php
/**
 * @file
 * cr_layout_base.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function cr_layout_base_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ds_extras_fields_extra';
  $strongarm->value = 0;
  $export['ds_extras_fields_extra'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ds_extras_fields_extra_list';
  $strongarm->value = '';
  $export['ds_extras_fields_extra_list'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ds_extras_field_permissions';
  $strongarm->value = 0;
  $export['ds_extras_field_permissions'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ds_extras_field_template';
  $strongarm->value = 1;
  $export['ds_extras_field_template'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ds_extras_hidden_region';
  $strongarm->value = 0;
  $export['ds_extras_hidden_region'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ds_extras_hide_page_sidebars';
  $strongarm->value = 0;
  $export['ds_extras_hide_page_sidebars'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ds_extras_hide_page_title';
  $strongarm->value = 0;
  $export['ds_extras_hide_page_title'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ds_extras_region_to_block';
  $strongarm->value = 0;
  $export['ds_extras_region_to_block'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ds_extras_switch_field';
  $strongarm->value = 0;
  $export['ds_extras_switch_field'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ds_extras_switch_view_mode';
  $strongarm->value = 1;
  $export['ds_extras_switch_view_mode'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ds_extras_vd';
  $strongarm->value = 0;
  $export['ds_extras_vd'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_fieldable_panels_pane__text';
  $strongarm->value = array(
    'view_modes' => array(
      'basic_pod' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'picture_main1pod_withoutside' => array(
        'custom_settings' => FALSE,
      ),
      'picture_main1pod_withside' => array(
        'custom_settings' => FALSE,
      ),
      'picture_main2pod_withoutside' => array(
        'custom_settings' => FALSE,
      ),
      'picture_main2pod_withside' => array(
        'custom_settings' => FALSE,
      ),
      'picture_main3pod_withoutside' => array(
        'custom_settings' => FALSE,
      ),
      'picture_main3pod_withside' => array(
        'custom_settings' => FALSE,
      ),
      'picture_promo_withoutside_' => array(
        'custom_settings' => FALSE,
      ),
      'picture_promo_withside' => array(
        'custom_settings' => FALSE,
      ),
      'picture_subpod_withoutside' => array(
        'custom_settings' => FALSE,
      ),
      'list_view' => array(
        'custom_settings' => FALSE,
      ),
      'intro' => array(
        'custom_settings' => TRUE,
      ),
      'pod' => array(
        'custom_settings' => FALSE,
      ),
      'intro_headline_huge' => array(
        'custom_settings' => TRUE,
      ),
      'grid_4' => array(
        'custom_settings' => FALSE,
      ),
      'grid_6' => array(
        'custom_settings' => FALSE,
      ),
      'grid_8' => array(
        'custom_settings' => FALSE,
      ),
      'grid_9' => array(
        'custom_settings' => FALSE,
      ),
      'grid_12' => array(
        'custom_settings' => FALSE,
      ),
      'grid_14' => array(
        'custom_settings' => FALSE,
      ),
      'grid_16' => array(
        'custom_settings' => FALSE,
      ),
      'grid_18' => array(
        'custom_settings' => FALSE,
      ),
      'grid_20' => array(
        'custom_settings' => FALSE,
      ),
      'grid_22' => array(
        'custom_settings' => FALSE,
      ),
      'grid_24' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'title' => array(
          'default' => array(
            'weight' => '-5',
            'visible' => TRUE,
          ),
          'basic_pod' => array(
            'weight' => '-5',
            'visible' => TRUE,
          ),
          'intro' => array(
            'weight' => '-5',
            'visible' => TRUE,
          ),
          'intro_headline_huge' => array(
            'weight' => '-5',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_fieldable_panels_pane__text'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_fieldable_panels_pane__text_media';
  $strongarm->value = array(
    'view_modes' => array(
      'media_position_after' => array(
        'custom_settings' => TRUE,
      ),
      'media_position_before' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'basic_pod' => array(
        'custom_settings' => TRUE,
      ),
      'picture_main1pod_withoutside' => array(
        'custom_settings' => FALSE,
      ),
      'picture_main1pod_withside' => array(
        'custom_settings' => FALSE,
      ),
      'picture_main2pod_withoutside' => array(
        'custom_settings' => FALSE,
      ),
      'picture_main2pod_withside' => array(
        'custom_settings' => FALSE,
      ),
      'picture_main3pod_withoutside' => array(
        'custom_settings' => FALSE,
      ),
      'picture_main3pod_withside' => array(
        'custom_settings' => FALSE,
      ),
      'picture_promo_withoutside_' => array(
        'custom_settings' => FALSE,
      ),
      'picture_promo_withside' => array(
        'custom_settings' => FALSE,
      ),
      'picture_subpod_withoutside' => array(
        'custom_settings' => FALSE,
      ),
      'list_view' => array(
        'custom_settings' => FALSE,
      ),
      'pod' => array(
        'custom_settings' => FALSE,
      ),
      'basic_pod_reverse' => array(
        'custom_settings' => TRUE,
      ),
      'intro_headline_huge' => array(
        'custom_settings' => FALSE,
      ),
      'grid_4' => array(
        'custom_settings' => FALSE,
      ),
      'grid_6' => array(
        'custom_settings' => FALSE,
      ),
      'grid_8' => array(
        'custom_settings' => FALSE,
      ),
      'grid_9' => array(
        'custom_settings' => FALSE,
      ),
      'grid_12' => array(
        'custom_settings' => FALSE,
      ),
      'grid_14' => array(
        'custom_settings' => FALSE,
      ),
      'grid_16' => array(
        'custom_settings' => FALSE,
      ),
      'grid_18' => array(
        'custom_settings' => FALSE,
      ),
      'grid_20' => array(
        'custom_settings' => FALSE,
      ),
      'grid_22' => array(
        'custom_settings' => FALSE,
      ),
      'grid_24' => array(
        'custom_settings' => FALSE,
      ),
      'intro' => array(
        'custom_settings' => FALSE,
      ),
      'tabs_grid_18' => array(
        'custom_settings' => TRUE,
      ),
      'tabs_grid_24' => array(
        'custom_settings' => TRUE,
      ),
      'flexislider_grid_16' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'flexslider_carousel_thumb' => array(
        'custom_settings' => FALSE,
      ),
      'flexslider_grid_16' => array(
        'custom_settings' => FALSE,
      ),
      'flexslider_main_slide' => array(
        'custom_settings' => FALSE,
      ),
      'grid_13' => array(
        'custom_settings' => FALSE,
      ),
      'image_first' => array(
        'custom_settings' => TRUE,
      ),
      'grid_2' => array(
        'custom_settings' => FALSE,
      ),
      'grid_15' => array(
        'custom_settings' => FALSE,
      ),
      'promo_slider' => array(
        'custom_settings' => TRUE,
      ),
      'action_pod_grid_3_404_page' => array(
        'custom_settings' => FALSE,
      ),
      'grid_12_promo' => array(
        'custom_settings' => FALSE,
      ),
      'grid_13_promo' => array(
        'custom_settings' => FALSE,
      ),
      'grid_14_promo' => array(
        'custom_settings' => FALSE,
      ),
      'grid_9_promo' => array(
        'custom_settings' => FALSE,
      ),
      'partners_carousel_front_' => array(
        'custom_settings' => FALSE,
      ),
      'partners_carousel_support_page_' => array(
        'custom_settings' => FALSE,
      ),
      'grid_3' => array(
        'custom_settings' => FALSE,
      ),
      'grid_10' => array(
        'custom_settings' => FALSE,
      ),
      'grid_mediabar_big' => array(
        'custom_settings' => FALSE,
      ),
      'full_width_promo' => array(
        'custom_settings' => TRUE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'title' => array(
          'default' => array(
            'weight' => '-5',
            'visible' => TRUE,
          ),
          'media_position_after' => array(
            'weight' => '-5',
            'visible' => TRUE,
          ),
          'media_position_before' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'basic_pod' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'basic_pod_reverse' => array(
            'weight' => '-5',
            'visible' => TRUE,
          ),
          'tabs_grid_18' => array(
            'weight' => '-5',
            'visible' => TRUE,
          ),
          'tabs_grid_24' => array(
            'weight' => '-5',
            'visible' => TRUE,
          ),
          'image_first' => array(
            'weight' => '-5',
            'visible' => TRUE,
          ),
          'promo_slider' => array(
            'weight' => '-5',
            'visible' => TRUE,
          ),
          'full_width_promo' => array(
            'weight' => '-5',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_fieldable_panels_pane__text_media'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_page';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_page';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_page';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_page';
  $strongarm->value = FALSE;
  $export['node_submitted_page'] = $strongarm;

  return $export;
}
