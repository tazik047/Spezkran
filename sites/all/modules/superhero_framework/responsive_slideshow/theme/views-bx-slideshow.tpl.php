<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<div id="<?php print $view_id; ?>" class="views-bx-slideshow">
	<?php for($i = 0; $i < count($rows); $i+=$sliderows):?>
		<div class="slide<?php if (isset($classes_array[$id])) { print " ".$classes_array[$id];  } ?>">
			<?php for($j=$i; $j<$i+$sliderows; $j++):?>
			<?php if($rows[$j]) print $rows[$j];?>
			<?php endfor;?>
		</div>
	<?php endfor;?>
</div>