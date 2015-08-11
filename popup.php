<?php
if($_GET){
	require_once 'simple_html_dom.php';
	print '<div class="white-popup mfp-zoom-out ">';
	if($_GET['type']=='del'){
		$html = file_get_html('http://'.$_SERVER['HTTP_HOST'].'/node/39');
		print($html->find('div#node-39',0)->innertext);
	}
	else if($_GET['type']=='cont'){
		$html = file_get_html('http://'.$_SERVER['HTTP_HOST'].'/node/5');
		print($html->find('div#node-5',0)->innertext);
	}
	print '</div>';
}
?>