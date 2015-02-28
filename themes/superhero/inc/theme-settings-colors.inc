<?php

/**
 * Add colour settings to superhero framework
 */
function superhero_theme_settings_color(&$form,&$form_state) {
	$form['superhero_settings']['color_settings'] = array(
		'#type' => 'fieldset',
		'#title' => t('Colour Settings')
	);
	
	$color_attrs = array(
		'class' => array(
			'colorpicker'
		)
	);
	
	$form['superhero_settings']['color_settings']['superhero_color_text'] = array(
		'#type' => 'textfield',
		'#title' => t('Text Color'),
		'#default_value' => theme_get_setting('superhero_color_text'),
		'#attributes' => $color_attrs
	);
	
	$form['superhero_settings']['color_settings']['superhero_color_link'] = array(
		'#type' => 'textfield',
		'#title' => t('Link Color'),
		'#default_value' => theme_get_setting('superhero_color_link'),
		'#attributes' => $color_attrs
	);
	
	$form['superhero_settings']['color_settings']['superhero_color_hover'] = array(
		'#type' => 'textfield',
		'#title' => t('Hover Color'),
		'#default_value' => theme_get_setting('superhero_color_hover'),
		'#attributes' => $color_attrs
	);
	
	$form['superhero_settings']['color_settings']['superhero_color_heading'] = array(
		'#type' => 'textfield',
		'#title' => t('Heading Color'),
		'#default_value' => theme_get_setting('superhero_color_heading'),
		'#attributes' => $color_attrs
	);
}