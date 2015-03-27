<?php
/**
 * @file
 * cr_donate_money_buy.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function cr_donate_money_buy_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'fieldable_panels_pane-donate_money_buy-field_amount'
  $field_instances['fieldable_panels_pane-donate_money_buy-field_amount'] = array(
    'bundle' => 'donate_money_buy',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => 1,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 2,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'fieldable_panels_pane',
    'field_name' => 'field_amount',
    'label' => 'Amount',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => 0,
      'prefix' => '£',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => -7,
    ),
  );

  // Exported field_instance: 'fieldable_panels_pane-donate_money_buy-field_body'
  $field_instances['fieldable_panels_pane-donate_money_buy-field_body'] = array(
    'bundle' => 'donate_money_buy',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'fieldable_panels_pane',
    'field_name' => 'field_body',
    'label' => 'Description',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => -5,
    ),
  );

  // Exported field_instance: 'fieldable_panels_pane-donate_money_buy-field_image'
  $field_instances['fieldable_panels_pane-donate_money_buy-field_image'] = array(
    'bundle' => 'donate_money_buy',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'picture',
        'settings' => array(
          'colorbox' => 'grid_4',
          'fallback_image_style' => '',
          'image_link' => '',
          'picture_group' => 'grid_6',
        ),
        'type' => 'picture',
        'weight' => 1,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'fieldable_panels_pane',
    'field_name' => 'field_image',
    'label' => 'Image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'filefield_paths' => array(
        'active_updating' => 0,
        'file_name' => array(
          'options' => array(
            'pathauto' => 0,
            'transliterate' => 0,
          ),
          'value' => '[file:ffp-name-only-original].[file:ffp-extension-original]',
        ),
        'file_path' => array(
          'options' => array(
            'pathauto' => 0,
            'transliterate' => 0,
          ),
          'value' => '',
        ),
        'retroactive_update' => 0,
      ),
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'insert' => 0,
        'insert_absolute' => 0,
        'insert_class' => '',
        'insert_default' => 'auto',
        'insert_picture_groups' => array(
          'grid_12' => 0,
          'grid_13' => 0,
          'grid_14' => 0,
          'grid_16' => 0,
          'grid_18' => 0,
          'grid_20' => 0,
          'grid_22' => 0,
          'grid_24' => 0,
          'grid_4' => 0,
          'grid_6' => 0,
          'grid_8' => 0,
          'grid_9' => 0,
        ),
        'insert_styles' => array(
          'auto' => 'auto',
          'icon_link' => 0,
          'image' => 0,
          'image_epsacrop_thumb' => 0,
          'image_flexslider_full' => 0,
          'image_flexslider_thumbnail' => 0,
          'image_grid-12-narrow' => 0,
          'image_grid-12-narrow-x2' => 0,
          'image_grid-12-normal' => 0,
          'image_grid-12-wide' => 0,
          'image_grid-13-narrow' => 0,
          'image_grid-13-narrow-x2' => 0,
          'image_grid-13-normal' => 0,
          'image_grid-13-wide' => 0,
          'image_grid-14-narrow' => 0,
          'image_grid-14-narrow-x2' => 0,
          'image_grid-14-normal' => 0,
          'image_grid-14-wide' => 0,
          'image_grid-16-narrow' => 0,
          'image_grid-16-narrow-x2' => 0,
          'image_grid-16-normal' => 0,
          'image_grid-16-wide' => 0,
          'image_grid-18-narrow' => 0,
          'image_grid-18-narrow-x2' => 0,
          'image_grid-18-normal' => 0,
          'image_grid-18-wide' => 0,
          'image_grid-20-narrow' => 0,
          'image_grid-20-narrow-x2' => 0,
          'image_grid-20-normal' => 0,
          'image_grid-20-wide' => 0,
          'image_grid-22-narrow' => 0,
          'image_grid-22-narrow-x2' => 0,
          'image_grid-22-normal' => 0,
          'image_grid-22-wide' => 0,
          'image_grid-24-narrow' => 0,
          'image_grid-24-narrow-x2' => 0,
          'image_grid-24-normal' => 0,
          'image_grid-24-wide' => 0,
          'image_grid-4-narrow' => 0,
          'image_grid-4-narrow-x2' => 0,
          'image_grid-4-normal' => 0,
          'image_grid-4-wide' => 0,
          'image_grid-6-narrow' => 0,
          'image_grid-6-narrow-x2' => 0,
          'image_grid-6-normal' => 0,
          'image_grid-6-wide' => 0,
          'image_grid-8-narrow' => 0,
          'image_grid-8-narrow-x2' => 0,
          'image_grid-8-normal' => 0,
          'image_grid-8-wide' => 0,
          'image_grid-9-narrow' => 0,
          'image_grid-9-narrow-x2' => 0,
          'image_grid-9-normal' => 0,
          'image_grid-9-wide' => 0,
          'image_grid-all-columns-fluid' => 0,
          'image_grid-all-columns-fluid-x2' => 0,
          'image_large' => 0,
          'image_medium' => 0,
          'image_promo_withside_breakpoints_theme_cr_layout_fluid_1x' => 0,
          'image_thumbnail' => 0,
          'image_video_poster' => 0,
          'link' => 0,
        ),
        'insert_width' => '',
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => -8,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Amount');
  t('Description');
  t('Image');

  return $field_instances;
}
