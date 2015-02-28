<?php

/**
 * Definition of Carousel Shortcode
 */

/**
 * Implements hook_shortcode_info
 */
function _carousel_shortcode_info(&$shortcodes) {
	$shortcodes['carousel'] = array(
		'title' => t('Carousel'),
		'description' => t('Create a Carousel of items with captions'),
		'process callback' => 'superhero_shortcode_carousel',
		'tips callback' => 'superhero_shortcode_carousel_tip',
	);
	
	$shortcodes['carousel_item'] = array(
		'title' => t('Carousel Item'),
		'description' => t('Create a carousel item to go inside a carousel'),
		'process callback' => 'superhero_shortcode_carousel_item',
		'tips callback' => 'superhero_shortcode_carousel_item_tip',
	);
	
	$shortcodes['caption'] = array(
		'title' => t('Caption'),
		'description' => t('Create a carousel item caption'),
		'process callback' => 'superhero_shortcode_caption',
		'tips callback' => 'superhero_shortcode_caption_tip',
	);
	
	return $shortcodes;
}

/**
 * Carousel Content
 */
function superhero_shortcode_carousel($attrs, $text) {
	$attrs = shortcode_attrs(array(
			'id' => '',
			'class' => ''
		),
		$attrs
	);
	
	$class = shortcode_add_class($attrs['class'],'carousel slide');
	return theme('carousel',array('id' => $attrs['id'],'class' => $class,'content' => $text));
}

/**
 * Carousel Item
 */
function superhero_shortcode_carousel_item($attrs, $text) {
	$attrs = shortcode_attrs(array(
			'class' => '',
		),
		$attrs
	);
	
	$class = shortcode_add_class($attrs['class'],'item');
	return theme('carousel_item',array('class' => $class,'content' => $text));
}

/**
 * Carousel Caption
 */
function superhero_shortcode_caption($attrs, $text) {
	$attrs = shortcode_attrs(array(
			'class' => '',
		),
		$attrs
	);
	
	$class = shortcode_add_class($attrs['class'],'carousel-caption');
	return theme('caption',array('class' => $class,'content' => $text));
}


/**
 * Carousel theme
 */
function _carousel_theme(&$themes) {
	$themes['carousel'] = array(
		'variables' => array(
			'id' => '',
			'class' => '',
			'content' => ''
		)
	);
	
	$themes['carousel_item'] = array(
		'variables' => array(
			'class' => '',
			'content' => ''
		)
	);
	
	$themes['caption'] = array(
		'variables' => array(
			'class' => '',
			'content' => ''
		)
	);
	
	return $themes;
}

/**
 * Theme Carousel
 */
function theme_carousel($vars) {
	$id = $vars['id'];
	$class = $vars['class'];
	$content = $vars['content'];
	
	$output = '<div id="'.$id.'" class="'.$class.'">';
	$output .= '<div class="carousel-inner">';
	$output .= $content;
	$output .= '</div>';
	$output .= '<a class="carousel-control left" href="#'.$id.'" data-slide="prev"><span class="glyphicon glyphicon-chevron-left"></span></a>';
	$output .= '<a class="carousel-control right" href="#'.$id.'" data-slide="next"><span class="glyphicon glyphicon-chevron-right"></span></a>';
	$output .= '</div>';
	
	return $output;
}

/**
 * Theme Carousel Item
 */
function theme_carousel_item($vars) {
	$class = $vars['class'];
	$content = $vars['content'];
	
	$output = '<div class="'.$class.'">';
	$output .= $content;
	$output .= '</div>';

	return $output;
}

/**
 * Theme Carousel caption
 */
function theme_caption($vars) {
	$class = $vars['class'];
	$content = $vars['content'];
	
	$output = '<div class="'.$class.'">';
	$output .= $content;
	$output .= '</div>';

	return $output;
}