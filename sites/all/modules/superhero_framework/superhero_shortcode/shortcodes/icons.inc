<?php

/**
 * Definition of Icon Shortcode
 */

/**
 * Implements hook_shortcode_info
 */
function _icon_shortcode_info(&$shortcodes) {
	$shortcodes['icon'] = array(
		'title' => t('Icon'),
		'description' => t('Create a Font Awesome Icon'),
		'process callback' => 'superhero_shortcode_icon',
		'tips callback' => 'superhero_shortcode_icon_tip',
	);
	return $shortcodes;
}

/**
 * Icon Content
 */
function superhero_shortcode_icon($attrs, $text) {
	$attrs = shortcode_attrs(array(
			'name' => '',
		),
		$attrs
	);
	
	return theme('icon',array('name' => $attrs['name'],'content' => $text));
}

/**
 * Icon theme
 */
function _icon_theme(&$themes) {
	$themes['icon'] = array(
		'variables' => array(
			'name' => '',
			'content' => ''
		)
	);
	
	return $themes;
}

/**
 * Theme icon
 */
function theme_icon($vars) {
	$name = $vars['name'];
	$content = $vars['content'];
	
	$output = '<i class="'.$name.'"><span>'.$content.'</span></i>';

	return $output;
}