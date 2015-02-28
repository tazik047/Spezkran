<?php

define('SCSS_PATH',dirname(__FILE__) . '/scss');
require_once dirname(__FILE__) . '/superhero_scss.php';

$scss = new scssc();
$scss->setImportPaths(SCSS_PATH);
$scss->setFormatter('scss_formatter');

$values = $form_state['values'];
$presets = json_decode(base64_decode($values['superhero_presets']));

// Section Custom Style
foreach($theme->sections as $section => $item) {
	$container = 'section-'.$section;
	
	$style_margin = trim($values["superhero_section_{$section}_style_margin"]);
	$style_padding = trim($values["superhero_section_{$section}_style_padding"]);
	$style_margin = ($style_margin=="")?"false":$style_margin;
	$style_padding = ($style_padding=="")?"false":$style_padding;
$output = <<<SCSS
	\$section: {$container};
	\$style_margin: {$style_margin};
	\$style_padding: {$style_padding};
	@import "section";
SCSS;
	$CSS .= $scss->compile($output);
}

// Preset Colours

foreach($presets as $k=>$preset):

$maincolor = (isset($preset->superhero_color_main))? $preset->superhero_color_main: "false";
$textcolor = (isset($preset->superhero_color_text))? $preset->superhero_color_text: "false";
$linkcolor = (isset($preset->superhero_color_link))? $preset->superhero_color_link: "false";
$hovercolor = (isset($preset->superhero_color_hover))? $preset->superhero_color_hover: "false";
$headingcolor = (isset($preset->superhero_color_heading))? $preset->superhero_color_heading: "false";
$maincolor = empty($maincolor)?"false":$maincolor;
$output = <<<SCSS
	\$maincolor: {$maincolor};
	\$textcolor: {$textcolor};
	\$linkcolor: {$linkcolor};
	\$hovercolor: {$hovercolor};
	\$headingcolor: {$headingcolor};
	
	@import "global";
SCSS;
try{
$tmpCSS = $CSS.$scss->compile($output);
}catch(exception $e) {
	drupal_set_message("fatal error: " . $e->getMessage(),'error');
}
$theme_path = drupal_get_path('theme',$theme->theme);
$css_file = "public://".$theme->theme."-preset".($k+1).".css";
//$css_file = $theme_path."/css/".$theme->theme."-preset".($k+1).".css";
file_unmanaged_save_data($tmpCSS,$css_file,FILE_EXISTS_REPLACE);
//Remove all custom scss
file_unmanaged_delete('public://'.$theme->theme.'-theme-preset'.($k+1).'.css');
endforeach;