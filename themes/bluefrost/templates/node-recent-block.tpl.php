<?php
/**
 * Template for recent node block
 *
 * Available object to use :
 *
 * $contents - is an array of node object keyed with node id
 * $contents[$cid][picture] - pre build node user picture
 * $contents[$cid][title_linked] - pre themed content title linked to node
 * $contents[$cid][posted_data_themed] - pre themed node date and user
 * $contents[$cid][node] - full raw node object
 * $contents[$cid][user] = full raw node object
 */
?>
<div class="content-block-wrapper">
  <?php if (isset($contents) && is_array($contents)) : ?>
  <?php foreach ($contents as $id => $value) : ?>
  <div class="content-node-top clearfix">
    <?php if (!empty($value['picture'])) print $value['picture'];?>
    <?php print t('!user wrote :', array('!user' => theme('username', array('account' => $value['user'])))); ?>
  </div>
  <div class="content-block clearfix">
    <div class="content-comment">
      <h6><?php print html_entity_decode($value['title_link']);?></h6>
      <?php print render(field_view_field('node', $value['node'], 'body', array(
              'label' =>'hidden',
              'type' => 'text_summary_or_trimmed',
              'settings'=> array('trim_length' => 30),
            )));;?>
    </div>
  </div>
  <?php endforeach;?>
  <?php endif; ?>
</div>