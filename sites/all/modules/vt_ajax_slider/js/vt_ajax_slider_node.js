// build for Drupal 7, using jQuery 1.4+
// Version 1.0

jQuery(document).ready(function ($) {
  var selected = $('#edit-vtslider-slidertype select');
  if (selected.val() == 'vt_ajax_slider') {
    $('#edit-vtslider-title').show();
    $('#edit-vtslider-body').show();
    $('#edit-vtslider-preview-title').show();
    $('#edit-vtslider-preview-body').show();
    $('#edit-vtslider-image').show();
    $('#edit-vtslider-preview-image').show();
  }
  selected.change(function() {
  if (selected.val() == 'vt_ajax_slider') {
    $('#edit-vtslider-title').show();
    $('#edit-vtslider-body').show();
    $('#edit-vtslider-preview-title').show();
    $('#edit-vtslider-preview-body').show();
    $('#edit-vtslider-image').show();
    $('#edit-vtslider-preview-image').show();
  }
  });
});
