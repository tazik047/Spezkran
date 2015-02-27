<?php
/**
 *
 * Available variables:
 * - $content: The array of content-related elements for the node. Use
 *   render($content) to print them all, or
 *   print a subset such as render($content['comment_form']).
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default value has the following:
 *   - comment-wrapper: The current template type, i.e., "theming hook".
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * The following variables are provided for contextual information.
 * - $node: Node object the comments are attached to.
 * The constants below the variables show the possible values and should be
 * used for comparison.
 * - $display_mode
 *   - COMMENT_MODE_FLAT
 *   - COMMENT_MODE_THREADED
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess_comment_wrapper()
 * @see theme_comment_wrapper()
 */
?>
<div id="comments" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <span class="headerline clearfix"></span>
  <?php if ($content['comments']): ?>
    <?php print render($title_prefix); ?>
    <h2 class="title comment-title">
      <?php print t('Comments'); ?>
      <span class="comment-count">
        <?php print format_plural($content['#node']->comment_count, '1 comment', '@count comments'); ?>
      </span>
    </h2>
    <?php print render($title_suffix); ?>

    <?php print render($content['comments']); ?>
  <?php endif;?>

  <span class="headerline clearfix"></span>

  <?php if ($content['comment_form']): ?>
    <?php print render($title_prefix); ?>
      <?php if ($node->type != 'forum'): ?>
        <h2 class="title comment-form"><span class="ui-icon ui-icon-comment left"></span><?php print t('Add new comment'); ?></h2>
      <?php endif;?>

      <?php if ($node->type == 'forum'): ?>
        <h2 class="title comment-form"><?php print t('Post Forum Reply'); ?></h2>
      <?php endif;?>
    <?php print render($title_suffix); ?>

    <span class="headerline clearfix"></span>

    <?php print render($content['comment_form']); ?>
  <?php endif; ?>
</div>
