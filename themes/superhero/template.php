<?php

/**
 * @file
 * Set up main functionality for the theme
 */
require_once dirname(__FILE__) . '/inc/superhero.inc';
require_once dirname(__FILE__) . '/inc/base.inc';
require_once dirname(__FILE__) . '/includes/theme.inc';
require_once dirname(__FILE__) . '/includes/menu.inc';
require_once dirname(__FILE__) . '/includes/pager.inc';
require_once dirname(__FILE__) . '/includes/form.inc';

require_once dirname(__FILE__) . '/includes/scss.inc.php';

/**
 * Implements hook_theme
 */
function superhero_theme($existing, $type, $theme, $path) {
  return array(
      'section' => array(
          'template' => 'section',
          'path' => $path . '/templates/base',
          'render element' => 'elements',
          'pattern' => 'section__',
          'preprocess functions' => array(
              'template_preprocess',
              'template_preprocess_section',
          ),
          'process functions' => array(
              'template_process',
              'template_process_section',
          ),
      )
  );
}

/**
 * Preprocess HTML
 */
function superhero_preprocess_html(&$vars) {
	$theme = superhero_get_theme();
	$vars['classes_array'][] = theme_get_setting('superhero_layout');
	$direction = isset($_SESSION['superhero_default_direction'])?$_SESSION['superhero_default_direction']:null;
	if(empty($direction)){
		$direction = theme_get_setting('superhero_direction');
	}
	if(empty($direction)){
		$direction = 'ltr';
	}
	$_SESSION['superhero_default_direction'] = $direction;
  $vars['classes_array'][] = $direction;
  drupal_add_js(drupal_get_path('theme', 'superhero') . '/js/smoothscroll.js');
  drupal_add_css(drupal_get_path('theme', 'superhero') . '/vendor/bootstrap/css/bootstrap.min.css');
  drupal_add_css(drupal_get_path('theme', 'superhero') . '/vendor/bootstrap/css/bootstrap-theme.min.css');
  if ($theme->settings['responsive']) {
    $viewport = array(
        '#type' => 'html_tag',
        '#tag' => 'meta',
        '#attributes' => array(
            'name' => 'viewport',
            'content' => 'width=device-width, initial-scale=1, maximum-scale=1',
        )
    );
    drupal_add_html_head($viewport, 'viewport');
  }
}

/**
 * Preprocess Page
 */
function superhero_preprocess_page(&$vars) {
  $theme = superhero_get_theme();
  $theme->page = &$vars;
  $vars['attributes_array']['class'] = array('body');

  // Primary nav
  $vars['primary_nav'] = FALSE;
  if ($vars['main_menu']) {
    // Build links
    $vars['primary_nav'] = menu_tree(variable_get('menu_main_links_source', 'main-menu'));
    // Provide default theme wrapper function
    $vars['primary_nav']['#theme_wrappers'] = array('menu_tree__primary');
  }

  $default_preset = $theme->settings['default_preset'];
	//$theme_path = drupal_get_path('theme',$theme->theme);
  //$preset_file = $theme_path."/css/" . $theme->theme . "-preset" . ($default_preset + 1) . ".css";
  //drupal_add_css($preset_file, array(
  ////    'type' => 'file',
  //    'group' => CSS_THEME
  //));
	$force = false;
	$superhero_base_url = variable_get('superhero_base_url','');
	global $base_url;
	if($superhero_base_url != $base_url){
		$force = true;
	}
	variable_set('superhero_base_url', $base_url);
  require_once dirname(__FILE__) . '/includes/superhero_scss.php';
  $scss = new Superhero_scss($theme);
	if(!file_exists('public://css')){
		drupal_mkdir('public://css');
	}
  $file = $scss->outputFile('public://css/' . $theme->theme . '-theme-preset' . ($default_preset + 1) . '.css',$force);
  drupal_add_css($file, array(
      'type' => 'file',
      'group' => CSS_THEME
  ));
}

/**
 * Preprocess node
 */
function superhero_preprocess_node(&$vars) {
  $node = $vars['node'];
  if ($vars['view_mode'] == 'teaser') {
    $vars['theme_hook_suggestions'][] = 'node__' . $node->type . '__teaser';
    $vars['theme_hook_suggestions'][] = 'node__' . $node->nid . '__teaser';
  }
}

/**
 * Preprocess block
 */
/* function superhero_preprocess_block(&$vars) {
  // Use a bare template for the page's main content.
  if ($vars['block_html_id'] == 'block-system-main') {
  $vars['theme_hook_suggestions'][] = 'block__no_wrapper';
  }
  } */

/**
 * Menu tree: Primary
 */
function superhero_menu_tree__primary(&$vars) {
  return '<ul class="menu nav">' . $vars['tree'] . '</ul>';
}

/**
 * Preprocess section
 */
