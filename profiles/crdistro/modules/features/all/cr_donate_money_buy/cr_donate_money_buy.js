(function ($) {

    Drupal.behaviors.cr_donate_money_buy = {
        attach: function (context) {
            $('.pane-bundle-donate-money-buy', context).click(function() {
                // Handles fields with or without Omega 4 BEM syntax
                var moneybuy_trigger = $('.cr-donate-moneybuy-amount .field-item', this);
                if ($('.cr-donate-moneybuy-amount .field__item', this).length > 0) {
                    moneybuy_trigger = $('.cr-donate-moneybuy-amount .field__item', this);
                }
                var amount = moneybuy_trigger.text().substring(1);
                $('.cr-donate-amount').val(amount + '.00').keyup();
                return false;
            });

            $('.money-buy-button a', context).click(function() {
                var amount = $(this).text().substring(1);
                $('.cr-donate-amount').val(amount + '.00').keyup();

                // Display related money buy on mobile.
                if (moneyBuyMobileCheck()) {
                    var moneyBuy = $(".pane-bundle-donate-money-buy:contains('£" + amount + " ')", context);
                    if (moneyBuy.length) {
                        moneyBuy.show().closest('.column').siblings().find('.pane-bundle-donate-money-buy').hide();
                    }
                }

                return false;
            });
        }
    };

    function moneyBuyMobileCheck(){
        if (Drupal.settings.hasOwnProperty('omega') && $.isFunction(Drupal.omega.getCurrentLayout)) {
            if (Drupal.omega.getCurrentLayout() == "mobile") {
                return true;
            }
        }
        if (Drupal.settings.hasOwnProperty('crl2')){
            var mobile_breaks = ['xs', 'sm', 'md'];
            if (mobile_breaks.indexOf(Drupal.settings.crl2.breakpointActive)) {
                return true;
            }
        }
        return false;
    }

})(jQuery);