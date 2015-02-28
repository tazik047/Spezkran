<?php
	$current_path = current_path();
?>
<div class="superhero-styleselector">
	<h3>Choose Your Layout Style</h3>
	<select name="superhero_layout">
		<option value="wide">Wide</option>
		<option value="boxed">Boxed</option>
	</select>
	<h3>Predefined Color Schemes</h3>
	<ul>
	<?php foreach($items['presets'] as $k=>$preset):?>
		<li class="preset" style="background-color:<?php print $preset->superhero_color_link;?>"><a href="<?php print url($current_path,array('query'=>array('preset'=>'preset'.($k+1))));?>">preset</a></span>
	<?php endforeach;?>
	</ul>
</div>
<span class="superhero-styleselector-close"></span>
<script type="text/javascript">
	jQuery(document).ready(function($){
		$('select[name=superhero_layout]').change(function(){
			$('body').removeClass('boxed wide').addClass($(this).val());
		});
		$('.superhero-styleselector-close').click(function(){
			$('.block-superhero-quicksettings').toggleClass('open');
		})
	})
</script>