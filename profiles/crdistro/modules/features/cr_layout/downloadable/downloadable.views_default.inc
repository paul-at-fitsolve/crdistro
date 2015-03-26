<?php
/**
 * @file
 * downloadable.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function downloadable_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'downloadables';
  $view->description = 'All outputs of downloadables go here';
  $view->tag = 'default';
  $view->base_table = 'downloadable';
  $view->human_name = 'Downloadables';
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
  $handler->display->display_options['pager']['options']['items_per_page'] = '15';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Downloadable: Internal, numeric downloadable ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'downloadable';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['label'] = '';
  $handler->display->display_options['fields']['id']['element_label_colon'] = FALSE;
  /* Field: Downloadable: Icon_upload */
  $handler->display->display_options['fields']['icon_upload']['id'] = 'icon_upload';
  $handler->display->display_options['fields']['icon_upload']['table'] = 'downloadable';
  $handler->display->display_options['fields']['icon_upload']['field'] = 'icon_upload';
  $handler->display->display_options['fields']['icon_upload']['label'] = '';
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
  $handler->display->display_options['fields']['label']['element_label_colon'] = FALSE;
  /* Field: Downloadable: Cta */
  $handler->display->display_options['fields']['cta']['id'] = 'cta';
  $handler->display->display_options['fields']['cta']['table'] = 'downloadable';
  $handler->display->display_options['fields']['cta']['field'] = 'cta';
  $handler->display->display_options['fields']['cta']['label'] = '';
  $handler->display->display_options['fields']['cta']['exclude'] = TRUE;
  $handler->display->display_options['fields']['cta']['element_label_colon'] = FALSE;
  /* Field: Download link */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Download link';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<a href="[file_upload]">[cta]</a>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;

  /* Display: Ideas and Tools: DLs */
  $handler = $view->new_display('block', 'Ideas and Tools: DLs', 'block');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'css-bootstrap';

  /* Display: Fundraising Tools: DLs */
  $handler = $view->new_display('block', 'Fundraising Tools: DLs', 'block_1');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'css-bootstrap';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'clearfix leader';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Downloadable: Icon_upload */
  $handler->display->display_options['fields']['icon_upload']['id'] = 'icon_upload';
  $handler->display->display_options['fields']['icon_upload']['table'] = 'downloadable';
  $handler->display->display_options['fields']['icon_upload']['field'] = 'icon_upload';
  $handler->display->display_options['fields']['icon_upload']['label'] = '';
  $handler->display->display_options['fields']['icon_upload']['element_class'] = 'grid-2 alpha';
  $handler->display->display_options['fields']['icon_upload']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['icon_upload']['element_default_classes'] = FALSE;
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
  $handler->display->display_options['fields']['label']['element_type'] = 'h5';
  $handler->display->display_options['fields']['label']['element_class'] = 'kill-spacing-here';
  $handler->display->display_options['fields']['label']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['label']['element_default_classes'] = FALSE;
  /* Field: Downloadable: Cta */
  $handler->display->display_options['fields']['cta']['id'] = 'cta';
  $handler->display->display_options['fields']['cta']['table'] = 'downloadable';
  $handler->display->display_options['fields']['cta']['field'] = 'cta';
  $handler->display->display_options['fields']['cta']['label'] = '';
  $handler->display->display_options['fields']['cta']['exclude'] = TRUE;
  $handler->display->display_options['fields']['cta']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['cta']['element_default_classes'] = FALSE;
  /* Field: Download link */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Download link';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<a class="cta" href="[file_upload]">[cta]</a>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Downloadable: Downloadable Category (field_dl_type) */
  $handler->display->display_options['filters']['field_dl_type_tid']['id'] = 'field_dl_type_tid';
  $handler->display->display_options['filters']['field_dl_type_tid']['table'] = 'field_data_field_dl_type';
  $handler->display->display_options['filters']['field_dl_type_tid']['field'] = 'field_dl_type_tid';
  $handler->display->display_options['filters']['field_dl_type_tid']['value'] = array(
    5 => '5',
  );
  $handler->display->display_options['filters']['field_dl_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_dl_type_tid']['vocabulary'] = 'dl_category';

  /* Display: FT: DLs--Vertical */
  $handler = $view->new_display('block', 'FT: DLs--Vertical', 'block_2');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'css-bootstrap';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'clearfix leader';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Downloadable: Icon_upload */
  $handler->display->display_options['fields']['icon_upload']['id'] = 'icon_upload';
  $handler->display->display_options['fields']['icon_upload']['table'] = 'downloadable';
  $handler->display->display_options['fields']['icon_upload']['field'] = 'icon_upload';
  $handler->display->display_options['fields']['icon_upload']['label'] = '';
  $handler->display->display_options['fields']['icon_upload']['alter']['text'] = '<div class="grid-2 alpha">
  [icon_upload]
</div>';
  $handler->display->display_options['fields']['icon_upload']['element_type'] = 'div';
  $handler->display->display_options['fields']['icon_upload']['element_class'] = 'grid-2 alpha left';
  $handler->display->display_options['fields']['icon_upload']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['icon_upload']['element_default_classes'] = FALSE;
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
  $handler->display->display_options['fields']['label']['element_type'] = 'h5';
  $handler->display->display_options['fields']['label']['element_class'] = 'kill-spacing-here';
  $handler->display->display_options['fields']['label']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['label']['element_default_classes'] = FALSE;
  /* Field: Downloadable: Cta */
  $handler->display->display_options['fields']['cta']['id'] = 'cta';
  $handler->display->display_options['fields']['cta']['table'] = 'downloadable';
  $handler->display->display_options['fields']['cta']['field'] = 'cta';
  $handler->display->display_options['fields']['cta']['label'] = '';
  $handler->display->display_options['fields']['cta']['exclude'] = TRUE;
  $handler->display->display_options['fields']['cta']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['cta']['element_default_classes'] = FALSE;
  /* Field: Download link */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Download link';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="grid-3 alpha omega right">
  <a href="[file_upload]"><h5 class="kill-spacing-here">[label]</h5></a>
  <a class="cta" href="[file_upload]">[cta]</a>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Downloadable: Downloadable Category (field_dl_type) */
  $handler->display->display_options['filters']['field_dl_type_tid']['id'] = 'field_dl_type_tid';
  $handler->display->display_options['filters']['field_dl_type_tid']['table'] = 'field_data_field_dl_type';
  $handler->display->display_options['filters']['field_dl_type_tid']['field'] = 'field_dl_type_tid';
  $handler->display->display_options['filters']['field_dl_type_tid']['value'] = array(
    5 => '5',
  );
  $handler->display->display_options['filters']['field_dl_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_dl_type_tid']['vocabulary'] = 'dl_category';
  $export['downloadables'] = $view;

  return $export;
}
