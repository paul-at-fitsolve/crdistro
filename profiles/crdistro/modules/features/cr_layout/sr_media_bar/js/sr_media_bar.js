/*
 * @file
 * JavaScript for sr_media_bar js.
 * Resize colourbox content on event cbox_complete
 */

(function($) {

  Drupal.behaviors.srMediaBarColourBox = {
    attach: function(context, settings) {
    // Only fire on media bar
      var $found = $(context).find('.view-mode-colorbox');
      if($found.length == 1){
        // Delay resize due to DOM calculating height before image loaded
        // Cannot use cbox_complete event because colorbox node fires another ajax request
        // through Drupal.ajax, meaning none of the colorbox api methods are useful to us.
        // Extremely frustrating!
        setTimeout(function() {
          $.colorbox.element().hide();
          var gW = $('.grid-16').width();
          $.colorbox.resize(options = {innerWidth: gW});
        } ,200);
        setTimeout(function() {
          $.colorbox.element().show();
        } ,2000);
      }
   }
  }

})(jQuery);

