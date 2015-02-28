<?php

/**
 * Definition of Icon Shortcode
 */

/**
 * Implements hook_shortcode_info
 */
function _tooltip_shortcode_info(&$shortcodes) {
	$shortcodes['tooltip'] = array(
		'title' => t('Tooltip'),
		'description' => t('Create a Tooltip'),
		'process callback' => 'superhero_shortcode_tooltip',
		//'tips callback' => 'superhero_shortcode_icon_tip',
	);
	return $shortcodes;
}

/**
 * Icon Content
 */
function superhero_shortcode_tooltip($attrs, $text) {
	$attrs = shortcode_attrs(array(
			'tip' => '',
			'position' => 'top',
		),
		$attrs
	);
	return '<span data-toggle="tooltip" data-placement="'.$attrs['position'].'" class="superhero-tooltip" data-original-title="'.$attrs['tip'].'">'.$text.'</span>';
}