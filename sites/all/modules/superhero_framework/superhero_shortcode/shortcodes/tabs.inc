<?php

/**
 * Definition of Tab Shortcodes
 */

/**
 * Implements hook_shortcode_info
 */
global $superhero_shortcode_tabnavs;
$superhero_shortcode_tabnavs = array();
global $superhero_tab_index;
$superhero_tab_index = 1;
function _tabs_shortcode_info(&$shortcodes) {
	$shortcodes['tabs'] = array(
		'title' => t('Bootstrap Tabs'),
		'description' => t('Create a tab container'),
		'process callback' => 'superhero_shortcode_bootstrap_tabs',
		'tips callback' => 'superhero_shortcode_bootstrap_tabs_tip',
	);
	
	$shortcodes['tab'] = array(
		'title' => t('Tab Item'),
		'description' => t('Provides the ability to create tabs within a tab container'),
		'process callback' => 'superhero_shortcode_bootstrap_tab',
		'tips callback' => 'superhero_shortcode_bootstrap_tab_tip',
	);
	
	return $shortcodes;
}

/**
 * Tabs theme
 */
function _tabs_theme(&$themes) {
	$themes['bootstrap_tabs'] = array(
		'variables' => array(
			'class' => 'bootstrap_tabs',
			'text' => ''
		),
	);
	$themes['bootstrap_tab'] = array();
}

/**
 * Bootstrap Tabs Container
 */
function superhero_shortcode_bootstrap_tabs($attrs, $text) {
	global $superhero_shortcode_tabnavs;
	$attrs = shortcode_attrs(array(
			'class' => 'nav-tabs',
		),
		$attrs
	);
	$tabs = '<ul class="nav '.$attrs['class'].'">';
	foreach($superhero_shortcode_tabnavs as $tabnav){
		$tabs .= $tabnav;
	};
	$tabs .= '</ul>';
	$superhero_shortcode_tabnavs = array();
	return $tabs.'<div class="tab-content">' . $text . '</div>';
}

/**
 * Theme tabs
 */
function theme_bootstrap_tabs($vars) {
	$class = $vars['class'];
	$text = $vars['text'];
	
	return '<span class="' . $class . '">'. $text . '</span>';
}

/**
 * Bootstrap tab
 */
function superhero_shortcode_bootstrap_tab($attrs, $text) {	
	global $superhero_shortcode_tabnavs;
	global $superhero_tab_index;
	$attrs = shortcode_attrs(array(
			'title' => '',
			'class' => ''
		),
		$attrs
	);
	$active = empty($superhero_shortcode_tabnavs)?" active":"";
	$superhero_shortcode_tabnavs[] = '<li class="'.$active.'"><a href="#superhero_tab_content_'.$superhero_tab_index.'" data-toggle="tab">'.$attrs['title'].'</a></li>';
	return '<div class="tab-pane '.$attrs['class'].$active.'" id="superhero_tab_content_'.$superhero_tab_index++.'">'.$text.'</div>';
}