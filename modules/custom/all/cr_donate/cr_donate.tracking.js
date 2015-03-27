(function ($) {

  Drupal.behaviors.cr_giftaid_calculator = {
    attach: function (context) {
      var originalText = $('.giftaid-calculator', context).html();

      // Calculate gift aid amount.
      var calculate = function() {
        var donation = parseFloat($('.cr-donate-amount', context).val());
        var currency = $('select[name=currency], input:radio[name=currency]:checked', context).val();
        if (currency == 'GBP' && donation > 0) {
          var amount = Math.floor(donation * 25) / 100;
          $('.giftaid-calculator-amount', context).text('£' + amount.toFixed(2).replace('.00', ''));
          $('.giftaid-calculator-donation', context).text('£' + donation.toFixed(2).replace('.00', ''));
        }
        else {
          $('.giftaid-calculator', context).html(originalText);
        }
      };

      $('.cr-donate-amount', context).keyup(calculate);
      $('.cr-donate-currency', context).change(calculate);
    }
  }

  Drupal.behaviors.cr_donate_tracking = {
    attach: function (context) {
      // Money buy image.
      if ((typeof _gaq !== 'undefined') && (typeof _gaq.push === 'function')) {
        $('.pane-bundle-donate-money-buy', context).click(function() {
          var amount_field = $('.cr-donate-moneybuy-amount .field-item', this);
          if ($('.cr-donate-moneybuy-amount .field__item', this).length > 0) {
            amount_field = $('.cr-donate-moneybuy-amount .field__item', this);
          }
          var amount = amount_field.text().substring(1);
          _gaq.push(['_trackEvent', 'Donate', 'Money buy', 'Donate | Money buy | ' + amount + ' pounds', parseInt(amount), true]);
        });

        // Money buy button.
        $('.money-buy-button a', context).click(function() {
          var amount = $(this).text().substring(1);
          _gaq.push(['_trackEvent', 'Donate', 'Button', 'Donate | Button | ' + amount + ' pounds', parseInt(amount), true]);
        });

        // Postcode lookup.
        $('.cr-plus-lookup', context).click(function() {
          _gaq.push(['_trackEvent', 'Donate', 'Button', 'Donate | Button | Find my address', undefined, true]);
        });

        // Manual address entry.
        $('.cr-plus-manual', context).click(function() {
          _gaq.push(['_trackEvent', 'Donate', 'Link', 'Donate | Link | Find address manually', undefined, true]);
        });

        // When parsley adds an inline errors, fire a GA event
        $(".cr-donate-form").bind("DOMNodeInserted",function(event){
          if (event.target.nodeName == 'LI' && $(event.target).parent('.parsley-error-list')) {
            var errorMessage = event.target.innerText;
            // send error event to GA
            _gaq.push(['_trackEvent', 'Donate', 'Error Messages', 'Donate | Error message | ' + errorMessage]);
          }
        });
      }
    }
  };

})(jQuery);
