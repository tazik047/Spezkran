<?php

function vt_slider_api_admin_settings() {
  // important variable to use
  $form['vt_slider_basic'] = array(
    '#type' => 'fieldset',
    '#weight' => 1,
    '#title' => t('Basic settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['vt_slider_basic']['vt_slider_api_source_content_type'] = array(
    '#type' => 'select',
		'#options' => node_type_get_names(),
    '#title' => t('Enable slider api for which content type?'),
		'#multiple' => true,
    '#default_value' => variable_get('vt_slider_api_source_content_type', 'article'),
  );
  if (module_exists('locale')) {
    $form['vt_slider_basic']['vt_slider_api_language'] = array(
    '#type' => 'select',
		'#options' => array('yes' => t('Yes'), 'no' => t('No')),
    '#title' => t('Only show node related to current language?'),
    '#default_value' => variable_get('vt_slider_api_language', 'no'),
    );
  } else {
    variable_set('vt_slider_api_language', 'no');
  }
  $form['#submit'][] = 'vtslider_admin_submit';

  return system_settings_form($form);
}

function vtslider_admin_submit($form, &$form_state) {

  // check and build the field first
  $fields = vtslide_fields();
  $instances = vtslide_instances();
  foreach ($fields as $key => $field) {
    $info = field_info_field($field['field_name']);
    if (empty($info)) field_create_field($field);
  }
  // check and build the instances
  $node_type = node_type_get_names();
  foreach ($node_type as $key => $value) {
    if (in_array($key, $form_state['values']['vt_slider_api_source_content_type'])) {
      foreach ($instances as $instance) {
        $check = field_read_instance($instance['entity_type'], $instance['field_name'], $key, $include_additional = array());
        $instance['bundle'] = $key;
        if (empty($check)) field_create_instance($instance);
      }
    } else {
      foreach ($instances as $instance) {
        $check = field_read_instance('node', $instance['field_name'], $key, $include_additional = array());
        $instance['bundle'] = $key;
        if (!empty($check)) field_delete_instance($instance, $field_cleanup = TRUE);
      }
    }
  }
}
