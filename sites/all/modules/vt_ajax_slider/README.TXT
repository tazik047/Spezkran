VicTheme Ajax Slider Module
Version 2.3
Previously known as vt_slider module and jQuery side slide module.
Major upgrade from 1.x series, it utilizes vt_slider_api as the core api.
The 2.x version is not compatible with the old 1.x version, the new version implement
a different approach to sort the content need to be slided.

Starting from 2.3 version, the slider is capable to do auto resizing responsively if
the slider themes css is set to do so by using fluid width and height.

Removed jQuery easing and only do fadeIn and fadeOut animation.
Version 2.3 and above may not compatible with themes created for version belows it.

FEATURE
Ajax content fetching
Multiple Content type as content
Several content sorting options
Animated Previous and Next button
Animated title & content
Content word limiting
Small Click-able preview item


INSTALLATION

This module will follow the standard drupal module installation.
You need to extract the module to drupal modules directory (eg. sites/all/modules) then
enable the module via drupal module configuration page.

CONFIGURATION

The module has 1 page for configuration located at : admin/config/vt_slider/vt_slider_config

The configuration form is self explanatory.

Note: the module will create 1 block that you will need to put in your desired block region.

THEMING

The module provides several themer friendly template that you can edit to style the module

The templates provided are :

1. vt-ajax-slider-button-left.tpl.php , This is the template for the left button (previous button).
2. vt-ajax-slider-button-right.tpl.php, This is the template for the right button (next button).
3. vt-ajax-slider-content.tpl.php, this is the template for the content item of the slider
4. vt-ajax-slider-preview.tpl.php, this is the template for the small click-able preview item
5. vt-ajax-slider-progress-bar.tpl.php, this is the template for the progress bar shown when ajax is loading
6. vt-ajax-slider-wrapper.tpl.php, this is the main template where all the other template content is merged together.

When you are theming the slider-preview.tpl.php and slider-content.tpl.php $node variable is available for you to use. You can do print_r($node, TRUE); to view what is the available variable in the $node.

WARNING: There are several css id and classes that linked together to jQuery, removing this will break the jQuery script.

