(function ($) {

  /**
   * Match Height JS Behaviour for CR Layout V2 
   * Author Jeremy P.
   */
  Drupal.behaviors.crl2_matchheight = {
    /*
     * Plugin Vars
     */
    matchheight_class: '.match-height',
    automatic_row_detection: true,

    throttle_update_fluid: 120,
    throttle_update_fixed: 1000,
    is_ipe: null,
    is_ipe_processed: null,
    breakpoints: null,

    /**
     * Main Attach Function
     *
     * @param context
     *   The context for which the behavior is being executed. This is either the
     *   full page or a piece of HTML that was just added through Ajax.
     * @param settings
     *   An array of settings (added through drupal_add_js()). Instead of accessing
     *   Drupal.settings directly you should use this because of potential
     *   modifications made by the Ajax callback that also produced 'context'.
     */
    attach: function (context, settings) {
      var _base = Drupal.behaviors.crl2_matchheight;
      
      // Assign breakpoints for local use
      if(_base.breakpoints === null && typeof settings.crl2.breakpoints !== 'undefined') {
        _base.breakpoints = settings.crl2.breakpoints;
      }

      // Set a boolean so we know if the IPE is running
      var $ipe_container = $('.panels-ipe-display-container', context);
      _base.is_ipe = $ipe_container.hasClass('panels-ipe-editing') || $ipe_container.hasClass('panels-ipe-processed');

      // Prevent Match Height when using the panels IPE
      if(_base.is_ipe) {
        $('[data-mh]', context).css('height', 'auto');
      }

      /**
       * Setup breakpoint handlers once
       */
      $('body', context).once('responsive-matchheight', _base.setupBreakpointHandlers);

      /**
       * Handle class based match height
       * Row detection detects if an element is within a row and applies the matched height
       */
      $(_base.matchheight_class, context).once('responsive-matchheight').matchHeight(_base.automatic_row_detection);
       
    },

    /*
     * Generic function to setup the handling of breakpoints
     * Throttles the update frequency of jquery match height
     */
    setupBreakpointHandlers: function() {
      var _base = Drupal.behaviors.crl2_matchheight;

      // Return of match height is undefined.
      if(typeof($.fn.matchHeight) == "undefined") return;

      // Stop Enquire before continuing & run the match height update
      if(typeof enquire=='undefined') {
        $.fn.matchHeight._update();
        return;
      }

      // Create an accesible enquire object with match/unmacth for reuse
      _base.matchHeightBetweenBreakpoints = {
        match : $.fn.matchHeight._update,
        unmatch : $.fn.matchHeight._update
      };

      /**
       * XS breakpoint
       */
      enquire.register(_base.breakpoints.xs, {
        match : _base.matchHeightXS,
        unmatch : _base.matchHeight
      });

      /**
       * SM breakpoint
       */
      enquire.register(_base.breakpoints.sm, {
        match : _base.matchHeightSM,
        unmatch : _base.unMatchHeightSM
      });

      /**
       * MD breakpoint
       */
      enquire.register(_base.breakpoints.md, _base.matchHeightBetweenBreakpoints);

      /**
       * LG breakpoint
       */
      enquire.register(_base.breakpoints.lg, _base.matchHeightBetweenBreakpoints);
    },

    /**
     * On match of XS breakpoint, update to a more frequent updating
     * XS Mobile First
     */
    matchHeightXS: function() {
      var _base = Drupal.behaviors.crl2_matchheight;
      $.fn.matchHeight._throttle = _base.throttle_update_fluid;
    },

    /**
     * On match of SM breakpoint, update to a less frequent updating
     * XS > SM
     */
    matchHeightSM: function() {
      var _base = Drupal.behaviors.crl2_matchheight;
      $.fn.matchHeight._throttle = _base.throttle_update_fixed;
    },

    /**
     * On unmatch of SM breakpoint, update to a less frequent updating
     * SM > XS
     */
    unMatchHeightSM: function() {
      var _base = Drupal.behaviors.crl2_matchheight;
      $.fn.matchHeight._throttle = _base.throttle_update_fluid;
    }
  };
})(jQuery);
