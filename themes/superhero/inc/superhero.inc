<?php

/**
 * @file
 * Define core functionality for the theme
 */

/**
 * Return the theme object
 */
function superhero_get_theme() {
	$container = &drupal_static(__FUNCTION__);
	
	$key = $theme = $GLOBALS['theme_key'];
	if (!isset($container[$key])) {
		$container[$key] = new superhero_theme($theme);
	}
	
	return $container[$key];
}

/** 
 * Helper function
 * Retrieve content from .info file
 */
function superhero_info($item,$theme) {
	$themes = list_themes();
	if (!empty($themes[$theme]->info[$item])) {
		return $themes[$theme]->info[$item];
	}
}

/**
 * Retrieve theme settings
 */
function superhero_theme_get_setting($name,$default = NULL,$theme = NULL) {
	$setting = theme_get_setting($name,$theme);
	return isset($setting) ? $setting : $default;
}

/**
 * Retrieve section settings
 */
function superhero_section_get_setting($name,$section,$default = NULL,$theme = NULL) {
	$setting = theme_get_setting('superhero_section_' . $section . '_' . $name,$theme);
	return isset($setting) ? $setting : $default;
}

/**
 * Retrieve region settings
 */
function superhero_region_get_setting($name,$region,$default = NULL,$theme = NULL) {
	$setting = theme_get_setting('superhero_region_' . $region . '_' . $name,$theme);
	return isset($setting) ? $setting : $default;
}

/**
 * Calculate primary column width
 */
function superhero_calculate_primary(&$items,$primary) {
	$cols = 12;
	if (!empty($items)) {
		$devices = array('xscolumns','smcolumns','mdcolumns','lgcolumns');
		foreach($devices as $device){
			$items[$primary]['#data'][$device] = $cols;
			foreach(element_children($items) as $item) {
				if ($item != $primary) {
					$items[$primary]['#data'][$device] -= $items[$item]['#data'][$device];
				}
			}
		}
	}
}

/**
 * Check is settings changed
 */
function superhero_is_settings_change(){
	$stime = isset($_SESSION['superhero_stime'])?$_SESSION['superhero_stime']:REQUEST_TIME;
	$_SESSION['superhero_stime'] = REQUEST_TIME;
	$sptime = variable_get('superhero_settings_updated',0);
	if($stime < $sptime){
		return true;
	}
	return false;
}
