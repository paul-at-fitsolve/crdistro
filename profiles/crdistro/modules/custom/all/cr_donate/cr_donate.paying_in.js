(function ($) {

  Drupal.behaviors.cr_donate_paying_in = {
    attach: function (context) {
      if ((typeof _gaq !== 'undefined') && (typeof _gaq.push === 'function')) {
        $('#boxes-box-global_simple_nav a.button', context).click(function(event) {
          _gaq.push(['_trackEvent', 'Paying In', 'Button', 'Paying In | Header | Back to home']);
        });

        $('.cr-fundraising-form-step-1 .form-item-type input').click(function(event) {
          // Convert label to virtual URL.
          var virtualPage = $(this).siblings('label').text().trim().toLowerCase().replace(/[^a-z ]/g, '').replace(/ or /, ' ').replace(/ /g, '-');
          _gaq.push(["_trackPageview", "/pay-in-fundraising-money/" + virtualPage]);
        });

        $('.cr-fundraising-form-step-1 .button--submit').click(function(event) {
          var label = $('.form-item-type input:checked').siblings('label').text();
          _gaq.push(['_trackEvent', 'Paying In', 'Button', 'Paying In | ' + label + ' | Next']);
        });

        if ($('.cr-fundraising-form-step-2').length) {
          _gaq.push(["_trackPageview", "/pay-in-fundraising-money/donate-payment"]);
        }
      }
    }
  }

  Drupal.behaviors.cr_donate = {
    attach: function (context) {
      // If there is an inline error in the page, insert an anchor and jump to it.
      var $error = $('.messages-inline.error:eq(0)', context);
      if ($error.length) {
        $error.closest('fieldset').before('<a id="error" />');
        location.hash = '#error';
      }
    }
  }


})(jQuery);
