<!--<script type="text/javascript" charset="utf-8" src="/buyme/js/jquery.js"></script>-->
<script type="text/javascript" charset="utf-8" src="/buyme/js/buyme.js"></script>
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
