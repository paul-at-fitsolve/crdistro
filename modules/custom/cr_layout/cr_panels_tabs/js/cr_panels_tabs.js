(function ($) {

  /**
   * JS related to the tabs in the Panels tabs.
   */
  Drupal.behaviors.panelsTabs = {
    attach: function (context) {
      for (var id in Drupal.settings.panelsTabs) {

        var $tabObject = $('#' + id, context);
        var tabSettings = Drupal.settings.panelsTabs[id];
        var delta = 0;
        var temp = "";
        var categoryArray = [];
        var categoryArray2 = [];


        $('.tab-link', $tabObject).each(function(){
          delta++;
          //$(this).attr('id','category-'+delta);
          var temp = $(this).text().replace(/\s/g,"-").replace(/[^a-zA-Z0-9\-]+/g,'').toLowerCase();
          $(this).attr('id', temp);
          $(this).attr('onclick'," ");

          categoryArray[delta-1] = $(this).text();
          categoryArray2[delta-1] = temp;
        });

        $.each(categoryArray,function(index,value){
          $('.tabs-selectbox', $tabObject).append("<option value="+(index+1)+">"+value+"</option>");
        });

        // Adding named anchors to each question heading
        $('.rounded-pane h3', $tabObject).each(function(){
          var temp = $(this).text().replace(/\s/g,"-").replace(/[^a-zA-Z0-9\-]+/g,'').toLowerCase();
          $(this).wrap('<a class="q-heading" name="'+temp+'" />');
        });

        var nav = (tabSettings.direction_nav == 'true' ? true : false);
        var nav_text_prev = "";
        var nav_text_next = "";
        if (nav == true){
          nav_text_prev = tabSettings.direction_nav_text_prev;
          nav_text_next = tabSettings.direction_nav_text_next;
        }

        $tabObject.flexslider({
          namespace: "tabs-",
          selector: ".tab-contents > .tab-content",
          directionNav: nav,
          manualControls: "#" + id + " .tab-link",
          animation: tabSettings.transition,
          animationSpeed: 400,
          useCSS: true,
          slideshow: false,
          animationLoop: false,
          touch: false,
          startAt: parseInt(tabSettings.open_tab),
          prevText: nav_text_prev,
          nextText: nav_text_next,
          start : function(slider) {

            // Tab-contents not sizing properly on touch devices regardless of CSS,
            // this seems to be only fix
            if ( $('#flexslider-1').hasClass('tabs--button-style') ) {
              var newHeight = String($('.tabs-active-slide').height());
              $('.tab-contents').css('height',newHeight + 'px');
            }

            if(Drupal.omega.getCurrentLayout() == "mobile") {
              $('.tabs-selectbox').change(function() {
                slider.flexAnimate((this.value -1));
              });
            }
            
            var param = document.URL.split('#')[1];

            if (param) {
              var anchor = param.split('?')[0];
              var tabName = param.split('?')[1];
              // Triggers relevant tab-button
              if (tabName) { 
                slider.flexAnimate( categoryArray2.indexOf(tabName) );
              }

              if (anchor) {
                // Crummy fix to sort out bug related to scrolling to
                // anchors before they're fully loaded and displayed, and also retain tabname for 'back' browsing
                setTimeout(function (){

                  location.hash = "#" + anchor;

                  setTimeout(function (){
                    window.location.href = window.location.href + "?" + tabName;}, 1500);
                }, 1500);
              }
            }
          },

           after : function(slider) {
            // Tab-contents not sizing properly on touch devices regardless of CSS,
            // this seems to be only fix
            if ( $('#flexslider-1').hasClass('tabs--button-style') ) {
              var newHeight = String($('.tabs-active-slide').height());
              $('.tab-contents').css('height',newHeight + 'px');
            }
           },
        });
    
        // Required when accessing a tab/question-heading from the same page
        $( ".rounded-pane .main-content a:not([class='scroll-to-top--button'],[class='contextual-links-trigger'],[class='q-heading'],[target='_blank'],[target='_self']), #block-menu-menu-footer-menu a[href*='tab-top?']").bind( "click", function() {
          window.location.href = $(this).attr('href');
          window.location.reload();
        });
      }
    }
  };
})(jQuery);
