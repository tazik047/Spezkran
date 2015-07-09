<!--<script type="text/javascript" charset="utf-8" src="/buyme/js/jquery.js"></script>-->
<script type="text/javascript" charset="utf-8" src="/buyme/js/buyme.js"></script>
  <div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

    <?php print $user_picture; ?>

    <?php print render($title_prefix); ?>
    <?php if (!$page): ?>
      <h2 class="product-title"<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
    <?php endif; ?>
    <?php print render($title_suffix); ?>

    <?php if ($display_submitted): ?>
      <div class="submitted">
        <?php print $submitted; ?>
      </div>
    <?php endif; ?>
    <div class="content b1c-good"<?php print $content_attributes; ?>>
      <?php print '<div style="display:none" class = "b1c-name">'.$title.'</div><div><button class="b1c">'.t('Call me').'</button></div>';
      $product_class_name = 'product-content'; ?>
      <?php if (!empty($content['product:field_images']) && $page): ?>
        <?php $product_class_name = 'span4'; ?>
        <div class="span5">

          <?php print render($content['product:field_images']); ?>
        </div>
      <?php endif; ?>
      <div class="<?php print $product_class_name; ?>">
        <?php
        // We hide the comments and links now so that we can render them later.
        hide($content['comments']);
        hide($content['links']);
        print render($content);
        ?>
      </div>
    </div>


    <?php
    if ($page) {
      print render($content['links']);
    }
    ?>

    <?php print render($content['comments']); ?>


  </div>
