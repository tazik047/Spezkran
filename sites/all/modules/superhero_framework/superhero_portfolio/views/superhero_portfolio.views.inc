<?php

/**
 * @file
 * Defines portfolio views styles
 */

/**
 * Implements hook_views_plugins
 */
function superhero_portfolio_views_plugins() {
	return array(
		'style' => array(
			'superhero_portfolio' => array(
				'title' => t('Superhero Portfolio'),
				'help' => t('Display the results as an Isotope Portfolio'),
				'handler' => 'superhero_portfolio_plugin_style_portfolio',
				'uses options' => TRUE,
				'uses row plugin' => TRUE,
				'uses row class' => TRUE,
				'type' => 'normal',
				'theme' => 'views_superhero_portfolio',
				'theme path' => drupal_get_path('module','superhero_portfolio') . '/theme',
				'theme file' => 'superhero_portfolio.theme.inc',
			),
		),
	);
}