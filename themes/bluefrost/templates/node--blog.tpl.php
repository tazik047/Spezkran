<?php
// $Id: node.tpl.php,v 1.2 2010/12/01 00:18:15 webchick Exp $

/**
 * @file
 *
 * Available variables:
 * - $title: the (sanitized) title of the node.
 * - $content: An array of node items. Use render($content) to print them all,
 *   or print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $user_picture: The node author's picture from user-picture.tpl.php.
 * - $date: Formatted creation date. Preprocess functions can reformat it by
 *   calling format_date() with the desired parameters on the $created variable.
 * - $name: Themed username of node author output from theme_username().
 * - $node_url: Direct url of the current node.
 * - $display_submitted: Whether submission information should be displayed.
 * - $submitted: Submission information created from $name and $date during
 *   template_preprocess_node().
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - node: The current template type, i.e., "theming hook".
 *   - node-[type]: The current node type. For example, if the node is a
 *     "Blog entry" it would result in "node-blog". Note that the machine
 *     name will often be in a short form of the human readable label.
 *   - node-teaser: Nodes in teaser form.
 *   - node-preview: Nodes in preview mode.
 *   The following are controlled through the node publishing options.
 *   - node-promoted: Nodes promoted to the front page.
 *   - node-sticky: Nodes ordered above other non-sticky nodes in teaser
 *     listings.
 *   - node-unpublished: Unpublished nodes visible only to administrators.
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * Other variables:
 * - $node: Full node object. Contains data that may not be safe.
 * - $type: Node type, i.e. story, page, blog, etc.
 * - $comment_count: Number of comments attached to the node.
 * - $uid: User ID of the node author.
 * - $created: Time the node was published formatted in Unix timestamp.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
 *   teaser listings.
 * - $id: Position of the node. Increments each time it's output.
 *
 * Node status variables:
 * - $view_mode: View mode, e.g. 'full', 'teaser'...
 * - $teaser: Flag for the teaser state (shortcut for $view_mode == 'teaser').
 * - $page: Flag for the full page state.
 * - $promote: Flag for front page promotion state.
 * - $sticky: Flags for sticky post setting.
 * - $status: Flag for published status.
 * - $comment: State of comment settings for the node.
 * - $readmore: Flags true if the teaser content of the node cannot hold the
 *   main body content.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * Field variables: for each field instance attached to the node a corresponding
 * variable is defined, e.g. $node->body becomes $body. When needing to access
 * a field's raw values, developers/themers are strongly encouraged to use these
 * variables. Otherwise they will have to explicitly specify the desired field
 * language, e.g. $node->body['en'], thus overriding any language negotiation
 * rule that was previously applied.
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 * @see template_process()
 */
?>
<div id="node-<?php print $node->nid; ?>"
	class="node <?php print $classes; ?><?php if ($teaser) : print ' node-teaser'; endif;?> <?php print $zebra;?> clearfix">

  <?php // Operate on full node view ?>
	<?php if (!$teaser) : ?>
  <?php if ($display_submitted) : ?>
  	<div class="node-right">

      <div class="node-author blog-pane clearfix">
        <p class="blog-pane-title"><strong><?php print t('Author Profile')?></strong></p>
        <?php print $user_picture; ?>
        <div class="blog-pane-content"><?php print $name; ?></div>
      </div>

      <?php if (!empty($content['links'])) : ?>
        <div class="node-link blog-pane clearfix">
          <p class="blog-pane-title"><strong><?php print t('Links')?></strong></p>
          <div class="blog-pane-content"><?php print render($content['links']); ?></div>
        </div>
      <?php endif;?>

      <?php if (!empty($signature)) : ?>
        <div class="node-signature blog-pane clearfix">
          <p class="blog-pane-title"><strong><?php print t('Signature'); ?></strong></p>
          <div class="blog-pane-content"><?php print $signature; ?></div>
        </div>
      <?php endif;?>

      <div class="node-posted-date blog-pane clearfix">
        <p class="blog-pane-title"><strong><?php print t('Posted date'); ?></strong></p>
        <div class="blog-pane-content"><?php print $date; ?></div>
      </div>

      <div class="node-feedback blog-pane clearfix">
        <p class="blog-pane-title"><strong><?php print t('Feedback');?></strong></p>
        <div class="blog-pane-content"><?php print $comment_count_formatted; ?></div>
      </div>

      <?php if (!empty($terms)) : ?>
        <div class="node-tags blog-pane clearfix">
          <p class="blog-pane-title"><strong><?php print t('Tags'); ?></strong></p>
          <div class="blog-pane-content"><?php print $terms; ?></div>
        </div>
      <?php endif;?>

   </div>
    	<?php endif; ?>

  	<div class="node-left">
    	<?php hide($content['comments']); hide($content['links']); print render($content); ?>
  	</div>

  	<?php print render($content['comments']); ?>
	<?php endif; ?>

  <?php // Operate on teaser mode?>
	<?php if ($teaser) : ?>
  	<div class="node-content">
      <?php print render($title_prefix); ?>
      <h2 class="title"><?php print $title_links?></h2>
      <?php print render($title_suffix); ?>

      <div class="node-links clearfix">

      <?php if ($display_submitted) : ?>
          <?php $user = user_load($node->uid) ;?>
          <?php print theme('user_picture', array('account' => $user)); ?>
            <time class="node-created" datetime="<?php print $formatted_created; ?>">
              <?php print html_entity_decode(t('By @username on @date', array('@username' => theme('username', array('account' => $user)), '@date' => $formatted_created))); ?>
            </time>
        <?php endif; ?>
        <?php hide($content['links']['comment']); ?>
        <?php print render($content['links']); ?>

      </div>
      <?php print render($content); ?>
  	</div>
	<?php endif; ?>
</div>
