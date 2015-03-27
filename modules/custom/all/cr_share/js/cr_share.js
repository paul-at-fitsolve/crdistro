(function ($) {
  Drupal.behaviors.cr_share = {
    namespace : 'cr_share',
    config : {
      updateTime : 100
    },

    $instances : null,
    $win : null,

    socialised : {},
    updateTimeout : null,

    activateInView : false,

    attach: function (context, settings) {
      var _base = Drupal.behaviors.cr_share;
      _base.setupSocialiteJs.call(context);
    },

    /*
     * Sets up socialite JS for us
     */
    setupSocialiteJs: function() {
      var _base = Drupal.behaviors.cr_share;
      var context = this;

      // Extends our default config with custom settings
      _base.config = $.extend(_base.config, Drupal.settings[_base.namespace]);

      // Set variables
      _base.$instances = $('.socialitejs', context);
      _base.activateInView = (_base.config.touch_activate_in_view && Modernizr && Modernizr.touch) ? true : false;

      // Setup Socialite with our extended Config
      Socialite.setup(_base.config.socialitejsConfig);

      if(_base.activateInView) {
        _base.$win = $(window);
        _base
          .$win
          .on('resize', _base.EH_onUpdate)
          .on('scroll', _base.EH_onUpdate);

        setTimeout(_base.CB_loadSocialiteJsInView, 100);
      } else {
        _base
          .$instances
          .once('cr_share')
          .one(_base.config.mouseEvent, _base.EH_loadSocialiteJs);
      }
    },

    /*
     * Loads Socialite JS
     * Event handler
     */
    EH_loadSocialiteJs : function(e) {
      e.preventDefault();
      Socialite.load(this);
    },

    /*
     * Loads Socialite JS which is in view
     * Callback one timer has ran
     */
    CB_loadSocialiteJsInView: function() {
      var _base = Drupal.behaviors.cr_share;

      // viewport bounds
      var wT = _base.$win.scrollTop(),
        wL = _base.$win.scrollLeft(),
        wR = wL + _base.$win.width(),
        wB = wT + _base.$win.height();
      // check which articles are visible and socialise!
      for (var i = 0; i < _base.$instances.length; i++) {
        if (_base.socialised[i]) {
          continue;
        }
        // article bounds

        var art = $(_base.$instances[i]),
          aT = art.offset().top,
          aL = art.offset().left,
          aR = aL + art.width(),
          aB = aT + art.height();
        // vertial point inside viewport
        if ((aT >= wT && aT <= wB) || (aB >= wT && aB <= wB)) {
          // horizontal point inside viewport
          if ((aL >= wL && aL <= wR) || (aR >= wL && aR <= wR)) {
            _base.socialised[i] = true;
            Socialite.load(_base.$instances[i]);
          }
        }
      }
    },

    /*
     * Handle on update event (Resize or scroll)
     * Only triggered if time has ran
     */
    EH_onUpdate: function() {
      var _base = Drupal.behaviors.cr_share;
      if (_base.updateTimeout) {
        clearTimeout(_base.updateTimeout);
      }
      _base.updateTimeout = setTimeout(_base.CB_loadSocialiteJsInView, _base.config.updateTime);
    }
  };
}(jQuery));