<?php
/**
 * @file
 * downloadable.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function downloadable_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'downloadable-downloadable-field_body'
  $field_instances['downloadable-downloadable-field_body'] = array(
    'bundle' => 'downloadable',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'downloadable',
    'field_name' => 'field_body',
    'label' => 'Description',
    'required' => 0,
    'settings' => array(
      'exclude_cv' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'downloadable-downloadable-field_dl_title'
  $field_instances['downloadable-downloadable-field_dl_title'] = array(
    'bundle' => 'downloadable',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'If entered, the Downloadable name will not be output as the title, this will be.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
      'list_view' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
      'search_result' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'downloadable',
    'exclude_cv' => 1,
    'field_name' => 'field_dl_title',
    'label' => 'Title override',
    'required' => 0,
    'settings' => array(
      'exclude_cv' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'downloadable-downloadable-field_dl_type'
  $field_instances['downloadable-downloadable-field_dl_type'] = array(
    'bundle' => 'downloadable',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'downloadable',
    'field_name' => 'field_dl_type',
    'label' => 'Downloadable Category',
    'required' => 0,
    'settings' => array(
      'exclude_cv' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 0,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Description');
  t('Downloadable Category');
  t('If entered, the Downloadable name will not be output as the title, this will be.');
  t('Title override');

  return $field_instances;
}
