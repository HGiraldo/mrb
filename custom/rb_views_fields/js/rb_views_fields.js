(function($) {
  Drupal.rbViewsFields = Drupal.rbViewsFields || {};
  Drupal.behaviors.rbViewsFields = {
    attach:function(context, settings) {
      $('.social-b').click(function(e) {
        // e.preventDefault();
        // window.open($(this).find('a').attr('href'), 'newwindow', 'width=450, height=350');
        // return false;
      });
    }
  }
}(jQuery));
