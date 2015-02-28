<?php

function boson_form_system_theme_settings_alter(&$form, &$form_state) {

  $form['boson_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('boson Theme Settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );


  
  $form['boson_settings']['general_settings']['theme_color_config']['theme_color_palette'] = array(
    '#type' => 'select',
    '#title' => t('Choose a color palette'),
    '#default_value' => theme_get_setting('theme_color_palette'),
    '#options' => array(
      'turquoise' => t('Turquoise Blue'),
      'purple' => t('Cool Purple'),
      'orange' => t('Pumpkin Orange'),
      'green' => t('Olive Green'),
      'red' => t('Red'),
      'blue' => t('Blue'),
      'grassgreen' => t('Grass Green'),
      'pink' => t('Pink'),
	  'kleinblue' => t('Klein Blue'),
    ),
  );

 $form['boson_settings']['general_settings']['boson_boxed'] = array(
    '#type' => 'checkbox',
    '#title' => t('Boxed Layout?'),
    '#default_value' => theme_get_setting('boson_boxed', 'boson'),
    '#description' => t("Check for yes!"),
  );
  
  $form['boson_settings']['general_settings']['theme_pattern_config']['theme_bg_pattern'] = array(
    '#type' => 'select',
    '#title' => t('Choose a background pattern'),
    '#default_value' => theme_get_setting('theme_bg_pattern'),
    '#options' => array(
      'none' => t('none'),
      'bg-wood-pattern' => t('bg-wood-pattern'),
      'bg-shattered' => t('bg-shattered'),
      'bg-vichy' => t('bg-vichy'),
      'bg-random-grey-variations' => t('bg-random-grey-variations'),
      'bg-irongrip' => t('bg-irongrip'),
      'bg-gplaypattern' => t('bg-gplaypattern'),
      'bg-diamond-upholstery' => t('bg-diamond-upholstery'),
      'bg-denim' => t('bg-denim'),
	  'bg-crissxcross' => t('bg-crissxcross'),
	  'bg-climpek' => t('bg-climpek'),
    ),
  );


}
