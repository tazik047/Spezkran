<?php

function superhero_portfolio_views_default_views() {
	$views = array();
	
	$view = new view();
	$view->name = 'superhero_portfolio';
	$view->description = 'Displays portfolio items in an isotope grid';
	$view->tag = 'default';
	$view->base_table = 'node';
	$view->human_name = 'Portfolio';
	$view->core = 7;
	$view->api_version = '3.0';
	$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
	
	/* Display: Master */
	$handler = $view->new_display('default', 'Master', 'default');
	$handler->display->display_options['use_more_always'] = FALSE;
	$handler->display->display_options['access']['type'] = 'perm';
	$handler->display->display_options['cache']['type'] = 'none';
	$handler->display->display_options['query']['type'] = 'views_query';
	$handler->display->display_options['exposed_form']['type'] = 'basic';
	$handler->display->display_options['pager']['type'] = 'full';
	$handler->display->display_options['style_plugin'] = 'superhero_portfolio';
	$handler->display->display_options['style_options']['columns'] = '2';
	$handler->display->display_options['style_options']['use_filter'] = 1;
	$handler->display->display_options['style_options']['filter_vocabulary'] = '2';
	$handler->display->display_options['row_plugin'] = 'node';
	$handler->display->display_options['row_options']['view_mode'] = 'superhero_portfolio';
	$handler->display->display_options['row_options']['links'] = FALSE;
	/* Field: Content: Title */
	$handler->display->display_options['fields']['title']['id'] = 'title';
	$handler->display->display_options['fields']['title']['table'] = 'node';
	$handler->display->display_options['fields']['title']['field'] = 'title';
	$handler->display->display_options['fields']['title']['label'] = '';
	$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
	$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
	/* Sort criterion: Content: Post date */
	$handler->display->display_options['sorts']['created']['id'] = 'created';
	$handler->display->display_options['sorts']['created']['table'] = 'node';
	$handler->display->display_options['sorts']['created']['field'] = 'created';
	$handler->display->display_options['sorts']['created']['order'] = 'DESC';
	/* Filter criterion: Content: Published */
	$handler->display->display_options['filters']['status']['id'] = 'status';
	$handler->display->display_options['filters']['status']['table'] = 'node';
	$handler->display->display_options['filters']['status']['field'] = 'status';
	$handler->display->display_options['filters']['status']['value'] = 1;
	$handler->display->display_options['filters']['status']['group'] = 1;
	$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
	
	/* Display: Portfolio 2 */
	$handler = $view->new_display('page', 'Portfolio 2', 'page_1');
	$handler->display->display_options['path'] = 'portfolio/2';
	
	/* Display: Portfolio 3 */
	$handler = $view->new_display('page', 'Portfolio 3', 'page_2');
	$handler->display->display_options['defaults']['style_plugin'] = FALSE;
	$handler->display->display_options['style_plugin'] = 'superhero_portfolio';
	$handler->display->display_options['style_options']['columns'] = '3';
	$handler->display->display_options['style_options']['use_filter'] = 1;
	$handler->display->display_options['style_options']['filter_vocabulary'] = '2';
	$handler->display->display_options['defaults']['style_options'] = FALSE;
	$handler->display->display_options['defaults']['row_plugin'] = FALSE;
	$handler->display->display_options['row_plugin'] = 'node';
	$handler->display->display_options['row_options']['view_mode'] = 'superhero_portfolio';
	$handler->display->display_options['row_options']['links'] = FALSE;
	$handler->display->display_options['defaults']['row_options'] = FALSE;
	$handler->display->display_options['path'] = 'portfolio/3';
	
	/* Display: Portfolio 4 */
	$handler = $view->new_display('page', 'Portfolio 4', 'page_3');
	$handler->display->display_options['defaults']['style_plugin'] = FALSE;
	$handler->display->display_options['style_plugin'] = 'superhero_portfolio';
	$handler->display->display_options['style_options']['columns'] = '4';
	$handler->display->display_options['style_options']['use_filter'] = 1;
	$handler->display->display_options['style_options']['filter_vocabulary'] = '2';
	$handler->display->display_options['defaults']['style_options'] = FALSE;
	$handler->display->display_options['defaults']['row_plugin'] = FALSE;
	$handler->display->display_options['row_plugin'] = 'node';
	$handler->display->display_options['row_options']['view_mode'] = 'superhero_portfolio';
	$handler->display->display_options['row_options']['links'] = FALSE;
	$handler->display->display_options['defaults']['row_options'] = FALSE;
	$handler->display->display_options['path'] = 'portfolio/4';
	
	$views[$view->name] = $view;

	return $views;
}