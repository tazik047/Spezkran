
<div class="d-slide-preview">
<div class="slider-preview-wrapper">
<?php if (isset($slider_imagethemed_preview)) : ?><div class="slider-preview-image"><?php print $slider_imagethemed_preview; ?></div><?php endif; ?>
 <?php if (isset($slider_preview_body) || isset($slider_preview_title)) : ?>
	<div class="slider-preview-content">
  	<?php if (isset($slider_preview_title)) : ?><h1><?php print $slider_preview_title; ?></h1><?php endif; ?>
    <?php if (isset($slider_preview_body)) : ?><div class="slider-preview-body"><?php print $slider_preview_body; ?></div><?php endif; ?>
  </div> 
	<?php endif; ?>
 </div>
</div>