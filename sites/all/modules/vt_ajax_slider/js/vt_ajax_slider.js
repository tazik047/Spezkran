// build for Drupal 7, using jQuery 1.4+
// Version 1.3

jQuery(document).ready(function($) {
  // Break early if no slider found
  if ($('#d-slide-container').length == 0) {
    return false;
  }
  
	var options = Drupal.settings.vt_ajax_slider;
	var target = $('#d-slide-container');
	var processing = false;
	var tw = target.width();
	var th = target.height();
	var eOptions = {};
	var statusBar = $('div#d-slide-status-bar');
	var preview = $('#d-slide-preview');
			
	// Function to fetch content via ajax					
	var getContent = function(target, page, currentpage) {
	  if (options.progressbar == 'yes') {
  		statusBar.fadeIn();
	  }
		
		var updateProducts = function(data) {
		  // Append the ajax fetched content
      target.append(data.content);
           
      // Load the appended data and remove the current displayed frame
      target.children().last().hide().find('img').load(function() {  
        targetpage = target.children().index(target.children().last());
        slideContent(target, targetpage, currentpage);
      });   

      // Bind the preview if configured to do so
			if (options.preview == 'yes') {
				preview.append(data.preview);
				preview.children().last().hide().find('img').load(function() {
				  preview.children().removeClass('active-preview').last().addClass('displayed active-preview').show();
				});
			}
			
			// Remove status bar
			if (options.progressbar == 'yes') {
			  statusBar.effect('puff', eOptions, 1000).hide();
			}
			
		};
		
		// Ajax fetching
		$.ajax({
			type : 'POST',
			url : Drupal.settings.basePath + 'jss_get_content',
			success : updateProducts,
			dataType : 'json',
			data : ({
			  'cache' : 'nocache',
				'number' : page,
				'json' : 1
			})
		});
	};

	function calculateWidth(source) {
		return $(source).innerWidth();
	}

	// Slide existing content
	var slideContent = function (target, targetpage, currentpage) {
  		var processing = true, 		
  		    wrapperHeight = target.parent().height(),
  		    contentHeight = target.height();
  		
  		target.parent().css('min-height', wrapperHeight);
  		target.css('min-height', contentHeight).children().eq(currentpage).addClass('slide-out').hide(options.animationModeOut, eOptions, parseInt(options.animationTimerOut), function() {
  		  target.children().eq(targetpage).addClass('slide-in').show(options.animationModeIn, eOptions, parseInt(options.animationTimerIn), function() { 		    
  		    $(this).removeClass('slide-in');
  	      target.css('min-height', '1px').parent().css('min-height', '1px');
  		  });
  		}).removeClass('slide-out');
  	
		options.currentpage = targetpage;
	};

	// Select whether to ajax or normal slide
	var selectMethod = function(target, getpage, page, mode) {
	  // Preventing multiple click
		if (processing) {
		  return false;
		}
		
		var count = target.children().eq(parseInt(getpage)).length;
	  // target exists just slide the content
		if (count != 0) {
			slideContent(target, parseInt(getpage), parseInt(page));
		} 
		
		// target not exists fetch it via ajax
		if (count == 0) {
			getContent(target, parseInt(getpage),	parseInt(page));
		}
			
		// process preview
		if (options.preview == 'yes') {
		  previewSlide(parseInt(getpage), mode);		
			preview.children().removeClass('active-preview').eq(parseInt(getpage)).addClass('active-preview');
		}
	};
	
	var previewSlide = function(page, mode) {
	  switch (mode) {
	    case 'next' :
	      if (preview.children().eq(page).hasClass('displayed') == false) {
	        $('.displayed').last().next().addClass('displayed').fadeIn('slow');
	        
	        var totalDisplayed = $('.displayed').length;
	        if (totalDisplayed >= options.maxPreview) {
	          $('.displayed').eq(0).removeClass('displayed').fadeOut();
	        }        
	      }
	    break;
	    case 'prev' :
	      preview.children().removeClass('active-preview');
	      if (preview.children().eq(page).hasClass('displayed') == false) {
	        var number = options.maxPreview - 1;
	        var totalDisplayed = $('.displayed').length;
	        if (totalDisplayed >= options.maxPreview) {
	          $('.displayed').eq(number).removeClass('displayed').fadeOut();
	        }
	        $('.displayed').eq(0).prev().addClass('displayed').fadeIn();	        
	      }
	    break;
	    case 'reset' :
	      preview.children().removeClass('displayed').removeClass('active-preview').fadeOut();
	      preview.children('.d-slide-preview:lt(' + options.maxPreview + ')').addClass('displayed').fadeIn();
	      preview.children().eq(0).addClass('active-preview');	
	    break;
	  }
	  
	};
	
	var previewClick = function(source) {
		slideContent(target, source, options.currentpage);
		preview.children().removeClass('active-preview').eq(parseInt(source)).addClass('active-preview');
	};


	var previewCount = function() {
		// we count the gross dimension of the container
		var maxWidth = preview.width();
		var maxHeight = preview.height();

		// get the preview item outer width
		var itemWidth = preview.children().outerWidth(true);
		var itemHeight = preview.children().outerHeight(true);

		var itemPerRow = Math.floor(maxWidth / itemWidth);
		if (itemPerRow < 1) {
			itemPerRow = 1;
		}
		var itemPerLine = Math.floor(maxHeight / itemHeight);
		if (itemPerLine < 1) {
			itemPerLine = 1;
		}
		var totalItem = itemPerRow * itemPerLine;

		return totalItem;
	};

	// Button left click
  $('#d-slide-left').live('click', function() {
		if (processing == true || options.currentpage == 0) {
		  return false;
		}

  	// check if new element exist or not
  	selectMethod(target, options.currentpage - 1, options.currentpage, 'prev');
					
		if (options.autoslide == 'yes') {
			clearInterval(autoscroll);
		}		
  });

	$('#d-slide-right').live('click', function() {
    if (processing == true) {
      return false;
    }

    if (options.currentpage == options.maxscroll) {
		  getpage = 0;
		  mode = 'reset';
		} 
		else {
		  getpage = options.currentpage + 1;
		  mode = 'next';
		}
		
		selectMethod(target, getpage, options.currentpage, mode);
		
		if (options.autoslide == 'yes') {
			clearInterval(autoscroll);
		}
	});

	// function to autoslide
	if (options.autoslide == 'yes' && options.maxscroll != 0 && processing == false) {
    if (processing == true) {
      return false;
    }
    
	  var timer = options.autoslideTimer;
		var autoscroll = setInterval(function() {
		  if (processing == true) {
		    return false;
		  }
		  var processing = true;
			var page = options.currentpage;

			// Reverse mode
			if (options.autoslideMode == 'reverse') {
				if ((page == 0 || options.autoslideWay == 'forward') && page < options.maxscroll) {
					var getpage = page + 1;
					mode = 'next';
					options.autoslideWay = 'forward';
				}
				if (page == options.maxscroll || options.autoslideWay == 'backward') {
					var getpage = page - 1;
					mode = 'prev';
					options.autoslideWay = 'backward';
				}			
			}
			
			// Return to beginning mode
			if (options.autoslideMode == 'return') {
				if (page == options.maxscroll) {
					getpage = 0;
					mode = 'reset';
				} else {
					getpage = page + 1;
					mode = 'next';
				}
			}
			
      selectMethod(target, getpage, page, mode);
      
		}, timer);
	}

	// Preview click function
	$('.d-slide-preview').live('click', function(e) {
		if ($(this).hasClass('active-preview') || processing == true) {
		  return false;
		}
		previewClick($('.d-slide-preview').index(this));

		if (options.autoslide == 'yes') {
			clearInterval(autoscroll);
		}
	});

	// first time running
	if (preview.children().hasClass('displayed') == false) {
	
		// fix click button wrong content
		target.children().not(':eq(0)').hide('fast');
		
		if (options.preview == 'yes') {
  		// count and store the maximum displayed preview
  		options.maxPreview = previewCount();
  		// only show the maximum available preview item	
  		preview.children().eq(0).addClass('active-preview');
  		preview.children().not(':lt(' + options.maxPreview + ')').hide('fast');
  		preview.children('.d-slide-preview:lt(' + options.maxPreview + ')').addClass('displayed');
		}
	}
	
});