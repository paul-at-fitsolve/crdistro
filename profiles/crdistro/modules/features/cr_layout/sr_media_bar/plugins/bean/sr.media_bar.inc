<?php
/**
 * @file
 * Listing bean plugin.
 */

class MediabarBean extends BeanPlugin {
  /**
   * Declares default block settings.
   */
  public function values() {
    $values = array(
      'settings' => array(
        'view_source_id' => 'media_bar',
        'view_display' => 'default',
        'taxonomy_vocab_machine_name' => 'media_bar_section',
        'twitter_vocab_machine_name' => 'twitter_tags'
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
      '#title' => t('Media Bar Settings'),
    );

    $default_values = $this->values();

    // Get the view
    $view = views_get_view($default_values['settings']['view_source_id']);

    // Get the displays
    $display_options = array();
    foreach($view->display as $machine_name => $display) {
      $display_options[$machine_name] = $display->display_title;
    }

    $form['settings']['view_display'] = array(
      '#type' => 'select',
      '#title' => t('View Display'),
      '#options' => $display_options,
      '#default_value' => isset($bean->settings['view_display']) ? $bean->settings['view_display'] : $default_values['settings']['view_display'],
      '#required' => TRUE,
      '#multiple' => FALSE,
    );

    // Get the term filters
    $vocab = taxonomy_vocabulary_machine_name_load($default_values['settings']['taxonomy_vocab_machine_name']);
    $terms = taxonomy_get_tree($vocab->vid, 0, 2, FALSE);
    $term_options = array();
    foreach($terms as $term) {
      if($term->depth > 0) {
        $term_options[$term->tid] = '--' . $term->name;
        continue;
      }
      $term_options[$term->tid] = $term->name;
    }

    $form['settings']['terms'] = array(
      '#type' => 'select',
      '#title' => t('Filter Terms'),
      '#size'=> 3,
      '#options' => $term_options,
      '#default_value' => isset($bean->settings['terms']) ? $bean->settings['terms'] : '',
      '#multiple' => TRUE,
      '#description' => t('Uses <a href="/admin/structure/taxonomy/media_bar_section">Media Bar Section</a>')
    );

    return $form;
  }

  /**
   * Displays the bean.
   */
  public function view($bean, $content, $view_mode = 'default', $langcode = NULL) {
    // We need iScroll and Scrollto
    drupal_add_js(path_to_theme().'/javascripts/vendor/iscroll.js');
    drupal_add_js(path_to_theme().'/javascripts/vendor/scrollTo.js');
    drupal_add_js(drupal_get_path('module', 'sr_media_bar').'/sr_media_bar.js');

    $default_values = $this->values();
    $view_arguments = null;
    if(is_array($bean->settings['terms']) && !empty($bean->settings['terms'])) {
      $view_arguments = implode ('+', $bean->settings['terms']);
    }
    $content = array(
      '#prefix' => '<div class="media-bar media-bar--type-media">',
      '#suffix' => '</div>',
    );
    $content['title'] = array(
      '#type' => 'markup',
      '#markup' => t('<h2 class="media-bar__header">@title</h2>', array('@title' => $bean->title)),
    );
    $content['view'] = array(
      '#type' => 'markup',
      '#markup' => views_embed_view($default_values['settings']['view_source_id'], $bean->settings['view_display'], $view_arguments),
    );
    return $content;
  }
}
/**
 * Displays the bean.
 */
class TwitterMediabarBean extends MediabarBean {
   /**
   * Builds extra settings for the block edit form.
   */
  public function form($bean, $form, &$form_state) {
    $form = array();
    $form['settings'] = array(
      '#type' => 'fieldset',
      '#tree' => 1,
      '#title' => t('Media Bar Settings'),
    );

    $default_values = $this->values();

    // Get the view
    $view = views_get_view($default_values['settings']['view_source_id']);

    // Get the displays
    $display_options = array();
    foreach($view->display as $machine_name => $display) {
      $display_options[$machine_name] = $display->display_title;
    }

    $form['settings']['view_display'] = array(
      '#type' => 'select',
      '#title' => t('View Display'),
      '#options' => $display_options,
      '#default_value' => isset($bean->settings['view_display']) ? $bean->settings['view_display'] : $default_values['settings']['view_display'],
      '#multiple' => FALSE,
    );

    // Get the term filters
    $vocab = taxonomy_vocabulary_machine_name_load($default_values['settings']['twitter_vocab_machine_name']);
    $terms = taxonomy_get_tree($vocab->vid, 0, 2, FALSE);
    $term_options = array();
    foreach($terms as $term) {
      if($term->depth > 0) {
        $term_options[$term->tid] = '--' . $term->name;
        continue;
      }
      $term_options[$term->tid] = $term->name;
    }

    $form['settings']['terms'] = array(
      '#type' => 'select',
      '#title' => t('Filter Terms'),
      '#size'=> 3,
      '#options' => $term_options,
      '#default_value' => isset($bean->settings['terms']) ? $bean->settings['terms'] : '',
      '#multiple' => TRUE,
      '#description' => t('Uses <a href="/admin/structure/taxonomy/twitter_tags">Twitter Tags</a>')
    );

    return $form;
  }

  /**
   * Displays the bean.
   */
  public function view($bean, $content, $view_mode = 'default', $langcode = NULL) {
    // We need iScroll and Scrollto
    drupal_add_js(path_to_theme().'/javascripts/vendor/iscroll.js');
    drupal_add_js(path_to_theme().'/javascripts/vendor/scrollTo.js');
    drupal_add_js(drupal_get_path('module', 'sr_media_bar').'/sr_media_bar.js');

    $default_values = $this->values();
    $view_arguments = null;
    if(is_array($bean->settings['terms']) && !empty($bean->settings['terms'])) {
      $view_arguments = implode ('+', $bean->settings['terms']);
    }
    $content = array(
      '#prefix' => '<div class="media-bar media-bar--type-twitter">',
      '#suffix' => '</div>',
    );
    $content['title'] = array(
      '#type' => 'markup',
      '#markup' => t('<h2 class="media-bar__header media-bar__header--twitter">@title <span class="icon-twitter">&nbsp;</span></h2>', array('@title' => $bean->title)),
    );
    $content['view'] = array(
      '#type' => 'markup',
      '#markup' => views_embed_view($default_values['settings']['view_source_id'], $bean->settings['view_display'], $view_arguments),
    );
    return $content;
  }
   
 }