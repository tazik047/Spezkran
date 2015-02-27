<?php
/**
 * Implement hook_preprocess_node().
 */
function bluefrost_preprocess_node(&$variables) {

  // User signature
  if (is_object($variables['user']) && isset($variables['user']->signature) && isset($variables['user']->signature_format)) {
    $variables['signature'] = check_markup($variables['user']->signature, $variables['user']->signature_format);
  }

  // Comment count formatted
  $variables['comment_count_formatted'] = t('No comment yet');
  if (isset($variables['comment_count']) && $variables['comment_count'] > 0) {
    $variables['comment_count_formatted'] = format_plural($variables['comment_count'], t('1 comment'), t('@count comments'));
  }

  // Remove links on teasers
  if ($variables['teaser'] == TRUE
      || !empty($variables['content']['comments']['comment_form'])
      || (arg(0) == 'comment' && arg(1) == 'reply')) {

    unset($variables['content']['links']['comment']['#links']['comment-add']);

  }

  // Title links
  // Don't use l() it won't work properly
  $variables['title_links'] = '<a href="' . $variables['node_url'] . '">' . $variables['title'] . '</a>';
}
