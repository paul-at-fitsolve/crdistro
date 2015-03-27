(function ($) {

  Drupal.behaviors.cr_donate_giftaid = {
    attach: function (context) {
      if ((typeof _gaq !== 'undefined') && (typeof _gaq.push === 'function')) {
        var backToHome = $('#boxes-box-global_simple_nav a.button', context);
        var faqLink = $('.form-item-giftaid .form-description a', context);
        var findMyAddress = $('#edit-postcode-lookup', context);
        var enterAddressManually = $('a.cr-plus-manual', context);
        var submitButton = $('#edit-submit', context);


        backToHome.on('click', function(event) {
          _gaq.push(['_trackEvent', 'Gift Aid', 'Button', 'Gift Aid declaration Page | Header | Back to home']);
        });

        faqLink.on('click', function(event) {
          _gaq.push(['_trackEvent', 'Gift Aid', 'Link', 'Gift Aid declaration Page | Your Details | Find out more about Gift Aid']);
        });

        findMyAddress.on('click', function(event) {
          _gaq.push(['_trackEvent', 'Gift Aid', 'Button', 'Gift Aid declaration Page | Your Details | Find my address']);
        });

        enterAddressManually.on('click', function(event) {
          _gaq.push(['_trackEvent', 'Gift Aid', 'Link', 'Gift Aid declaration Page | Your Details | Find address manually'])
        });

        submitButton.on('click', function(event) {
          _gaq.push(['_trackEvent', 'Gift Aid', 'Button', 'Gift Aid declaration Page | Your Details | Submit button']);
        });
      }
    }
  }
})(jQuery);
