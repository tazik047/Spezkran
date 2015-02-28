<?php

/**
 * @file
 * Basic Theme Settings
 */
function superhero_theme_settings_basic(&$form,&$form_state) {
	// Basic Settings
	$form['superhero_settings']['basic_settings'] = array(
		'#type' => 'fieldset',
		'#title' => t('Basic'),
	);
	
	$form['superhero_settings']['basic_settings']['superhero_responsive'] = array(
		'#type' => 'select',
		'#title' => t('Responsive'),
		'#options' => array(
			0 => t('No'),
			1 => t('Yes'),
		),
		'#default_value' => theme_get_setting('superhero_responsive'),
	);
	
	$form['superhero_settings']['basic_settings']['superhero_layout'] = array(
		'#type' => 'select',
		'#title' => t('Layout style'),
		'#options' => array(
			'wide' => t('Wide'),
			'boxed' => t('Boxed'),
		),
		'#default_value' => theme_get_setting('superhero_layout'),
	);
	
	$form['superhero_settings']['basic_settings']['superhero_direction'] = array(
		'#type' => 'select',
		'#title' => t('Theme direction'),
		'#options' => array(
			'ltr' => t('LTR'),
			'rtl' => t('RLT'),
		),
		'#default_value' => theme_get_setting('superhero_direction'),
	);
}