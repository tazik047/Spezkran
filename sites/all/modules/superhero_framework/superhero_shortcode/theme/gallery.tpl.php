<?php if($filter == 'yes'):?>
<?php $html_id = drupal_html_id('superhero_gallery');?>
<div id="<?php print $html_id;?>">
<div class="gallery-filters btn-group">
	<a href="#" class="btn btn-default active" data-filter="*"><?php print t('Show All');?></a><?php foreach($categories as $category):?><a href="#" class="btn btn-default" data-filter=".<?php print drupal_html_class($category);?>"><?php print $category;?></a><?php endforeach;?>
</div>
<?php endif;?>
<div class="supperhero-gallery"><div style="margin:5px;"><?php print $content;?></div></div>
</div>
<script type="text/javascript">
	jQuery(document).ready(function($){
		var itemwidth = Math.floor(100/<?php print $cols;?>)+'%';
		$('#<?php print $html_id;?> .superhero-gallery-item').width(itemwidth);
		var $gallery = $('#<?php print $html_id;?> .supperhero-gallery');
		$gallery.isotope({
			// options
			itemSelector : '.superhero-gallery-item',
			layoutMode : 'fitRows'
		});
		
		var $filter = $('#<?php print $html_id;?> .gallery-filters');
		$filter.find('a').click(function(){
			var selector = $(this).attr('data-filter');
			$filter.find('a').removeClass('active');
			$(this).addClass('active');
			
			$gallery.isotope({ filter: selector });
			return false;
		});
	})
</script>