(function($) {
  Drupal.behaviors.donate_popup = {
    attach: function(context) {
      $('a[href="/donate"]').click(function() {
        var html = '<div id="redirect-wrapper"><div id="redirect-message">';
        html += "You are being redirected to our site <strong>comicrelief.com</strong> to process your donation...";
        html += '</div><div class="overlay_bg"></div></div>';
        $('body').append(html);

        setTimeout(function() {
          window.location.href = "http://www.comicrelief.com/donate";
        }, 4000);

        return false;
      });
    }
  }
})(jQuery);
