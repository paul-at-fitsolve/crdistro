(function ($) {

/**
 * JS related to the tabs in the Panels slider.
 */
Drupal.behaviors.panelsSlider = {
  attach: function (context) {

    $.each(Drupal.settings.panelsSlider, function(i, panelsSlider){

      var jsSlider = $("."+panelsSlider.flexsliderIdentifier);
      var nav = (panelsSlider.direction_nav == 'true' ? true : false);
      var pausePlay = (panelsSlider.pause_play == 'true' ? true : false);
      var autoPlay = (panelsSlider.auto_play == 'true' ? true : false);
      var nav_text_prev = "";
      var nav_text_next = "";
      var flexsliderSelector = "." + panelsSlider.flexsliderSlideClass + " > .slider-content";
      var flexsliderIdentifier = panelsSlider.flexsliderIdentifier;

      if (nav == true){
        nav_text_prev = panelsSlider.direction_nav_text_prev;
        nav_text_next = panelsSlider.direction_nav_text_next;
      }

      var options = {
        selector: flexsliderSelector,
        animation: panelsSlider.transition,
        animationSpeed: 400,
        directionNav: nav,
        animationLoop: true,
        useCSS: true,
        startAt: parseInt(panelsSlider.open_slide),
        //prevText: "<i class=\"icon-arrow-left\"></i>",
        prevText: nav_text_prev,
        nextText: nav_text_next,
        pausePlay: pausePlay,
      }

      // Add more options if present
      if(typeof Drupal.settings.panelsSliderExtend !== "undefined" && typeof Drupal.settings.panelsSliderExtend[flexsliderIdentifier] !== "undefined"){
        var moreOptions  = Drupal.settings.panelsSliderExtend[flexsliderIdentifier];
        options = $.extend( options, moreOptions );
      }

      try{
        jsSlider.flexslider(options);
        if(!autoPlay) jsSlider.flexslider("pause");
      }
      catch(e){
        alert('An error has occurred (Panels slider) : '+e.message)
      }

  });

  }
};

})(jQuery);
