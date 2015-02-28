<?php

function boson_breadcrumb($variables) {

   $breadcrumb = $variables['breadcrumb'];
  if (!empty($breadcrumb)) {

    $output = '<h2 class="element-invisible">' . t('You are here') . '</h2>';

	$breadcrumb[] = drupal_get_title();
    $output .= '<ul class="crumbs"><li>You are here:</li> '  . implode('  >  ', $breadcrumb) . '</ul>';
    return $output;
  }
}


function boson_preprocess_html(&$vars) {
	
  $bgklasa = theme_get_setting('theme_bg_pattern');
  $vars['classes_array'][] = drupal_html_class($bgklasa);
	
	
	drupal_add_css(path_to_theme() . '/css/main.css');
	
  
  // The Color Palette.
  $file = theme_get_setting('theme_color_palette');
  drupal_add_css(path_to_theme() . '/css/color-scheme/' . $file . '.css');
    

}


