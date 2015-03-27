<?php

/**
 * @file
 * Provide email signup blocks to Panels.
 */

$plugin = array(
  'title' => t('Email signup'),
);

/**
 * Return all ESU subtypes available.
 */
function cr_marketing_prefs_esu_content_type_content_types() {
  $types['pod'] = array(
    'title' => t('Pod'),
    'category' => t('Email signup'),
    'add form' => 'cr_marketing_prefs_esu_content_type_edit_pod_form',
    'edit form' => 'cr_marketing_prefs_esu_content_type_edit_pod_form',
  );
  $types['promo'] = array(
    'title' => t('Promo banner'),
    'category' => t('Email signup'),
    'add form' => 'cr_marketing_prefs_esu_content_type_edit_promo_form',
    'edit form' => 'cr_marketing_prefs_esu_content_type_edit_promo_form',
  );
  return $types;
}

/**
 * General configuration form.
 */
function cr_marketing_prefs_esu_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['source'] = array(
    '#type' => 'textfield',
    '#title' => t('Source'),
    '#description' => t('This will be recorded as the source in cr_core.'),
    '#default_value' => isset($conf['source']) ? $conf['source'] : '',
    '#maxlength' => 30,
    '#required' => TRUE,
  );
  $form['source_mobile'] = array(
    '#type' => 'textfield',
    '#title' => t('Source (mobile'),
    '#default_value' => isset($conf['source_mobile']) ? $conf['source_mobile'] : '',
    '#maxlength' => 30,
    '#required' => TRUE,
  );

  return $form;
}

/**
 * Submit callback for promo configuration form.
 */
function cr_marketing_prefs_esu_content_type_edit_form_submit($form, &$form_state) {
  $form_state['conf']['source'] = $form_state['values']['source'];
  $form_state['conf']['source_mobile'] = $form_state['values']['source_mobile'];
}

/**
 * Pod configuration form.
 */
function cr_marketing_prefs_esu_content_type_edit_pod_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['teacher'] = array(
    '#type' => 'radios',
    '#title' => t('Teacher selection'),
    '#options' => array(
      'never' => 'Never',
      'checkbox' => 'Checkbox',
      'always' => 'Always',
    ),
    '#default_value' => isset($conf['teacher']) ? $conf['teacher'] : '',
  );

  // Add source setting.
  $form = cr_marketing_prefs_esu_content_type_edit_form($form, $form_state);

  return $form;
}

/**
 * Submit callback for promo configuration form.
 */
function cr_marketing_prefs_esu_content_type_edit_pod_form_submit($form, &$form_state) {
  foreach (array('teacher') as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }

  // Save source setting.
  cr_marketing_prefs_esu_content_type_edit_form_submit($form, $form_state);
}

/**
 * Promo configuration form.
 */
function cr_marketing_prefs_esu_content_type_edit_promo_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['intro_copy'] = array(
    '#type' => 'textarea',
    '#title' => t('Intro copy'),
    '#default_value' => isset($conf['intro_copy']) ? $conf['intro_copy'] : '',
  );
  $form['teacher_copy'] = array(
    '#type' => 'textarea',
    '#title' => t('Teacher copy'),
    '#default_value' => isset($conf['teacher_copy']) ? $conf['teacher_copy'] : '',
  );

  $form['teacher_select_title'] = array(
    '#type' => 'textarea',
    '#title' => t('Teacher select box title'),
    '#default_value' => isset($conf['teacher_select_title']) ? $conf['teacher_select_title'] : '',
  );

  $form['thankyou_copy'] = array(
    '#type' => 'textarea',
    '#title' => t('Thankyou copy'),
    '#default_value' => isset($conf['thankyou_copy']) ? $conf['thankyou_copy'] : '',
  );

  // Add source setting.
  $form = cr_marketing_prefs_esu_content_type_edit_form($form, $form_state);

  return $form;
}

/**
 * Submit callback for promo configuration form.
 */
function cr_marketing_prefs_esu_content_type_edit_promo_form_submit($form, &$form_state) {
  foreach (array('intro_copy', 'teacher_copy', 'teacher_select_title', 'thankyou_copy') as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }

  // Save source setting.
  cr_marketing_prefs_esu_content_type_edit_form_submit($form, $form_state);
}

/**
 * Output function for the 'esu' content type.
 */
function cr_marketing_prefs_esu_content_type_render($subtype, $conf) {
  $block = new stdClass();
  switch ($subtype) {
    case 'pod':
      $block->content = drupal_get_form('cr_marketing_prefs_signup_form', $conf);
      break;

    case 'promo':
      $block->content = drupal_get_form('cr_marketing_prefs_promo_form', $conf);
      break;
  }
  return $block;
}
