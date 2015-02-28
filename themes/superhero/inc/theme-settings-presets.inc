<?php

/**
 * Add colour settings to superhero framework
 */
function superhero_theme_settings_preset(&$form,&$form_state) {
	$theme = superhero_get_theme();
	$presets = $theme->presetsstr;
	$default_preset = theme_get_setting('superhero_default_preset');
	$default_preset = empty($default_preset)?0:$default_preset;
	if($presets){
		$js = "var superhero_presets = ".base64_decode($presets)."; var superhero_current_preset = 0; var default_preset = {$default_preset}";
	}else{
		$js = "var superhero_presets = [{name:'Preset 1',superhero_color_link:'#00AFD1'},{name:'Preset 2',superhero_color_link:'#FF5A19'}]; var superhero_current_preset = 0; var default_preset = {$default_preset}";
	}
	drupal_add_js($js,'inline');
	drupal_add_js(drupal_get_path('theme','superhero').'/js/presets.js');
	
	$form['superhero_settings']['preset_settings'] = array(
		'#type' => 'fieldset',
		'#title' => t('Presets')
	);
	
	$color_attrs = array(
		'class' => array(
			'colorpicker',
			'perset-option'
		)
	);
	$form['superhero_settings']['preset_settings']['new_preset'] = array(
		'#markup' => '<div class="presets"></div>',
	);
	
	$form['superhero_settings']['preset_settings']['superhero_color_main'] = array(
		'#type' => 'textfield',
		'#title' => t('Main Color'),
		'#default_value' => theme_get_setting('superhero_color_main'),
		'#attributes' => $color_attrs
	);
	
	$form['superhero_settings']['preset_settings']['superhero_color_text'] = array(
		'#type' => 'textfield',
		'#title' => t('Text Color'),
		'#default_value' => theme_get_setting('superhero_color_text'),
		'#attributes' => $color_attrs
	);
	
	$form['superhero_settings']['preset_settings']['superhero_color_link'] = array(
		'#type' => 'textfield',
		'#title' => t('Link Color'),
		'#default_value' => theme_get_setting('superhero_color_link'),
		'#attributes' => $color_attrs
	);
	
	$form['superhero_settings']['preset_settings']['superhero_color_hover'] = array(
		'#type' => 'textfield',
		'#title' => t('Hover Color'),
		'#default_value' => theme_get_setting('superhero_color_hover'),
		'#attributes' => $color_attrs
	);
	
	$form['superhero_settings']['preset_settings']['superhero_color_heading'] = array(
		'#type' => 'textfield',
		'#title' => t('Heading Color'),
		'#default_value' => theme_get_setting('superhero_color_heading'),
		'#attributes' => $color_attrs
	);
	$form['superhero_settings']['preset_settings']['superhero_presets'] = array('#type' => 'hidden', '#default_value' => theme_get_setting('superhero_presets'));
	$form['superhero_settings']['preset_settings']['superhero_default_preset'] = array('#type' => 'hidden', '#default_value' => theme_get_setting('superhero_default_preset'));
}