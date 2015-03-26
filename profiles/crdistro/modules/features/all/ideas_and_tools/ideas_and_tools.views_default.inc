<?php
/**
 * @file
 * ideas_and_tools.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ideas_and_tools_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'ideas_tips';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Ideas & Tips';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Ideas and tools';
  $handler->display->display_options['css_class'] = 'ideas_tips';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'item-column [field_fundraising_category_1] [field_fundraising_category_2]';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<div class="associated-tools-wrapper clearfix">
 <div class="associated-tools views-row"> 
  <div class="associated-items-first"> 
     <h2>Get tools</h2>
     <h3> for this idea</h3>
     <div class="fr-shares">
       <p><strong>Share this idea</strong></p>
       <div class="fr-share-widget"> 

       </div>
     </div>
   </div>
 </div>
</div>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  /* Field: Content: ID */
  $handler->display->display_options['fields']['field_fundraising_ideas_id']['id'] = 'field_fundraising_ideas_id';
  $handler->display->display_options['fields']['field_fundraising_ideas_id']['table'] = 'field_data_field_fundraising_ideas_id';
  $handler->display->display_options['fields']['field_fundraising_ideas_id']['field'] = 'field_fundraising_ideas_id';
  $handler->display->display_options['fields']['field_fundraising_ideas_id']['label'] = '';
  $handler->display->display_options['fields']['field_fundraising_ideas_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_fundraising_ideas_id']['alter']['text'] = '<span class="fr-gettools"></span>
