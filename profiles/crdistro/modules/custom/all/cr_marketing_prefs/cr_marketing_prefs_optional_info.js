(function($) {
  Drupal.behaviors.cr_marketing_optional_info = {
    attach: function(context) {
      $('input[name="organisation"]', context).change(function() {
        $(window).resize();
      });
      $('select[name="organisation_name"]', context).change(function() {
        if ($(this).val() == 'Other') {
          $(window).resize();
        }
      });
    }
  }
  $.fn.crInvokeEqualHeights = function () {
    $(window).resize();
  }
})(jQuery);
