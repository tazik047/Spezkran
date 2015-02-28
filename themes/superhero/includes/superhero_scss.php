<?php

require_once dirname(__FILE__) . '/scss.inc.php';

define('GLOBAL_SCSS_PATH',dirname(__FILE__) . '/scss');

class Superhero_scss {
	var $theme;
	var $theme_path;
	var $scss;
	var $output;
	var $css;
	
	public function __construct($theme,$form_values = array(),$formatter = 'scss_formatter') {
		$this->theme = $theme;
		$this->theme_path = drupal_get_path('theme',$theme->theme);
		$this->css = '';
		$this->output = '';
		
		$this->scss = new scssc();
		$this->scss->setFormatter($formatter);
		$this->scss->addImportPath(GLOBAL_SCSS_PATH);
		
		// Add theme specific import
		if (!empty($this->theme->scss)) {
			$this->scss->addImportPath($this->theme_path . '/scss/');
		}
		global $base_url;
		$theme_path = '\''.$base_url.'/'.drupal_get_path('theme',$theme->theme).'\'';
		$this->addVariable('theme_path',$theme_path);
		if (empty($form_values)) {
			$this->_add_colour_variables();
		} else {
			$this->_add_colour_form_variables($form_values);
		}
	}
	
	private function _add_colour_variables() {
		$keys = array('color_main','color_text','color_link','color_hover','color_heading');
		foreach($keys as $key) {
			$val = ($this->theme->settings[$key] != '') ? $this->theme->settings[$key] : "false";
			$this->addVariable($key,$val);
		}
		if(!empty($this->theme->custom)){
			foreach($this->theme->custom as $key=>$val){
				$this->addVariable($key,$val);
			}
		}
	}
	
	private function _add_colour_form_variables($values) { 
		$vars = array(
			'color_main' => ($values['superhero_color_main'] != '') ? $values['superhero_color_main'] : "false",
			'color_text' => ($values['superhero_color_text'] != '') ? $values['superhero_color_text'] : "false",
			'color_link' => ($values['superhero_color_link'] != '') ? $values['superhero_color_link'] : "false",
			'color_hover' => ($values['superhero_color_hover'] != '') ? $values['superhero_color_hover'] : "false",
			'color_heading' => ($values['superhero_color_heading'] != '') ? $values['superhero_color_heading'] : "false"
		);
		foreach($vars as $var => $value) {
			$this->addVariable($var,$value);
		}
	}
	
	public function addVariable($variable_name,$variable_value) {
		$this->output .= "\${$variable_name}: {$variable_value}; \n";
	}
	
	public function compileScss() {	
		// Import theme specific scss
		if (!empty($this->theme->scss)) {
			foreach($this->theme->scss as $scss_file) {
				$this->output .= "@import \"$scss_file\";\n";
			}
		}
		$this->css = $this->scss->compile($this->output);
		return $this->css;	
	}	
	
	public function outputFile($file,$force = FALSE) {
		if ($this->css == '') {
			$this->compileScss();
		}
		if (file_exists($file) && !$force) {
			$update = FALSE;
			$last_modified = filemtime($file);
			if (!empty($this->theme->scss)) {
				foreach($this->theme->scss as $scss) {
					$path = $this->theme_path . '/scss/'.$scss;
					if (filemtime($path) > $last_modified) {
						$update = TRUE;
						break;
					}
				}
			} 
		} else {
			$update = TRUE;
		}
		if ($update) {
			$file_update = file_unmanaged_save_data($this->css,$file,FILE_EXISTS_REPLACE);
			if (!$file_update) {
				return FALSE;
			}
		}
		return $file;
	}
}