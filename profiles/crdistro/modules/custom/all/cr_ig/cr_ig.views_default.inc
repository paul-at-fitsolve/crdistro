<?php
function cr_ig_views_default_views() {

  /**
   * Hall of Fame view
   */
  $view = new view();
  $view->name = 'idea_generator_hall_of_fame';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'cr_ig_pledge';
  $view->human_name = 'Idea Generator Hall of Fame';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_json';
  $handler->display->display_options['style_options']['root_object'] = 'ig';
  $handler->display->display_options['style_options']['top_child_object'] = 'pledge';
  $handler->display->display_options['style_options']['field_output'] = 'raw';
  $handler->display->display_options['style_options']['plaintext_output'] = 1;
  $handler->display->display_options['style_options']['remove_newlines'] = 1;
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 0;
  $handler->display->display_options['style_options']['object_arrays'] = 0;
  $handler->display->display_options['style_options']['numeric_strings'] = 0;
  $handler->display->display_options['style_options']['bigint_string'] = 0;
  $handler->display->display_options['style_options']['pretty_print'] = 0;
  $handler->display->display_options['style_options']['unescaped_slashes'] = 0;
  $handler->display->display_options['style_options']['unescaped_unicode'] = 0;
  $handler->display->display_options['style_options']['char_encoding'] = array();
  /* Field: Idea Generator Pledge: Age */
  $handler->display->display_options['fields']['age']['id'] = 'age';
  $handler->display->display_options['fields']['age']['table'] = 'cr_ig_pledge';
  $handler->display->display_options['fields']['age']['field'] = 'age';
  $handler->display->display_options['fields']['age']['label'] = '';
  $handler->display->display_options['fields']['age']['element_label_colon'] = FALSE;
  /* Field: Idea Generator Pledge: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'cr_ig_pledge';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Sort criterion: Idea Generator Pledge: Idea generator pledge ID */
  $handler->display->display_options['sorts']['id']['id'] = 'id';
  $handler->display->display_options['sorts']['id']['table'] = 'cr_ig_pledge';
  $handler->display->display_options['sorts']['id']['field'] = 'id';
  $handler->display->display_options['sorts']['id']['order'] = 'DESC';
  /* Contextual filter: Idea Generator Pledge: Name */
  $handler->display->display_options['arguments']['name']['id'] = 'name';
  $handler->display->display_options['arguments']['name']['table'] = 'cr_ig_pledge';
  $handler->display->display_options['arguments']['name']['field'] = 'name';
  $handler->display->display_options['arguments']['name']['default_action'] = 'default';
  $handler->display->display_options['arguments']['name']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['name']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['name']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['name']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['name']['limit'] = '0';
  /* Contextual filter: Idea Generator Pledge: Age */
  $handler->display->display_options['arguments']['age']['id'] = 'age';
  $handler->display->display_options['arguments']['age']['table'] = 'cr_ig_pledge';
  $handler->display->display_options['arguments']['age']['field'] = 'age';
  $handler->display->display_options['arguments']['age']['default_action'] = 'default';
  $handler->display->display_options['arguments']['age']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['age']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['age']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['age']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Idea Generator Pledge: Validated */
  $handler->display->display_options['filters']['validated']['id'] = 'validated';
  $handler->display->display_options['filters']['validated']['table'] = 'cr_ig_pledge';
  $handler->display->display_options['filters']['validated']['field'] = 'validated';
  $handler->display->display_options['filters']['validated']['value']['value'] = '1';

  /* Display: Search */
  $handler = $view->new_display('page', 'Search', 'hof_search');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Idea Generator Pledge: Name */
  $handler->display->display_options['arguments']['name']['id'] = 'name';
  $handler->display->display_options['arguments']['name']['table'] = 'cr_ig_pledge';
  $handler->display->display_options['arguments']['name']['field'] = 'name';
  $handler->display->display_options['arguments']['name']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['name']['default_argument_options']['argument'] = '{\'ig\':[{\'error\'}]}';
  $handler->display->display_options['arguments']['name']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['name']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['name']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['name']['limit'] = '0';
  /* Contextual filter: Idea Generator Pledge: Age */
  $handler->display->display_options['arguments']['age']['id'] = 'age';
  $handler->display->display_options['arguments']['age']['table'] = 'cr_ig_pledge';
  $handler->display->display_options['arguments']['age']['field'] = 'age';
  $handler->display->display_options['arguments']['age']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['age']['default_argument_options']['argument'] = '{\'ig\':[{\'error\'}]}';
  $handler->display->display_options['arguments']['age']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['age']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['age']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['path'] = 'fun-and-games/hall-of-fame/search';

  $views[$view->name] = $view;

  /**
   * Admin view for idea generator
   */
  $view = new view();
  $view->name = 'idea_generator_admin';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'cr_ig_pledge';
  $view->human_name = 'Idea Generator Admin';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Idea Generator Pledge: Idea generator pledge ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'cr_ig_pledge';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['label'] = '';
  $handler->display->display_options['fields']['id']['element_label_colon'] = FALSE;
  /* Field: Idea Generator Pledge: Age */
  $handler->display->display_options['fields']['age']['id'] = 'age';
  $handler->display->display_options['fields']['age']['table'] = 'cr_ig_pledge';
  $handler->display->display_options['fields']['age']['field'] = 'age';
  $handler->display->display_options['fields']['age']['label'] = '';
  $handler->display->display_options['fields']['age']['element_label_colon'] = FALSE;
  /* Field: Idea Generator Pledge: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'cr_ig_pledge';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Idea Generator Pledge: Pledge */
  $handler->display->display_options['fields']['pledge']['id'] = 'pledge';
  $handler->display->display_options['fields']['pledge']['table'] = 'cr_ig_pledge';
  $handler->display->display_options['fields']['pledge']['field'] = 'pledge';
  $handler->display->display_options['fields']['pledge']['label'] = '';
  $handler->display->display_options['fields']['pledge']['element_label_colon'] = FALSE;
  /* Field: Idea Generator Pledge: Validated */
  $handler->display->display_options['fields']['validated']['id'] = 'validated';
  $handler->display->display_options['fields']['validated']['table'] = 'cr_ig_pledge';
  $handler->display->display_options['fields']['validated']['field'] = 'validated';
  $handler->display->display_options['fields']['validated']['label'] = '';
  $handler->display->display_options['fields']['validated']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['validated']['element_default_classes'] = FALSE;

  $views[$view->name] = $view;

  return $views;
}
