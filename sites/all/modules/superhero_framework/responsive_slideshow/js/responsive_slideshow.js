(function($){
	// Responsive Slideshow
	Drupal.behaviors.responsive_slideshow = {
		attach: function(context,settings) {
			$('.views-bx-slideshow').each(function(index){
				var responsiveID = $(this).attr('id');
				var options = jmbxAdjustOptions(settings.responsiveSlideshow[responsiveID],$(this).innerWidth());
				$('#' + responsiveID).bxSlider(options);
			});
		}
	};
	
	/*Adjust bxslider options to fix on any screen*/
	function jmbxAdjustOptions(options, container_width){
		var _options = {};
		$.extend(_options, options);
		
		if((_options.slideWidth*_options.maxSlides + (_options.slideMargin*(_options.maxSlides-1))) < container_width){
			_options.slideWidth = (container_width-(_options.slideMargin*(_options.maxSlides-1)))/_options.maxSlides;
		}else{
			_options.maxSlides = Math.floor((container_width-(_options.slideMargin*(_options.maxSlides-1)))/_options.slideWidth);
			_options.maxSlides = _options.maxSlides == 0?1:_options.maxSlides;
			_options.slideWidth = (container_width-(_options.slideMargin*(_options.maxSlides-1)))/_options.maxSlides;
		}
		return _options;
	}
	
})(jQuery);