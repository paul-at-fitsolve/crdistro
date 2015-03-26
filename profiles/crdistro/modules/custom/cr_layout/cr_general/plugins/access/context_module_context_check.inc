<?php

/**
 * Define ctools access plugin context module context check
 */
$plugin = array(
  'title' => t('Context module context check'),
  'description' => 'Checks whether a context namespace/attribute is set to a specific value (via context_set)',
  'callback' => 'cr_general_context_value_ctools_access_check',
  'defaults' => array(
    'summary' => '',
    'context_namespace' => '',
    'context_attribute' => '',
    'context_value' => '',
    'empty_behaviour' => 'deny',
  ),
  'settings form' => 'cr_general_context_value_ctools_settings_form',
  'settings form submit' => 'cr_general_context_value_ctools_settings_form_submit',
  'summary' => 'cr_general_context_value_ctools_summary',
);

/**
 * Context module context check plugin's access callback
 */
function cr_general_context_value_ctools_access_check($conf, $context) {
  foreach (array_keys($conf) as $settings_field) {
    // if any settings are missing return FALSE as we don't have enough info to check
    if (empty($conf[$settings_field])) {
      return FALSE;
    }
  }

  $context_result = context_get($conf['context_namespace'], $conf['context_attribute']);

  // if the context being checked is unset then use the 'empty_behaviour' key to determine whether or not to allow access
  if ($context_result === FALSE) {
    return $conf['empty_behaviour'] === 'allow';
  }

  // if the context is as required then allow access
  if ($context_result == $conf['context_value']) {
    return TRUE;
  }

  return FALSE;
}

/**
 * Context module context check plugin's settings form
 */
function cr_general_context_value_ctools_settings_form($form, &$form_state, $conf) {
  // build form defaults either form previously entered values, or fall back to plugin defaults
  $defaults = array();
  foreach ($form_state['plugin']['defaults'] as $key => $plugin_default) {
    if (isset($conf[$key]) && !empty($conf[$key])) {
      $defaults[$key] = $conf[$key];
    }
    else {
      $defaults[$key] = $plugin_default;
    }
  }

  $form['settings'] = array(
    'summary' => array(
      '#type' => 'textfield',
      '#title' => 'Summary',
      '#description' => 'Optional summary for this condition, to replace the generated summary shown in panels UI',
      '#default_value' => $defaults['summary'],
    ),
    'context_namespace' => array(
      '#type' => 'textfield',
      '#title' => 'Namespace',
      '#description' => 'The $namespace parameter as passed to context_get($namespace, $attribute)',
      '#default_value' => $defaults['context_namespace'],
      '#required' => TRUE,
    ),
    'context_attribute' => array(
      '#type' => 'textfield',
      '#title' => 'attribute',
      '#description' => 'The $attribute parameter as passed to context_get($namespace, $attribute)',
      '#default_value' => $defaults['context_attribute'],
      '#required' => TRUE,
    ),
    'context_value' => array(
      '#type' => 'textfield',
      '#title' => 'Value to check for',
      '#description' => 'The value to check for, as returned by context_get($namespace, $attribute)',
      '#default_value' => $defaults['context_value'],
      '#required' => TRUE,
    ),
    'empty_behaviour' => array(
      '#type' => 'radios',
      '#options'  => array(
        'deny' => 'Deny Access',
        'allow' => 'Allow Access',
      ),
      '#title' => 'Behaviour if context not set?',
      '#description' => 'If this requested context is not set, what should happen?',
      '#default_value' => $defaults['empty_behaviour'],
    ),
  );

  return $form;
}

/**
 * Context module context check plugin's settings form submit handler
 */
function cr_general_context_value_ctools_settings_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['values']['settings'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Context module context check plugin's summary callback
 */
function cr_general_context_value_ctools_summary($conf, $context) {
  if (!empty($conf['summary'])) {
    return $conf['summary'];
  }

  $replacements = array(
    '!namespace' => $conf['context_namespace'],
    '!attribute' => $conf['context_attribute'],
    '!value' => $conf['context_value'],
  );
  return t('Context with namespace !namespace and attribute !attribute set to: !value', $replacements);
}
