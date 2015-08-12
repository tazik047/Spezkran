var input_id;
jQuery(document).ready(function(){
	var img_changed =function () {
		jQuery('img.'+input_id).attr('src',jQuery(this).val());
	}
	var t = jQuery('input[name=logo]');
	t.attr('id','path_to_logo');
	t.change(img_changed);
	jQuery('#bt_for_logo').click(function(e){
		input_id = 'path_to_logo';
		window.open('/imce?app=ostpc|url@path_to_logo|sendto@myFileHandler', '', 'width=760,height=560,resizable=1');
		e.preventDefault();
	});
	t = jQuery('input[name=background]');
	t.attr('id','path_to_background');
	t.change(img_changed);
	jQuery('#bt_for_bg').click(function(e){
		input_id = 'path_to_background';
		window.open('/imce?app=ostpc|sendto@myFileHandler|url@path_to_background', '', 'width=760,height=560,resizable=1');
		e.preventDefault();
	});
});
function myFileHandler (file, win) {
	jQuery('#'+input_id).val(file.url).change();//insert file url into the url field
	win.close();//close IMCE
}