<div id="node-<?php print $node->nid; ?>" class="sh-blog <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
    <div class="catItem row">
        <div class="catItemInfo-Image col-sx-12 col-sm-4 col-md-4 col-lg-4">                
            <div class="blog-image clearfix">
                <?php print render($content['field_image']);?>
                <div class="date">
                    <span class="day"><?php print format_date($created,'custom','d');?></span>
                    <span class="month"><?php print format_date($created,'custom','M');?></span>
                </div>
            </div>
        </div>  

        <div class="catItemInfo-Text col-sx-12 col-sm-8 col-md-8 col-lg-8">
            <div class="article-info">
                <span class="catItemAuthor">Written by <?php print $name;?></span>
                <span class="catItemCategory">Published in <?php print render($content['field_tags'])?></span>
            </div>    
            
            <?php print render($title_prefix); ?>
            <?php if (!$page): ?>
                <h2 class="blog-content-tile" <?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
            <?php endif; ?>
            <?php print render($title_suffix); ?>

            <div class="blog-content content"<?php print $content_attributes; ?>>
                <?php print render($content['body']);?>
                <?php
                // We hide the comments and links now so that we can render them later.
                hide($content['comments']);
                hide($content['links']);
                //print render($content);
                ?>
            </div>
            <div class="read-more clearfix">
                <a class="btn btn-default" href="<?php print $node_url; ?>">Read more...</a>
            </div>
            <?php //print l('Read more...','node/'.$nid);?>
            <?php //print render($content['links']); ?>
            <?php //print render($content['comments']); ?>
        </div>
    </div>
</div>