<?php

class superhero_theme {
	var $theme;
	var $settings;
	var $sections;
	var $regions;
	var $scss;
	var $page;
	var $custom = array();
	var $presetsstr = 'W3sibmFtZSI6IlByZXNldCAxIiwic3VwZXJoZXJvX2NvbG9yX2xpbmsiOiIjMDBjNGFhIiwic3VwZXJoZXJvX2NvbG9yX3RleHQiOiIjOTk5OTk5Iiwic3VwZXJoZXJvX2NvbG9yX2hvdmVyIjoiIzAwNWU1MiIsInN1cGVyaGVyb19jb2xvcl9oZWFkaW5nIjoiIzY2NjY2NiIsInN1cGVyaGVyb19jb2xvcl9tYWluIjoiIzAwYzRhYSJ9LHsibmFtZSI6IlByZXNldCAyIiwic3VwZXJoZXJvX2NvbG9yX2xpbmsiOiIjZWZiYjhlIiwic3VwZXJoZXJvX2NvbG9yX3RleHQiOiIjOTk5OTk5Iiwic3VwZXJoZXJvX2NvbG9yX2hvdmVyIjoiI2UyODUzNSIsInN1cGVyaGVyb19jb2xvcl9oZWFkaW5nIjoiIzY2NjY2NiIsInN1cGVyaGVyb19jb2xvcl9tYWluIjoiI2VmYmI4ZSJ9LHsibmFtZSI6InByZXNldDMiLCJzdXBlcmhlcm9fY29sb3JfdGV4dCI6IiM5OTk5OTkiLCJzdXBlcmhlcm9fY29sb3JfbGluayI6IiNkYjQwM2MiLCJzdXBlcmhlcm9fY29sb3JfaG92ZXIiOiIjOTUxZjFjIiwic3VwZXJoZXJvX2NvbG9yX2hlYWRpbmciOiIjNjY2NjY2Iiwic3VwZXJoZXJvX2NvbG9yX21haW4iOiIjZGI0MDNjIn0seyJzdXBlcmhlcm9fY29sb3JfdGV4dCI6IiM5OTk5OTkiLCJzdXBlcmhlcm9fY29sb3JfbGluayI6IiNmNjYzOGIiLCJzdXBlcmhlcm9fY29sb3JfaG92ZXIiOiIjZTYwZDQ4Iiwic3VwZXJoZXJvX2NvbG9yX2hlYWRpbmciOiIjNjY2NjY2Iiwic3VwZXJoZXJvX2NvbG9yX21haW4iOiIjZjY2MzhiIn0seyJzdXBlcmhlcm9fY29sb3JfdGV4dCI6IiM5OTk5OTkiLCJzdXBlcmhlcm9fY29sb3JfbGluayI6IiMwMGI0NGUiLCJzdXBlcmhlcm9fY29sb3JfaG92ZXIiOiIjMDA0ZTIyIiwic3VwZXJoZXJvX2NvbG9yX2hlYWRpbmciOiIjNjY2NjY2Iiwic3VwZXJoZXJvX2NvbG9yX21haW4iOiIjMDBiNDRlIn0seyJzdXBlcmhlcm9fY29sb3JfdGV4dCI6IiM5OTk5OTkiLCJzdXBlcmhlcm9fY29sb3JfbGluayI6IiM1YWFkZGQiLCJzdXBlcmhlcm9fY29sb3JfaG92ZXIiOiIjMjQ3YmFkIiwic3VwZXJoZXJvX2NvbG9yX2hlYWRpbmciOiIjNjY2NjY2Iiwic3VwZXJoZXJvX2NvbG9yX21haW4iOiIjNWFhZGRkIn0seyJzdXBlcmhlcm9fY29sb3JfdGV4dCI6IiM5OTk5OTkiLCJzdXBlcmhlcm9fY29sb3JfbGluayI6IiMxMGQzZmYiLCJzdXBlcmhlcm9fY29sb3JfaG92ZXIiOiIjMDA4YWE5Iiwic3VwZXJoZXJvX2NvbG9yX2hlYWRpbmciOiIjNjY2NjY2Iiwic3VwZXJoZXJvX2NvbG9yX21haW4iOiIjMTBkM2ZmIn0seyJzdXBlcmhlcm9fY29sb3JfdGV4dCI6IiM5OTk5OTkiLCJzdXBlcmhlcm9fY29sb3JfbGluayI6IiM5NDJlOGYiLCJzdXBlcmhlcm9fY29sb3JfaG92ZXIiOiIjNDYxNjQ0Iiwic3VwZXJoZXJvX2NvbG9yX2hlYWRpbmciOiIjNjY2NjY2Iiwic3VwZXJoZXJvX2NvbG9yX21haW4iOiIjOTQyZThmIn1d';
	function __construct($theme) {
		$this->theme = $theme;
		$this->init();
	}
	
	function init() {
		$theme_path = drupal_get_path('theme',$this->theme);
		if(file_exists($theme_path.'/default_presets.php')){
			require_once $theme_path.'/default_presets.php';
		}
		$this->settings();
		$this->sections();
		$this->regions();
		$this->scss();
	}
	
