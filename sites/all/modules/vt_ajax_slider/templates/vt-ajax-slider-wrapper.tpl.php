<?php
/**
  * Container theme for vt_slider module
	* Important not to change the id for the div element, otherwise the jQuery and Ajax script will breaks
	* You can change the order of the div element or add other div element.
	**/
?>

<div id="d-slide-container-wrapper" class="<?php print $animation_mode; ?>">
	<?php if (isset($slider_content)) : ?><div id="d-slide-container"><?php print render($slider_content); ?></div><?php endif; ?>
  <?php if (isset($slider_preview)) : ?><div id="d-slide-preview"><?php print $slider_preview; ?></div><?php endif; ?>
  <?php if (isset($slider_button_left)) : ?><?php print $slider_button_left; ?><?php endif; ?>
  <?php if (isset($slider_progress_bar)) : ?><?php print $slider_progress_bar; ?><?php endif; ?>
  <?php if (isset($slider_button_right)) : ?><?php print $slider_button_right; ?><?php endif; ?>
</div>