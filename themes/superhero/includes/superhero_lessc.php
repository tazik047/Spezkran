<?php

require_once dirname(__FILE__) . '/lessc.inc.php';

define('GLOBAL_LESS_PATH',dirname(__FILE__) . '/lessc');

class Superhero_lessc {
	var $theme;
	var $theme_path;
	var $lessc;
	var $output;
	var $css;
	
	public function __construct($theme,$form_values = array(),$formatter = 'lessc_formatter') {
		$this->theme = $theme;
		$this->theme_path = drupal_get_path('theme',$theme->theme);
		$this->css = '';
		$this->output = '';
		
		$this->lessc = new lessc();
		//$this->lessc->setFormatter($formatter);
		$this->lessc->addImportDir(GLOBAL_LESS_PATH);
		
		// Add theme specific import
		if (!empty($this->theme->lessc)) {
			$this->lessc->addImportDir($this->theme_path . '/lessc/');
		}
		
		if (empty($form_values)) {
			$this->_add_colour_variables();
		} else {
			$this->_add_colour_form_variables($form_values);
		}
	}
	
	private function _add_colour_variables() {
		$keys = array('color_text','color_link','color_hover','color_heading');
		foreach($keys as $key) {
			$val = ($this->theme->settings[$key] != '') ? $this->theme->settings[$key] : "false";
			$this->addVariable($key,$val);
		}
	}
	
	private function _add_colour_form_variables($values) { 
		$vars = array(
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
		$this->output .= "@{$variable_name}: {$variable_value}; \n";
	}
	
	public function compileLessc() {	
		// Import theme specific lessc
		if (!empty($this->theme->lessc)) {
			foreach($this->theme->lessc as $lessc_file) {
				$this->output .= "@import \"$lessc_file\";\n";
			}
		}
    $this->css = $this->lessc->compile($this->output);
		return $this->css;	
	}	
	
	public function outputFile($file,$force = FALSE) {    
		if (file_exists($file) && !$force) {
			$update = FALSE;
			$last_modified = filemtime($file);
			if (!empty($this->theme->lessc)) {
				foreach($this->theme->lessc as $lessc) {
					$path = $this->theme_path . '/lessc/'.$lessc;
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
      if ($this->css == '') {
        $this->compileLessc();
      }
			$file_update = file_unmanaged_save_data($this->css,$file,FILE_EXISTS_REPLACE);
			if (!$file_update) {
				return FALSE;
			}
		}
		return $file;
	}
}