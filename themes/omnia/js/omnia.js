jQuery(document).ready(function($){
	$('.portfolio-item').each(function(){
		$(this).hoverdir();
	});
	$('.section').not('#section-bottom, #section-footer, #section-header').css({
		position: 'relative',
		zIndex: 1
	}).each(function(){
		var bcolor = $(this).css('backgroundColor');
		$(this).attr('bco',bcolor);
		if(bcolor == 'undefined' || bcolor == 'transparent'){
			$(this).css('backgroundColor','#fff');
		}
	});
	$('#section-bottom').prev().addClass('before-bottom-fixed');
	$('#section-bottom, #section-footer').wrapAll('<div class="bottom-fixed">');
	setInterval(function(){
		if($(window).width()>=992){
			$('.before-bottom-fixed').css({
				marginBottom: $('.bottom-fixed').height()
			});
		}else{
			$('.before-bottom-fixed').css({
				marginBottom: 0
			});
		}
	},500);
})