<?php if (isset($form['calculator'])): ?>
  <div class="giftaid-calculator">
    <?php print theme('image', array('path' => drupal_get_path('module', 'cr_donate') . '/images/giftaid.png')); ?>
    <?php print drupal_render($form['calculator']); ?>
  </div>
<?php else: ?>
  <?php print theme('image', array('path' => drupal_get_path('module', 'cr_donate') . '/images/giftaid.png')); ?>
<?php endif; ?>

<?php print drupal_render_children($form); ?>
