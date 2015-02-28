(function($){
	CKEDITOR.plugins.add('shortcode',{
		icons: '',
		
		init: function(editor) {		
			CKEDITOR.dialog.add('superheroDialog',function(editor){
				var shortcodeChanged = function() {
					var dialog = this.getDialog(),
						columnFeatures = dialog.getContentElement('shortcodeSelect','columnsFeatures');
					
					console.log(columnFeatures);
					columnFeatures.hide();
				};
			
				return {
					title: 'Superhero Shortcodes',
					minWidth: 400,
					minHeight: 200,
					contents: [{
						id:	'shortcodeSelect',
						elements: [
							{
								type: 'select',
								id: 'shortcode',
								label: 'Shortcode',
								items: [
									[''],
									['Columns'],
									['Testimonial'],
									['Accordion']
								],
								default: '',
								setup: function(data) {
									console.log('test');
									shortcodeChanged.call(this);
								},
								onChange: function(api) {
									var dialog = CKEDITOR.dialog.getCurrent();
									var elem = dialog.getContentElement('shortcodeSelect','shortcode');
									//elem.getElement().remove();
									
								}
							},
							{
								type: 'vbox',
								width: '100%',
								id: 'columnsFeatures',
								children: [
									{
										type: 'fieldset',
										label: 'Column Settings',
										children: [
											{
												type: 'select',
												id: 'numColumns',
												label: 'Number of Columns',
												items: [
													['2'],
													['3'],
													['4']
												],
												default: '2'
											}
										]
									}
								]
							}
						]
					}]
				}
			});
			
			editor.addCommand('shortcodeDialogCmd',new CKEDITOR.dialogCommand('superheroDialog'));
			
			editor.ui.addButton('Shortcode', {
				label: 'Insert Superhero Shortcode',
				icon: this.path + 'images/icon.png',
				command: 'shortcodeDialogCmd',
			});
			
		}
	});
})(jQuery);