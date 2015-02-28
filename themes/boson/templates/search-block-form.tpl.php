<?php

$search["search_block_form"] = str_replace('value=""', 'value="Search.." onblur="setTimeout(\'closeResults()\',2000); if (this.value == \'\') {this.value = \'\';}"  onfocus="if (this.value == \'Search..\') {this.value = \'\';}" ', $search["search_block_form"]);

?>

<div class="container-inline">
<i class="icon-search"></i>
<?php
  print $search["search_block_form"];
  
  print $search["hidden"];  
  
  if (isset($search['extra_field'])): ?>
    <div class="extra-field">
      <?php print $search['extra_field']; ?>
    </div>
  <?php endif; ?>
</div>