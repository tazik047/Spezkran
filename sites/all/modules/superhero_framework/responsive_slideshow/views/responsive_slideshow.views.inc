<?php

/**
 * @file
 * Defines the views style plugin for the responsive carousel
 */

/**
 * Implements hook_views_plugins()
 */
function responsive_slideshow_views_plugins() {
	return array(
		'style' => array(
			'bx_slideshow' => array(
				'title' => t('BX Slideshow'),
				'help' => t('Display the results as a responsive slideshow'),
				'handler' => 'responsive_slideshow_plugin_style_bx_slideshow',
				'uses options' => TRUE,
				'uses row plugin' => TRUE,
				'uses row class' => TRUE,
				'type' => 'normal',
				'theme' => 'views_bx_slideshow',
				'theme path' => drupal_get_path('module','responsive_slideshow') . '/theme',
				'theme file' => 'responsive_slideshow.theme.inc',
			),
		),
	);
}

// !TODO: Preprocess function