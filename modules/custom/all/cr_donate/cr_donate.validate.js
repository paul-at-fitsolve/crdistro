(function($) {
  Drupal.behaviors.cr_donate_validate = {
    attach: function(context) {
      var parsleySettings = {
        errors: {
          errorsWrapper: '<ul class="messages error"></ul>',
          container: function (element, isRadioOrCheckbox) {
            if (isRadioOrCheckbox) {
              return element.closest('.form-type-radios, .form-type-checkbox');
            }
          }
        },
        listeners: {
          onFieldError: function (element, constraints, ParsleyField) {
            // Ensure address fields are shown if an error occurs when they are hidden.
            if (element.closest('.cr-plus-address-fields').length) {
              $('.form-item-address-select', context).hide();
              $('.cr-plus-address-fields', context).show();
            }
          }
        }
      };

      var $form = $('#cr-donate-form, #cr-donate-giftaid-form, #cr-donate-pay-in-form', context);
      $form.parsley(parsleySettings);
      // As parsley cannot do conditional submit validation based on which button is clicked, we need to put in
      // workarounds to fulfill our requirements as follows:
      // * When clicking paypal button, we only want to validate the amount field.
      // * When clicking previous button on pay in form (page 2), we don't want to do any validation
      //
      // So when any button is clicked, we remove all validation and then selectively re-apply it as required.
      $form.find('.button').click(function () {
        // Remove any existing validation on the form.
        $form.parsley('destroy');

        if ($(this).is('#edit-previous')) {
          // Validate nothing for the 'previous' button.
        }
        else if ($(this).hasClass('button-paypal')) {
          // Only validate the amount field for PayPal submissions.
          $form.parsley($.extend({}, parsleySettings, {
            inputs: 'input.cr-donate-amount'
          }));
        }
        else {
          // Disable email confirm field for mobile.
          var isMobile = $(window).width() < 740;
          $form.find('input[name="email_confirm"]').prop('disabled', isMobile);

          // Validate all fields.
          $form.parsley(parsleySettings);
          addPayInFormVisibilityBasedValidation();
        }
      });

      addPayInFormVisibilityBasedValidation();

      function addPayInFormVisibilityBasedValidation() {
        $('#cr-donate-pay-in-form' ).parsley( 'addListener', {
          onFieldValidate: function ( elem ) {
            // if field is not visible, we should not apply Parsley validation
            // but we cant simply check element visibility as selects are always hidden as we provide our own custom
            // select boxes, so will have to resort to checking whether the elements parent fieldset is visible instead
            if ($(elem).closest('fieldset').is(':hidden')) {
              return true;
            }

            // if we get here then the element being validated is within the currently visible fieldset.
            // so perform any additional checks as required.

            // Don't validate hidden elements, generally conditional "other" text fields
            if($('.cr-fundraising-form-step-2').length == 0) {
              if ($(elem).closest('.form-item-wrapper').is(':hidden')) {
                return true;
              }
            }

            // Don't validate the school look up field if the manual address fields are visible
            if ($(elem).is('#establishment_lookup') && $('#manual-address-fields-container').is(':visible')) {
              return true;
            }

            return false;
          }
        });
      }
    }
  }
})(jQuery);
