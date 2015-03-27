
(function ($) {

	$(document).ready(function(){

		var questionHeadings = [];
		var questionTopics = [];

		/* 
		/ Grabs all h3 text from tab-content Pane elements, uses for element IDs and Typeahead.js suggestions
		*/
		$( ".tab-content h3" ).each(function(){
			questionHeadings.push($(this).text());
			$(this).attr("id", stripPunctuation($(this).text()));
		});

		/* 
		/ Grabs all h2 text from tab-content Pane elements, uses for element IDs, tab switching and select box option
		*/
		$( ".tab-content h2" ).each(function(){
			questionTopics.push( $(this).text() );
			$(this).attr("id", stripPunctuation( $(this).text() ));
			var o = new Option( "option text" , $(this).text() );
			$(o).html( $(this).text() );
			//$(".quickfinder-select").append(o);
		});

		// Implements Typeahead.js and adds class to ensure generated text input box is styled appropriately
		$(".quickfinder-box").typeahead({
			  local: questionHeadings
		});

		$('.tt-hint, .tt-dropdown-menu').addClass('text-input');

		// TODO: IMPROVE THIS
		$(".quickfinder-box").keypress(function(e) {
			var event = e || window.event;
			var charCode = event.which || event.keyCode;
			if ( charCode == '13' ) {
				submitSearch( $(".quickfinder-box").val() );
			}
		});

		function submitSearch(searchTerm){

			if (questionHeadings.indexOf(searchTerm) > -1) {

       			var $selectedTab = $(".tab-content").find('h3:contains("'+searchTerm+'")').closest('.tab-content');
       			var $selectedButton = $('.tab-link[href="#'+$selectedTab.attr('id')+'"]');
				$selectedButton.trigger( "click" );

				searchTerm = stripPunctuation(searchTerm);

       			if (searchTerm) {	
					$('html, body').animate({
					    'scrollTop':   $("#"+searchTerm).offset().top },500 );
				} else {
					return false;
				}
			}
		}
	});

	function stripPunctuation (inputstring) {
		return inputstring.replace(/\s/g,"-").replace(/[^a-zA-Z0-9\-]+/g,'');
	};

})(jQuery);






