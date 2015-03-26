(function ($) {
  Drupal.behaviors.cr_eddirect = {
    attach: function (context) {
      var $establishment_lookup = $('#establishment_lookup');
      var $establishment_id = $('#establishment_id');
      var $establishment_address_container = $('#manual-address-fields-container');
      var $establishment_schoolname = $('#establishment_schoolname');
      var $establishment_address1 = $('#establishment_address1');
      var $establishment_address2 = $('#establishment_address2');
      var $establishment_address3 = $('#establishment_address3');
      var $establishment_town = $('#establishment_town');
      var $establishment_postcode = $('#establishment_postcode');
      var $enter_address_manually = $('.establishment-manual');

      // hide manual selection if user has not explicitly
      // entered an address yet.
      if ($('.error', $establishment_address_container).length == 0 && manual_address_fields_empty()) {
        $establishment_address_container.hide();
      }

      $enter_address_manually.click(function() {
        // Clear lookup field, hide manual link, hide error, show manual fields.
        $establishment_lookup.val('');
        $establishment_id.val('0');

        $enter_address_manually.hide();
        Drupal.behaviors.cr_eddirect.remove_no_results_error();
        $establishment_address_container.show();
        return false;
      });

      function manual_address_fields_empty() {
        var fields_empty =
          $establishment_schoolname.attr('value') == '' &&
            $establishment_address1.attr('value') == '' &&
            $establishment_address2.attr('value') == '' &&
            $establishment_address3.attr('value') == '' &&
            $establishment_town.attr('value') == '' &&
            $establishment_postcode.attr('value') == '';

        return fields_empty;
      }
    }
  }

  /** Override default behaviour to handle 'no results' separately. */
  Drupal.jsAC.prototype.cr_original_found = Drupal.jsAC.prototype.found;
  Drupal.jsAC.prototype.found = function (matches) {
    var $establishment_lookup = $('#establishment_lookup');
    var $establishment_id = $('#establishment_id');
    var $enter_address_manually = $('.establishment-manual');
    var $establishment_address_container = $('#manual-address-fields-container');
    if (matches.length !== 0 || this.input.value.length < 2) {
      this.cr_original_found(matches);
      Drupal.behaviors.cr_eddirect.remove_no_results_error();
    }
    else {
      // Clear lookup field, hide manual link, show error, show manual fields
      $establishment_lookup.val('');
      $establishment_id.val('0');
      $enter_address_manually.hide();
      Drupal.behaviors.cr_eddirect.add_no_results_error();
      $establishment_address_container.show();

    }
  };

  /**
   * Override default behaviour to split ID out from string, and hide extra
   * fields when a selection is made.
   */
  Drupal.jsAC.prototype.select = function (node) {
    var $establishment_id = $('#establishment_id');
    var $enter_address_manually = $('.establishment-manual');
    var $establishment_address_container = $('#manual-address-fields-container');
    var value = $(node).data('autocompleteValue');
    var matches = /^(.*) \[ID: (\d+)\]$/.exec(value);
    $(node).data('autocompleteValue', matches[1]);
    this.input.value = matches[1];
    $establishment_id.val(matches[2]);

    // Show manual link, hide manual fields.
    $establishment_address_container.hide();
    $enter_address_manually.show();
  };

  Drupal.behaviors.cr_eddirect.add_no_results_error = function() {
    var $establishment_address_container = $('#manual-address-fields-container');
    if ($('.establishment-error').size() == 0) {
      error_element =
        $("<div class='messages error messages-inline establishment-error no-results-error'>" +
          "We can't seem to find the correct address. You can fill it in below though and we'll make sure we save it." +
          "</div>"
        );

      $establishment_address_container.prepend(error_element);
      Drupal.attachBehaviors($establishment_address_container);
    }
  }

  Drupal.behaviors.cr_eddirect.remove_no_results_error = function () {
    $('.no-results-error').remove();
  }

})(jQuery);
