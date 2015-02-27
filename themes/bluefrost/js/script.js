jQuery(document).ready(function ($) {
  // superfish menu in top navigation block
  $('#navigation').find('ul.menu').each(function() {
    $(this).superfish({
      hoverClass:    'sfHover',          // the class applied to hovered list items 
      pathClass:     'overideThisToUse', // the class you have applied to list items that lead to the current page 
      pathLevels:    1,                  // the number of levels of submenus that remain open or are restored using pathClass 
      delay:         1000,                // the delay in milliseconds that the mouse can remain outside a submenu without it closing 
      animation:     {opacity:'show'},   // an object equivalent to first parameter of jQuery�s .animate() method 
      speed:         'normal',           // speed of the animation. Equivalent to second parameter of jQuery�s .animate() method 
      autoArrows:    false,               // if true, arrow mark-up generated automatically = cleaner source code at expense of initialisation performance 
      dropShadows:   true,               // completely disable drop shadows by setting this to false 
      disableHI:     false 
    });
  });
    
  // CSS3PIE
  if (window.PIE) {
    // Navigations
    $('#navigation')
      // Block menu wrapper
      .find('.block-menu')

      // Hover element
      .find('li').each(function() {
        PIE.attach(this);
    });
    
    // Content comment
    $('.content-comment-top').css('position', 'relative').each(function() {
      PIE.attach(this);
    });
    
    // Node comment
    $('.content-node-top').css('position', 'relative').each(function() {
      PIE.attach(this);
    });
    
    // Node links
    $('.node-links').css('position', 'relative').each(function() {
      PIE.attach(this);
    });
    
    // Comments
    $('.comment-top').css('position', 'relative').each(function() {
      PIE.attach(this);
    });
    
    $('.comment-bubble-content').css('position', 'relative').each(function() {
      PIE.attach(this);
    });
    
  }
  
});



