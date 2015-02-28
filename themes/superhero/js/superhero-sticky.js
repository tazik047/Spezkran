(function($) {
	$.fn.spsticky = function(options) {
		this.each( function() {
			var $this = $(this);
			$this.data('offset-top',$this.data('offset-top')||$this.offset().top);
			$this.data('max-height',$this.outerHeight());
			var $wrapper = $('<div>').addClass('sticky-wrapper').height($this.outerHeight());
			$this.wrap($wrapper);
			var $stickywrapper = $this.parents('.sticky-wrapper');
			setInterval(function(){
				$stickywrapper.height($this.outerHeight());
			},10);
			$(window).scroll(function(){
				if($(window).width() < 992 || $('body').hasClass('header-overlay')) return;
				var offsetTop = $(window).scrollTop();
				if (offsetTop > $this.data('offset-top')){
					$this.addClass('fixed');
					setTimeout(function(){$this.addClass('fixed-transition')},10);
				}else{
					$this.removeClass('fixed');
					setTimeout(function(){$this.removeClass('fixed-transition')},10);
				}
			}).resize(function(){
				$this.removeClass('fixed fixed-transition').data('offset-top',$this.offset().top);
				$(window).scroll();
				if($(window).width() < 992 || $('body').hasClass('header-overlay')){
					$this.removeClass('fixed fixed-transition');
				}
			}).scroll().resize();
		});
	}
	$(document).ready(function(){
		$('.superhero-sticky').spsticky();
	});
}(jQuery));