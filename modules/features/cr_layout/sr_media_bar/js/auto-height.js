/**
 * Comic Relief Auto Height Plugin
 */
(function ($) {
Drupal.behaviors.cr_auto_height = {
  config: {
    autoheightselector: '.autoheight-run',
    resizableElementSelector: '.auto-height__resizable'
  },

  $autoheightregion: null,
  $childDivs: null,
  $parentWrapper: null,

  ran: false,

  attach: function(context, settings) {
    var _base = Drupal.behaviors.cr_auto_height;

    // Extends our default config with cr_auto_height settings
    if(Drupal.settings.cr_auto_height) {
      _base.config = $.extend(_base.config, Drupal.settings.cr_auto_height);
    }

    // Listen to document for responsivelayout event, then run height calculations
    $(document).on('responsivelayout', {'context':context}, _base.responsiveLayoutHandler);

    // This is a fallback if responsive live event has triggered before we can even capture it!
    var responsiveNotRun = function(context){
      $(_base.config.autoheightselector, context).once('autoheight', _base.run);
    };
    setTimeout(responsiveNotRun, 800, context);
  },

  /*
   * Core Initaliser
   */
  responsiveLayoutHandler: function(event, layout) {
    var _base = Drupal.behaviors.cr_auto_height;
    setTimeout(function(context){
      $(_base.config.autoheightselector, context).once('autoheight', _base.run);
    }, 500, event.data.context);
  },


  /*
   * Core Initaliser
   */
  run: function() {
    var _base = Drupal.behaviors.cr_auto_height;
    _base.ran = true;
    var breakpoint = null, heightNeeded = 0, height40percent = 0, height60percent = 0, panelHeights = [], resizableElementHeights = [], hasResizableElements = 0;

    try {
        breakpoint = Drupal.omega.getCurrentLayout();
    }
    catch(err) {
        console.log('Error: Cant get current layout! Defaulting to normal.');
        breakpoint = 'normal';
    }

    // Exception to not calculate height if breakpoint is mobile
    if(breakpoint == 'mobile' || breakpoint == 'narrow')
      return;

    // Cache jQuery Objects
    _base.$autoheightregion = $(this);
    _base.$childDivs = _base.$autoheightregion.find('> div');
    _base.$parentWrapper = _base.$autoheightregion.parents('.container-24');

    heightNeeded = _base.$parentWrapper.outerHeight(); // Not great, but this fixes the descrepency

    height40percent = parseInt((heightNeeded/100) * 40, 10);
    height60percent = parseInt((heightNeeded/100) * 60, 10);


    // Simply check the class and assign either a 60/40 or 40/60
    if(_base.$autoheightregion.hasClass('auto-height__6040')) {
      panelHeights[0] = height60percent;
      panelHeights[1] = height40percent;
    } else if(_base.$autoheightregion.hasClass('auto-height__6040')) {
      panelHeights[0] = height40percent;
      panelHeights[1] = height60percent;
    } else {
      height100percent = parseInt(heightNeeded, 10);
      panelHeights[0] = height100percent;
    }

    hasResizableElements = $(_base.config.resizableElementSelector, _base.$childDivs).length;

    var offsetsHeight = 0, i = 0;

    if(hasResizableElements){
      var resizableElementHeight = 0;
      // Because we have a resizable element, we need to calculate the difference
      for(i=0; i<_base.$childDivs.length; i++) {
        resizableElementHeight = $(_base.config.resizableElementSelector, _base.$childDivs[i]).outerHeight();
        resizableElementWrapperHeight = $('.pane-content', _base.$childDivs[1]).outerHeight(); // $(_base.$childDivs[i]).outerHeight();
        resizableElementOffsetHeight = (resizableElementWrapperHeight - resizableElementHeight); // This is the height of the title, footer etc. Also add 20px bottom margin
        resizableElementHeights[i] = panelHeights[i] - resizableElementOffsetHeight;
        offsetsHeight += resizableElementOffsetHeight;

        // Add margin bottom except for last one.
        if(i !== _base.$childDivs.length) {
          resizableElementHeights[i] -= 19;
        }
      }
    }


    for(i=0; i<panelHeights.length; i++) {
      if(resizableElementHeights[i]) {
        $(_base.config.resizableElementSelector, _base.$childDivs[i]).css({
          'transition': 'height 300ms ease',
          'height':resizableElementHeights[i]+'px',
        });
      } else {
        $(_base.$childDivs[i]).css({'height':panelHeights[i]+'px'});
      }
    }

  },
}; // End Drupal.behaviors.cr_auto_height

})(jQuery);