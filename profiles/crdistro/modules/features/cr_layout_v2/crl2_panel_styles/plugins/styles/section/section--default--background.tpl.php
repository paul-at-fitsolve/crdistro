<section class="clearfix <?php print $custom_classes['classes_section'] ?>">
  <?php if($bg_pane_needs_container): ?>
    <div class="container section__container__bg-pane">
      <div class="row row--content">
        <?php print $bg_pane; ?>
      </div>
    </div>
  <?php else: ?>
  <?php print $bg_pane; ?>
  <?php endif; ?>

  <div class="section__content" <?php if(!empty($matchheight_group)) { print $matchheight_group; } ?>>
    <div class="container section__container<?php print $custom_classes['classes_container'] ?>">
      <div class="row row--content <?php print $custom_classes['classes_row'] ?>">
        <?php print $panes ?>
      </div>
    </div>
   </div>
</section>