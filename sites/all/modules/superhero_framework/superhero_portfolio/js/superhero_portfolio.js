(function($){
	Drupal.behaviors.superhero_portfolio = {
		attach: function(context,settings) {
			$('.superhero-portfolio').each(function() {
				var viewID = $(this).attr('id');
							
				var $source = $('ul.filter-source');
				var $destination = $('div.filter-destination');
				
				if ($destination.get(0)) {
					$(window).load(function(){
						$destination.isotope({
							itemSelector: 'div.element',
							layoutMode: 'fitRows'
						});
						
						$source.find('a').click(function(e){
							e.preventDefault();
							var $this = $(this);
							
							$source.find('li a.active').removeClass('active');
							$(this).addClass('active');
							
							$destination.isotope({
								filter: $this.attr('data-option-value')
							});
							return false;
						});
						
					});
				}
			});
		}
	};
})(jQuery);