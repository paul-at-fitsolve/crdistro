<?php
/**
 * @file
 * Email signup bean plugin.
 */

class CrEmailSignupBean extends BeanPlugin {

  /**
   * Declares default block settings.
   */
  public static function defaults() {
    return array(
      // General settings.
      'action' => '',
      'source' => 'splash page',
      'source_mobile' => 'splash page mobile',

      'show_labels' => FALSE,
      'show_first_name' => FALSE,

      // Copy goes in a subarray.
      'copy' => array(
        'title' => 'Stay in the loop',
        'intro' => "Be the first to know about what we're up to, how you can get involved, the difference your money makes... plus loads of other juicy news.",
        'email_placeholder' => 'Enter your email',
        'list_teacher' => 'I am a teacher',
        'thank_you_title' => 'Thank you!',
        'thank_you' => 'Keep an eye out for your welcome email which should appear in your inbox soon.',
      ),

      // Redirects go in a subarray.
      'redirects' => array(
        'general' => 'email-sign-up/thankyou',
        'teacher' => 'email-sign-up/thankyou/teacher',
      ),
    );
  }

  /**
   * Declares default block settings.
   */
  public function values() {
    return array_merge(parent::values(), array('settings' => self::defaults()));
  }

  /**
   * Builds extra settings for the block edit form.
   */
  public function form($bean, $form, &$form_state) {
    $defaults = self::defaults();

    $form['settings'] = array(
      '#type' => 'fieldset',
      '#tree' => TRUE,
      '#title' => t('Settings'),
    );
    $form['settings']['action'] = array(
      '#type' => 'textfield',
      '#title' => t('Form action'),
      '#description' => t('Set this to e.g. /#tabs-4 if you need to force the submitted form to have a specific destination.'),
      '#default_value' => $bean->settings['action'],
    );
    $form['settings']['source'] = array(
      '#type' => 'textfield',
      '#title' => t('Source'),
      '#description' => t('This will be recorded as the source in cr_core.'),
      '#default_value' => $bean->settings['source'],
      '#maxlength' => 30,
    );
    $form['settings']['source_mobile'] = array(
      '#type' => 'textfield',
      '#title' => t('Source (mobile)'),
      '#description' => t('This will be recorded as the source in cr_core.'),
      '#default_value' => @$bean->settings['source_mobile'],
      '#maxlength' => 30,
    );

    $form['settings']['show_labels'] = array(
      '#type' => 'checkbox',
      '#title' => t('Show field labels and required fields help message'),
      '#default_value' => @$bean->settings['show_labels'],
    );
    $form['settings']['show_first_name'] = array(
      '#type' => 'checkbox',
      '#title' => t('Show first name field'),
      '#default_value' => @$bean->settings['show_first_name'],
    );

    $form['settings']['copy'] = array(
      '#type' => 'fieldset',
      '#title' => t('Copy'),
      '#description' => t('Leave a field blank to use the default.'),
    );
    $form['settings']['copy']['title'] = array(
      '#type' => 'textfield',
      '#title' => t('Pod title'),
    );
    $form['settings']['copy']['intro'] = array(
      '#type' => 'textarea',
      '#title' => t('Intro paragraph'),
    );
    $form['settings']['copy']['email_placeholder'] = array(
      '#type' => 'textfield',
      '#title' => t('E-mail address field placeholder'),
    );
    $form['settings']['copy']['list_teacher'] = array(
      '#type' => 'textfield',
      '#title' => t('Teacher list checkbox'),
    );
    $form['settings']['copy']['thank_you_title'] = array(
      '#type' => 'textfield',
      '#title' => t('Thank you title'),
    );
    $form['settings']['copy']['thank_you'] = array(
      '#type' => 'textarea',
      '#title' => t('Thank you paragraph'),
    );
    foreach (element_children($form['settings']['copy']) as $field) {
      $form['settings']['copy'][$field] += array(
        '#description' => 'Default: ' . $defaults['copy'][$field],
        '#default_value' => @$bean->settings['copy'][$field],
      );
    }

    $form['settings']['redirects'] = array(
      '#type' => 'fieldset',
      '#title' => t('Redirect on submit'),
      '#description' => t('Leave a field blank to not redirect; instead, the thank you copy set above will be displayed in place of the ESU form.'),
    );
    $form['settings']['redirects']['general'] = array(
      '#type' => 'textfield',
      '#title' => t('General signup'),
      '#field_prefix' => url('<front>', array('absolute' => TRUE)),
      '#default_value' => isset($bean->settings['redirects']['general']) ? $bean->settings['redirects']['general'] : $defaults['redirects']['general'],
    );
    $form['settings']['redirects']['teacher'] = array(
      '#type' => 'textfield',
      '#title' => t('Teacher signup'),
      '#field_prefix' => url('<front>', array('absolute' => TRUE)),
      '#default_value' => isset($bean->settings['redirects']['teacher']) ? $bean->settings['redirects']['teacher'] : $defaults['redirects']['teacher'],
    );

    return $form;
  }

  /**
   * Handles the bean being submitted.
   */
  public function submit(Bean $bean) {
    cache_clear_all();
  }

  /**
   * Displays the bean.
   */
  public function view($bean, $content, $view_mode = 'default', $langcode = NULL) {
    return drupal_get_form('cr_marketing_prefs_signup_form', $bean->settings);
  }

}


class CrOptionalInformationBean extends BeanPlugin {

  /**
   * Declares default block settings.
   */
  public static function defaults() {
    return array(
      // General settings.
      'source' => 'splash page',

      // Copy goes in a subarray.
      'copy' => array(
        'title' => 'Give us some more info',
        'intro' => "You don't have to fill in this next bit but, if you do, it'll help us make sure our emails are even more relevant and interesting to you.",
        'thank_you_title' => "You're a star!",
      ),
    );
  }

  /**
   * Declares default block settings.
   */
  public function values() {
    return array_merge(parent::values(), array('settings' => self::defaults()));
  }

  /**
   * Builds extra settings for the block edit form.
   */
  public function form($bean, $form, &$form_state) {
    $defaults = self::defaults();

    $form['settings'] = array(
      '#type' => 'fieldset',
      '#tree' => TRUE,
      '#title' => t('Settings'),
    );
    $form['settings']['source'] = array(
      '#type' => 'textfield',
      '#title' => t('Source'),
      '#description' => t('This will be recorded as the source in cr_core.'),
      '#default_value' => $bean->settings['source'],
    );

    $form['settings']['copy'] = array(
      '#type' => 'fieldset',
      '#title' => t('Copy'),
      '#description' => t('Leave a field blank to use the default.'),
    );
    $form['settings']['copy']['title'] = array(
      '#type' => 'textfield',
      '#title' => t('Pod title'),
    );
    $form['settings']['copy']['intro'] = array(
      '#type' => 'textarea',
      '#title' => t('Intro paragraph'),
    );
    $form['settings']['copy']['thank_you_title'] = array(
      '#type' => 'textfield',
      '#title' => t('Thank you title'),
    );
    foreach (element_children($form['settings']['copy']) as $field) {
      $form['settings']['copy'][$field] += array(
        '#description' => 'Default: ' . $defaults['copy'][$field],
        '#default_value' => @$bean->settings['copy'][$field],
      );
    }

    return $form;
  }

  /**
   * Handles the bean being submitted.
   */
  public function submit(Bean $bean) {
    cache_clear_all();
  }

  /**
   * Displays the bean.
   */
  public function view($bean, $content, $view_mode = 'default', $langcode = NULL) {
    return drupal_get_form('cr_marketing_prefs_optional_info_form', $bean->settings);
  }

}
