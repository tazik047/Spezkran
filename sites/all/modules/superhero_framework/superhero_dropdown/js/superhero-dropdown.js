jQuery(document).ready(function($){
	$('.superhero-dropdown').find('li.expanded').each(function(){
		var $submenu = $(this).find('>ul');
		//var $arrow = $('<i class="icon-angle-right menu-arrow"></i>');
		var $arrow = $('<i class="fa fa-angle-right menu-arrow"></i>');
		$arrow.click(function(){
			$(this).toggleClass('fa-angle-right fa-angle-down');
			$submenu.toggleClass('open');
			return false;
		})
		$submenu.before($arrow);
	});
	$('.superhero-mobile-menu-toggle').click(function(){
		$('.superhero-dropdown').toggleClass('open');
	})
})