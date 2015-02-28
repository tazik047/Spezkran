<?php

/**
 * @file
 * Sections settings
 */

function superhero_theme_settings_sections(&$form,&$form_state) {
	$theme = superhero_get_theme();
	$theme_name = $theme->theme;
	
	$form['superhero_settings']['section_theme_settings'] = array(
		'#type' => 'fieldset',
		'#title' => t('Section Settings'),
	);
	
	foreach($theme->sections as $section => $item) {
		$form['superhero_settings']['section_theme_settings'][$section] = array(
			'#type' => 'fieldset',
			'#title' => $item['name'],
			'#collapsible' => TRUE,
			'#collapsed' => TRUE,
		);
		
		$form['superhero_settings']['section_theme_settings'][$section]['superhero_section_'.$section.'_fullwidth'] = array(
			'#type' => 'radios',
			'#title' => t('Full Width'),
			'#description' => t('Determines whether the section is full width or its content is centered'),
			'#options' => array(
				0 => t('No'),
				1 => t('Yes')
			),
			'#default_value' => $item['fullwidth'],
		);
		
		/*Sticky settings*/
		$form['superhero_settings']['section_theme_settings'][$section]['superhero_section_'.$section.'_sticky'] = array(
			'#type' => 'radios',
			'#title' => t('Sticky on top'),
			'#description' => t('If yes, this section will always top of screen.'),
			'#options' => array(
				0 => t('No'),
				1 => t('Yes')
			),
			'#default_value' => $item['sticky'],
			
		);
		/*Style setting*/
		$form['superhero_settings']['section_theme_settings'][$section]['section_style'] = array(
			'#type' => 'fieldset',
			'#title' => t('Custom style'),
			'#collapsible' => TRUE,
			'#collapsed' => TRUE,
		);
		$form['superhero_settings']['section_theme_settings'][$section]['section_style']['superhero_section_'.$section.'_custom_class'] = array(
			'#type' => 'textfield',
			'#title' => t('Custom class'),
			'#default_value' => $item['custom_class'],
		);
		$form['superhero_settings']['section_theme_settings'][$section]['section_style']['superhero_section_'.$section.'_style_background'] = array(
			'#type' => 'textfield',
			'#title' => t('Background color'),
			'#default_value' => $item['style_background'],
			'#attributes' => array('class'=>array('colorpicker'))
		);
		$form['superhero_settings']['section_theme_settings'][$section]['section_style']['superhero_section_'.$section.'_style_margin'] = array(
			'#type' => 'textfield',
			'#title' => t('Margin'),
			'#default_value' => $item['style_margin'],
		);
		$form['superhero_settings']['section_theme_settings'][$section]['section_style']['superhero_section_'.$section.'_style_padding'] = array(
			'#type' => 'textfield',
			'#title' => t('Padding'),
			'#default_value' => $item['style_padding'],
		);
		$form['superhero_settings']['section_theme_settings'][$section]['section_responsive'] = array(
			'#type' => 'fieldset',
			'#title' => t('Responsive Settings'),
			'#collapsible' => TRUE,
			'#collapsed' => TRUE,
			//'#attributes' => array('class'=>array('col-md-4')),
		);
		
		$visible_opts = array(
			'vphone' => t('Visible Phone'),
			'vtablet' => t('Visible Tablet'),
			'vdesktop' => t('Visible Desktop'),
			'hphone' => t('Hidden Phone'),
			'htablet' => t('Hidden Tablet'),
			'hdesktop' => t('Hidden Desktop')
		);
		
		foreach($visible_opts as $rclass => $rtitle) {
			$form['superhero_settings']['section_theme_settings'][$section]['section_responsive']['superhero_section_'.$section.'_'.$rclass] = array(
				'#type' => 'checkbox',
				'#title' => $rtitle,
				'#default_value' => $item[$rclass],
			);
		}
	}	
}