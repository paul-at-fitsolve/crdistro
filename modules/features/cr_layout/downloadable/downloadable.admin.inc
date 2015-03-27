<?php

/**
 * @file
 * Administration hooks and functions for the downloadable type.
 */

/**
 * Generates the downloadable type editing form.
 */
function downloadable_form($form, &$form_state, $downloadable, $op = 'edit') {

  if ($op == 'clone') {
    $downloadable->label .= ' (cloned)';
    $downloadable->type .= '_clone';
  }

  $form['label'] = array(
    '#title' => t('Downloadable name'),
    '#type' => 'textfield',
    '#size' => 40,
    '#maxlength' => 64,
    '#required' => TRUE,
    '#default_value' => isset($downloadable->label) ? $downloadable->label : '',
  );

  // Machine-readable type name.
  $form['name'] = array(
    '#type' => 'machine_name',
    '#disabled' => method_exists($downloadable, 'isLocked') ? $downloadable->isLocked() : FALSE,
    '#machine_name' => array(
      'exists' => 'downloadable_name_exists',
      'source' => array('label'),
    ),
    '#maxlength' => 32,
    '#description' => t('A unique machine-readable name for this profile type. It must only contain lowercase letters, numbers, and underscores.'),
    '#default_value' => isset($downloadable->type) ? $downloadable->type : '',
  );

  $form['file_upload'] = array(
    '#title' => t('Choose a file'),
    '#type' => 'managed_file',
    '#size' => 22,
    '#description' => t('Optional. If the downloadable isn\'t an external link then upload it here.'),
    '#upload_validators'  => array("file_validate_extensions" => array('jpg jpeg gif png txt doc docx xls xlsm xlsx pdf ppt pptx pps odt ods odp zip mp3 mp4 wav mov avi wmv')),
    '#default_value' => isset($downloadable->file_upload) ? $downloadable->file_upload : 0,
    '#upload_location' => 'public://files/downloadables',
  );

  $form['url'] = array(
    '#title' => t('Otherwise enter a link (url)'),
    '#type' => 'textfield',
    '#maxlength' => 255,
    '#size' => 60,
    '#element_validate' => array('_link_generic_validate'),
    '#description' => t('Optional. If you didn\'t upload a file then provide the link (url) to the resource here.'),
    '#default_value' => isset($downloadable->url) ? $downloadable->url : '',
  );

  $form['icon_upload'] = array(
    '#title' => t('Choose an icon (image)'),
    '#type' => 'managed_file',
    '#size' => 22,
    '#description' => t('Optional. Choose an icon (image) for this downloadable. Allowed extensions: png gif jpg.'),
    '#upload_validators'  => array("file_validate_extensions" => array('png gif jpg')),
    '#default_value' => isset($downloadable->icon_upload) ? $downloadable->icon_upload : 0,
    '#upload_location' => 'public://files/downloadables',
  );

  $form['cta'] = array(
    '#title' => t('CTA'),
    '#type' => 'textfield',
    '#size' => 60,
    '#maxlength' => 255,
    '#required' => TRUE,
    '#description' => t('Control how the download link is outputted. For example if dealing with a PDF it might say by default <strong>Download PDF (1.86 MB)</strong>. Instead you might want to say <strong>Get the kit [downloadable:type] ([downloadable:size])</strong>, or if it is a link something like <strong>Get it from the shop</strong> (without tokens).'),
    '#default_value' => isset($downloadable->cta) ? $downloadable->cta : 'Download [downloadable:type] ([downloadable:size])',
  );

  field_attach_form('downloadable', $downloadable, $form, $form_state);

  $form['actions'] ['#weight'] = 999;
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save Downloadable')
  );

  return $form;
}

/**
 * Form API submit callback for the type form.
 */
function downloadable_form_submit(&$form, &$form_state) {
  $form_obj = (object)$form_state['values'];
  $downloadable = entity_ui_form_submit_build_entity($form, $form_state);

  // Set the files to permanent and shit
  if($downloadable->file_upload != 0) {
    $file = file_load($downloadable->file_upload);
    $file->status = FILE_STATUS_PERMANENT;
    file_save($file);
    $downloadable->file_upload = $file->fid;
    file_usage_add($file, 'downloadable', 'downloadable', $file->fid);
  }

  if($downloadable->icon_upload != 0) {
    $file = file_load($downloadable->icon_upload);
    $file->status = FILE_STATUS_PERMANENT;
    file_save($file);
    $downloadable->icon_upload = $file->fid;
    file_usage_add($file, 'downloadable', 'downloadable', $file->fid);
  }

  // Save and go back.
  $downloadable->save();
  $form_state['redirect'] = 'admin/structure/downloadable';
}

/**
 * Implements hook_entity_presave().
 */
function downloadable_entity_presave($entity) {
  // file_upload
  if(isset($entity->original->file_upload)) {
    // If the original ent fid wasn't null and the new one is..
    if($entity->original->file_upload != 0 && $entity->file_upload == 0) {
      // the file was deleted
      _deleteFileByFid($entity->original->file_upload);
    }
  }

  // icon_upload
  if(isset($entity->original->icon_upload)) {
    // If the original ent fid wasn't null and the new one is..
    if($entity->original->icon_upload != 0 && $entity->icon_upload == 0) {
      // the file was deleted
      _deleteFileByFid($entity->original->icon_upload);
    }
  }
}

/**
 * Checks if a machine name already exists in the db.
 * Called by downloadable_form
 */
function downloadable_name_exists($element_name, $element, &$form_state) {

  if($form_state['op'] === 'add') {
    $result = db_query('SELECT 1 FROM {downloadable} ent WHERE ent.name = :name', array(':name' => $element_name));
    return $result->rowCount() === 0 ? FALSE : TRUE;
  }

  return FALSE; // @todo: assume machine name remains unchanged on edit form - is this ok?
}

/**
 * A generic function to validate a form link
 */
if(!function_exists('_link_generic_validate')) :
function _link_generic_validate($element, &$form_state, $form) {
  if(!empty($element['#value']) && !filter_var($element['#value'], FILTER_VALIDATE_URL)) {
    form_error($element, t('Please enter a valid url.'));
  }
}
endif;

/**
 * Helper function to delete a file by id.
 */
if(!function_exists('_deleteFileByFid')) :
function _deleteFileByFid($fid) {
  if($fid != 0) {
    $file = file_load($fid);

    // Unregister this module's useage of the file
    file_usage_delete($file, 'downloadable', 'downloadable', $fid);

    // Delete the file if nothing else is using it
    return file_delete($file);
  }
}
endif;
