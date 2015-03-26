<?php
  /**
   * @file
   * Administration hooks and functions for the downloadable type.
   */

  /**
   * Generates the downloadable type editing form.
   */
  function crl2_downloadable_form($form, &$form_state, $downloadable, $op = 'edit') {
    $form['label'] = array(
      '#title' => t('Human readable name of the downloadable'),
      '#type' => 'textfield',
      '#size' => 40,
      '#maxlength' => 64,
      '#required' => TRUE,
      '#description' => t('This label also acts as default text for the '
        . ' link to the resource.'),
      '#default_value' => isset($downloadable->label) ? $downloadable->label : '',
    );

    // Machine-readable type name.
    $form['name'] = array(
      '#type' => 'machine_name',
      '#disabled' => method_exists($downloadable, 'isLocked') ? $downloadable->isLocked() : FALSE,
      '#machine_name' => array(
        'exists' => 'crl2_downloadable_name_exists',
        'source' => array('label'),
      ),
      '#maxlength' => 32,
      '#description' => t('A unique machine-readable name for this profile type.'
        . ' It must only contain lowercase letters, numbers, and underscores.'),
      '#default_value' => isset($downloadable->name) ? $downloadable->name : '',
    );

    $form['file_upload'] = array(
      '#title' => t('Choose a file'),
      '#type' => 'managed_file',
      '#size' => 22,
      '#description' => t('Optional. If the downloadable isn\'t an external '
        . 'link then upload it here.'),
      '#upload_validators'  => array(
        "file_validate_extensions" => array(
          'jpg jpeg gif png txt doc docx xls xlsm xlsx pdf'
          . ' ppt pptx pps odt ods odp zip mp3 mp4 wav mov avi wmv'
        )
      ),
      '#default_value' => isset($downloadable->file_upload) ? $downloadable->file_upload : 0,
      '#upload_location' => 'public://downloadables',
    );

    $form['url'] = array(
      '#title' => t('Otherwise enter a link (url)'),
      '#type' => 'textfield',
      '#maxlength' => 255,
      '#size' => 60,
      '#element_validate' => array('crl2_downloadable_link_generic_validate'),
      '#description' => t('Optional. If you didn\'t upload a file please ' .
        'provide the link (url) to the resource here.'),
      '#default_value' => isset($downloadable->url) ? $downloadable->url : '',
    );

    field_attach_form('crl2_downloadableable', $downloadable, $form, $form_state);

    $form['actions'] ['#weight'] = 999;
    $form['actions']['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Save Downloadable')
    );
    $form['actions']['cancel'] = array(
      '#type' => 'link',
      '#href' => isset($_GET['destination']) ? $_GET['destination'] : CRL2_DOWNLOADABLE_ADMIN_URL,
      '#title' => t('Cancel'),
    );

    return $form;
  }

  /**
   * Form API submit callback for the type form.
   */
  function crl2_downloadable_form_submit(&$form, &$form_state) {
    $downloadable = entity_ui_form_submit_build_entity($form, $form_state);

    // Set the files to permanent
    if($downloadable->file_upload != 0) {
      $file = file_load($downloadable->file_upload);
      $file->status = FILE_STATUS_PERMANENT;
      file_save($file);
      $downloadable->file_upload = $file->fid;
      file_usage_add($file, 'crl2_downloadableable', 'crl2_downloadableable', $file->fid);
    }

    // Save and go back.
    $downloadable->save();
    $form_state['redirect'] = 'admin/structure/downloadable';
  }

  /**
   * Implements hook_entity_presave().
   */
  function crl2_downloadable_entity_presave($entity) {
    // file_upload
    if(isset($entity->original->file_upload)) {
      // If the original ent fid wasn't null and the new one is..
      if($entity->original->file_upload != 0 && $entity->file_upload == 0) {
        // the file was deleted
        _delete_file_by_fid($entity->original->file_upload);
      }
    }
  }

  /**
   * Checks if a machine name already exists in the db.
   * Called by downloadable_form
   */
  function crl2_downloadable_name_exists($element_name, $element, &$form_state) {
    if($form_state['op'] === 'add') {
      $querystr = 'SELECT 1 FROM {crl2_downloadable} ent WHERE ent.name = :name';
      $result = db_query($querystr, array(':name' => $element_name));
      return $result->rowCount() === 0 ? FALSE : TRUE;
    }
  }

  /**
   * A generic function to validate a form link
   */
  function crl2_downloadable_link_generic_validate($element, &$form_state, $form) {
    if(!empty($element['#value']) && !filter_var($element['#value'], FILTER_VALIDATE_URL)) {
      form_error($element, t('Please enter a valid url.'));
    }
  }

  /**
   * Helper function to delete a file by id.
   */
  if (!function_exists('_delete_file_by_fid')) :
    function _delete_file_by_fid($fid) {
      if($fid != 0) {
        $file = file_load($fid);

        // Unregister this module's usage of the file
        file_usage_delete($file, 'crl2_downloadable', 'crl2_downloadable', $fid);

        // Delete the file if nothing else is using it
        return file_delete($file);
      }
    }
  endif;