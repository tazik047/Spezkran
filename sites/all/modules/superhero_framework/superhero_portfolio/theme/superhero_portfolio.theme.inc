<?php

function _views_slideshow_preprocess_views_superhero_portfolio(&$vars) {
	$view = $vars['view'];
	$options = $vars['options'];
	$use_filter = $options['use_filter'];
	$vocab = $options['filter_vocabulary'];
	$columns = $options['columns'];
	
	$vars['view_id'] = $view->name . '-' . $view->current_display;
	$vars['columns'] = $columns;
	
	$library = libraries_get_libraries();
	if (isset($library['isotope'])) {
		$path = $library['isotope'];
		drupal_add_css($path . '/jquery.isotope.css');
		drupal_add_js($path . '/jquery.isotope.js');
	}
	
	$module_path = drupal_get_path('module','superhero_portfolio');
	drupal_add_css($module_path . '/css/superhero_portfolio.css');
	
	$js_settings = array(
		'superheroPortfolio' => array(
			$vars['view_id'] => array(
				'columns' => $columns
			)
		)
	);
	drupal_add_js($js_settings,'setting');	
	drupal_add_js($module_path . '/js/superhero_portfolio.js');
	
	// Get list of filters
	if ($use_filter) {
		$categories = array();
		$taxonomies = taxonomy_get_tree($vocab);
		foreach($taxonomies as $tax) {
			if ($tax->parents[0] == 0) {
				$key = _superhero_portfolio_class_string($tax->name);
				$categories[$key] = $tax->name;
			}
		}
		$vars['categories'] = $categories;
	}

	template_preprocess_views_view_unformatted($vars);
}