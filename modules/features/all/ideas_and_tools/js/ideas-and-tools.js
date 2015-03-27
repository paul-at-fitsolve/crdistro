(function($) {

  Drupal.behaviors.ideas_and_tools = {
    attach: function (context, settings) {

      var downloadableView = $('.fundraise-tools');
      var downloadableViewList = $('.views-column', downloadableView);

      var ideaView = $('.ideas-tips');
      var ideaViewItem = $('.item-column', ideaView);
      var associatedToolDiv = $('.associated-tools-wrapper');
      var associatedTool = $('.associated-tools');

    // only call jquery function once
    $('.ideas-tips', context).once('ideas_and_tools', function(){

      // initialise
      $('.item-column').wrapAll( "<div class='item-row' />");
      $('.item-row').wrap("<div id='idea-tips-item'></div>");
      ideaViewItem.each(function(i){
         $(this).attr('col', (i+1));
      });   

      // ------ Touch devices only ----------- //
      if (('ontouchstart' in window) || window.DocumentTouch && document instanceof DocumentTouch ) {
      // ------ All devices exclude touch devices ----------- //
      } else {
        ideaViewItem.on({
          mouseenter: function(event) {
            $(this).addClass('hover');
          },
          mouseleave: function(event) {
            $(this).removeClass('hover');
          }
        });
      }

      // ------ All devices ----------- //
      ideaViewItem.on({
        click: function(event) {

         // wait when all animation stops 
         if($(".item-column:animated").length == 0 && 
            $(".views-field-title:animated").length == 0 &&
            $(".views-field-body:animated").length == 0 &&
            $(".fr-icons:animated").length == 0) {
         
          var activeObjParent;
          var activeObjParentId;
          var activeClick = $(this);

          //var activeObj = $(this).attr('class').split(' ')[1];
          var activeAssociatedIds = $(this).find('.views-field-field-associated-downloads').children().text();
          associatedTool.find('.associated-item').remove();

                    // clone associated item from bottom list to associatedToolDiv
                    if(activeAssociatedIds.length) {
                      activeAssociatedIds = activeAssociatedIds.split(';');
                      //console.log(activeAssociatedIds);
                      
                      $.each(activeAssociatedIds, function(key, value) {
                        downloadableViewList.each(function() {
                          var item = $(this);
                          if(item.find('.tool-id').text() == value) {
                            item.addClass('associated-item');
                            item.clone(true).attr('class', 'associated-item').appendTo(associatedTool);
                          }
                        });
                      });
          
                      if(Drupal.omega.getCurrentLayout() != "mobile") {
                        var j = 6 - parseInt(activeAssociatedIds.length);
                          for(var i = 1; i <= j; i++) {
                            $('<div class="associated-item fr-holder"> &nbsp;</div>').appendTo(associatedTool);
                          }
                      } else if (Drupal.omega.getCurrentLayout() == "mobile") {
                        var j = parseInt(activeAssociatedIds.length)%2;
                        if( j != 0) {
                          $('<div class="associated-item fr-holder"> &nbsp;</div>').appendTo(associatedTool);
                        }
                      }   
          

                    }/* end - activeAssociatedIds length*/

          // ------ Mobile only ----------- //
          if(Drupal.omega.getCurrentLayout() == "mobile") {
          
            // parent div = item div
            activeObjParent = $(this);
            activeObjParentId = $(this).attr('class').split(' ')[1];

            // ------ ideas/tips box behaviour (mobile) ----------- //  
            // if alreday click
            if($('.active-item').length) {
                if($(this).hasClass('active-item')) {
                   $(this).removeClass('active-item').find('.fr-more').removeClass('open');
                   $(associatedToolDiv).slideUp("slow");
                }
                else if (!$(this).hasClass('active-item')) {
                  $('.active-item').removeClass('active-item').find('.fr-more').removeClass('open');              
                  $(associatedToolDiv).slideUp("slow", function() {
                    $(this).insertAfter(activeObjParent)
                      .slideDown("slow", function() {
                        activeClick.addClass('active-item').find('.fr-more').addClass('open');
                      });
                  });
                }    
            } /* end - active-item length */ 
            else {  
                 $(this).addClass('active-item').find('.fr-more').addClass('open');
                 $(associatedToolDiv).insertAfter(activeObjParent).slideDown("slow");
            } /* end - else - active-item length */  

          } else {
          // ------ All devices exclude mobile ----------- //
            
            // values depends on layout
              var layouts = Drupal.omega.getCurrentLayout();
              var move_box, move_icon, move_title, move_body;
              switch (layouts) { 
                case 'wide': 
                  move_box = 69;
                  move_icon = 25;
                  move_title = 25;
                  move_body = 35;
                break; 
                case 'normal': 
                  move_box = 84;
                  move_icon = 35;
                  move_title = 43;
                  move_body = 35;
                break;
                case 'narrow': 
                  move_box = 62;
                  move_icon = 25;
                  move_title = 25;
                  move_body = 25;
                break;
            }

            // get row 
            var currIndex = $(this).attr('col');
            var currRow =  Math.ceil(parseInt(currIndex) / 4);

            if(parseInt(currIndex)%4 > 0) {
              var lastOfRow = parseInt(currIndex) + (4 - (parseInt(currIndex)%4)); 
            } else {
              var lastOfRow = parseInt(currIndex);
            } 
            activeObjParent = $('.item-column[col="'+ lastOfRow +'"]');
            activeObjParentId = currRow;

            // ------ ideas/tips box behaviour (non mobile)----------- //  
            // if alreday click
            if($('.active-item').length) {
             var activeIndex = $('.active-item').attr('col');
             var activeRow =  Math.ceil(parseInt(activeIndex) / 4);
             var activeItemParent = activeRow;

             if($(this).hasClass('active-item')) { // same item
                 activeClick.find('.fr-more').removeClass('open');
                 $(associatedToolDiv).slideUp("slow")
                   .siblings('.item-column')
                   .animate({"min-height": "+=" + move_box +"px"}, "slow", function() {
                    $('.item-column').removeClass('active-item');
                 }).find(".fr-icons")
                   .animate({"top": "+=" + move_icon + "px"}, "slow")
                   .end()
                   .find(".views-field-title")
                   .animate({"top": "+=" + move_title + "px"}, "slow")
                   .end()
                   .find(".views-field-body")
                   .animate({"top": "+=" + move_body + "px"}, "slow")
                   .end()
                   .removeClass('collapse');
             }
             else if (!$(this).hasClass('active-item')) { // different item
                 if( activeItemParent == activeObjParentId ) { // same row
                  $('.item-column').removeClass('active-item');
                  $('.fr-more').removeClass('open');
                  activeClick.addClass('active-item').find('.fr-more').addClass('open');
                 }
                 else if( activeItemParent != activeObjParentId ) { // different row
                  $(associatedToolDiv).slideUp("slow", function() {
                    $(this).insertAfter(activeObjParent)
                      .slideDown("slow", function() {
                        activeClick.addClass('active-item').find('.fr-more').addClass('open');
                      }).siblings('.item-column')
                        .animate({"min-height": "-=" + move_box + "px"}, "slow")
                        .find(".fr-icons")
                        .animate({"top": "-=" + move_icon + "px"}, "slow")
                        .end()
                        .find(".views-field-title")
                        .animate({"top": "-=" + move_title + "px"}, "slow")
                        .end()
                        .find(".views-field-body")
                        .animate({"top": "-=" + move_body + "px"}, "slow")
                        .end()
                        .addClass('collapse');
    
                  }).siblings('.item-column')
                    .removeClass('active-item')
                    .find('.fr-more')
                    .removeClass('open')
                    .end()
                    .animate({"min-height": "+=" + move_box + "px"}, "slow")
                    .find(".fr-icons")
                    .animate({"top": "+=" + move_icon + "px"}, "slow")
                    .end()
                    .find(".views-field-title")
                    .animate({"top": "+=" + move_title + "px"}, "slow")
                    .end()
                    .find(".views-field-body")
                    .animate({"top": "+=" + move_body + "px"}, "slow")
                    .end()
                    .removeClass('collapse');
                 }
    
              }
    
            } /* end - active-item length */ 
            else { 
                 // if not click at all
                 activeClick.find('.fr-more').addClass('open');
                 $(associatedToolDiv).insertAfter(activeObjParent).slideDown("slow", function() {
                    activeClick.addClass('active-item');
                 }).siblings('.item-column')
                   .animate({"min-height": "-=" + move_box +"px"}, "slow")
                   .find(".fr-icons")
                   .animate({"top": "-=" + move_icon + "px"}, "slow")
                   .end()
                   .find(".views-field-title")
                   .animate({"top": "-=" + move_title + "px"}, "slow")
                   .end()
                   .find(".views-field-body")
                   .animate({"top": "-=" + move_body + "px"}, "slow")
                   .end()
                   .addClass('collapse');
    
              } /* end - else - active-item length */
            } /* end - != "mobile" */
          } /* end - click */
        } /* end - :animatied */      
      }); /* end - on */   

  }); // jquery once

      // call filterd pagination
      pagination = new $.smFilteredPagination($("#idea-tips-item"), {
          pagerItems: ".item-column", 
          pagerItemsWrapper: ".item-row", 
          pagerClass: "pager",
          pagerFooter: "item-list",
          showPagerHeader: false,
          showFirst: false,
          showLast: false, 
          itemsPerPage: 12
      });   

    }/*attach*/
  }/*behaviour*/

})(jQuery);