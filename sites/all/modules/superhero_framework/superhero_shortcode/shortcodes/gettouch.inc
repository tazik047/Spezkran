<?php

/**
 * Definition of Gettouch Shortcode
 */

/**
 * Implements hook_shortcode_info
 */
function _gettouch_shortcode_info(&$shortcodes) {
	$shortcodes['gettouch'] = array(
		'title' => t('Gettouch'),
		'description' => t('Create a Font Awesome Gettouch'),
		'process callback' => 'superhero_shortcode_gettouch',
		'tips callback' => 'superhero_shortcode_gettouch_tip',
	);
	return $shortcodes;
}

/**
 * Gettouch Content
 */
function superhero_shortcode_gettouch($attrs, $text) {
	$attrs = shortcode_attrs(array(
			'class' => '',
		),
		$attrs
	);
	return '<i class="'.$attrs['class'].'"></i><span>'.$text.'</span>';
}