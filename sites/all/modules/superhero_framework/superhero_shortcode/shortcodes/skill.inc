<?php

/**
 * Definition of Alert Shortcode
 */

/**
 * Implements hook_shortcode_info
 */
function _skill_shortcode_info(&$shortcodes) {
	$shortcodes['skill'] = array(
		'title' => t('Skill'),
		'description' => t('Create Skill Process'),
		'process callback' => 'superhero_shortcode_skill',
	);
	return $shortcodes;
}

/**
 * Icon Content
 */
function superhero_shortcode_skill($attrs, $text) {
	$attrs = shortcode_attrs(array(
			'title' => '',
			'percent' => 50,
		),
		$attrs
	);
	return '<div class="sh_title_wrap clearfix"><span class="sh_skill_title letf">'.$attrs['title'].'</span><span class="sh_skill_percent right">'.$attrs['percent'].'%</span></div>
					<div class="sh_skill_progress_wrap clearfix">
						<div class="sh_progress_bar">
							<div class="sh_skills_progress_percent left" style="width:'.$attrs['percent'].'%"></div>
						</div>
					</div>';
}