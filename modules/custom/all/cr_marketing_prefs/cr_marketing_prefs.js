(function($) {
  Drupal.behaviors.cr_marketing_prefs = {
    attach: function(context) {
      var esu_form = $('body:not(.panels-ipe) .cr-marketing-prefs-signup-form', context);
      var pod = $('body:not(.panels-ipe) #esu-thanks', context);
      var esu_intro_copy = $('.esu--subpod .esu-intro', context);
      if (window.location.hash == '#thanks') {
        esu_form.addClass('element-hidden');
        pod.removeClass('element-hidden');
        esu_intro_copy.addClass('is-not-mobile');

        // Scroll the page to the real anchor. We cannot just link to the real
        // anchor as the initial scroll is wrong due to late DOM manipulation.
        location.hash = '#esu-thanks';
      }
      else {
        pod.addClass('element-hidden');

        // If there is an inline error in the page, insert an anchor and jump to it.
        var $error = $('.messages-inline.error:eq(0)', context);
        if ($error.length) {
          $error.closest('form').before('<a id="error" />');
          location.hash = '#error';
        }
      }
    }
  }
})(jQuery);
