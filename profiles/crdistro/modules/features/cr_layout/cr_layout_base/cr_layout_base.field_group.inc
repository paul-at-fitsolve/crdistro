<?php
/**
 * @file
 * cr_layout_base.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function cr_layout_base_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pod_media|fieldable_panels_pane|text_media|basic_pod';
  $field_group->group_name = 'group_pod_media';
  $field_group->entity_type = 'fieldable_panels_pane';
  $field_group->bundle = 'text_media';
  $field_group->mode = 'basic_pod';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Media wrapper',
    'weight' => '1',
    'children' => array(
      0 => 'field_image',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Media wrapper',
      'instance_settings' => array(
        'classes' => 'pod-media',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_pod_media|fieldable_panels_pane|text_media|basic_pod'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pod_media|fieldable_panels_pane|text_media|basic_pod_reverse';
  $field_group->group_name = 'group_pod_media';
  $field_group->entity_type = 'fieldable_panels_pane';
  $field_group->bundle = 'text_media';
  $field_group->mode = 'basic_pod_reverse';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Media wrapper',
    'weight' => '5',
    'children' => array(
      0 => 'field_image',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Media wrapper',
      'instance_settings' => array(
        'classes' => 'pod-media',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_pod_media|fieldable_panels_pane|text_media|basic_pod_reverse'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pod_text|fieldable_panels_pane|text_media|basic_pod';
  $field_group->group_name = 'group_pod_text';
  $field_group->entity_type = 'fieldable_panels_pane';
  $field_group->bundle = 'text_media';
  $field_group->mode = 'basic_pod';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Text wrapper',
    'weight' => '0',
    'children' => array(
      0 => 'field_custom_body',
      1 => 'title_field',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Text wrapper',
      'instance_settings' => array(
        'classes' => 'pod-text',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_pod_text|fieldable_panels_pane|text_media|basic_pod'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pod_text|fieldable_panels_pane|text_media|basic_pod_reverse';
  $field_group->group_name = 'group_pod_text';
  $field_group->entity_type = 'fieldable_panels_pane';
  $field_group->bundle = 'text_media';
  $field_group->mode = 'basic_pod_reverse';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Text wrapper',
    'weight' => '8',
    'children' => array(
      0 => 'field_custom_body',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Text wrapper',
      'instance_settings' => array(
        'classes' => 'pod-text',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_pod_text|fieldable_panels_pane|text_media|basic_pod_reverse'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pod_text|fieldable_panels_pane|text|basic_pod';
  $field_group->group_name = 'group_pod_text';
  $field_group->entity_type = 'fieldable_panels_pane';
  $field_group->bundle = 'text';
  $field_group->mode = 'basic_pod';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Text wrapper',
    'weight' => '0',
    'children' => array(
      0 => 'field_body',
      1 => 'title_field',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Text wrapper',
      'instance_settings' => array(
        'classes' => 'pod-text',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_pod_text|fieldable_panels_pane|text|basic_pod'] = $field_group;

  return $export;
}
