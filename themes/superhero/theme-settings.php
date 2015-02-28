<?php

require_once dirname(__FILE__) . '/inc/superhero.inc';
require_once dirname(__FILE__) . '/inc/base.inc';
require_once dirname(__FILE__) . '/inc/theme-settings-layout.inc';
require_once dirname(__FILE__) . '/inc/theme-settings-basic.inc';
require_once dirname(__FILE__) . '/inc/theme-settings-sections.inc';
require_once dirname(__FILE__) . '/inc/theme-settings-colors.inc';
require_once dirname(__FILE__) . '/inc/theme-settings-presets.inc';

require_once dirname(__FILE__) . '/includes/scss.inc.php';

/**
 * Implements hook_form_system_theme_settings_alter()
 */
function superhero_form_system_theme_settings_alter(&$form,&$form_state,$form_id = NULL) {
	$theme = superhero_get_theme();
	$theme_name = $theme->theme;
	
	drupal_add_library('system','ui.sortable');
	
	if (isset($form_id)) {
		return;
	}
	
	// Check if Superhero Theme module exists if not, dont allow access to tools
	if (!module_exists('superhero_theme')) {
		drupal_set_message(t('Please make sure you install the Superhero Theme. This module is required to manage theme settings'),'warning');
		return;
	}
	
	$superhero_logo = drupal_get_path('theme','superhero') . '/images/logo.png';
	$form['superhero_logo'] = array(
		'#prefix' => '<div id="framework-logo">',
		'#markup' => theme('image',array('path' => $superhero_logo)),
		'#suffix' => '</div>',
		'#weight' => -9,
	);

	// Main Settings
	$form['superhero_settings'] = array(
		'#type' => 'vertical_tabs',
		'#title' => t('Theme Settings'),
		'#weight' => -8
	);
	
	superhero_theme_settings_layout($form,$form_state);
	superhero_theme_settings_sections($form,$form_state);
	superhero_theme_settings_basic($form,$form_state);
	//superhero_theme_settings_color($form,$form_state);
	superhero_theme_settings_preset($form,$form_state);
	// Drupal Core Settings
	$form['superhero_settings']['drupal_settings'] = array(
		'#type' => 'fieldset',
		'#title' => t('Drupal Core'),
	);
	
	$form['superhero_settings']['drupal_settings']['theme_settings'] = $form['theme_settings'];
	$form['superhero_settings']['drupal_settings']['logo'] = $form['logo'];
	$form['superhero_settings']['drupal_settings']['favicon'] = $form['favicon'];
	unset($form['theme_settings']);
	unset($form['logo']);
	unset($form['favicon']);
	
	$theme_path = drupal_get_path('theme','superhero');
	$bootstrap_path = $theme_path . '/vendor/bootstrap';
	$fontawesome_path = $theme_path . '/vendor/font-awesome';
	$form['#attached'] = array(
		'css' => array(
			//$bootstrap_path . '/css/bootstrap-responsive.min.css',
			$bootstrap_path . '/css/bootstrap.min.css',
			$fontawesome_path . '/css/font-awesome.min.css',
			$theme_path . '/vendor/minicolors/jquery.minicolors.css',
			$theme_path . '/css/theme_admin.css'
		),
		'js' => array(
			$theme_path . '/js/superhero-admin.js',
			$bootstrap_path . '/js/bootstrap.min.js',
			$theme_path . '/vendor/minicolors/jquery.minicolors.min.js'
		),
	);
	
	$form['#theme_object'] = $theme;
	$form['scss_css'] = array(
		'#type' => 'hidden',
		'#default_value' => theme_get_setting('scss_css') 
	);
	
	$form['#submit'][] = 'superhero_form_system_theme_settings_alter_submit';
}

/**
 * Custom Submit
 */
function superhero_form_system_theme_settings_alter_submit($form,&$form_state) {
	global $CSS;
	$theme = $form['#theme_object'];
	include dirname(__FILE__) . '/includes/scss.php';
	//reset settings in session
	$_SESSION['superhero_default_preset'] = null;
	$_SESSION['superhero_default_direction'] = null;
	variable_set('superhero_settings_updated',REQUEST_TIME);
	//include dirname(__FILE__) . '/includes/lessc.php';
}