<?php

/**
 * Preprocess functions of BX Slider
 */

function _views_slideshow_preprocess_views_bx_slideshow(&$vars) {
	$options = $vars['options'];
	$view = $vars['view'];
	
	$view_id = $view->name . '-' . $view->current_display;
	$vars['view_id'] = $view_id;
	$vars['sliderows'] = $options['rows'];
	$library = libraries_get_libraries();
	if (isset($library['bxslider'])) {
		// Include bxSlider
		$path = $library['bxslider'];
		drupal_add_css($path . '/jquery.bxslider.css');
		drupal_add_js($path . '/jquery.bxslider.js');
	}
	//print_r($options);
	$js_settings = array(
		'responsiveSlideshow' => array(
			$view_id => array(
				'mode' => $options['mode'],
				'speed' => $options['speed'],
				'auto' => ($options['auto']) ? true : false,
				'pause' => $options['pause'],
				'infiniteLoop' => ($options['infinite']) ? true : false,
				'slideMargin' => ($options['slidemargin'])? (int)$options['slidemargin']: 20,
				'startSlide' => $options['startslide'],
				'randomStart' => ($options['randomstart']) ? true : false,
				'pager' => ($options['pager']) ? true : false,
				'controls' => ($options['controls']) ? true : false,
				'minSlides' => $options['minslides'],
				'maxSlides' => $options['maxslides'],
				'moveSlides' => $options['moveslides'],
				'slideWidth' => $options['slidewidth'],
				'prevText' =>'<i class="fa fa-angle-left"></i>',
				'nextText' =>'<i class="fa fa-angle-right"></i>'
			),
		),
	);
	drupal_add_js($js_settings,'setting');
	// Add responsive js
	$responsive_js_path = drupal_get_path('module','responsive_slideshow') . '/js/responsive_slideshow.js';
	drupal_add_js($responsive_js_path);

	template_preprocess_views_view_unformatted($vars);
}