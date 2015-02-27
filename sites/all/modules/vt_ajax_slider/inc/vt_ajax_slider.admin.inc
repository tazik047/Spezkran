<?php
/**
 * Admin form callback function
 */
function vt_ajax_slider_admin_settings() {
	// important variable to use
  $options_boolean = array(
  	'yes' => t('Yes'),
  	'no' => t('No'),
  );

  $options_theme = vtslide_read_dir('vt_ajax_slider');

  $option_number = range(0, 20, 1);
	unset($option_number[0]);

	$options_animation = array(
		'explode' => t('Explode'),
		'fade' => t('Fade'),
	  'puff' => t('Puff'),
	  'fold' => t('Fold'),
	  'clip' => t('Clip'),
	  'blind' => t('Blind'),
	);

	// basic fieldset
  $form['vt_ajax_slider_basic'] = array(
    '#type' => 'fieldset',
    '#weight' => 1,
    '#title' => t('Basic settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['vt_ajax_slider_basic']['vt_ajax_slider_animation_mode_in'] = array(
    '#type' => 'select',
    '#title' => t('Animation in mode'),
    '#options' => $options_animation,
    '#default_value' => variable_get('vt_ajax_slider_animation_mode_in', 'fade'),
  );

  $form['vt_ajax_slider_basic']['vt_ajax_slider_animation_mode_out'] = array(
    '#type' => 'select',
    '#title' => t('Animation out mode'),
    '#options' => $options_animation,
    '#default_value' => variable_get('vt_ajax_slider_animation_mode_out', 'fade'),
  );

  $form['vt_ajax_slider_basic']['vt_ajax_slider_animation_time_in'] = array(
    '#type' => 'textfield',
    '#title' => t('Animation in time'),
    '#field_suffix' => t('miliseconds'),
    '#size' => 5,
    '#default_value' => variable_get('vt_ajax_slider_animation_time_in', '1500'),
  );

  $form['vt_ajax_slider_basic']['vt_ajax_slider_animation_time_out'] = array(
    '#type' => 'textfield',
    '#title' => t('Animation out time'),
    '#field_suffix' => t('miliseconds'),
    '#size' => 5,
    '#default_value' => variable_get('vt_ajax_slider_animation_time_out', '1500'),
  );

  $form['vt_ajax_slider_basic']['vt_ajax_slider_theme'] = array(
    '#type' => 'select',
    '#title' => t('Select the theme'),
    '#options' => $options_theme,
    '#default_value' => variable_get('vt_ajax_slider_theme', 'original'),
  );

	$form['vt_ajax_slider_basic']['vt_ajax_slider_button'] = array(
    '#type' => 'select',
    '#title' => t('Show next and previous button?'),
    '#options' => $options_boolean,
    '#default_value' => variable_get('vt_ajax_slider_button', 'yes'),
  );

	$form['vt_ajax_slider_basic']['vt_ajax_slider_progress_bar'] = array(
    '#type' => 'select',
    '#title' => t('Show loading progress bar?'),
    '#options' => $options_boolean,
    '#default_value' => variable_get('vt_ajax_slider_progress_bar', 'yes'),
  );

	// autoslide fieldset
	$form['vt_ajax_slider_auto'] = array(
    '#type' => 'fieldset',
    '#weight' => 7,
    '#title' => t('Autoslide Configuration'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

	$form['vt_ajax_slider_auto']['vt_ajax_slider_autoslide'] = array(
    '#type' => 'select',
    '#title' => t('Use Autoslide feature?'),
    '#options' => $options_boolean,
    '#default_value' => variable_get('vt_ajax_slider_autoslide', 'yes'),
  );

	$form['vt_ajax_slider_auto']['vt_ajax_slider_autoslide_mode'] = array(
    '#type' => 'select',
    '#title' => t('Autoslide Mode'),
    '#options' => array('return' => 'Return to beginning', 'reverse' => 'Reverse One'),
    '#default_value' => variable_get('vt_ajax_slider_autoslide_mode', 'yes'),
  );

	$form['vt_ajax_slider_auto']['vt_ajax_slider_autoslide_timer'] = array(
    '#type' => 'textfield',
    '#title' => t('Input the autoslide delay in miliseconds'),
    '#default_value' => variable_get('vt_ajax_slider_autoslide_timer', '20000'),
  );

	// mini preview setting
	$form['vt_ajax_slider_mini'] = array(
    '#type' => 'fieldset',
    '#weight' => 4,
    '#title' => t('Mini Preview Configuration'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

	$form['vt_ajax_slider_mini']['vt_ajax_slider_mini_preview'] = array(
    '#type' => 'select',
    '#title' => t('Show mini preview?'),
    '#options' => $options_boolean,
    '#default_value' => variable_get('vt_ajax_slider_mini_preview', 'yes'),
  );

	$form['vt_ajax_slider_mini']['vt_ajax_slider_mini_preview_image'] = array(
    '#type' => 'select',
    '#title' => t('Show mini preview Image?'),
    '#options' => $options_boolean,
    '#default_value' => variable_get('vt_ajax_slider_mini_preview_image', 'yes'),
  );

	$form['vt_ajax_slider_mini']['vt_ajax_slider_mini_preview_title'] = array(
    '#type' => 'select',
    '#title' => t('Show mini preview title?'),
    '#options' => $options_boolean,
    '#default_value' => variable_get('vt_ajax_slider_mini_preview_title', 'yes'),
  );

	$form['vt_ajax_slider_mini']['vt_ajax_slider_mini_preview_body'] = array(
    '#type' => 'select',
    '#title' => t('Show mini preview body?'),
    '#options' => $options_boolean,
    '#default_value' => variable_get('vt_ajax_slider_mini_preview_body', 'yes'),
  );

  $form['vt_ajax_slider_source'] = array(
    '#type' => 'fieldset',
    '#weight' => 2,
    '#title' => t('Content sorting configuration'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

	$form['vt_ajax_slider_source']['vt_ajax_slider_first_time'] = array(
    '#type' => 'select',
		'#options' => $option_number,
    '#title' => t('How many content for first load?'),
    '#default_value' => variable_get('vt_ajax_slider_first_time', '2'),
  );

	$form['vt_ajax_slider_source']['vt_ajax_slider_published'] = array(
    '#type' => 'select',
		'#options' => array('0' => 'Unpublished', '1' => 'Published', '2' => 'Both'),
    '#title' => t('Show published node or unpublished node?'),
    '#default_value' => variable_get('vt_ajax_slider_published', '1'),
  );

	$form['vt_ajax_slider_source']['vt_ajax_slider_sort_data'] = array(
    '#type' => 'select',
		'#options' => array('ASC' => 'Ascending - oldest first', 'DESC' => 'Descending - newest first'),
    '#title' => t('Sort direction for the displayed data'),
    '#default_value' => variable_get('vt_ajax_slider_sort_data', 'ASC'),
  );

	$form['vt_ajax_slider_content'] = array(
    '#type' => 'fieldset',
    '#weight' => 3,
    '#title' => t('Content configuration'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

	$form['vt_ajax_slider_content']['vt_ajax_slider_node_show_title'] = array(
    '#type' => 'select',
		'#options' => $options_boolean,
    '#title' => t('Show content title?'),
    '#default_value' => variable_get('vt_ajax_slider_node_show_title', 'yes'),
  );

	$form['vt_ajax_slider_content']['vt_ajax_slider_node_show_body'] = array(
    '#type' => 'select',
		'#options' => $options_boolean,
    '#title' => t('Show content body?'),
    '#default_value' => variable_get('vt_ajax_slider_node_show_body', 'yes'),
  );

	$form['vt_ajax_slider_content']['vt_ajax_slider_node_show_image'] = array(
    '#type' => 'select',
		'#options' => $options_boolean,
    '#title' => t('Show content image?'),
    '#default_value' => variable_get('vt_ajax_slider_node_show_image', 'yes'),
  );

	// Imagecache
	$form['vt_ajax_slider_imagecache'] = array(
    '#type' => 'fieldset',
    '#weight' => 10,
    '#title' => t('Imagecache configuration'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

	$form['vt_ajax_slider_imagecache']['vt_ajax_slider_content_width'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter width for slider main content imagecache'),
    '#default_value' => variable_get('vt_ajax_slider_content_width', '200'),
		'#field_suffix' => t('px'),
    '#size' => 5,
	);

	$form['vt_ajax_slider_imagecache']['vt_ajax_slider_content_height'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter height for slider main content imagecache'),
    '#default_value' => variable_get('vt_ajax_slider_content_height', '200'),
		'#field_suffix' => t('px'),
    '#size' => 5,
	);

	$form['vt_ajax_slider_imagecache']['vt_ajax_slider_preview_width'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter width for slider preview imagecache'),
    '#default_value' => variable_get('vt_ajax_slider_preview_width', '50'),
		'#field_suffix' => t('px'),
    '#size' => 5,
	);

	$form['vt_ajax_slider_imagecache']['vt_ajax_slider_preview_height'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter height for slider preview imagecache'),
    '#default_value' => variable_get('vt_ajax_slider_preview_height', '50'),
		'#field_suffix' => t('px'),
    '#size' => 5,
	);

  return system_settings_form($form);
}