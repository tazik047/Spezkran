<?php

/**
 * Definition of Video Shortcode
 */

/**
 * Implements hook_shortcode_info
 */
function _video_shortcode_info(&$shortcodes) {
	$shortcodes['video'] = array(
		'title' => t('Video'),
		'description' => t('Embed youtube/vimeo video'),
		'process callback' => 'superhero_shortcode_video',
		'tips callback' => 'superhero_shortcode_video_tip',
	);
	return $shortcodes;
}

/**
 * Icon Content
 */
function superhero_shortcode_video($attrs, $text) {
	$attrs = shortcode_attrs(array(
			'type' => '',
			'video_id' => ''
		),
		$attrs
	);
	
	return theme('video',array('type' => $attrs['type'],'video_id' => $attrs['video_id']));
}

/**
 * Video theme
 */
function _video_theme(&$themes) {
	$themes['video'] = array(
		'variables' => array(
			'type' => '',
			'video_id' => ''
		)
	);
	
	return $themes;
}

/**
 * Theme icon
 */
function theme_video($vars) {
	$type = $vars['type'];
	$video_id = $vars['video_id'];
	switch($type){
		case 'vimeo':
			return '<div class="superhero_video"><iframe frameborder="0" allowfullscreen="" mozallowfullscreen="" webkitallowfullscreen="" src="http://player.vimeo.com/video/'.$video_id.'"></iframe></div>';
			break;
		case 'youtube':
			return '<div class="superhero_video"><iframe frameborder="0" allowfullscreen="" mozallowfullscreen="" webkitallowfullscreen="" src="https://www.youtube.com/embed/'.$video_id.'"></iframe></div>';
			break;
		default:
			return '[video type="'.$type.'" video_id="'.$video_id.'"][/video]';
	}
}