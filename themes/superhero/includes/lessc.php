<?php

define('LESSC_PATH',dirname(__FILE__) . '/lessc');
require_once dirname(__FILE__) . '/superhero_lessc.php';

$lessc = new lessc();
$lessc->setImportDir(LESSC_PATH);
//$lessc->setFormatter('lessc_formatter');

$values = $form_state['values'];
$presets = json_decode(base64_decode($values['superhero_presets']));

// Section Colours ; Deprecated
foreach($theme->sections as $section => $item) {
	$container = 'section-'.$section;
	$backimage = '';//$item['backimage']['fid'];
	if ($backimage) {
		$file = file_load($backimage);
		$url = "'".file_create_url($file->uri)."'";
	} else {
		$url = "false";
	}
	$backcolour = ($item['backcolour']) ? $item['backcolour'] : "false";

$output = <<<LESSC
	@section: {$container};
	@bgimage: {$url};
	@bgcolor: {$backcolour};
LESSC;

	$CSS .= $lessc->compile($output);
}

// Preset Colours

foreach($presets as $k=>$preset):

$textcolor = (isset($preset->superhero_color_text))? $preset->superhero_color_text: "false";
$linkcolor = (isset($preset->superhero_color_link))? $preset->superhero_color_link: "false";
$hovercolor = (isset($preset->superhero_color_hover))? $preset->superhero_color_hover: "false";
$headingcolor = (isset($preset->superhero_color_heading))? $preset->superhero_color_heading: "false";
$output = <<<LESSC
	@textcolor: {$textcolor};
	@linkcolor: {$linkcolor};
	@hovercolor: {$hovercolor};
	@headingcolor: {$headingcolor};
	
	@import "global";
LESSC;
$tmpCSS = $CSS.$lessc->compile($output);
$css_file = "public://".$theme->theme."-preset".($k+1).".less.css";
file_unmanaged_save_data($tmpCSS,$css_file,FILE_EXISTS_REPLACE);
//Remove all custom scss
file_unmanaged_delete('public://'.$theme->theme.'-theme-preset'.($k+1).'.less.css');
endforeach;