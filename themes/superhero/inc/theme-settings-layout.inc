<?php

/**
 * @file
 * Provides the layout manager
 */

function superhero_theme_settings_layout(&$form,&$form_state) {
	$theme = superhero_get_theme();
	$theme_name = $theme->theme;

	// Section Settings
	$form['section_settings'] = array(
		'#type' => 'container',
		'#attributes' => array(
			'id' => 'sectionsettings',
		),
		'#weight' => -110,
	);
	
	$form['section_settings']['fullwidth'] = array(
		'#type' => 'checkbox',
		'#title' => t('Full Width'),
	);
	
	// Row Settings
	$form['region_settings'] = array(
		'#type' => 'container',
		'#attributes' => array(
			'id' => 'regionsettings',
		),
		'#weight' => -109
	);
	
	$cols = array();
	for($i = 1; $i < 13; $i++) {
		$cols[$i] = t('span@col',array('@col' => $i));
	}
	$sections = array_keys($theme->sections);
	
	$form['region_settings']['section'] = array(
		'#type' => 'select',
		'#title' => t('Section'),
		'#options' => array_merge(drupal_map_assoc($sections),array('' => 'None')),
	);
	$form['region_settings']['lgcolumns'] = array(
		'#type' => 'select',
		'#title' => t('Large Desktop'),
		'#options' => $cols,
	);
	
	$form['region_settings']['mdcolumns'] = array(
		'#type' => 'select',
		'#title' => t('Desktop'),
		'#options' => $cols,
	);
	
	$form['region_settings']['smcolumns'] = array(
		'#type' => 'select',
		'#title' => t('Table'),
		'#options' => $cols,
	);
	
	$form['region_settings']['xscolumns'] = array(
		'#type' => 'select',
		'#title' => t('Phone'),
		'#options' => $cols,
	);

	$form['region_settings']['force'] = array(
		'#type' => 'checkbox',
		'#title' => t('Force'),
	);
	
	$form['region_settings']['apply_region'] = array(
		'#markup' => '<a href="#" class="apply-region">Apply</a>',
	);

	// LAYOUT
	$form['superhero_settings']['layout_settings'] = array(
		'#type' => 'fieldset',
		'#title' => t('Layout Settings'),
	);
	
	$form['superhero_settings']['layout_settings']['__unassigned__'] = array(
		'#type' => 'container',
		'#theme_wrappers' => array('admin_section'),
		'#section_name' => 'Unassigned',
		'#weight' => 100,
	);
	
	$form['superhero_settings']['layout_settings']['__unassigned__']['regions'] = array(
		'#type' => 'container',
		'#theme_wrappers' => array('admin_region_container'),
	);	
	
	foreach($theme->sections as $section => $item) {
		$form['superhero_settings']['layout_settings'][$section] = array(
			'#type' => 'container',
			'#theme_wrappers' => array('admin_section'),
			'#section_name' => $item['name']
		);
		
		$form['superhero_settings']['layout_settings'][$section]['section'] = array(
			'#type' => 'container',
			'#theme_wrappers' => array('admin_section_properties'),
		);
		
		$form['superhero_settings']['layout_settings'][$section]['section']['superhero_section_'.$section.'_weight'] = array(
			'#type' => 'hidden',
			'#default_value' => $item['weight'],
		);
		
		$form['superhero_settings']['layout_settings'][$section]['section']['superhero_section_'.$section.'_primary'] = array(
			'#type' => 'hidden',
			'#default_value' => $item['primary'],
		);
		
		$form['superhero_settings']['layout_settings'][$section]['section']['superhero_section_'.$section.'_fullwidth'] = array(
			'#type' => 'hidden',
			'#default_value' => $item['fullwidth'],
		);
		
		$form['superhero_settings']['layout_settings'][$section]['regions'] = array(
			'#type' => 'container',
			'#theme_wrappers' => array('admin_region_container'),
		);	
	}	
	
	foreach($theme->regions as $region => $item) {
		$section = $item['enabled'] ? $item['section'] : '__unassigned__';
		
		$cols = "";
		if(!empty($item['xscolumns'])){
			$cols .= " col-xs-".$item['xscolumns'];
		}
		if(!empty($item['smcolumns'])){
			$cols .= " col-sm-".$item['smcolumns'];
		}
		if(!empty($item['mdcolumns'])){
			$cols .= " col-md-".$item['mdcolumns'];
		}
		if(!empty($item['lgcolumns'])){
			$cols .= " col-lg-".$item['lgcolumns'];
		}
		
		$form['superhero_settings']['layout_settings'][$section]['regions'][$region] = array(
			'#type' => 'container',
			'#theme_wrappers' => array('admin_region'),
			'#columns' => $cols,
			'#region_name' => $item['name']
		);
		
		$form['superhero_settings']['layout_settings'][$section]['regions'][$region]['superhero_region_'.$region.'_section'] = array(
			'#type' => 'hidden',
			'#default_value' => $section,
		);	
		
		$form['superhero_settings']['layout_settings'][$section]['regions'][$region]['superhero_region_'.$region.'_xscolumns'] = array(
			'#type' => 'hidden',
			'#default_value' => $item['xscolumns'],
		);
		$form['superhero_settings']['layout_settings'][$section]['regions'][$region]['superhero_region_'.$region.'_smcolumns'] = array(
			'#type' => 'hidden',
			'#default_value' => $item['smcolumns'],
		);
		$form['superhero_settings']['layout_settings'][$section]['regions'][$region]['superhero_region_'.$region.'_mdcolumns'] = array(
			'#type' => 'hidden',
			'#default_value' => $item['mdcolumns'],
		);
		$form['superhero_settings']['layout_settings'][$section]['regions'][$region]['superhero_region_'.$region.'_lgcolumns'] = array(
			'#type' => 'hidden',
			'#default_value' => $item['lgcolumns'],
		);
		
		$form['superhero_settings']['layout_settings'][$section]['regions'][$region]['superhero_region_'.$region.'_weight'] = array(
			'#type' => 'hidden',
			'#default_value' => $item['weight'],
		);
		
		$form['superhero_settings']['layout_settings'][$section]['regions'][$region]['superhero_region_'.$region.'_force'] = array(
			'#type' => 'hidden',
			'#default_value' => $item['force'],
		);
	}
}