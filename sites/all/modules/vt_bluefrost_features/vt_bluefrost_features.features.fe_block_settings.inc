<?php
/**
 * @file
 * vt_bluefrost_features.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function vt_bluefrost_features_default_fe_block_settings() {
  $export = array();

  // bartik
  $theme = array();

  $theme['block-bluefrost_postface_left'] = array(
    'module' => 'block',
    'theme' => 'bartik',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Sample Article',
    'cache' => -1,
    'machine_name' => 'bluefrost_postface_left',
  );

  $theme['block-bluefrost_postface_middle'] = array(
    'module' => 'block',
    'theme' => 'bartik',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Sample Article',
    'cache' => -1,
    'machine_name' => 'bluefrost_postface_middle',
  );

  $theme['block-bluefrost_postface_right'] = array(
    'module' => 'block',
    'theme' => 'bartik',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Sample Article',
    'cache' => -1,
    'machine_name' => 'bluefrost_postface_right',
  );

  $theme['block-bluefrost_preface_left'] = array(
    'module' => 'block',
    'theme' => 'bartik',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Sample Article',
    'cache' => -1,
    'machine_name' => 'bluefrost_preface_left',
  );

  $theme['block-bluefrost_preface_right'] = array(
    'module' => 'block',
    'theme' => 'bartik',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Sample Article',
    'cache' => -1,
    'machine_name' => 'bluefrost_preface_right',
  );

  $theme['block-bluefrost_preface_middle'] = array(
    'module' => 'block',
    'theme' => 'bartik',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Sample Article',
    'cache' => -1,
    'machine_name' => 'bluefrost_preface_middle',
  );

  $theme['block-bluefrost_footer_left'] = array(
    'module' => 'block',
    'theme' => 'bartik',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Sample Article',
    'cache' => -1,
    'machine_name' => 'bluefrost_footer_left',
  );

  $theme['block-gallerix_highlight'] = array(
    'module' => 'block',
    'theme' => 'bartik',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => '<front>',
    'title' => '<none>',
    'cache' => -1,
    'machine_name' => 'gallerix_highlight',
  );

  $theme['block-bluefrost_footer_middle'] = array(
    'module' => 'block',
    'theme' => 'bartik',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Sample Article',
    'cache' => -1,
    'machine_name' => 'bluefrost_footer_middle',
  );

  $theme['block-bluefrost_footer_right'] = array(
    'module' => 'block',
    'theme' => 'bartik',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Sample Article',
    'cache' => -1,
    'machine_name' => 'bluefrost_footer_right',
  );

  $theme['block-bluefrost_contact'] = array(
    'module' => 'block',
    'theme' => 'bartik',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'contact',
    'title' => 'Contact us information sample',
    'cache' => -1,
    'machine_name' => 'bluefrost_contact',
  );

  $theme['block-bluefrost_sidebar_second'] = array(
    'module' => 'block',
    'theme' => 'bartik',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Sample Article',
    'cache' => -1,
    'machine_name' => 'bluefrost_sidebar_second',
  );

  $theme['blog-recent'] = array(
    'module' => 'blog',
    'delta' => 'recent',
    'theme' => 'bartik',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['comment-recent'] = array(
    'module' => 'comment',
    'delta' => 'recent',
    'theme' => 'bartik',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => 'contact',
    'title' => '',
    'cache' => '1',
  );

  $theme['search-form'] = array(
    'module' => 'search',
    'delta' => 'form',
    'theme' => 'bartik',
    'status' => 0,
    'weight' => '-1',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => 'contact',
    'title' => '',
    'cache' => -1,
  );

  $theme['system-help'] = array(
    'module' => 'system',
    'delta' => 'help',
    'theme' => 'bartik',
    'status' => '1',
    'weight' => '0',
    'region' => 'help',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['user-login'] = array(
    'module' => 'user',
    'delta' => 'login',
    'theme' => 'bartik',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => 'contact',
    'title' => '',
    'cache' => -1,
  );

  $theme['user-new'] = array(
    'module' => 'user',
    'delta' => 'new',
    'theme' => 'bartik',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['user-online'] = array(
    'module' => 'user',
    'delta' => 'online',
    'theme' => 'bartik',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['vt_ajax_slider-vt_ajax_slider'] = array(
    'module' => 'vt_ajax_slider',
    'delta' => 'vt_ajax_slider',
    'theme' => 'bartik',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $export['bartik'] = $theme;

  // bluefrost
  $theme = array();

  $theme['block-bluefrost_postface_left'] = array(
    'module' => 'block',
    'theme' => 'bluefrost',
    'status' => '1',
    'weight' => '0',
    'region' => 'postface_left',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Sample Article',
    'cache' => -1,
    'machine_name' => 'bluefrost_postface_left',
  );

  $theme['block-bluefrost_postface_middle'] = array(
    'module' => 'block',
    'theme' => 'bluefrost',
    'status' => '1',
    'weight' => '0',
    'region' => 'postface_middle',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Sample Article',
    'cache' => -1,
    'machine_name' => 'bluefrost_postface_middle',
  );

  $theme['block-bluefrost_postface_right'] = array(
    'module' => 'block',
    'theme' => 'bluefrost',
    'status' => '1',
    'weight' => '0',
    'region' => 'postface_right',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Sample Article',
    'cache' => -1,
    'machine_name' => 'bluefrost_postface_right',
  );

  $theme['block-bluefrost_preface_left'] = array(
    'module' => 'block',
    'theme' => 'bluefrost',
    'status' => '1',
    'weight' => '0',
    'region' => 'preface_left',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Sample Article',
    'cache' => -1,
    'machine_name' => 'bluefrost_preface_left',
  );

  $theme['block-bluefrost_preface_right'] = array(
    'module' => 'block',
    'theme' => 'bluefrost',
    'status' => '1',
    'weight' => '0',
    'region' => 'preface_right',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Sample Article',
    'cache' => -1,
    'machine_name' => 'bluefrost_preface_right',
  );

  $theme['block-bluefrost_preface_middle'] = array(
    'module' => 'block',
    'theme' => 'bluefrost',
    'status' => '1',
    'weight' => '0',
    'region' => 'preface_middle',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Sample Article',
    'cache' => -1,
    'machine_name' => 'bluefrost_preface_middle',
  );

  $theme['block-bluefrost_footer_left'] = array(
    'module' => 'block',
    'theme' => 'bluefrost',
    'status' => '1',
    'weight' => '0',
    'region' => 'footer_left',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Sample Article',
    'cache' => -1,
    'machine_name' => 'bluefrost_footer_left',
  );

  $theme['block-gallerix_highlight'] = array(
    'module' => 'block',
    'theme' => 'bluefrost',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => '<front>',
    'title' => '<none>',
    'cache' => -1,
    'machine_name' => 'gallerix_highlight',
  );

  $theme['block-bluefrost_footer_middle'] = array(
    'module' => 'block',
    'theme' => 'bluefrost',
    'status' => '1',
    'weight' => '0',
    'region' => 'footer_middle',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Sample Article',
    'cache' => -1,
    'machine_name' => 'bluefrost_footer_middle',
  );

  $theme['block-bluefrost_footer_right'] = array(
    'module' => 'block',
    'theme' => 'bluefrost',
    'status' => '1',
    'weight' => '0',
    'region' => 'footer_right',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Sample Article',
    'cache' => -1,
    'machine_name' => 'bluefrost_footer_right',
  );

  $theme['block-bluefrost_contact'] = array(
    'module' => 'block',
    'theme' => 'bluefrost',
    'status' => '1',
    'weight' => '-25',
    'region' => 'sidebar_first',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'contact',
    'title' => 'Contact us information sample',
    'cache' => -1,
    'machine_name' => 'bluefrost_contact',
  );

  $theme['block-bluefrost_sidebar_second'] = array(
    'module' => 'block',
    'theme' => 'bluefrost',
    'status' => '1',
    'weight' => '-26',
    'region' => 'sidebar_second',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Sample Article',
    'cache' => -1,
    'machine_name' => 'bluefrost_sidebar_second',
  );

  $theme['blog-recent'] = array(
    'module' => 'blog',
    'delta' => 'recent',
    'theme' => 'bluefrost',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['comment-recent'] = array(
    'module' => 'comment',
    'delta' => 'recent',
    'theme' => 'bluefrost',
    'status' => '1',
    'weight' => '-21',
    'region' => 'sidebar_first',
    'custom' => '0',
    'visibility' => '0',
    'pages' => 'contact',
    'title' => '',
    'cache' => '1',
  );

  $theme['search-form'] = array(
    'module' => 'search',
    'delta' => 'form',
    'theme' => 'bluefrost',
    'status' => '1',
    'weight' => '-24',
    'region' => 'sidebar_first',
    'custom' => '0',
    'visibility' => '0',
    'pages' => 'contact',
    'title' => '',
    'cache' => -1,
  );

  $theme['system-help'] = array(
    'module' => 'system',
    'delta' => 'help',
    'theme' => 'bluefrost',
    'status' => '1',
    'weight' => '0',
    'region' => 'help',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['user-login'] = array(
    'module' => 'user',
    'delta' => 'login',
    'theme' => 'bluefrost',
    'status' => '1',
    'weight' => '-22',
    'region' => 'sidebar_first',
    'custom' => '0',
    'visibility' => '0',
    'pages' => 'contact',
    'title' => '',
    'cache' => -1,
  );

  $theme['user-new'] = array(
    'module' => 'user',
    'delta' => 'new',
    'theme' => 'bluefrost',
    'status' => '1',
    'weight' => '-24',
    'region' => 'sidebar_second',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['user-online'] = array(
    'module' => 'user',
    'delta' => 'online',
    'theme' => 'bluefrost',
    'status' => '1',
    'weight' => '-25',
    'region' => 'sidebar_second',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['vt_ajax_slider-vt_ajax_slider'] = array(
    'module' => 'vt_ajax_slider',
    'delta' => 'vt_ajax_slider',
    'theme' => 'bluefrost',
    'status' => '1',
    'weight' => '-20',
    'region' => 'slider',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $export['bluefrost'] = $theme;

  // gallerix
  $theme = array();

  $theme['block-bluefrost_postface_left'] = array(
    'module' => 'block',
    'theme' => 'gallerix',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Sample Article',
    'cache' => -1,
    'machine_name' => 'bluefrost_postface_left',
  );

  $theme['block-bluefrost_postface_middle'] = array(
    'module' => 'block',
    'theme' => 'gallerix',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Sample Article',
    'cache' => -1,
    'machine_name' => 'bluefrost_postface_middle',
  );

  $theme['block-bluefrost_postface_right'] = array(
    'module' => 'block',
    'theme' => 'gallerix',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Sample Article',
    'cache' => -1,
    'machine_name' => 'bluefrost_postface_right',
  );

  $theme['block-bluefrost_preface_left'] = array(
    'module' => 'block',
    'theme' => 'gallerix',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Sample Article',
    'cache' => -1,
    'machine_name' => 'bluefrost_preface_left',
  );

  $theme['block-bluefrost_preface_right'] = array(
    'module' => 'block',
    'theme' => 'gallerix',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Sample Article',
    'cache' => -1,
    'machine_name' => 'bluefrost_preface_right',
  );

  $theme['block-bluefrost_preface_middle'] = array(
    'module' => 'block',
    'theme' => 'gallerix',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Sample Article',
    'cache' => -1,
    'machine_name' => 'bluefrost_preface_middle',
  );

  $theme['block-bluefrost_footer_left'] = array(
    'module' => 'block',
    'theme' => 'gallerix',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Sample Article',
    'cache' => -1,
    'machine_name' => 'bluefrost_footer_left',
  );

  $theme['block-gallerix_highlight'] = array(
    'module' => 'block',
    'theme' => 'gallerix',
    'status' => '1',
    'weight' => '0',
    'region' => 'highlight',
    'custom' => '0',
    'visibility' => '1',
    'pages' => '<front>',
    'title' => '<none>',
    'cache' => -1,
    'machine_name' => 'gallerix_highlight',
  );

  $theme['block-bluefrost_footer_middle'] = array(
    'module' => 'block',
    'theme' => 'gallerix',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Sample Article',
    'cache' => -1,
    'machine_name' => 'bluefrost_footer_middle',
  );

  $theme['block-bluefrost_footer_right'] = array(
    'module' => 'block',
    'theme' => 'gallerix',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Sample Article',
    'cache' => -1,
    'machine_name' => 'bluefrost_footer_right',
  );

  $theme['block-bluefrost_contact'] = array(
    'module' => 'block',
    'theme' => 'gallerix',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'contact',
    'title' => 'Contact us information sample',
    'cache' => -1,
    'machine_name' => 'bluefrost_contact',
  );

  $theme['block-bluefrost_sidebar_second'] = array(
    'module' => 'block',
    'theme' => 'gallerix',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Sample Article',
    'cache' => -1,
    'machine_name' => 'bluefrost_sidebar_second',
  );

  $theme['blog-recent'] = array(
    'module' => 'blog',
    'delta' => 'recent',
    'theme' => 'gallerix',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['comment-recent'] = array(
    'module' => 'comment',
    'delta' => 'recent',
    'theme' => 'gallerix',
    'status' => '1',
    'weight' => '0',
    'region' => 'sidebar_second',
    'custom' => '0',
    'visibility' => '0',
    'pages' => 'contact',
    'title' => '',
    'cache' => '1',
  );

  $theme['search-form'] = array(
    'module' => 'search',
    'delta' => 'form',
    'theme' => 'gallerix',
    'status' => '1',
    'weight' => '-1',
    'region' => 'sidebar_first',
    'custom' => '0',
    'visibility' => '0',
    'pages' => 'contact',
    'title' => '',
    'cache' => -1,
  );

  $theme['system-help'] = array(
    'module' => 'system',
    'delta' => 'help',
    'theme' => 'gallerix',
    'status' => '1',
    'weight' => '0',
    'region' => 'help',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['user-login'] = array(
    'module' => 'user',
    'delta' => 'login',
    'theme' => 'gallerix',
    'status' => '1',
    'weight' => '0',
    'region' => 'sidebar_first',
    'custom' => '0',
    'visibility' => '0',
    'pages' => 'contact',
    'title' => '',
    'cache' => -1,
  );

  $theme['user-new'] = array(
    'module' => 'user',
    'delta' => 'new',
    'theme' => 'gallerix',
    'status' => '1',
    'weight' => '0',
    'region' => 'sidebar_first',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['user-online'] = array(
    'module' => 'user',
    'delta' => 'online',
    'theme' => 'gallerix',
    'status' => '1',
    'weight' => '0',
    'region' => 'sidebar_second',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['vt_ajax_slider-vt_ajax_slider'] = array(
    'module' => 'vt_ajax_slider',
    'delta' => 'vt_ajax_slider',
    'theme' => 'gallerix',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $export['gallerix'] = $theme;

  // seven
  $theme = array();

  $theme['block-bluefrost_postface_left'] = array(
    'module' => 'block',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Sample Article',
    'cache' => -1,
    'machine_name' => 'bluefrost_postface_left',
  );

  $theme['block-bluefrost_postface_middle'] = array(
    'module' => 'block',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Sample Article',
    'cache' => -1,
    'machine_name' => 'bluefrost_postface_middle',
  );

  $theme['block-bluefrost_postface_right'] = array(
    'module' => 'block',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Sample Article',
    'cache' => -1,
    'machine_name' => 'bluefrost_postface_right',
  );

  $theme['block-bluefrost_preface_left'] = array(
    'module' => 'block',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Sample Article',
    'cache' => -1,
    'machine_name' => 'bluefrost_preface_left',
  );

  $theme['block-bluefrost_preface_right'] = array(
    'module' => 'block',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Sample Article',
    'cache' => -1,
    'machine_name' => 'bluefrost_preface_right',
  );

  $theme['block-bluefrost_preface_middle'] = array(
    'module' => 'block',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Sample Article',
    'cache' => -1,
    'machine_name' => 'bluefrost_preface_middle',
  );

  $theme['block-bluefrost_footer_left'] = array(
    'module' => 'block',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Sample Article',
    'cache' => -1,
    'machine_name' => 'bluefrost_footer_left',
  );

  $theme['block-gallerix_highlight'] = array(
    'module' => 'block',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => '<front>',
    'title' => '<none>',
    'cache' => -1,
    'machine_name' => 'gallerix_highlight',
  );

  $theme['block-bluefrost_footer_middle'] = array(
    'module' => 'block',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Sample Article',
    'cache' => -1,
    'machine_name' => 'bluefrost_footer_middle',
  );

  $theme['block-bluefrost_footer_right'] = array(
    'module' => 'block',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Sample Article',
    'cache' => -1,
    'machine_name' => 'bluefrost_footer_right',
  );

  $theme['block-bluefrost_contact'] = array(
    'module' => 'block',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'contact',
    'title' => 'Contact us information sample',
    'cache' => -1,
    'machine_name' => 'bluefrost_contact',
  );

  $theme['block-bluefrost_sidebar_second'] = array(
    'module' => 'block',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Sample Article',
    'cache' => -1,
    'machine_name' => 'bluefrost_sidebar_second',
  );

  $theme['blog-recent'] = array(
    'module' => 'blog',
    'delta' => 'recent',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['comment-recent'] = array(
    'module' => 'comment',
    'delta' => 'recent',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => 'contact',
    'title' => '',
    'cache' => '1',
  );

  $theme['search-form'] = array(
    'module' => 'search',
    'delta' => 'form',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '-10',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => 'contact',
    'title' => '',
    'cache' => -1,
  );

  $theme['system-help'] = array(
    'module' => 'system',
    'delta' => 'help',
    'theme' => 'seven',
    'status' => '1',
    'weight' => '0',
    'region' => 'help',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['user-login'] = array(
    'module' => 'user',
    'delta' => 'login',
    'theme' => 'seven',
    'status' => '1',
    'weight' => '10',
    'region' => 'content',
    'custom' => '0',
    'visibility' => '0',
    'pages' => 'contact',
    'title' => '',
    'cache' => -1,
  );

  $theme['user-new'] = array(
    'module' => 'user',
    'delta' => 'new',
    'theme' => 'seven',
    'status' => '1',
    'weight' => '0',
    'region' => 'dashboard_sidebar',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['user-online'] = array(
    'module' => 'user',
    'delta' => 'online',
    'theme' => 'seven',
    'status' => '1',
    'weight' => '0',
    'region' => 'dashboard_inactive',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['vt_ajax_slider-vt_ajax_slider'] = array(
    'module' => 'vt_ajax_slider',
    'delta' => 'vt_ajax_slider',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $export['seven'] = $theme;

  // sigmaone
  $theme = array();

  $theme['block-bluefrost_postface_left'] = array(
    'module' => 'block',
    'theme' => 'sigmaone',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Sample Article',
    'cache' => -1,
    'machine_name' => 'bluefrost_postface_left',
  );

  $theme['block-bluefrost_postface_middle'] = array(
    'module' => 'block',
    'theme' => 'sigmaone',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Sample Article',
    'cache' => -1,
    'machine_name' => 'bluefrost_postface_middle',
  );

  $theme['block-bluefrost_postface_right'] = array(
    'module' => 'block',
    'theme' => 'sigmaone',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Sample Article',
    'cache' => -1,
    'machine_name' => 'bluefrost_postface_right',
  );

  $theme['block-bluefrost_preface_left'] = array(
    'module' => 'block',
    'theme' => 'sigmaone',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Sample Article',
    'cache' => -1,
    'machine_name' => 'bluefrost_preface_left',
  );

  $theme['block-bluefrost_preface_right'] = array(
    'module' => 'block',
    'theme' => 'sigmaone',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Sample Article',
    'cache' => -1,
    'machine_name' => 'bluefrost_preface_right',
  );

  $theme['block-bluefrost_preface_middle'] = array(
    'module' => 'block',
    'theme' => 'sigmaone',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Sample Article',
    'cache' => -1,
    'machine_name' => 'bluefrost_preface_middle',
  );

  $theme['block-bluefrost_footer_left'] = array(
    'module' => 'block',
    'theme' => 'sigmaone',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Sample Article',
    'cache' => -1,
    'machine_name' => 'bluefrost_footer_left',
  );

  $theme['block-gallerix_highlight'] = array(
    'module' => 'block',
    'theme' => 'sigmaone',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => '<front>',
    'title' => '<none>',
    'cache' => -1,
    'machine_name' => 'gallerix_highlight',
  );

  $theme['block-bluefrost_footer_middle'] = array(
    'module' => 'block',
    'theme' => 'sigmaone',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Sample Article',
    'cache' => -1,
    'machine_name' => 'bluefrost_footer_middle',
  );

  $theme['block-bluefrost_footer_right'] = array(
    'module' => 'block',
    'theme' => 'sigmaone',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Sample Article',
    'cache' => -1,
    'machine_name' => 'bluefrost_footer_right',
  );

  $theme['block-bluefrost_contact'] = array(
    'module' => 'block',
    'theme' => 'sigmaone',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'contact',
    'title' => 'Contact us information sample',
    'cache' => -1,
    'machine_name' => 'bluefrost_contact',
  );

  $theme['block-bluefrost_sidebar_second'] = array(
    'module' => 'block',
    'theme' => 'sigmaone',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Sample Article',
    'cache' => -1,
    'machine_name' => 'bluefrost_sidebar_second',
  );

  $theme['blog-recent'] = array(
    'module' => 'blog',
    'delta' => 'recent',
    'theme' => 'sigmaone',
    'status' => '1',
    'weight' => '2',
    'region' => 'dashboard_main',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['comment-recent'] = array(
    'module' => 'comment',
    'delta' => 'recent',
    'theme' => 'sigmaone',
    'status' => '1',
    'weight' => '0',
    'region' => 'dashboard_main',
    'custom' => '0',
    'visibility' => '0',
    'pages' => 'contact',
    'title' => '',
    'cache' => '1',
  );

  $theme['search-form'] = array(
    'module' => 'search',
    'delta' => 'form',
    'theme' => 'sigmaone',
    'status' => '1',
    'weight' => '-1',
    'region' => 'sidebar_first',
    'custom' => '0',
    'visibility' => '0',
    'pages' => 'contact',
    'title' => '',
    'cache' => -1,
  );

  $theme['system-help'] = array(
    'module' => 'system',
    'delta' => 'help',
    'theme' => 'sigmaone',
    'status' => '1',
    'weight' => '0',
    'region' => 'help',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['user-login'] = array(
    'module' => 'user',
    'delta' => 'login',
    'theme' => 'sigmaone',
    'status' => '1',
    'weight' => '0',
    'region' => 'sidebar_first',
    'custom' => '0',
    'visibility' => '0',
    'pages' => 'contact',
    'title' => '',
    'cache' => -1,
  );

  $theme['user-new'] = array(
    'module' => 'user',
    'delta' => 'new',
    'theme' => 'sigmaone',
    'status' => '1',
    'weight' => '0',
    'region' => 'dashboard_sidebar',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['user-online'] = array(
    'module' => 'user',
    'delta' => 'online',
    'theme' => 'sigmaone',
    'status' => '1',
    'weight' => '1',
    'region' => 'dashboard_sidebar',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['vt_ajax_slider-vt_ajax_slider'] = array(
    'module' => 'vt_ajax_slider',
    'delta' => 'vt_ajax_slider',
    'theme' => 'sigmaone',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $export['sigmaone'] = $theme;

  $theme_default = variable_get('theme_default', 'garland');
  $themes = list_themes();
  foreach ($export as $theme_key => $settings) {
    if ($theme_key != $theme_default && empty($themes[$theme_key]->status)) {
      unset($export[$theme_key]);
    }
  }
  return $export;
}
