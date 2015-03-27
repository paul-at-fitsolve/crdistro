/**
 * JS for FB Share Feed Dialog Link
 * @param {type} $
 * @returns {undefined}
 */
(function ($) {
  Drupal.behaviors.cr_fb_share = {
    attach : function(context) {
      if(!$('body').find('#fb-root').length) {
        $('body').prepend('<div id="fb-root"></div>');
      }
      jQuery('#cr_fb_share').click(function(){
      var settings = Drupal.settings.cr_fb_share;
      var pageUrl = settings.path,
      title = settings.title,
      caption = settings.summary;
      appId = settings.appId;

      if (!Drupal.settings.fb || !Drupal.settings.fb.fb_init_settings ||
        !Drupal.settings.fb.fb_init_settings.appId) {
        FB.init({
          appId  : appId,
          status :true,
          cookie : true,
          xfbml  : true  
        });
      }
      FB.ui({
        method: 'feed',
        name: title,
        link: pageUrl,
        description: settings.summary
      }, function(response){});

    });//click
  }
}
        
})(jQuery);