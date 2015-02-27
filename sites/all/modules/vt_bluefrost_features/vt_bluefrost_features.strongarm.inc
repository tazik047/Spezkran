<?php
/**
 * @file
 * vt_bluefrost_features.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function vt_bluefrost_features_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'vt_ajax_slider_animation_mode';
  $strongarm->value = 'fold';
  $export['vt_ajax_slider_animation_mode'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'vt_ajax_slider_animation_time';
  $strongarm->value = '1500';
  $export['vt_ajax_slider_animation_time'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'vt_ajax_slider_autoslide';
  $strongarm->value = 'yes';
  $export['vt_ajax_slider_autoslide'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'vt_ajax_slider_autoslide_mode';
  $strongarm->value = 'return';
  $export['vt_ajax_slider_autoslide_mode'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'vt_ajax_slider_autoslide_timer';
  $strongarm->value = '20000';
  $export['vt_ajax_slider_autoslide_timer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'vt_ajax_slider_button';
  $strongarm->value = 'yes';
  $export['vt_ajax_slider_button'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'vt_ajax_slider_content_height';
  $strongarm->value = '200';
  $export['vt_ajax_slider_content_height'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'vt_ajax_slider_content_width';
  $strongarm->value = '200';
  $export['vt_ajax_slider_content_width'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'vt_ajax_slider_first_time';
  $strongarm->value = '3';
  $export['vt_ajax_slider_first_time'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'vt_ajax_slider_mini_preview';
  $strongarm->value = 'yes';
  $export['vt_ajax_slider_mini_preview'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'vt_ajax_slider_mini_preview_body';
  $strongarm->value = 'yes';
  $export['vt_ajax_slider_mini_preview_body'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'vt_ajax_slider_mini_preview_image';
  $strongarm->value = 'yes';
  $export['vt_ajax_slider_mini_preview_image'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'vt_ajax_slider_mini_preview_title';
  $strongarm->value = 'yes';
  $export['vt_ajax_slider_mini_preview_title'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'vt_ajax_slider_node_show_body';
  $strongarm->value = 'yes';
  $export['vt_ajax_slider_node_show_body'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'vt_ajax_slider_node_show_image';
  $strongarm->value = 'yes';
  $export['vt_ajax_slider_node_show_image'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'vt_ajax_slider_node_show_title';
  $strongarm->value = 'yes';
  $export['vt_ajax_slider_node_show_title'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'vt_ajax_slider_preview_height';
  $strongarm->value = '50';
  $export['vt_ajax_slider_preview_height'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'vt_ajax_slider_preview_width';
  $strongarm->value = '50';
  $export['vt_ajax_slider_preview_width'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'vt_ajax_slider_progress_bar';
  $strongarm->value = 'yes';
  $export['vt_ajax_slider_progress_bar'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'vt_ajax_slider_published';
  $strongarm->value = '1';
  $export['vt_ajax_slider_published'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'vt_ajax_slider_theme';
  $strongarm->value = 'bluefrost';
  $export['vt_ajax_slider_theme'] = $strongarm;

  return $export;
}
