<?php
function cr_hs_views_default_views() {

  $view = new view;
  $view->name = 'high_scores_admin';
  $view->description = 'Provides JSON list for use in the admin view of the high scores table';
  $view->tag = 'default';
  $view->base_table = 'cr_hs_scores';
  $view->human_name = 'High Scores Admin';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Field: High Scores Entry: High scores entry ID */
  $handler->display->display_options['fields']['id_1']['id'] = 'id_1';
  $handler->display->display_options['fields']['id_1']['table'] = 'cr_hs_scores';
  $handler->display->display_options['fields']['id_1']['field'] = 'id';
  $handler->display->display_options['fields']['id_1']['label'] = '';
  $handler->display->display_options['fields']['id_1']['element_label_colon'] = FALSE;
  /* Field: High Scores Entry: Published */
  $handler->display->display_options['fields']['published']['id'] = 'published';
  $handler->display->display_options['fields']['published']['table'] = 'cr_hs_scores';
  $handler->display->display_options['fields']['published']['field'] = 'published';
  $handler->display->display_options['fields']['published']['label'] = '';
  $handler->display->display_options['fields']['published']['element_label_colon'] = FALSE;
  /* Field: High Scores Entry: Score */
  $handler->display->display_options['fields']['score']['id'] = 'score';
  $handler->display->display_options['fields']['score']['table'] = 'cr_hs_scores';
  $handler->display->display_options['fields']['score']['field'] = 'score';
  $handler->display->display_options['fields']['score']['label'] = '';
  $handler->display->display_options['fields']['score']['element_label_colon'] = FALSE;
  /* Field: High Scores Entry: Username */
  $handler->display->display_options['fields']['username']['id'] = 'username';
  $handler->display->display_options['fields']['username']['table'] = 'cr_hs_scores';
  $handler->display->display_options['fields']['username']['field'] = 'username';
  $handler->display->display_options['fields']['username']['label'] = '';
  $handler->display->display_options['fields']['username']['element_label_colon'] = FALSE;
  /* Field: High Scores Entry: Gameid */
  $handler->display->display_options['fields']['gameid']['id'] = 'gameid';
  $handler->display->display_options['fields']['gameid']['table'] = 'cr_hs_scores';
  $handler->display->display_options['fields']['gameid']['field'] = 'gameid';
  $handler->display->display_options['fields']['gameid']['label'] = '';
  $handler->display->display_options['fields']['gameid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['gameid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['gameid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['gameid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['gameid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['gameid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['gameid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['gameid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['gameid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['gameid']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['gameid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['gameid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['gameid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['gameid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['gameid']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['gameid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['gameid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['gameid']['hide_alter_empty'] = 1;

  $views[$view->name] = $view;

  return $views;
}
