 <?php 
if (!$page) { 
?>


			
				
					<div class="post-preview">
						<!-- Post Title & Meta -->
						<h2><?php print $title; ?></h2>
						<div class="post-meta">
							 Posted by <span class="meta-author"><?php print render($name) ?></span>
							<span class="meta-date">on <?php print format_date($node->created, 'custom', 'M d, Y') ?></span>
							<span class="meta-tags">
                            <?php
// Query database table taxonomy_term_data and taxonomy_index
// So I can get all terms from my node.
$term = db_query('SELECT t.name, t.tid FROM {taxonomy_index} n LEFT JOIN  {taxonomy_term_data} t ON (n.tid = t.tid) WHERE n.nid = :nid', array(':nid' => $node->nid));

// db_query in Drupal 7 returns a stdClass object. 
// Value names are corresponding to the fields in your SQL query 
//(in our case "t.name") AND t.tid for build path.
$tags = '';
foreach ($term as $record) {
  // I put l() function for make my links.
  $tags .= l($record->name, 'taxonomy/term/' . $record->tid) . ' ';
}

print 'In ' . $tags;
?>
                            
                            </span>
							<span class="meta-comment">
                            <?php if(module_exists('comment') && ($node->comment == COMMENT_NODE_OPEN)) { ?>
                            <?php print $comment_count; ?><a href="<?php print $node_url; ?>">  comments</a>
                            <?php } ;?>
                            </span>
						</div>
						<!-- End Post Title & Meta -->
						<!-- Post Image -->
						<div class="post-image-wrap">
							<a href="<?php print $node_url; ?>" class="post-image">
								 <?php print render($content['field_blog_image']) ?>
								<div class="link-overlay icon-chevron-right"></div>
							</a>
						</div>
						<!-- End Post Image -->
						 <!-- body -->
<?php hide($content['comments']); hide($content['links']); print render($content); ?>
						<a class="btn colored" href="<?php print $node_url; ?>">More<i class="icon-chevron-sign-right" style="margin: 0 0 0 7px;"></i></a>
					 </div>
				
				


 
 
 
            
             <?php } else { 

$acc = user_load(1);
?>

<div class="row">

				<div class="row-item col-3_4">
				
					<div class="post-preview">
						<!-- Post Title & Meta -->
						<h2><?php print $title; ?></h2>
						<div class="post-meta">
							 Posted by <span class="meta-author"><?php print render($name) ?></span>
							<span class="meta-date">on <?php print format_date($node->created, 'custom', 'M d, Y') ?></span>
							<span class="meta-tags">
                            <?php
// Query database table taxonomy_term_data and taxonomy_index
// So I can get all terms from my node.
$term = db_query('SELECT t.name, t.tid FROM {taxonomy_index} n LEFT JOIN  {taxonomy_term_data} t ON (n.tid = t.tid) WHERE n.nid = :nid', array(':nid' => $node->nid));

// db_query in Drupal 7 returns a stdClass object. 
// Value names are corresponding to the fields in your SQL query 
//(in our case "t.name") AND t.tid for build path.
$tags = '';
foreach ($term as $record) {
  // I put l() function for make my links.
  $tags .= l($record->name, 'taxonomy/term/' . $record->tid) . ' ';
}

print 'In ' . $tags;
?>
                            
                            </span>
							<span class="meta-comment">
                            <?php if(module_exists('comment') && ($node->comment == COMMENT_NODE_OPEN)) { ?>
                            <?php print $comment_count; ?><a href="<?php print $node_url; ?>">  comments</a>
                            <?php } ;?>
                            </span>
						</div>
						<!-- End Post Title & Meta -->
						<!-- Post Image -->
						<div class="post-image-wrap">
							
								 <?php print render($content['field_blog_image']) ?>
								
							
						</div>
						<!-- End Post Image -->
						 <!-- body -->
<?php hide($content['comments']); hide($content['links']); print render($content); ?>
						<div class="clearfix"></div>	
					 </div>
			
				<?php print render($content['comments']); ?>
</div>
</div>
    
<?php } ?>

