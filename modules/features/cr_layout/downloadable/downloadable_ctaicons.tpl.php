<?php
$cta_title = '<span class="text">' . $cta. '</span>';
$icon_image = '<span class="icon">' . $icon . '</span>';
$dl_title = $downloadable->field_dl_title ? $downloadable->field_dl_title[LANGUAGE_NONE][0]['safe_value'] : $title;
$overlay_class = '';
if(!empty($downloadable->field_dl_overlay) && $downloadable->field_dl_overlay['und'][0]['value'] == '1') { $overlay_class = 'dl-overlay'; }
?>
<div class="action-pod-item">
  <div class="curtain-icon <?php print $overlay_class; ?>">
    <div class="tile rollover-state">
      <div class="inner-wrap">
        <div class="desc"><?php print $text; ?></div>
        <div class="download-ref">
          <?php 
          //check for 3 slashes and remove one before printing out link as IE can't handle it
          print preg_replace('/(?<=href=\")(.*\/\/\/)/', '//', l($cta_title, $link_url, array('html' => TRUE, 'attributes' => array('title' => $title,'class'=>$link_class)))); ?>
        </div>
      </div>
    </div>
    <div class="tile normal-state">
      <div class="inner-wrap">
        <?php print $icon_image; ?>
        <h3 class="title"><?php print $dl_title ?></h3>
      </div>
    </div>
  </div>
</div>