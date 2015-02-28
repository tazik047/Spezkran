<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<div id="<?php print $view_id; ?>" class="superhero-portfolio supcolumns<?php echo $columns; ?>">
	<?php if (isset($categories)): ?>
	<div class="portfolio-filters">
		<ul id="filters" class="filter-source option-set clearfix" data-option-key="filter">
			<li><a class="active" href="#" data-option-value="*">Show All</a></li>
			<?php foreach($categories as $key => $c): ?>
				<li>
					<a href="#" data-option-value=".<?php echo $key; ?>"><?php echo $c; ?></a>
				</li>
			<?php endforeach; ?>
		</ul>
	</div>
	<?php endif; ?>
	<div class="filter-destination portfolio-container">
		<?php foreach ($rows as $id => $row): ?>
			<div<?php if ($classes_array[$id]) { print ' class="' . $classes_array[$id] .'"';  } ?>>
				<?php print $row; ?>
			</div>
		<?php endforeach; ?>
	</div>
</div>


