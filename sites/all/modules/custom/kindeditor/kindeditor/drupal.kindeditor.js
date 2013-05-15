(function($){

		$(function() {
				//添加过滤条件
				KindEditor.options.htmlTags['fieldset'] = [];
				KindEditor.options.htmlTags['legend'] = [];

				var settings = Drupal.settings.kindeditor;
				settings['afterCreate'] = function(){
  				this.sync(); 
  			};
  			settings['afterBlur'] = function(){
  				this.sync(); 
  			};    
				var editor = KindEditor.create(settings.id , settings);

				$(document).ajaxSuccess(function() {
  				var settings = Drupal.settings.kindeditor;

  				settings['afterCreate'] = function(){
  					this.sync(); 
  				};
  				settings['afterBlur'] = function(){
  					this.sync(); 
  				};       
					var editor = KindEditor.create(settings.id , settings);
				});

				$('.close-class').live('click', function(){
					Drupal.CTools.Modal.dismiss();
					if( $.browser.msie ) {
						editor.focus();
					}
				});
		});
})(jQuery);