	function settings() {
		if (!isset($this->settings)) {
			$default_presets = theme_get_setting('superhero_presets',$this->theme);
			if(empty($default_presets) || $default_presets == $this->presetsstr){
				$func = $this->theme.'_default_presets';
				if(function_exists($func)){
					$this->presetsstr = $func();		
				}
			}else{
				$this->presetsstr = $default_presets;
			}
			$presets = json_decode(base64_decode($this->presetsstr));
			if(superhero_is_settings_change()){
				$default_preset = theme_get_setting('superhero_default_preset',$this->theme);
			}else{
				$default_preset = isset($_SESSION['superhero_default_preset'])?$_SESSION['superhero_default_preset']:theme_get_setting('superhero_default_preset',$this->theme);
				$custom_preset = isset($_GET['preset'])?str_replace('preset','',$_GET['preset']):'';
				if(is_numeric($custom_preset)){
					$custom_preset--;
					if(isset($presets[$custom_preset])){
						$default_preset= $custom_preset;
					}
				}
			}
			$_SESSION['superhero_default_preset'] = $default_preset;
		
			$preset = isset($presets[$default_preset])?$presets[$default_preset]:null;
			//Non superhero theme
			if(empty($preset)){
				$preset = new stdClass();
				$preset->superhero_color_main = '';
				$preset->superhero_color_text = '';
				$preset->superhero_color_link = '';
				$preset->superhero_color_hover = '';
				$preset->superhero_color_heading = '';
			}
			$this->settings = array(
				'responsive' => superhero_theme_get_setting('superhero_responsive',1,$this->theme),
				'color_main' => isset($preset->superhero_color_main)?$preset->superhero_color_main:'',
				'color_text' => $preset->superhero_color_text,
				'color_link' => $preset->superhero_color_link,
				'color_hover' => $preset->superhero_color_hover,
				'color_heading' => $preset->superhero_color_heading,
				'default_preset' => $default_preset
			);
			foreach($preset as $k=>$v){
				if(strpos($k, 'custom_color') !== false){
					$color = trim($v);
					$this->settings[$k] = empty($color)?'transparent':$color;
				}
			}
		}
		return $this->settings;
	}
	
	function sections() {
		if (!isset($this->sections)) {
			$this->sections = array();
			
			if ($sections = superhero_info('sections',$this->theme)) {
				foreach($sections as $section => $title) {
					$this->sections[$section] = array(
						'section' => $section,
						'name' => $title,
						'enabled' => superhero_section_get_setting('enabled',$section,1,$this->theme),
						'weight' => superhero_section_get_setting('weight',$section,0,$this->theme),
						'primary' => superhero_section_get_setting('primary',$section,0,$this->theme),
						'fullwidth' => superhero_section_get_setting('fullwidth',$section,0,$this->theme),
						'backtype' => superhero_section_get_setting('backtype',$section,0,$this->theme),
						'backcolour' => superhero_section_get_setting('backcolour',$section,'',$this->theme),
						'backimage' => superhero_section_get_setting('backimage',$section,'',$this->theme),
						'vphone' => superhero_section_get_setting('vphone',$section,0,$this->theme),
						'vtablet' => superhero_section_get_setting('vtablet',$section,0,$this->theme),
						'vdesktop' => superhero_section_get_setting('vdesktop',$section,0,$this->theme),
						'hphone' => superhero_section_get_setting('hphone',$section,0,$this->theme),
						'htablet' => superhero_section_get_setting('htablet',$section,0,$this->theme),
						'hdesktop' => superhero_section_get_setting('hdesktop',$section,0,$this->theme),
						'sticky' => superhero_section_get_setting('sticky',$section,0,$this->theme),
						'style_margin' => superhero_section_get_setting('style_margin',$section,'',$this->theme),
						'style_padding' => superhero_section_get_setting('style_padding',$section,'',$this->theme),
						'style_background' => superhero_section_get_setting('style_background',$section,'',$this->theme),
						'custom_class' => superhero_section_get_setting('custom_class',$section,'',$this->theme),
					);
				}
			}
			uasort($this->sections,'drupal_sort_weight');
		}
		return $this->sections;
	}
	
	function regions() {
		if (!isset($this->regions)) {
			$this->sections();
			$this->regions = array();
			$exclude = array('page_top','page_bottom');
			
			foreach(system_region_list($this->theme) as $region => $title) {
				if (!in_array($region,$exclude)) {
					$section = superhero_region_get_setting('section',$region,NULL,$this->theme);
					//$columns = superhero_region_get_setting('columns',$region,NULL,$this->theme);
					$xscolumns = superhero_region_get_setting('xscolumns',$region,NULL,$this->theme);
					$smcolumns = superhero_region_get_setting('smcolumns',$region,NULL,$this->theme);
					$mdcolumns = superhero_region_get_setting('mdcolumns',$region,NULL,$this->theme);
					$lgcolumns = superhero_region_get_setting('lgcolumns',$region,NULL,$this->theme);
					
					$section = isset($section) && isset($this->sections[$section]) ? $section : NULL;
					
					$this->regions[$region] = array(
						'region' => $region,
						'name' => $title,
						'section' => $section,
						'enabled' => isset($section),
						//'columns' => $columns,
						'xscolumns' => $xscolumns,
						'smcolumns' => $smcolumns,
						'mdcolumns' => $mdcolumns,
						'lgcolumns' => $lgcolumns,
						//'width' => $columns,
						'weight' => superhero_region_get_setting('weight',$region,0,$this->theme),
						'force' => superhero_region_get_setting('force',$region,0,$this->theme)
					);
				}
			}
			uasort($this->regions,'drupal_sort_weight');
		}
		return $this->regions;
	}
	
	function scss() {
		if (!isset($this->scss)) {
			$scss_files = superhero_info('scss',$this->theme);
			$this->scss = $scss_files;
		}
		return $this->scss;
	}
}