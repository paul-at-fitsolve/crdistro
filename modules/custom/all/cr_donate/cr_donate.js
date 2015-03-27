(function ($) {
  Drupal.behaviors.cr_donate_currency_buttons = {
    attach: function(context) {
      var $currency_buttons = $('img.currency-item');
      var $select = $('#edit-currency');

      // these vars are used for manually updated the dropkick select widget that
      // does not update automatically in response to programmatic updates to
      // its selectbox source
      var currency_selectbox_values = [];
      var $currency_selectbox_options = $('option', $select);
      $currency_selectbox_options.each(function() {
        currency_selectbox_values[this.value] = this.text;
      });

      $currency_buttons.on('click', context, function() {
        var currency_clicked = this.id.toUpperCase();
        $select.val(currency_clicked);

        // Due to using dropdick select boxes we now have to add a little hack
        // to update its value as it does not respond to programmatic changes
        // we have to define the following vars in the click handler as we can't
        // guarantee they have made it into the DOM at the time this behaviour
        // is attached
        var $dropkick_container = $('#dk_container_' + $select[0].id);
        var $dk_label = $('.dk_label', $dropkick_container);
        $dk_label.text(currency_selectbox_values[currency_clicked]);
      });
    }
  }
})(jQuery);
