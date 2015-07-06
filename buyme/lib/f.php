<?php
$f = (strlen($_GET["fields"]) === 0 ? "Имя, Телефон, -Адрес доставки" : $_GET["fields"]);

function b1c($s) {
	echo $_GET[$s];
}
?>

<div class="b1c-bg"></div>
<div class="b1c-form">
	<div class="b1c-tl">
		<div class="b1c-close">
			<a href="/buyme/index.html"><img class="b1c-close b1c-opct" src='/buyme/templates/blank.gif' alt='' /></a>
		</div>
		<span class="b1c-title-name"><?php b1c('title'); ?></span>
	</div>
	<div class='b1c-description'>
		<?php b1c('description'); ;?>
	</div>

<?php
$f = str_replace(", ", ",", $f);
$f = str_replace("'", "\"", $f);
$f = explode(",", $f);
for ($i=0; $i < count($f); $i++){
	if ($f[$i][0] == "-") {
		echo "<div class='b1c-caption'>".substr($f[$i], 1)."</div>";
		echo "<textarea placeholder='".substr($f[$i], 1)."' class='b1c-txt'></textarea>";
	} 
	elseif ($f[$i][0] == "!") 
	{
		$str = substr($f[$i], 1);
		$str = explode("!", $str);
		echo "<div class='b1c-caption'>".$str[0]."</div>";
		echo "<select class='b1c-select' name='".$str[0]."'>";
		for ($j=1; $j<count($str); $j++) {
			echo "<option value=".$str[$j].">".$str[$j]."</option>";
		}
		echo"</select>";
	} 
	elseif ($f[$i][0] == "?") 
	{
		echo "<div class='b1c-checkbox'><input type='checkbox' name='".substr($f[$i], 1)."' id='b1c".$i."'> <label for='b1c".$i."'>".substr($f[$i], 1)."</label></div>";
	}
	else 
	{
		echo "<div class='b1c-caption'>".$f[$i]."</div>";
		echo "<input placeholder='".$f[$i]."' class='b1c-txt' type='text' maxlength='150'>";
	}
}
?>

	<div class="b1c-submit-area">
		<button class="b1c-submit"><?php b1c('button'); ?></button>
		<div class="b1c-result"></div>
	</div>
</div>