<!--<script type="text/javascript" charset="utf-8" src="/buyme/js/jquery.js"></script>-->
<link rel="stylesheet" href="<?php print base_path() . drupal_get_path('theme', 'boson');?>/css/magnific.css"> 
<script type="text/javascript" charset="utf-8" src="/buyme/js/buyme.js"></script>
<script type="text/javascript" charset="utf-8" src="<?php print base_path() . drupal_get_path('theme', 'boson');?>/js/magnific.js"></script>
  <div id="node-<?php print $node->nid; ?>" class="product <?php print $classes; ?> clearfix"<?php print $attributes; ?>>

    <?php print $user_picture; ?>

    <?php print render($title_prefix); ?>
    <?php if (!$page): ?>
      <h2 class="product-title"<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
    <?php endif; ?>
    <?php print render($title_suffix); ?>

    <?php if ($display_submitted): ?>
      <div class="submitted">
        <?php print $submitted; ?>
      </div>
    <?php endif; ?>
    <div class="content b1c-good"<?php print $content_attributes; ?>>
      <?php print '<div style="display:none" class = "b1c-name">'.$title.'</div>';
		hide($content['comments']);
        hide($content['links']);
		hide($content['uc_product_image']);
		hide($content['body']);
		/*unset($content['body']);
		unset($content['comments']);
        unset($content['links']);
		unset($content['uc_product_image']);
		print '<pre>';
		print_r($content);
		die();*/
	  ?>
	  <div class="blocks">
		<?php print render($content['uc_product_image']); ?>
	  </div>
	  <div class="blocks">
		<?php print render($content); ?>
		<div><button class="b1c"><?php print t('Call me');?></button></div>
		<div id="links">
			<a href="/popup.php?type=del" >Условия оплаты и доставки</a>
			<a href="/popup.php?type=cont" >Адреса и контакты</a>
		</div>
	  </div>
	  <div style="clear:both;"></div>
	  <h2 class="title-desc"><?php print t('Description').':';?></h2>
	  <hr/>
	  <?php print render($content['body']); ?>
	  
        
    </div>


    <?php
    if ($page) {
      print render($content['links']);
    }
    ?>

    <?php print render($content['comments']); ?>


  </div>
  <script>
	jQuery(document).ready(function() {
	    jQuery('#links').magnificPopup({
		  delegate: 'a',
		  removalDelay: 500,
		  type: 'ajax'		  
		});
		jQuery.extend(true, jQuery.magnificPopup.defaults, {
		  tClose: '<?php print t('Close'); ?> (Esc)', // Alt text on close button
		  tLoading: '<?php print t('Loading'); ?>...', // Text that is displayed during loading. Can contain %curr% and %total% keys
		  gallery: {
			tPrev: 'Previous (Left arrow key)', // Alt text on left arrow
			tNext: 'Next (Right arrow key)', // Alt text on right arrow
			tCounter: '%curr% of %total%' // Markup for "1 of 7" counter
		  },
		  image: {
			tError: '<a href="%url%">The image</a> could not be loaded.' // Error message when image could not be loaded
		  },
		  ajax: {
			tError: '<a href="%url%">The content</a> could not be loaded.' // Error message when ajax request failed
		  }
		});
		if(jQuery('.cloud-zoom-gallery-thumbs a').length==1)
			jQuery('.cloud-zoom-gallery-thumbs').hide();
	});
  </script>
