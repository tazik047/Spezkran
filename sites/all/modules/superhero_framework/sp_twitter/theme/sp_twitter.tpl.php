<?php
	$items = $variables['items'];
?>
<div class="sp-twitter">
<?php foreach($items['tweets'] as $tweet):?>
<div class="sp-tweet clearfix">
	<?php if($items['options']['sp_twitter_block_avatar'] == 'icon'):?>
		<i class="fa fa-twitter left"></i>
	<?php elseif($items['options']['sp_twitter_block_avatar'] == 'profile'):?>
		<span class="sp-avatar left"><img src="<?php print $tweet->avatar;?>" alt=""></span>
	<?php endif;?>
	<div class="content">
		<span class="sp-user">
			<a target="_blank" href="http://www.twitter.com/<?php print $items['name'];?>" style="text-decoration: none;"><?php print $tweet->name;?></a>
		</span> 
		<span class="sp-created" style="font-size: smaller;">(<?php print $tweet->created;?>)</span>
		<div class="sp-text">
			<?php print $tweet->text;?>
		</div>
		</div>
</div>
<?php endforeach;?>
</div>
<script type="text/javascript">
	jQuery(document).ready(function($){
		$('.sp-twitter').bxSlider({
			mode: '<?php print $items['options']['sp_twitter_carousel_mode'];?>',
			slideMargin: 5,
			pager: false,
			moveSlides: 1,
			auto: true,
			minSlides: <?php print $items['options']['sp_twitter_carousel_minslides']?>,
			maxSlides: <?php print $items['options']['sp_twitter_carousel_maxslides']?>,
			controls: <?php print $items['options']['sp_twitter_carousel_controls'];?>,
			nextText:'<i class="fa fa-angle-right"></i>',
			prevText:'<i class="fa fa-angle-left"></i>',
		});
	})
</script>