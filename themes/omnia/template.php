<?php
/**
 * Custom Galeria Template settings
 */
 
/**
 * page alter
 */
function omnia_page_alter(&$vars) {
	// Add custom varibales for scss
	$theme = superhero_get_theme();
	$theme->custom['header_height'] = theme_get_setting('superhero_header_height');
	$theme->custom['header_fixed_height'] = theme_get_setting('superhero_header_fixed_height');
	// Remove content from front page
	if (drupal_is_front_page()) {
		unset($vars['data']['content']);
	}
}

/**
 * Preprocess node
 */
function omnia_preprocess_node(&$vars) {
  $node = $vars['node'];
  if ($vars['view_mode'] == 'teaser_alt') {
    $vars['theme_hook_suggestions'][] = 'node__' . $node->type . '__teaser__alt';
    $vars['theme_hook_suggestions'][] = 'node__' . $node->nid . '__teaser_alt';
  }
}