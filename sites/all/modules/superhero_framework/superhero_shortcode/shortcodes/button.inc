<?php

/**
 * Definition of Button Shortcode
 */

/**
 * Implements hook_shortcode_info
 */
function _button_shortcode_info(&$shortcodes) {
	$shortcodes['button'] = array(
		'title' => t('button'),
		'description' => t('Create Button'),
		'process callback' => 'superhero_shortcode_button',
		'tips callback' => 'superhero_shortcode_button_tip',
	);
	return $shortcodes;
}

/**
 * Button Content
 */
function superhero_shortcode_button($attrs, $text) {
	$attrs = shortcode_attrs(array(
			'type' => 'default',
			'size' => 'sm'
		),
		$attrs
	);
	
	//return theme('button',array('type' => $attrs['type'],'size'=>$attrs['size'],'content' => $text));
	return '<button type="button" class="btn btn-'.$attrs['type'].' btn-'.$attrs['size'].'">'.$text.'</button>';
}