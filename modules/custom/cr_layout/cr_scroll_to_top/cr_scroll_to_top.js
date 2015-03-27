(function ($) {
  Drupal.behaviors.scrolltotop = {
    attach: function(context, settings) {

		$('body').bind('responsivelayout', function () {

			if (!$(this).hasClass("responsive-layout-mobile")) {
				$(window).scroll(function() {
					$(window).scrollTop() > $('.tab-contents').offset().top 
					? $('.scroll-to-top--button').fadeIn(200).css('display','block').addClass("scrolling") 
					: $('.scroll-to-top--button').fadeOut(10, function(){ $(this).css('display','none').removeClass("scrolling");} );
				});
			}
		});
    }
  };
})(jQuery);




