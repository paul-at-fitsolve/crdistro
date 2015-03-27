<?php
/**
 * @file
 * Listing bean plugin.
 */

class CrShareBean extends BeanPlugin {
  /**
   * Declares default block settings.
   */
  public function values() {
    $default_app_id = variable_get('cr_fb_share_appId', '');
    $values = array(
      'settings' => array(
        'cr_share_links_body' => array(
          'value' => _default_sharelinks_markup()
        ),
        'cr_share_facebook_id' => $default_app_id,
        'cr_share_event' => 'hover',
        'cr_share_touch_activate_in_view' => false,
      ),
    );
    return array_merge(parent::values(), $values);
  }
  /**
   * Builds extra settings for the block edit form.
   */
  public function form($bean, $form, &$form_state) {
    $form = array();
    $form['settings'] = array(
      '#type' => 'fieldset',
      '#tree' => 1,
      '#title' => t('Share Links'),
    );

    $default_values = $this->values();

    // All we need to provide is the specific configuration options for our
    // block. Drupal will take care of the standard block configuration options
    // (block title, page visibility, etc.) and the save button.
    $form['settings']['cr_share_links_body'] = array(
      '#type' => 'text_format',
      '#format' => 'full_html',
      '#title' => t('Share Links Markup'),
      '#size' => 60,
      '#description' => t('Widgets are activated on hover or click.'),
      '#default_value' => $bean->settings['cr_share_links_body']['value'],
    );

    $form['settings']['cr_share_facebook_id'] = array(
      '#type' => 'textfield',
      '#title' => t('The Facebook App ID'),
      '#size' => 60,
      '#description' => t('If CR_FB_SHARE_APP_ID_DEFAULT is set, will default to this.'),
      '#default_value' => $bean->settings['cr_share_facebook_id'],
    );

    $form['settings']['cr_share_event'] = array(
      '#type' => 'select',
      '#title' => t('Selected'),
      '#options' => array(
        'click' => t('Click'),
        'mouseenter' => t('Hover'),
      ),
      '#default_value' => $bean->settings['cr_share_event'],
      '#description' => t('Activate widgets on click or hover.'),
    );

    $form['settings']['cr_share_touch_activate_in_view'] = array(
      '#type' => 'checkbox',
      '#title' => t('Activate Widgets when Visible on Touch Devices'),
      '#description' => t('Useful for footer share links and prevents the need to tap to load the widgets. Once in plain sight the widgets will be automatically loaded.'),
      '#default_value' => $bean->settings['cr_share_touch_activate_in_view'],
    );


    return $form;
  }

  /**
   * Displays the bean.
   */
  public function view($bean, $content, $view_mode = 'default', $langcode = NULL) {
    $default_values = $this->values();

    $basepath = drupal_get_path('module', 'cr_share');
    $socialite_path = _cr_share_load_socialite();

    // Create block
    $block['#theme'] = 'cr_share_links';

    // Requirement to have socialite library
    if(!$socialite_path) {
      drupal_set_message(t('Please add socialite.js to your libraries.'), 'warning');
    } else {
      // Settings
      $block['#js_settings'] = array();
      $fb_app_id = $bean->settings['cr_share_facebook_id'];
      $block['#js_settings'] = array();

      if($fb_app_id) {
        $block['#js_settings'] = array(
          'mouseEvent' => $bean->settings['cr_share_event'],
          'touch_activate_in_view' => $bean->settings['cr_share_touch_activate_in_view'],
          'socialitejsConfig' => array(
            'facebook' => array(
              'lang' => 'en_GB',
              'appId' => $bean->settings['cr_share_facebook_id']
            )
          )
        );
      };

      $content_html = $bean->settings['cr_share_links_body'];
      $block['#body'] = check_markup($content_html['value'], 'full_html', '', true);
      
    }

    // Use the bean title for our block
    $block['#title'] = $bean->title;
    $bean->label = '';
    $bean->title = '';

    return $block;
  }
}

/**
 * Helper function for the default sharelinks markup
 */
function _default_sharelinks_markup() {
  return '<ul class="socialitejs">
  <li class="socialite-item first">
    <a href="http://www.facebook.com/sharer.php?u=[current-page:url]&p[summary]=[cr_share:summary]" class="socialite facebook-share" data-href="[current-page:url]" data-width="60" data-show-faces="false" data-send="false" data-layout="button_count" data-type="button">Share on Facebook</a>&nbsp;</li>
  <li class="socialite-item"><a href="http://twitter.com/share?url=[current-page:url]" class="socialite twitter-share" data-text="Loads going on for @comicrelief. Take a look at comicrelief.com to get involved. " data-count="none">Twitter</a>&nbsp;</li>
  <li class="socialite-item last"><a href="https://plus.google.com/share?url=[current-page:url]" class="socialite googleplus-one" data-href="[current-page:url]" data-size="medium" data-annotation="none">Google+</a>&nbsp;</li>
</ul>';
}