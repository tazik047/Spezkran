(function ($) {
  $(document).ready(function () {
    $(superhero_presets).each(function (index) {
			addPresetPreview(index);
    });

    setTimeout(function () {
      loadPreset($('input[name=superhero_default_preset]').val())
    }, 1000);
		
		function addPresetPreview(index){
			var preset = $('<div>').attr('index',index).addClass('preset preview');
			var preview = $('<span>').text('Preset '+(index+1)).css({background:superhero_presets[index].superhero_color_link});
			//var remove = $('<span>').addClass('remove');
			//preview.append(remove);
			var input = $('<input type="radio" name="default_preset" title="Set as default preset" value="'+index+'">');
			if($('input[name=superhero_default_preset]').val()==index){
				input.attr('checked',true);
			}
			input.click(function(){
				$('input[name=superhero_default_preset]').val($(this).val());
			});
			preview.click(function(){
				savePreset();
        loadPreset(index);
        $('.presets .preset').removeClass('active');
        $(this).parent().addClass('active');
			})
			preset.append(preview).append(input);
			$('.presets').append(preset);
		}
		
    function savePreset() {
      $('.perset-option').each(function () {
        superhero_presets[superhero_current_preset][$(this).attr('name')] = $(this).val();
      })
    }

    function loadPreset(index) {
      $('.presets .preset').removeClass('active');
      $('.presets .preset[index=' + index + ']').addClass('active');
      superhero_current_preset = index;
      $('.perset-option').each(function () {
        $(this).val(superhero_presets[index][$(this).attr('name')] || '');
        $(this).minicolors('value', $(this).val());
      })
    }

    $('form#system-theme-settings').submit(function () {
      savePreset();
      $('input[name=superhero_presets]').val(base64Encode(JSON.stringify(superhero_presets)));
    })

    $('a.new-preset').click(function () {
      var newindex = superhero_presets.length;
			superhero_presets[newindex] = {
				name: $('#preset_name').val()
			};
			addPresetPreview(newindex);
			loadPreset(newindex);
			return false;
    });
  })
})(jQuery);

var keyString = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";
base64Encode = function (c) {
  var a = "";
  var k, h, f, j, g, e, d;
  var b = 0;
  c = UTF8Encode(c);
  while (b < c.length) {
    k = c.charCodeAt(b++);
    h = c.charCodeAt(b++);
    f = c.charCodeAt(b++);
    j = k >> 2;
    g = ((k & 3) << 4) | (h >> 4);
    e = ((h & 15) << 2) | (f >> 6);
    d = f & 63;
    if (isNaN(h)) {
      e = d = 64
    } else {
      if (isNaN(f)) {
        d = 64
      }
    }
    a = a + keyString.charAt(j) + keyString.charAt(g) + keyString.charAt(e) + keyString.charAt(d)
  }
  return a
};

UTF8Encode = function (b) {
  b = b.replace(/\x0d\x0a/g, "\x0a");
  var a = "";
  for (var e = 0; e < b.length; e++) {
    var d = b.charCodeAt(e);
    if (d < 128) {
      a += String.fromCharCode(d)
    } else {
      if ((d > 127) && (d < 2048)) {
        a += String.fromCharCode((d >> 6) | 192);
        a += String.fromCharCode((d & 63) | 128)
      } else {
        a += String.fromCharCode((d >> 12) | 224);
        a += String.fromCharCode(((d >> 6) & 63) | 128);
        a += String.fromCharCode((d & 63) | 128)
      }
    }
  }
  return a
};