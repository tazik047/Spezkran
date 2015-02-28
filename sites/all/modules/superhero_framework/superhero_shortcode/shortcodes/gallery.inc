<?php

/**
 * Definition of Tab Shortcodes
 */

/**
 * Implements hook_shortcode_info
 */
global $superhero_shortcode_gallery;
global $superhero_shortcode_galleries_categories;
$superhero_shortcode_galleries_categories = array();
function _gallery_shortcode_info(&$shortcodes) {
	$shortcodes['gallery'] = array(
		'title' => t('Gallery'),
		'description' => t('Create Isotope gallery'),
		'process callback' => 'superhero_shortcode_gallery',
		'cache' => TRUE,
	);
	
	$shortcodes['gallery_item'] = array(
		'title' => t('Gallery Item'),
		'process callback' => 'superhero_shortcode_gallery_item',
		'cache' => TRUE,
	);
	
	return $shortcodes;
}


/**
 * Isotope Gallery Container
 */
function superhero_shortcode_gallery($attrs, $text) {
	global $superhero_shortcode_gallery;
	if(empty($superhero_shortcode_gallery)){
		$superhero_shortcode_gallery = 1;
	}
	global $superhero_shortcode_galleries_categories;
	$attrs = shortcode_attrs(array(
			'cols' => '4',
			'filter' => 'no'
		),
		$attrs
	);
	return theme('superhero_shortcode_gallery', array(
		'cols' => $attrs['cols'],
		'categories' => $superhero_shortcode_galleries_categories,
		'filter' => $attrs['filter'],
		'content' => $text
	));
}

/**
 * Gallery Item
 */
function superhero_shortcode_gallery_item($attrs, $text) {		
	global $superhero_shortcode_galleries_categories;
	$attrs = shortcode_attrs(array(
			'tag' => '',
			'image' => '',
		),
		$attrs
	);
	$superhero_shortcode_galleries_categories[$attrs['tag']] = $attrs['tag'];
	return theme('superhero_shortcode_gallery_item',array(
		'tag' => $attrs['tag'],
		'image' => $attrs['image'],
		'content' => $text,
	));
}

/**
 * Icon theme
 */
function _gallery_theme(&$themes) {
	$path = drupal_get_path('module','superhero_shortcode');
	$themes['superhero_shortcode_gallery'] = array(
		'template' => 'gallery',
		'path' => $path . '/theme',
		'variables' => array(
			'cols' => '',
			'filter' => '',
		)
	);
	$themes['superhero_shortcode_gallery_item'] = array(
		'template' => 'galleryitem',
		'path' => $path . '/theme',
		'variables' => array(
			'tag' => '',
			'image' => '',
			'content' => '',
		)
	);
	
	return $themes;
}