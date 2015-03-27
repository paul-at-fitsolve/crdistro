<?php
/**
 * @file
 * .admin.inc file for cr_invalidate_varnish module
 *
 * All functions apart form hook implementations are in this file and are only
 * loaded when a path specific to this module is requested
 *
 * Author: Graham Utton
 */

/**
 * Configuration form for varnish invalidation functionality
 *
 * Used to set:
 *   # service endpoint and whether it is stubbed
 *   # schedule window duration and limit
 *   # schedule buffer time for spreading out requests
 *
 * @param array $form
 *  The config form
 * @param $form_state
 *  The config form_state
 * @return array
 *  The config form
 */
function cr_invalidate_varnish_config_form($form, &$form_state) {
  $form = array();
  $form['cr_invalidate_varnish_service_endpoint'] = array(
    '#type' => 'textfield',
    '#title' => t('Service endpoint'),
    '#description' => t('The endpoint to which we send varnish invalidation requests'),
    '#default_value' => variable_get('cr_invalidate_varnish_service_endpoint', 'http://localhost'),
  );

  $form['cr_invalidate_varnish_window_duration'] = array(
    '#type' => 'textfield',
    '#title' => t('Schedule window duration'),
    '#description' => t(
      'The duration in which a certain number of invalidations can be requested'),
    '#default_value' => variable_get('cr_invalidate_varnish_window_duration', 300),
  );

  $form['cr_invalidate_varnish_window_limit'] = array(
    '#type' => 'textfield',
    '#title' => t('Invalidation limit per schedule window'),
    '#description' => t(
      'The number of invalidations that can be requested per schedule window'),
    '#default_value' => variable_get('cr_invalidate_varnish_window_limit', 5),
  );

  $form['cr_invalidate_varnish_schedule_buffer_duration'] = array(
    '#type' => 'textfield',
    '#title' => t('Buffer duration between invalidations'),
    '#description' => t(
      'A minimum number of seconds between invalidations, to space them out'),
    '#default_value' => variable_get('cr_invalidate_varnish_schedule_buffer_duration', 20),
  );

  $form['cr_invalidate_varnish_stub_service'] = array(
    '#type' => 'checkbox',
    '#title' => t('Stub the invalidation service?'),
    '#description' => t(
      'For testing scheduling / other functionality, don\'t make requests, but return TRUE'),
    '#default_value' => variable_get('cr_invalidate_varnish_stub_service', 0),
  );

  return system_settings_form($form);
}

/**
 * Validation handler for config form

 * @param array $form
 *  The config form
 * @param $form_state
 *  The config form_state
 * @return array
 *  The config form
 */
function cr_invalidate_varnish_config_form_validate(&$form, $form_state) {
  $values = $form_state['values'];

  // To aid readability, defining long form keys as short vars
  $endpoint_key = 'cr_invalidate_varnish_service_endpoint';
  $window_duration_key = 'cr_invalidate_varnish_window_duration';
  $window_limit_key = 'cr_invalidate_varnish_window_limit';
  $buffer_duration_key = 'cr_invalidate_varnish_schedule_buffer_duration';

  // Found some strange behaviour in PHP's FILTER_VALIDATE_URL filter
  // When used with filter_var_array: FILTER_VALIDATE_URL requires the protocol
  // to be present in order for a url to be valid
  // But when used with filter_var: FILTER_VALIDATE_URL requires the protocol
  // to be absent in order for a url to be valid
  // Since our endpoint may use http:// or https:// we need to use filter_var_array
  if (filter_var_array(
      array($values[$endpoint_key]), FILTER_VALIDATE_URL)[0] === FALSE) {
    form_set_error(
      $endpoint_key, t(
        'Service endpoint is not a valid url. Did you include a protocol? eg http://'
      )
    );
  }

  if (!ctype_digit($values[$window_duration_key])) {
    form_set_error($window_duration_key, t('Window duration is not an integer'));
  }

  if (!ctype_digit($values[$window_limit_key])) {
    form_set_error($window_limit_key, t('Window limit is not an integer'));
  }

  if (!ctype_digit($values[$buffer_duration_key])) {
    form_set_error($buffer_duration_key, t('Buffer duration is not an integer'));
  }
}
