<?php

/**
 * Definition of Alert Shortcode
 */

/**
 * Implements hook_shortcode_info
 */
function _alert_shortcode_info(&$shortcodes) {
	$shortcodes['alert'] = array(
		'title' => t('Alert'),
		'description' => t('Create Alert Messages'),
		'process callback' => 'superhero_shortcode_alert',
		'tips callback' => 'superhero_shortcode_alert_tip',
	);
	return $shortcodes;
}

/**
 * Icon Content
 */
function superhero_shortcode_alert($attrs, $text) {
	$attrs = shortcode_attrs(array(
			'type' => '',
		),
		$attrs
	);
	
	return theme('alert',array('type' => $attrs['type'],'content' => $text));
}

/**
 * Icon theme
 */
function _alert_theme(&$themes) {
	$themes['alert'] = array(
		'variables' => array(
			'type' => '',
			'content' => ''
		)
	);
	
	return $themes;
}

/**
 * Theme icon
 */
function theme_alert($vars) {
	$type = $vars['type'];
	$content = $vars['content'];
	$output = '<div class="alert alert-'.$type.' fade in">';
	$output .= '<a type="button" class="close" data-dismiss="alert">&times;</a>';
	$output .= $content;
	$output .= '</div>';
	return $output;
}