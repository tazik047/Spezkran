<?php

/**
 * Definition of Testimonial Shortcode
 */

/**
 * Implements hook_shortcode_info
 */
function _testimonial_shortcode_info(&$shortcodes) {
	$shortcodes['testimonial'] = array(
		'title' => t('Testimonial'),
		'description' => t('Create a Testimonial'),
		'process callback' => 'superhero_shortcode_testimonial',
		'tips callback' => 'superhero_shortcode_testimonial_tip',
	);
	return $shortcodes;
}

/**
 * Testimonial Content
 */
function superhero_shortcode_testimonial($attrs, $text) {
	$attrs = shortcode_attrs(array(
			'name' => '',
			'email' => '',
			'company' => '',
			'designation' => ''
		),
		$attrs
	);
	
	return theme('testimonial',array('data' => $attrs,'content' => $text));
}


/**
 * Testimonial theme
 */
function _testimonial_theme(&$themes) {
	$themes['testimonial'] = array(
		'variables' => array(
			'data' => array(),
			'content' => ''
		)
	);
	
	return $themes;
}

/**
 * Theme testimonial
 */
function theme_testimonial($vars) {
	$data = $vars['data'];
	$content = $vars['content'];
	
	$output = '<div class="media testimonial">';
	$output .= '<div class="pull-left">';
	$output .= '<i style="font-size:48px" class="icon-quote-left"></i>';
	$output .= '</div>';
	$output .= '<div class="media-body">';
	$output .= '<div class="testimonial-content">';
	$output .= $content;
	$output .= '</div>';
	$output .= '<div style="margin-top:5px;" class="media testimonial-author">';
	$output .= '<div class="pull-left">';
	$output .= '<img class="img-circle" src="http://1.gravatar.com/avatar/a015150ac9a854b803d08f4a6cd3abc2?s=68&r=pg&d=mm"/>';
	$output .= '</div>';
	$output .= '<div class="media-body">';
	$output .= '<strong>'.$data['name'].'</strong><br>';
	$output .= $data['designation'].'<br>';
	$output .= $data['company'].'<br>';
	$output .= '</div>';
	$output .= '</div>';
	$output .= '</div>';
	$output .= '</div>';

	return $output;
}