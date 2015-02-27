(function ($) {

Drupal.behaviors.vt_slider_apiFieldsetSummaries = {
  attach: function (context) {
    $('fieldset.slider-dashboard-form', context).drupalSetSummary(function (context) {
      var revisionCheckbox = $('.field-name-vtslider-enable select option:selected', context);
      if (revisionCheckbox.val() == 'enable') {
        return Drupal.t('Slider Enabled');
      }

      return Drupal.t('Slider Disabled');
    });
  }
};

})(jQuery);