<?php
/**
  * Available variables :
	* Div id "d-slide-content" is connected to jQuery, please don't remove it
	* Div class "slider-content" is connected to jQuery for title animation, please don't remove it
	* $node = full node object
	* $nid = node nid
	* $owner_uid = current node user id
	* $owner_name = current node username
	* $owner_picture = current node user picture filepath
	* $path = the node path
	* $owner_link = themed link to user page
	* $slider_title = the node title
	* $slider_title_link = the themed title linked to node
	* $slider_imagepath = the delta 0 image path
	* $slider_imagethemed = the imagecache themed delta 0 image
	* $slider_imagethemed_link = the imagecace themed delta 0 image linked to node
	* $slider_body = the node body, if the trim option is selected then the output is trimmed
	**/
?>

<div class="d-slide-content">
<div class="slider-content-wrapper">
  <?php if (isset($slider_imagethemed_link)) : ?><div class="slider-image"><?php print $slider_imagethemed_link; ?></div><?php endif; ?>
  <?php if (isset($slider_body) || isset($slider_title_link)) : ?>
	 <div class="slider-content">
  	<?php if (isset($slider_title_link)) : ?><h1><?php print $slider_title_link; ?></h1><?php endif;?>
    <?php if (isset($slider_body)) : ?><div class="slider-body"><?php print $slider_body; ?></div><?php endif; ?> 
  </div> 
	<?php endif; ?>
 </div>
</div>