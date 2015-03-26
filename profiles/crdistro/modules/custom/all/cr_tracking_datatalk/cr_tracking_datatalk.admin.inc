<?php

/**
 * Site wide donation settings.
 */
function cr_tracking_datatalk_admin($form, $form_state) {
  global $base_url;
  $form['cr_tracking_datatalk_tracking_source'] = array(
    '#type' => 'textfield',
    '#title' => t('DataTalk Tracking Image'),
    '#description' => t('The URL to the tracking image. <a href="!confluence_docs" target="_blank">More information on DataTalk Tracking</a>.', array('!confluence_docs' => 'http://confluence.comicrelief.com/display/rnd15Documentation/DataTalk+Tracking')),
    '#default_value' => variable_get('cr_tracking_datatalk_tracking_source', CR_DATATALK_SOURCE),
  );
  return system_settings_form($form);
}