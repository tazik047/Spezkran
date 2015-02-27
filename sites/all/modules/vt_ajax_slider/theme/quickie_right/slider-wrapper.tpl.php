<?php
/**
  * Container theme for jquery side slide
	* Important not to change the id for the div element, otherwise the jquery and ajax script will breaks
	* the theme function calls for jquery_side_slide_get_content($content_type) api, without it the module won't work
	* You can change the order of the div element or add other div element.
	**/
?>
<?php if ($slider_title) : ?>
	<div id="slider-title"><h1 class="slider-title"><?php print $slider_title; ?></h1></div>
<?php endif; ?>

<div id="d-slide-container-wrapper">
	<div id="d-slide-container"><?php print $slider_content; ?></div>
  <?php if ($slider_preview) : ?>
  <div id="d-slide-preview"><?php print $slider_preview; ?></div>
  <?php endif; ?>
  <?php print $slider_progress_bar; ?> 
  <div id="d-slider-button-wrapper"> 
  <?php print $slider_button_right; ?><?php print $slider_button_left; ?>
  </div>
</div>