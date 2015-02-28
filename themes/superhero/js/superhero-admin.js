(function($){
	$(document).ready(function(){
		$('#edit-layout-settings > .fieldset-wrapper').sortable({
			axis: "y",
			handle: '.rowmove',
			update: function(event,ui) {
				setRowWeights(ui.item);
				showSaveMessage();
			}
		});
		
		$('.regions').sortable({
			axis: "x",
			handle: '.columnmove',
			update: function(event,ui) {
				setColumnWeights(ui.item);
				showSaveMessage();
			}
		});
		
		$('.regions .region:last-child .columnsettings').attr('data-placement','left');
		
		$('.columntools a').on('click',function(event){
			event.preventDefault();
			return false;
		});
		
		$('.rowtools a').on('click',function(event){
			event.preventDefault();
			return false;
		});
		
		$('.colorpicker').minicolors();
		
	
		$('.columnsettings').popover({
			html: true,
			content: function() {
				// Section Settings
				$('#system-theme-settings').on('change','.popover select[name="section"]',function(event){
					event.stopImmediatePropagation();
					var $region = $(this).closest('.region');
					var $field = $region.find('input[name$="section"]');
					$field.val($(this).val());
				});
				
				// Column Settings
				// Phone
				$('#system-theme-settings').on('change','.popover select[name="xscolumns"]',function(event){
					event.stopImmediatePropagation();
					var $region = $(this).closest('.region');
					var $field = $region.find('input[name$="xscolumns"]');
					$field.val($(this).val());
					var classes = $region.attr('class').split(" ");
					var pattern = /^col-xs-/;
					for(var i = 0; i < classes.length; i++) {
						if (classes[i].match(pattern)) {
							$region.removeClass(classes[i]);
						}
					}
					$region.addClass('col-xs-'+$(this).val());	
				});
				// Tablet
				$('#system-theme-settings').on('change','.popover select[name="smcolumns"]',function(event){
					event.stopImmediatePropagation();
					var $region = $(this).closest('.region');
					var $field = $region.find('input[name$="smcolumns"]');
					$field.val($(this).val());
					var classes = $region.attr('class').split(" ");
					var pattern = /^col-sm-/;
					for(var i = 0; i < classes.length; i++) {
						if (classes[i].match(pattern)) {
							$region.removeClass(classes[i]);
						}
					}
					$region.addClass('col-sm-'+$(this).val());	
				});
				// Desktop
				$('#system-theme-settings').on('change','.popover select[name="mdcolumns"]',function(event){
					event.stopImmediatePropagation();
					var $region = $(this).closest('.region');
					var $field = $region.find('input[name$="mdcolumns"]');
					$field.val($(this).val());
					var classes = $region.attr('class').split(" ");
					var pattern = /^col-md-/;
					for(var i = 0; i < classes.length; i++) {
						if (classes[i].match(pattern)) {
							$region.removeClass(classes[i]);
						}
					}
					$region.addClass('col-md-'+$(this).val());	
				});
				// X Desktop
				$('#system-theme-settings').on('change','.popover select[name="lgcolumns"]',function(event){
					event.stopImmediatePropagation();
					var $region = $(this).closest('.region');
					var $field = $region.find('input[name$="lgcolumns"]');
					$field.val($(this).val());
					var classes = $region.attr('class').split(" ");
					var pattern = /^col-lg-/;
					for(var i = 0; i < classes.length; i++) {
						if (classes[i].match(pattern)) {
							$region.removeClass(classes[i]);
						}
					}
					$region.addClass('col-lg-'+$(this).val());	
				});
				
				
				// Force Settings
				$('#system-theme-settings').on('click','.popover input:checkbox',function(event) {
					event.stopImmediatePropagation();
					var $region = $(this).closest('.region');
					var $field = $region.find('input[name$=force]');		
					if ($(this).is(':checked')) {
						$field.val(1);
					} else {
						$field.val(0);
					}		
				});
				
				$('#system-theme-settings').on('click','.popover .apply-region',function(event){
					event.stopImmediatePropagation();
					$(this).closest('.popover').prev().popover('hide');
					$(this).closest('.columntools').removeClass('open');
					return false;
				});
				return $('#regionsettings').html();
			}
		}).on('click',function(event){
			var $columntools = $(this).parent();
		
			var settings = getColumnSettings($(this));
			$('.popover-content',$columntools).find('select[name="section"]')
								.find('option[value="'+settings.section+'"]')
								.attr('selected','selected');
			/*
			$('.popover-content',$columntools).find('select[name="columns"]')
								.find('option[value="'+settings.columns+'"]')
								.attr('selected','selected');
			*/
			$('.popover-content',$columntools).find('select[name="xscolumns"]')
								.find('option[value="'+settings.xscolumns+'"]')
								.attr('selected','selected');
			$('.popover-content',$columntools).find('select[name="smcolumns"]')
								.find('option[value="'+settings.smcolumns+'"]')
								.attr('selected','selected');
			$('.popover-content',$columntools).find('select[name="mdcolumns"]')
								.find('option[value="'+settings.mdcolumns+'"]')
								.attr('selected','selected');
			$('.popover-content',$columntools).find('select[name="lgcolumns"]')
								.find('option[value="'+settings.lgcolumns+'"]')
								.attr('selected','selected');
			var $force = $('.popover-content',$columntools).find('input[name="force"]');
			if (settings.force == '1') {
				$force.attr('checked','checked');
			}
			
			if ($columntools.hasClass('open')) {
				$columntools.removeClass('open');
			} else {
				$columntools.addClass('open');
			}

		});
		
		//$("input[name$='superhero_section_header_fullwidth']").val(0);
		/* Sticky settings*/
		$('input.superhero-sticky-form-item').click(function(){
			if($(this).val()==1){
				$('input.superhero-sticky-form-item[value=0]').attr('checked',true);
				$(this).attr('checked',true);
			}
		})
	});
	
	function setColumnWeights(item) {
		var $parent = item.parent();
		$parent.children().each(function(i){
			$(this).find("input[name$='weight']").val(i);
		});
	}
	
	function setRowWeights(item) {
		var $parent = item.parent();
		$parent.children().each(function(i){
			$(this).find(".section-properties input[name$='weight']").val(i);
		});
	}
	
	function getColumnSettings(item) {
		var $region = item.parent().parent();
		var settings = {};
		$('input',$region).each(function(i){
			var name = $(this).attr('name');
			var key = name.split('_').pop();
			settings[key] = $(this).val();
		});
		return settings;
	}
	
	function showSaveMessage() {
		if ($('.save-message').length == 0) {
			$('#edit-layout-settings').prepend(
				'<div class="save-message warning">The changes to the page layout will not be saved until the Save Configuration button is clicked</div>'
			);
			$('.save-message').fadeIn('slow');
		}
	}
})(jQuery);