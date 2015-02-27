<?php
/**
 * Template for recent comment block
 *
 * Available variable to use :
 *
 * $contents - is an array of comments object keyed with comment id
 * $contents[$cid][picture] - pre build commented user picture
 * $contents[$cid][title_linked] - pre themed content title linked to comment
 * $contents[$cid][posted_data_themed] - pre themed comment date and user
 * $contents[$cid][comment] - full raw comment object
 * $contents[$cid][user] = full raw user object
 * $contents[$cid][comment_subject] = comment subject
 * $contents[$cid][comment_subject_stripped] = comment subject stripped of tags
 * $contents[$cid][comment_body_stripped] = comment body stripped of tags and limited to 50 words
 * $contents[$cid][comment_body_raw] = unsanitized comment body
 * $contents[$cid][comment_body_safe] = sanitized comment body
 * $contents[$cid][username] = commenter user name
 * $contents[$cid][username_linked] = commenter user name linked to user page if not anonymous
 */
?>
<div class="content-block-wrapper">
  <?php if (isset($contents) && is_array($contents)) :?>
  <?php foreach ($contents as $id => $value) : ?>
  <div class="content-comment-top clearfix">
    <?php if (!empty($value['picture'])) print $value['picture'];?>
    <?php print t('!username wrote :', array('!username' => $value['username_linked']));?>
  </div>
  <div class="content-block clearfix">
    <div class="content-comment">
      <h6><?php print strip_tags($value['comment_subject_stripped']); ?></h6>
      <p><?php print strip_tags($value['comment_body_stripped']); ?></p>
    </div>
  </div>
  <?php endforeach;?>
  <?php endif;?>
</div>