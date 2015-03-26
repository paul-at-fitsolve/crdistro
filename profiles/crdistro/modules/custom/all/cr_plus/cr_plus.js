(function ($) {

  Drupal.behaviors.cr_plus = {
    attach: function (context) {
      var addresses;

      // Hide manual address fields, only if there is no error.
      if ($('.error', context).length == 0) {
        $('.cr-plus-address-fields', context).hide();
      }

      // Hide address selection.
      var $preselect = $('.form-item-address-select select', context);
      $('.form-item-address-select', context).hide();

      // Click for manual address entry.
      $('.cr-plus-manual', context).click(function() {
        $('.form-item-address-select', context).hide();
        $('.cr-plus-address-fields', context).show();
        return false;
      });

      // Click for postcode lookup.
      $('.cr-plus-lookup', context).click(function() {
        var postcode = $('.form-item-postcode input').val();
        if (!postcode) {
          alert('Please enter a postcode.');
          return false;
        }

        $('.cr-plus-address-fields', context).hide();

        var $select = $('.form-item-address-select select', context);

        $.ajax({
          type: "GET",
          dataType: 'json',
          url: Drupal.settings.cr_plus_url,
          data: {
            postcode: postcode
          },
          success: function (data) {
            addresses = data.addresses;
            if (!addresses) {
              alert('Please enter a valid postcode.');
              return;
            }

            $select.empty();
              
            for (var i = 0; i < addresses.length; i++) {
              var address = [];
              if (addresses[i].Line1) {
                address.push(addresses[i].Line1);
              }
              if (addresses[i].Line2) {
                address.push(addresses[i].Line2);
              }
              if (addresses[i].Line3) {
                address.push(addresses[i].Line3);
              }
              if (addresses[i].posttown) {
                address.push(addresses[i].posttown);
              }
              if (addresses[i].postcode) {
                address.push(addresses[i].postcode);
              }

              var option = '<option value="' + i + '">' + address.join(', ') + '</option>';
              $select.append(option);
            }

            // Checks to see if the select has a Dropkick version in place,
            // if so, update Dropkick version with the newly-added options
            if ($select.siblings('.dk-select').size() > 0) {
              $select.dropkick('refresh').parent().show();
            } else {
              // If not, show standard selectbox as Dropkick isn't being used
              $select.show().parent().show();
            }
          }
        });

        return false;
      });

      // Change address selection -  We need to listen for the focusout event for iphone and other iOS devices as they
      // automatically select the first option in the selectbox, and thus the change event is not fired should this
      // option be chosen by the user.
      $('.form-item-address-select select', context).on('focusout change', function() {
        var address = addresses[$(this).val()];
        $('.form-item-address1 input', context).val(address.Line1).blur();
        $('.form-item-address2 input', context).val(address.Line2).blur();
        $('.form-item-address3 input', context).val(address.Line3).blur();
        $('.form-item-town input', context).val(address.posttown).blur();
        $('.form-item-address-select', context).hide();
        $('.cr-plus-address-fields', context).show();
        return false;
      });
    }
  };

})(jQuery);