function template_preprocess_section(&$vars) {
  $vars['theme_hook_suggestions'][] = 'section__' . $vars['elements']['#section'];
  $vars['section'] = $vars['elements']['#section'];
  $vars['content'] = $vars['elements']['#children'];
  $vars['full_width'] = $vars['elements']['#data']['fullwidth'];
  $vars['sticky'] = $vars['elements']['#data']['sticky'];
	$margin = $vars['elements']['#data']['style_margin'];
	$padding = $vars['elements']['#data']['style_padding'];
	$background = $vars['elements']['#data']['style_background'];
	$custom_class = $vars['elements']['#data']['custom_class'];
	$vars['attributes_array']['id'] = drupal_html_id('section-' . $vars['section']);
  // Bootstrap responsive
  $keys = array(
      'vphone' => 'visible-xs',
      'vtablet' => 'visible-sm',
      'vdesktop' => 'visible-md visible-lg',
      'hphone' => 'hidden-xs',
      'htablet' => 'hidden-sm',
      'hdesktop' => 'hidden-md hidden-lg',
      'sticky' => 'superhero-sticky'
  );
  $vars['classes_array'] = array('section', $vars['attributes_array']['id']);
  foreach ($keys as $key => $class) {
    if ($vars['elements']['#data'][$key]) {
      $vars['classes_array'][] = $class;
    }
  }

  $vars['attributes_array']['class'] = $vars['classes_array'];
	if(!empty($custom_class)){
		$vars['classes_array'][] = $custom_class;
	}
  $vars['attributes_array']['class'] = $vars['classes_array'];
	$custom_style = "";
	if(trim($margin) != ''){
		$custom_style .= "margin:{$margin};";
	}
	if(trim($padding) != ''){
		$custom_style .= "padding:{$padding};";
	}
	if(trim($background)){
		$custom_style .= "background-color:{$background};";
	}
	if($custom_style){
		$vars['attributes_array']['style'] = "{$custom_style}";
	}
}

/**
 * Preprocess Region
 */
function superhero_preprocess_region(&$vars) {
  if (isset($vars['elements']['#data'])) {
		//xs,sm,md,lg
    $vars['xscolumns'] = $vars['elements']['#data']['xscolumns'];
    $vars['smcolumns'] = $vars['elements']['#data']['smcolumns'];
    $vars['mdcolumns'] = $vars['elements']['#data']['mdcolumns'];
    $vars['lgcolumns'] = $vars['elements']['#data']['lgcolumns'];
		if($vars['xscolumns']){
			$vars['classes_array'][] = 'col-xs-' . $vars['xscolumns'];
		}
		if($vars['smcolumns']){
			$vars['classes_array'][] = 'col-sm-' . $vars['smcolumns'];
		}
		if($vars['mdcolumns']){
			$vars['classes_array'][] = 'col-md-' . $vars['mdcolumns'];
		}
		if($vars['lgcolumns']){
			$vars['classes_array'][] = 'col-lg-' . $vars['lgcolumns'];
		}
  }
}

/**
 * Process Region
 */
function superhero_process_region(&$vars) {
  $theme = superhero_get_theme();
  switch ($vars['elements']['#region']) {
    case 'logo':
      $vars['logo'] = $theme->page['logo'];
      $vars['logo_img'] = !is_null($vars['logo']) ? '<img src="' . $vars['logo'] . '" id="logo"/>' : '';
      $vars['linked_logo'] = !is_null($vars['logo']) ? l($vars['logo_img'], '<front>', array('html' => TRUE, 'attributes' => array('rel' => 'home'))) : '';
      break;
    case 'menu':
      $vars['main_menu'] = $theme->page['main_menu'];
      $vars['secondary_menu'] = $theme->page['secondary_menu'];
      $vars['primary_nav'] = $theme->page['primary_nav'];
      break;
    case 'content':
      $vars['messages'] = $theme->page['messages'];
      $vars['title_prefix'] = $theme->page['title_prefix'];
      $vars['title'] = $theme->page['title'];
      $vars['title_suffix'] = $theme->page['title_suffix'];
      $vars['tabs'] = $theme->page['tabs'];
      $vars['action_links'] = $theme->page['action_links'];
      $vars['feed_icons'] = $theme->page['feed_icons'];
      break;
  }
}

/**
 * Implements hook_css_alter
 */
function superhero_css_alter(&$css) {
  
}

/**
 * Implements hook_page_alter
 */
function superhero_page_alter(&$vars) {
  $theme = superhero_get_theme();
  $data = array();

  foreach ($theme->regions as $region => $item) {
    if ($item['enabled'] && $theme->sections[$item['section']]['enabled'] && ($item['force'] || !empty($vars[$region]))) {
      $data['data'][$item['section']][$region] = !empty($vars[$region]) ? $vars[$region] : array();
      $data['data'][$item['section']][$region]['#weight'] = (int) $item['weight'];
      $data['data'][$item['section']][$region]['#data'] = $item;

      if (empty($vars[$region])) {
        $data['data'][$item['section']][$region]['#region'] = $region;
        $data['data'][$item['section']][$region]['#theme_wrappers'] = array('region');
      }
    } elseif (!empty($vars[$region])) {
      $vars['#excluded'][$region] = !empty($vars[$region]) ? $vars[$region] : array();
      $vars['#excluded'][$region]['#weight'] = (int) $item['weight'];
      $vars['#excluded'][$region]['#data'] = $item;
    }
    unset($vars[$region]);
  }

  foreach ($theme->sections as $section => $item) {
    if ($item['enabled'] && !empty($data['data'][$item['section']])) {
      if (isset($item['primary']) && isset($data['data'][$section][$item['primary']])) {
        superhero_calculate_primary($data['data'][$section], $item['primary']);
      }

      $data['data'][$section]['#theme_wrappers'] = array('section');
      $data['data'][$section]['#section'] = $section;
      $data['data'][$section]['#weight'] = (int) $item['weight'];
      $data['data'][$section]['#data'] = $item;
    }
  }

  $vars = array_merge($vars, $data);
}

/**
 * Implement hook_breadcrumd
 */
function superhero_breadcrumb($variables) {
  $breadcrumb = $variables['breadcrumb'];

  if (!empty($breadcrumb)) {
    // Provide a navigational heading to give context for breadcrumb links to
    // screen-reader users. Make the heading invisible with .element-invisible.
    $output = '<h2 class="element-invisible">' . t('You are here') . '</h2>';

    $output .= '<div class="breadcrumb">' . implode('<span class="divider">/</span>', $breadcrumb) . '</div>';
    return $output;
  }
}