<span class="fr-more" aria-hidden="true"></span>
<span class="fr-icons fr-icons--[field_fundraising_ideas_id-value]" aria-hidden="true"></span>
<span class="fr-arrow" aria-hidden="true"></span>';
  $handler->display->display_options['fields']['field_fundraising_ideas_id']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  $handler->display->display_options['fields']['title']['node_in_colorbox_width'] = '600';
  $handler->display->display_options['fields']['title']['node_in_colorbox_height'] = '600';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content: Fundraising Category 1 */
  $handler->display->display_options['fields']['field_fundraising_category_1']['id'] = 'field_fundraising_category_1';
  $handler->display->display_options['fields']['field_fundraising_category_1']['table'] = 'field_data_field_fundraising_category_1';
  $handler->display->display_options['fields']['field_fundraising_category_1']['field'] = 'field_fundraising_category_1';
  $handler->display->display_options['fields']['field_fundraising_category_1']['label'] = '';
  $handler->display->display_options['fields']['field_fundraising_category_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_fundraising_category_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_fundraising_category_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_fundraising_category_1']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Fundraising Category 2 */
  $handler->display->display_options['fields']['field_fundraising_category_2']['id'] = 'field_fundraising_category_2';
  $handler->display->display_options['fields']['field_fundraising_category_2']['table'] = 'field_data_field_fundraising_category_2';
  $handler->display->display_options['fields']['field_fundraising_category_2']['field'] = 'field_fundraising_category_2';
  $handler->display->display_options['fields']['field_fundraising_category_2']['label'] = '';
  $handler->display->display_options['fields']['field_fundraising_category_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_fundraising_category_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_fundraising_category_2']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_fundraising_category_2']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_fundraising_category_2']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_fundraising_category_2']['delta_offset'] = '0';
  /* Field: Content: Associated Downloads */
  $handler->display->display_options['fields']['field_associated_downloads']['id'] = 'field_associated_downloads';
  $handler->display->display_options['fields']['field_associated_downloads']['table'] = 'field_data_field_associated_downloads';
  $handler->display->display_options['fields']['field_associated_downloads']['field'] = 'field_associated_downloads';
  $handler->display->display_options['fields']['field_associated_downloads']['label'] = '';
  $handler->display->display_options['fields']['field_associated_downloads']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_associated_downloads']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_associated_downloads']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_associated_downloads']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_associated_downloads']['separator'] = ';';
  /* Sort criterion: Content: Fundraising Category 1 (field_fundraising_category_1) */
  $handler->display->display_options['sorts']['field_fundraising_category_1_tid']['id'] = 'field_fundraising_category_1_tid';
  $handler->display->display_options['sorts']['field_fundraising_category_1_tid']['table'] = 'field_data_field_fundraising_category_1';
  $handler->display->display_options['sorts']['field_fundraising_category_1_tid']['field'] = 'field_fundraising_category_1_tid';
  /* Sort criterion: Content: Fundraising Category 2 (field_fundraising_category_2) */
  $handler->display->display_options['sorts']['field_fundraising_category_2_tid']['id'] = 'field_fundraising_category_2_tid';
  $handler->display->display_options['sorts']['field_fundraising_category_2_tid']['table'] = 'field_data_field_fundraising_category_2';
  $handler->display->display_options['sorts']['field_fundraising_category_2_tid']['field'] = 'field_fundraising_category_2_tid';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'fundraising_ideas' => 'fundraising_ideas',
  );

  /* Display: All */
  $handler = $view->new_display('block', 'All', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $export['ideas_tips'] = $view;

  $view = new view();
  $view->name = 'tools';
  $view->description = 'All outputs of downloadables go here';
  $view->tag = 'default';
  $view->base_table = 'downloadable';
  $view->human_name = 'Tools';
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
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'responsive_grid';
  $handler->display->display_options['style_options']['columns'] = '6';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Field: Downloadable: Internal, numeric downloadable ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'downloadable';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['label'] = '';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['id']['element_default_classes'] = FALSE;
  /* Field: Downloadable: Icon_upload */
  $handler->display->display_options['fields']['icon_upload']['id'] = 'icon_upload';
  $handler->display->display_options['fields']['icon_upload']['table'] = 'downloadable';
  $handler->display->display_options['fields']['icon_upload']['field'] = 'icon_upload';
  $handler->display->display_options['fields']['icon_upload']['label'] = '';
  $handler->display->display_options['fields']['icon_upload']['exclude'] = TRUE;
  $handler->display->display_options['fields']['icon_upload']['element_label_colon'] = FALSE;
  /* Field: Downloadable: Url */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'downloadable';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['label'] = '';
  $handler->display->display_options['fields']['url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['url']['element_label_colon'] = FALSE;
  /* Field: Downloadable: File_upload */
  $handler->display->display_options['fields']['file_upload']['id'] = 'file_upload';
  $handler->display->display_options['fields']['file_upload']['table'] = 'downloadable';
  $handler->display->display_options['fields']['file_upload']['field'] = 'file_upload';
  $handler->display->display_options['fields']['file_upload']['label'] = '';
  $handler->display->display_options['fields']['file_upload']['exclude'] = TRUE;
  $handler->display->display_options['fields']['file_upload']['element_label_colon'] = FALSE;
  /* Field: Downloadable: Label */
  $handler->display->display_options['fields']['label']['id'] = 'label';
  $handler->display->display_options['fields']['label']['table'] = 'downloadable';
  $handler->display->display_options['fields']['label']['field'] = 'label';
  $handler->display->display_options['fields']['label']['label'] = '';
  $handler->display->display_options['fields']['label']['exclude'] = TRUE;
  $handler->display->display_options['fields']['label']['element_label_colon'] = FALSE;
  /* Field: Downloadable: Cta */
  $handler->display->display_options['fields']['cta']['id'] = 'cta';
  $handler->display->display_options['fields']['cta']['table'] = 'downloadable';
  $handler->display->display_options['fields']['cta']['field'] = 'cta';
  $handler->display->display_options['fields']['cta']['label'] = '';
  $handler->display->display_options['fields']['cta']['exclude'] = TRUE;
  $handler->display->display_options['fields']['cta']['element_label_colon'] = FALSE;
  /* Field: Field: Description */
  $handler->display->display_options['fields']['field_body']['id'] = 'field_body';
  $handler->display->display_options['fields']['field_body']['table'] = 'field_data_field_body';
  $handler->display->display_options['fields']['field_body']['field'] = 'field_body';
  $handler->display->display_options['fields']['field_body']['label'] = '';
  $handler->display->display_options['fields']['field_body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_body']['element_label_colon'] = FALSE;
  /* Field: Download link */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Download link';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="curtain">
<div class="tool-id">[id]</div>
<div class="tile rollover-state"><div class="inner-wrap">
<div class="desc">[field_body]</div>
<div class="download-ref"><a href="[file_upload]" class="download-link">[cta]</a></div>
</div></div>
<a href="[file_upload]" class="download-link">
<div class="tile normal-state"><div class="inner-wrap">
<div class="icon">[icon_upload]</div>
<h2 class="title">[label]</h2>
<div class="download-ref">[cta]</div>
</div></div>
</a>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Filter criterion: Downloadable: Downloadable Category (field_dl_type) */
  $handler->display->display_options['filters']['field_dl_type_tid']['id'] = 'field_dl_type_tid';
  $handler->display->display_options['filters']['field_dl_type_tid']['table'] = 'field_data_field_dl_type';
  $handler->display->display_options['filters']['field_dl_type_tid']['field'] = 'field_dl_type_tid';
  $handler->display->display_options['filters']['field_dl_type_tid']['value'] = array(
    5 => '5',
  );
  $handler->display->display_options['filters']['field_dl_type_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_dl_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_dl_type_tid']['vocabulary'] = 'dl_category';

  /* Display: Ideas and Tools: DLs */
  $handler = $view->new_display('block', 'Ideas and Tools: DLs', 'block');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'fundraise-tools';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'responsive_grid';
  $handler->display->display_options['style_options']['columns'] = '6';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_dl_overlay' => 'field_dl_overlay',
  );
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Downloadable: Internal, numeric downloadable ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'downloadable';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['label'] = '';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['id']['element_default_classes'] = FALSE;
  /* Field: Downloadable: Icon_upload */
  $handler->display->display_options['fields']['icon_upload']['id'] = 'icon_upload';
  $handler->display->display_options['fields']['icon_upload']['table'] = 'downloadable';
  $handler->display->display_options['fields']['icon_upload']['field'] = 'icon_upload';
  $handler->display->display_options['fields']['icon_upload']['label'] = '';
  $handler->display->display_options['fields']['icon_upload']['exclude'] = TRUE;
  $handler->display->display_options['fields']['icon_upload']['element_label_colon'] = FALSE;
  /* Field: Downloadable: Url */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'downloadable';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['label'] = '';
  $handler->display->display_options['fields']['url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['url']['element_label_colon'] = FALSE;
  /* Field: Downloadable: File_upload */
  $handler->display->display_options['fields']['file_upload']['id'] = 'file_upload';
  $handler->display->display_options['fields']['file_upload']['table'] = 'downloadable';
  $handler->display->display_options['fields']['file_upload']['field'] = 'file_upload';
  $handler->display->display_options['fields']['file_upload']['label'] = '';
  $handler->display->display_options['fields']['file_upload']['exclude'] = TRUE;
  $handler->display->display_options['fields']['file_upload']['element_label_colon'] = FALSE;
  /* Field: Downloadable: Label */
  $handler->display->display_options['fields']['label']['id'] = 'label';
  $handler->display->display_options['fields']['label']['table'] = 'downloadable';
  $handler->display->display_options['fields']['label']['field'] = 'label';
  $handler->display->display_options['fields']['label']['label'] = '';
  $handler->display->display_options['fields']['label']['exclude'] = TRUE;
  $handler->display->display_options['fields']['label']['element_label_colon'] = FALSE;
  /* Field: Downloadable: Cta */
  $handler->display->display_options['fields']['cta']['id'] = 'cta';
  $handler->display->display_options['fields']['cta']['table'] = 'downloadable';
  $handler->display->display_options['fields']['cta']['field'] = 'cta';
  $handler->display->display_options['fields']['cta']['label'] = '';
  $handler->display->display_options['fields']['cta']['exclude'] = TRUE;
  $handler->display->display_options['fields']['cta']['element_label_colon'] = FALSE;
  /* Field: Field: Description */
  $handler->display->display_options['fields']['field_body']['id'] = 'field_body';
  $handler->display->display_options['fields']['field_body']['table'] = 'field_data_field_body';
  $handler->display->display_options['fields']['field_body']['field'] = 'field_body';
  $handler->display->display_options['fields']['field_body']['label'] = '';
  $handler->display->display_options['fields']['field_body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_body']['element_label_colon'] = FALSE;
  /* Field: Downloadable: Overlay */
  $handler->display->display_options['fields']['field_dl_overlay']['id'] = 'field_dl_overlay';
  $handler->display->display_options['fields']['field_dl_overlay']['table'] = 'field_data_field_dl_overlay';
  $handler->display->display_options['fields']['field_dl_overlay']['field'] = 'field_dl_overlay';
  $handler->display->display_options['fields']['field_dl_overlay']['label'] = '';
  $handler->display->display_options['fields']['field_dl_overlay']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_dl_overlay']['element_label_colon'] = FALSE;
  /* Field: Download link */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Download link';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="curtain [field_dl_overlay]">
<div class="tool-id">[id]</div>
<div class="tile rollover-state"><div class="inner-wrap">
<div class="desc">[field_body]</div>
<div class="download-ref"><a href="[file_upload]" class="download-link">[cta]</a></div>
</div></div>
<a href="[file_upload]" class="download-link">
<div class="tile normal-state"><div class="inner-wrap">
<div class="icon">[icon_upload]</div>
<h2 class="title">[label]</h2>
<div class="download-ref">[cta]</div>
</div></div>
</a>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Field: Draggableviews: Downloadable */
  $handler->display->display_options['fields']['draggableviews']['id'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['table'] = 'downloadable';
  $handler->display->display_options['fields']['draggableviews']['field'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['label'] = '';
  $handler->display->display_options['fields']['draggableviews']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['ajax'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Draggableviews: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'draggableviews_structure';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_view'] = 'self';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_new_items_bottom_list'] = 1;
  $export['tools'] = $view;

  return $export;
}
