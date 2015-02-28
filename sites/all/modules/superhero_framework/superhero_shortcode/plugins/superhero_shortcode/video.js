jQuery(document).ready(function($){
	$('.superhero_video').each(function(){
		var ratio = 1.78;
		var w = $(this).width();
		var h = w/ratio;
		$(this).height(h);
		$(this).find('iframe').width('100%').height('100%');
	})
})