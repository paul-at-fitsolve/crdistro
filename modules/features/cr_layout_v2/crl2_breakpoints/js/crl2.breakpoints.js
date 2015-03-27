(function ($) {

/**
 * crl2Breakpoints JS Behavior
 * This behavior actively sets two variables:
 * 
 * Drupal.settings.crl2.breakpointActive
 * The active breakpoint the current user is on
 * 
 * Drupal.settings.crl2.breakpointFrom
 * The previous breakpoint the user just came from
 * 
 * @type {Object}
 */
  Drupal.behaviors.crl2Breakpoints = {
    attach: function (context, settings) {
      _base = Drupal.behaviors.crl2Breakpoints;
      
      // Attached the breakpoint handler once
      $('body').once('crl2Breakpoints', _base.attachBreakpointHandler);
    },
    attachBreakpointHandler: function() {
      
      // Set the default breakpoint
      Drupal.settings.crl2.breakpointActive = null;

      // Stop Enquire before continuing e.g. IE8
      if(typeof enquire == 'undefined') {
        Drupal.settings.crl2.breakpointFrom = Drupal.settings.crl2.breakpointActive = 'md';
        return;
      }

      // Cache the set active functions here so we can reuse them later
      var setActiveXS = function(){ Drupal.behaviors.crl2Breakpoints.setActiveBreakpoints('xs'); };
      var setActiveSM = function(){ Drupal.behaviors.crl2Breakpoints.setActiveBreakpoints('sm'); };
      var setActiveMD = function(){ Drupal.behaviors.crl2Breakpoints.setActiveBreakpoints('md'); };
      var setActiveLG = function(){ Drupal.behaviors.crl2Breakpoints.setActiveBreakpoints('lg'); };
      
      // We use the exception handler in case enquire.js is not available
      try {
        // Attach enquire JS events
        enquire
          .register(Drupal.settings.crl2.breakpoints.xs, {
            match : setActiveXS
          })
          .register(Drupal.settings.crl2.breakpoints.sm, {
            match : setActiveSM
          })
          // Notice this one passes in true for shouldDegrade option
          // this query used IF the browser is incapable of understanding CSS3 media queries, 
          // then always consider this query a match.
          // Source: http://wicky.nillia.ms/enquire.js/
          .register(Drupal.settings.crl2.breakpoints.md, {
            match : setActiveMD
          }, true)
          .register(Drupal.settings.crl2.breakpoints.lg, {
            match : setActiveLG
          });
      }
      catch(err) {
        // Output the error
        if (window.console) {
          console.log(err);
        }
      }
    },

    /**
     * Helper function to set the active breakpoint
     * @param {string} bp
     */
    setActiveBreakpoints: function(bp) {
      // Preserve the previous breakpoint
      Drupal.settings.crl2.breakpointFrom = Drupal.settings.crl2.breakpointActive;

      // Set the active and current breakpoint
      Drupal.settings.crl2.breakpointActive = bp;
    }
  };

})(jQuery);