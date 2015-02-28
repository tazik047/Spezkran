<?php
function omnia_theme_settings_header(&$form,&$form_state) {
	$form['superhero_settings']['header_settings'] = array(
		'#type' => 'fieldset',
		'#title' => t('Header')
	);
	$form['superhero_settings']['header_settings']['superhero_header_height'] = array(
		'#type' => 'textfield',
		'#title' => t('Header height'),
		'#default_value' => theme_get_setting('superhero_header_height'),
		//'#attributes' => $color_attrs
	);
	
	$form['superhero_settings']['header_settings']['superhero_header_fixed_height'] = array(
		'#type' => 'textfield',
		'#title' => t('Header fixed height'),
		'#default_value' => theme_get_setting('superhero_header_fixed_height'),
		//'#attributes' => $color_attrs
	);
}