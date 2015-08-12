<!DOCTYPE html>

<html lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>"<?php print $rdf_namespaces; ?>>
<head>
<?php print $head; ?>
<meta charset="utf-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0" />
<title><?php print $head_title; ?></title>
<?php print $styles; ?>
<?php print $scripts; ?>
        <!--[if lt IE 9]><script src="http://html5shiv.googlecode.com/svn/trunk/html5.js"></script><![endif]-->
        <!-- END: js -->
</head>
<body class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <?php print $page_top; ?>
  <?php print $page; ?>
  <?php print $page_bottom; ?>
</body>
<script>	

	jQuery(document).ready(function() {
		jQuery('.uc-price').each(function(){
			if(jQuery(this).text()=='0.00грн.')
				jQuery(this).text("Цену уточняйте");
		});
		if(jQuery('[id^="node-"]').length==1){
			jQuery('table').wrap('<div class="wrap-table"></div>');
		}
	});
</script>
</html>