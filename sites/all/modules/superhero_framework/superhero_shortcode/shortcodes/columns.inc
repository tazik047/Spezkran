<?php

/**
 * Definition of Columns Shortcode
 */

/**
 * Implements hook_shortcode_info
 */
function _columns_shortcode_info(&$shortcodes) {
	$shortcodes['row'] = array(
		'title' => t('Row'),
		'description' => t('Create a Column Row'),
		'process callback' => 'superhero_shortcode_row',
		'tips callback' => 'superhero_shortcode_row_tip',
	);
	
	$shortcodes['col'] = array(
		'title' => t('Column'),
		'description' => t('Create a Column to go in a Column Row'),
		'process callback' => 'superhero_shortcode_column',
		'tips callback' => 'superhero_shortcode_column_tip',
	);
	
	return $shortcodes;
}

/**
 * Row Content
 */
function superhero_shortcode_row($attrs, $text) {
	$attrs = shortcode_attrs(array(
			'id' => '',
			'class' => ''
		),
		$attrs
	);
	
	$class = shortcode_add_class($attrs['class'],'row');
	return theme('col_row',array('id' => $attrs['id'],'class' => $class,'content' => $text));
}

/**
 * Column Content
 */
function superhero_shortcode_column($attrs, $text) {
	$attrs = shortcode_attrs(array(
			'id' => '',
			'class' => ''
		),
		$attrs
	);
	return theme('col_col',array('id' => $attrs['id'],'class' => $attrs['class'],'content' => $text));
}

/**
 * Column/Row theme
 */
function _columns_theme(&$themes) {
	$themes['col_row'] = array(
		'variables' => array(
			'id' => '',
			'class' => '',
			'content' => ''
		)
	);
	
	$themes['col_col'] = array(
		'variables' => array(
			'id' => '',
			'class' => '',
			'content' => ''
		)
	);
	
	return $themes;
}

/**
 * Theme Column Row
 */
function theme_col_row($vars) {
	$id = $vars['id'];
	$class = $vars['class'];
	$content = $vars['content'];
	return '<div id="'.$id.'" class="'.$class.'">' . $content . '</div>';
}

/**
 * Theme Column
 */
function theme_col_col($vars) {
	$id = $vars['id'];
	$class = $vars['class'];
	$content = $vars['content'];
	return '<div id="'.$id.'" class="'.$class.'">' . $content . '</div>';
}