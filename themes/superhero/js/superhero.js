(function($){	
	function animations() {
		$("[data-appear-animation]").each(function(){
			var $this = $(this);
			
			$this.addClass('appear-animation');
			if ($(window).width() > 767) {
				$this.appear(function(){
					var delay = ($this.attr('data-appear-animation-delay') ? $this.attr("data-appear-animation-delay") : 1);
					if (delay > 1) $this.css('animation-delay',delay + 'ms');
					$this.addClass($this.attr('data-appear-animation'));
					setTimeout(function(){
						$this.addClass('appear-animation-visible');
					},delay);
				},{accX: 0,accY: 0,one:false});
			} else {
				$this.addClass('appear-animation-visible');
			}
		});
	}

	$(document).ready(function(){
		animations();
		
		// Accordion Shortcode
		if ($('#sup-accordion .accordion-toggle').hasClass('open')) {
			$('#sup-accordion .accordion-toggle').find('i').attr('class','icon-minus-sign');
		} else {
			$('#sup-accordion .accordion-toggle').find('i').attr('class','icon-plus-sign');
		}
		
		$('.accordion-toggle h3 a').click(function(){
			if (!($(this).parents('.toggles').hasClass('accordion'))) {
				var $toggle = $(this).parents('.accordion-toggle');
				$(this).parents('.accordion-toggle').parent().find('.accordion-toggle').not($toggle).removeClass('open').find('> div').slideUp(300);
				$(this).parents('.accordion-toggle').parent().find('.accordion-toggle').not($toggle).find('i').removeClass('icon-minus-sign').addClass('icon-plus-sign');
				$(this).parents('.accordion-toggle').find('> div').slideToggle(300);
				$(this).parents('.accordion-toggle').toggleClass('open');
				
				// Switch Icon
				if ($(this).parents('.accordion-toggle').hasClass('open')) {
					$(this).find('i').attr('class','icon-minus-sign');
				} else {
					$(this).find('i').attr('class','icon-plus-sign');
				}
			}
			return false;
		});
		
		//accordion start open
		$('.accordion-toggle').find('> div').hide();
 		$('.accordion-toggle').first().addClass('open').find('> div').show();
 		$('.accordion-toggle').first().find('i').attr('class','icon-minus-sign');
		
		// Alert
		$('.alert').alert();
		
		// Carousel
		$('.carousel').find('.item').first().addClass('active');
		$('.carousel').carousel();
		
		// Menu
		$('li.dropdown').hover(function(){
			$(this).stop(true,true).addClass('open');
		},function() {		
			$(this).stop(true,true).delay(200).removeClass('open');
		});
		
		$('li.dropdown').find('a').click(function(){
			window.location = $(this).attr('href');
		});	
		//Tooltip
		$('.superhero-tooltip').tooltip({html:true});
		//Video
		var videoRatio = 1.777;
		$('.superhero_video').each(function(){
			var $this = $(this);
			$this.find('iframe').width($this.width()).height($this.width()/videoRatio);
		});
		$(window).bind('resize', function(){
			$('.superhero_video').each(function(){
				var $this = $(this);
				$this.find('iframe').width($this.width()).height($this.width()/videoRatio);
			});
		})
		//$('.supperhero-gallery')
		// MD Slider fix colours
		$('.md-object').each(function(){
			var $obj = $(this);
			$obj.find('p').each(function(){
				$(this).css('color',$obj.css('color'));
			});
		});

	});
})(jQuery);