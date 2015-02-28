<?php

/**
 * Definition of Icon Shortcode
 */

/**
 * Implements hook_shortcode_info
 */
function _typo_shortcode_info(&$shortcodes) {
	$shortcodes['dropcap'] = array(
		'title' => t('Dropcap'),
		//'description' => t('Create a Font Awesome Icon'),
		'process callback' => 'superhero_shortcode_dropcap',
		//'tips callback' => 'superhero_shortcode_icon_tip',
	);
	$shortcodes['blocknumber'] = array(
		'title' => t('Block Number'),
		//'description' => t('Create a Font Awesome Icon'),
		'process callback' => 'superhero_shortcode_blocknumber',
		//'tips callback' => 'superhero_shortcode_icon_tip',
	);
	$shortcodes['block'] = array(
		'title' => t('Block'),
		//'description' => t('Create a Font Awesome Icon'),
		'process callback' => 'superhero_shortcode_block',
		//'tips callback' => 'superhero_shortcode_icon_tip',
	);
	$shortcodes['bubble'] = array(
		'title' => t('Bubble'),
		//'description' => t('Create a Font Awesome Icon'),
		'process callback' => 'superhero_shortcode_bubble',
		//'tips callback' => 'superhero_shortcode_icon_tip',
	);
	return $shortcodes;
}

/**
 * Dropcap Content
 */
function superhero_shortcode_dropcap($attrs, $text) {
	return "<p class=\"sh-dropcap\">{$text}</p>";
}

/**
 * Blocknumber Content
 */
function superhero_shortcode_blocknumber($attrs, $text) {
	$attrs = shortcode_attrs(array(
			'type' => '',
			'text' => '',
			'color' => '',
			'background' => '',
		),
		$attrs
	);
	return "<p class=\"sh-blocknumber\"><span class=\"{$attrs['type']}\" style=\"background:{$attrs['background']};color:{$attrs['color']}\">{$attrs['text']}</span> {$text}</p>";
}

/**
 * Block Content
 */
function superhero_shortcode_block($attrs, $text) {
	$attrs = shortcode_attrs(array(
			'color' => '',
			'background' => '',
		),
		$attrs
	);
	return "<div style=\"background:{$attrs['background']};color:{$attrs['color']};padding:15px;border:0\" class=\"sh-block\">{$text}</div>";
}

/**
 * Bubble Content
 */
function superhero_shortcode_bubble($attrs, $text) {
	$attrs = shortcode_attrs(array(
			'background' => '#CCC',
			'color' => '',
			'padding' => '10px',
			'border' => '0',
			'author' => 'Cong',
			'type' =>''//rounded, circle
		),
		$attrs
	);
	$background = $attrs['background'];
	$color = $attrs['color'];
	$padding = $attrs['padding'];
	$border = $attrs['border'];
	$type = $attrs['type'];
	$author = $attrs['author'];
	
	$bg			= $background;
		 
	$background = ($background !='') ? 'background:'.$background.';' : '';
	$color = ($color !='') ? 'color:'.$color.';' : '';
	
	if($border!=0) {
		$border_color = explode(' ', $border);
		$border_color = $border_color[2];
	}
	
	$cite = ($border!=0) ? $border_color : $bg;

	return '<div class="sh-bubble '.$type.'" style="'.$background.'padding:'.$padding.';border:'.$border.'"><div style="'.$color.'">'.$text.'</div><cite><span style="border:15px solid '.$cite.'"></span>'.$author.'</cite></div>';
}