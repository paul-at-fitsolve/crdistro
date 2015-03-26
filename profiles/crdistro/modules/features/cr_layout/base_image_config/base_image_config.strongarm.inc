<?php
/**
 * @file
 * base_image_config.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function base_image_config_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_fieldable_panels_pane__image';
  $strongarm->value = array(
    'view_modes' => array(
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'list_view' => array(
        'custom_settings' => FALSE,
      ),
      'basic_pod' => array(
        'custom_settings' => FALSE,
      ),
      'grid_4' => array(
        'custom_settings' => TRUE,
      ),
      'grid_6' => array(
        'custom_settings' => TRUE,
      ),
      'grid_9' => array(
        'custom_settings' => TRUE,
      ),
      'grid_12' => array(
        'custom_settings' => TRUE,
      ),
      'grid_14' => array(
        'custom_settings' => TRUE,
      ),
      'grid_16' => array(
        'custom_settings' => TRUE,
      ),
      'grid_18' => array(
        'custom_settings' => TRUE,
      ),
      'grid_20' => array(
        'custom_settings' => TRUE,
      ),
      'grid_22' => array(
        'custom_settings' => TRUE,
      ),
      'grid_24' => array(
        'custom_settings' => TRUE,
      ),
      'intro' => array(
        'custom_settings' => FALSE,
      ),
      'grid_8' => array(
        'custom_settings' => TRUE,
      ),
      'flexislider_grid_16' => array(
        'custom_settings' => FALSE,
      ),
      'basic_pod_reverse' => array(
        'custom_settings' => FALSE,
      ),
      'intro_headline_huge' => array(
        'custom_settings' => FALSE,
      ),
      'flexslider_grid_14_carousel' => array(
        'custom_settings' => FALSE,
      ),
      'flexslider_grid_14_main_slide' => array(
        'custom_settings' => FALSE,
      ),
      'flexslider_grid_16' => array(
        'custom_settings' => TRUE,
      ),
      'tabs_grid_18' => array(
        'custom_settings' => FALSE,
      ),
      'tabs_grid_24' => array(
        'custom_settings' => FALSE,
      ),
      'flexslider_carousel_thumb' => array(
        'custom_settings' => TRUE,
      ),
      'flexslider_main_slide' => array(
        'custom_settings' => TRUE,
      ),
      'grid_2' => array(
        'custom_settings' => TRUE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'grid_13' => array(
        'custom_settings' => TRUE,
      ),
      'partners_carousel_front_' => array(
        'custom_settings' => TRUE,
      ),
      'partners_carousel_support_page_' => array(
        'custom_settings' => TRUE,
      ),
      'image_first' => array(
        'custom_settings' => FALSE,
      ),
      'grid_15' => array(
        'custom_settings' => TRUE,
      ),
      'grid_3' => array(
        'custom_settings' => TRUE,
      ),
      'action_pod_grid_3_404_page' => array(
        'custom_settings' => FALSE,
      ),
      'grid_13_promo' => array(
        'custom_settings' => TRUE,
      ),
      'grid_mediabar_big' => array(
        'custom_settings' => FALSE,
      ),
      'grid_9_promo' => array(
        'custom_settings' => TRUE,
      ),
      'grid_14_promo' => array(
        'custom_settings' => TRUE,
      ),
      'grid_12_promo' => array(
        'custom_settings' => TRUE,
      ),
      'event_slider' => array(
        'custom_settings' => TRUE,
      ),
      'basic_pod_image_first_grid8' => array(
        'custom_settings' => FALSE,
      ),
      'partner_basic' => array(
        'custom_settings' => FALSE,
      ),
      'promo_slider' => array(
        'custom_settings' => FALSE,
      ),
      'grid_10' => array(
        'custom_settings' => TRUE,
      ),
      'full_width_promo' => array(
        'custom_settings' => FALSE,
      ),
      'video' => array(
        'custom_settings' => FALSE,
      ),
      'grid_15_otn' => array(
        'custom_settings' => TRUE,
      ),
      'basic_pod_h3_title' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'title' => array(
          'default' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'list_view' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'grid_4' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'grid_6' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'grid_9' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'grid_12' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'grid_14' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'grid_16' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'grid_18' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'grid_20' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'grid_22' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'grid_24' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'grid_8' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'flexislider_grid_16' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'flexslider_grid_14_carousel' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'flexslider_grid_14_main_slide' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'flexslider_grid_16' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'flexslider_carousel_thumb' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'flexslider_main_slide' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'grid_2' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'partners_carousel_front_' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'partners_carousel_support_page_' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'grid_3' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'grid_13' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'grid_15' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'grid_13_promo' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'grid_9_promo' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'grid_14_promo' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'grid_12_promo' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'event_slider' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'grid_10' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'grid_15_otn' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_fieldable_panels_pane__image'] = $strongarm;

  return $export;
}
