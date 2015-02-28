/*------------------------------------------------------------------------
 # MD Slider - March 18, 2013
 # ------------------------------------------------------------------------
 # Websites:  http://www.megadrupal.com -  Email: info@megadrupal.com
 --------------------------------------------------------------------------*/

(function($) {
    var MdSliderPanel = function() {
        var self = this;
        this.tabs = null;
        this.activePanel = null;
        this.selectedItem = null;
        this.mdSliderToolbar = new MdSliderToolbar(self);
        this.mdSliderTimeline = new MdSliderTimeline(self);
        this.textBoxTemplate = '<div class="slider-item ui-widget-content item-text" data-top="0" data-left="0" data-width="100" data-height="50" data-borderstyle="solid" data-type="text" data-title="Text" style="width: 100px; height: 50px;"><div>Text</div><span class="sl-tl"></span><span class="sl-tr"></span><span class="sl-bl"></span><span class="sl-br"></span><span class="sl-top"></span><span class="sl-right"></span><span class="sl-bottom"></span><span class="sl-left"></span> </div>';
        this.imageBoxTemplate = '<div class="slider-item ui-widget-content item-image" data-top="0" data-left="0" data-width="100" data-height="50" data-borderstyle="solid" style="height: 80px;width: 80px;" data-type="image"><img width="100%" height="100%" src="http://files.megadrupal.com/other/image.jpg" /><span class="sl-tl"></span><span class="sl-tr"></span><span class="sl-bl"></span><span class="sl-br"></span><span class="sl-top"></span><span class="sl-right"></span><span class="sl-bottom"></span><span class="sl-left"></span></div>';
        this.videoBoxTemplate = '<div class="slider-item ui-widget-content item-video" data-top="0" data-left="0" data-width="100" data-height="50" data-borderstyle="solid" style="height: 80px;width: 80px;" data-type="video"><img width="100%" height="100%" src="http://files.megadrupal.com/other/video.jpg" /><span class="sl-tl"></span><span class="sl-tr"></span><span class="sl-bl"></span><span class="sl-br"></span><span class="sl-top"></span><span class="sl-right"></span><span class="sl-bottom"></span><span class="sl-left"></span></div>';
        this.tab_counter = $("#md-tabs ul.md-tabs-head li.tab-item").size();
        this.init = function() {
            self.initTab();
            self.initPanel();
            self.initSliderItem();
            $(document).keyup(function(event) {
                var keyCode = event.keyCode || event.which;
                var isInput = $(event.target).is("input, textarea, select");
                if(!isInput && keyCode == 46 && self.selectedItem != null){
                    var timeline = self.selectedItem.data("timeline");
                    if(timeline != null) {
                        timeline.remove();
                        self.selectedItem.remove();
                        self.triggerChangeSelectItem();
                    }
                }
            });
            $(window).resize(function() {
                self.resizeWindow();
            })
        };
        this.initTab = function() {
            self.tabs = $("#md-tabs").tabs({
                tabTemplate: '<li class="tab-item first clearfix"><a class="tab-link" href="#{href}"><span class="tab-text">#{label}</span></a> <span class="ui-icon ui-icon-close">Remove Tab</span></li>',
                add: function( event, ui ) {
                    $( ui.panel ).append($('#dlg-slide-setting').html());
                    $( ui.panel ).data('timelinewidth', $('input[name=default-timelinewidth]').val());
                    self.tabs.tabs('select', ui.index);
                },
                show: function( event, ui ) {
                    $(self.activePanel).find(".slider-item.ui-selected").removeClass("ui-selected");
                    self.activePanel = $(ui.panel);
                    self.mdSliderTimeline.changeActivePanel();
                    self.triggerChangeSelectItem();
                    self.resizeBackgroundImage();
                }
            });
            $(".md-tabs-head li").live({
                mouseenter: function() {
                    $(this).find(".ui-icon-close").show();
                },
                mouseleave: function() {
                    $(this).find(".ui-icon-close").hide();
                }
            });

            $(".md-tabs-head span.ui-icon-close").live("click", function() {
                var _close = $(this);
                var panel_id = _close.prev().attr('href');
                var settings = JSON.parse($('.settings input', $(panel_id)).val());
                if (!confirm('Are you sure want to delete this slide? After accepting this slide will be removed completely.')) {
                    return;
                }

                if (settings.slide_id == -1) {
                    var index = $("li", self.tabs).index($(this).parent());
                    self.tabs.tabs("remove", index);
                }
                else {
                    $.post(location.protocol + '//' + location.host + Drupal.settings.basePath + '?q=admin/structure/md-slider/slide/delete', {sid: settings.slide_id}, function(data_response) {
                        if (data_response == 'OK') {
                            var index = $("li", self.tabs).index(_close.parent());
                            self.tabs.tabs("remove", index);
                        }
                    });
                }
            });
            self.tabs.find(".ui-tabs-nav").sortable({
                axis: "x",
                stop: function() {
                    self.tabs.tabs("refresh");
                }
            });
            /**
             * Added by Duynv
             */
            $("#slide-setting-dlg").dialog({
                resizable: false,
                autoOpen: false,
                draggable: false,
                modal: true,
                width: 960,
                open: function() {
                    var $tab = $(this).data("tab");
                    if($tab) {
                        var settings = $("input.panelsettings", $tab).val();
                        (settings != "") && (settings = $.stringToObject(settings));
                        self.setSlideSettingValue(settings);
                    }
                },
                buttons: {
                    Save: function() {
                        var $tab = $(this).data("tab");
                        if($tab) {
                            var settings = self.getSlideSettingValue();
                            var old_settings = $.stringToObject($("input.panelsettings", $tab).val());
                            settings= $.extend(old_settings, settings);
                            $("input.panelsettings", $tab).val($.objectToString(settings));
                            // Add slide background image
                            var slid = $('input[name=slider_id]').val();
                            $.post(Drupal.settings.basePath + '?q=admin/structure/md-slider/get-background-image', {fid: settings.background_image, slider_id: slid}, function(response) {
                                $('.md-slide-image img', self.activePanel).attr('src', response);
                            });
                        }
                        $(this).dialog("close");
                    },
                    Cancel: function() {
                        $(this).dialog("close");
                    }
                }
            });
            $('.panel-settings-link').live('click', function() {
                $("#slide-setting-dlg").data("tab", $(this).parent().parent()).dialog("open");
				return false;
            });
            $('.random-transition').click(function() {
                $('#navbar-content-transitions input').removeAttr("checked");
                for (i = 0; i < 3; i++) {
                    randomTran = Math.floor(Math.random() * 26) + 1;
                    $('#navbar-content-transitions li:eq('+randomTran+') input').attr("checked","checked");
                }
                return false;
            });

            $('.slide-choose-image-link, .slide-choose-thumbnail-link').live('click', function() {
                var input_save = $(this).parent().next();
                var _self = $(this);
                Drupal.media.popups.mediaBrowser(function(files) {
                    var icon = files[0];
                    Drupal.settings.select_image = icon;
                    input_save.val(icon.fid);
                    _self.next().empty().append('<img width="100" height="100" alt="" src="'+icon.url+'">');
                });
            });
            var slider = $("#md-slider").mdSlider({
                transitions: "fade",
                height: 150,
                width: 290,
                fullwidth: false,
                showArrow: true,
                showLoading: false,
                slideShow: true,
                showBullet: true,
                showThumb: false,
                slideShowDelay: 3000,
                loop: true,
                strips: 5,
                transitionsSpeed: 1500
            });
            $('#navbar-content-transitions li').hoverIntent(function(){
                var tran = $("input", this).attr('value');
                $("#md-slider").data("transitions", tran);
                var position = $(this).position();
                $("#md-tooltip").css({left: position.left - 200 + $(this).width() / 2, top: position.top - 180}).show();
            }, function() {$("#md-tooltip").hide()});

            /**
             * End added by Duynv
             */
            $('.panel-clone').live('click', function() {
                self.cloneTab($(this).parent().parent());
                return false;
            });
        };
        this.resizeWindow = function() {
            self.resizeBackgroundImage();
        }
        this.resizeBackgroundImage = function() {
            if($(".md-slidewrap", self.activePanel).hasClass("md-fullwidth")) {
                var panelWidth = $(".md-slide-image", self.activePanel).width(),
                    panelHeight = $(".md-slide-image", self.activePanel).height(),
                    $background = $(".md-slide-image img", self.activePanel),
                    dimensions = getImgSize($background.attr("src")),
                    width = dimensions.width,
                    height = dimensions.height;
                //console.log(panelWidth + " - " + panelHeight);
                if(height > 0 && panelHeight > 0) {
                    if((width / height) > (panelWidth / panelHeight)) {
                        var left = panelWidth - (panelHeight / height) * width;
                        $background.css({width: "auto", height: "100%"});
                        if(left < 0) {
                            $background.css({left: (left/2) + "px", top: 0 });
                        } else {
                            $background.css({left: 0, top: 0 });
                        }
                    } else {
                        var top = panelHeight - (panelWidth / width) * height;
                        $background.css({width: "100%", height: "auto"});
                        if(top < 0) {
                            $background.css({top: (top/2) + "px", left: 0 });
                        } else {
                            $background.css({left: 0, top: 0 });
                        }
                    }
                }
            }
        }
        function getImgSize(imgSrc) {
            var newImg = new Image();
            newImg.src = imgSrc;
            var dimensions = {height: newImg.height, width: newImg.width};
            return dimensions;
        };
        this.initSliderItem = function() {
            $("#md-tabs div.slider-item").each(function() {
                var setting = $(this).getItemValues();
                $(this).setItemStyle(setting);
            });
        }
        this.initPanel = function() {
            $("#add_tab").click(function() {
                self.addTab();
                return false;
            });
            $("#md-tabs .slider-item").each(function(){
                $(this).data("slidepanel", self).triggerItemEvent();
            });
        }

        this.addTab = function() {
            self.tab_counter++;
            var tab_title = "Slide " + self.tab_counter;
            self.tabs.tabs( "add", "#tabs-" + self.tab_counter, tab_title );
        }
        this.cloneTab = function(tab) {
            self.tab_counter++;
            var tab_title = "Slide " + self.tab_counter;
            self.tabs.tabs( "add", "#tabs-" + self.tab_counter, tab_title );
            self.activePanel = $("#tabs-" + self.tab_counter);
            $("#tabs-" + self.tab_counter).find(".md-slide-image").html(tab.find(".md-slide-image").html());
            var setting = $.stringToObject($("input.panelsettings", tab).val());
            setting.slide_id = -1;
            $("#tabs-" + self.tab_counter + " input.panelsettings").val($.objectToString(setting));
            $("#tabs-" + self.tab_counter).data("timelinewidth", tab.data("timelinewidth"));
            self.mdSliderTimeline.setTimelineWidth(tab.data("timelinewidth"));
            $(".slider-item", tab).each(function() {
                self.cloneBoxItem($(this));
            });
        }
        this.cloneBoxItem = function(boxItem) {
            var itemValue = $(boxItem).getItemValues();
            if(itemValue && self.activePanel != null) {
                var box,
                    type = itemValue.type;
                if (type == "text") {
                    box =  $(self.textBoxTemplate).clone();
                } else if (type == "image") {
                    box =  $(self.imageBoxTemplate).clone();
                } else {
                    box =  $(self.videoBoxTemplate).clone();
                }
                box.data("slidepanel", self).appendTo($(".md-objects", self.activePanel));
                box.setItemValues(itemValue);
                box.setItemStyle(itemValue);
                box.setItemHtml(itemValue);
                box.triggerItemEvent();
                self.mdSliderTimeline.addTimelineItem(type, box);
                return true;
            }
        }

        this.addBoxItem = function(type) {
            if (this.activePanel != null) {
                var box;
                if (type == "text") {
                    box =  $(this.textBoxTemplate).clone();
                } else if (type == "image") {
                    box =  $(this.imageBoxTemplate).clone();
                } else {
                    box =  $(this.videoBoxTemplate).clone();
                }
                self.mdSliderTimeline.addTimelineItem(type, box);
                box.data("slidepanel", this).appendTo($(".md-objects", this.activePanel)).triggerItemEvent();
                self.changeSelectItem(box);
                self.mdSliderTimeline.triggerChangeOrderItem();
                self.mdSliderToolbar.focusEdit();
                return true;
            }
            return false;
        };

        this.triggerChangeSelectItem = function() {
            if (this.activePanel == null) return;
            var selected = $(this.activePanel).find(".slider-item.ui-selected");
            if (selected.size() == 1) {
                this.selectedItem = selected;
            } else {
                this.selectedItem = null;
            }
            this.mdSliderToolbar.changeSelectItem(this.selectedItem);
            this.mdSliderTimeline.changeSelectItem(this.selectedItem);
        }

        this.setItemAttribute = function(attrName, value) {
            if (this.selectedItem != null) {
                switch (attrName) {
                    case "width": return self.setBoxWidth(this.selectedItem, value); break;
                    case "height": return self.setBoxHeight(this.selectedItem, value); break;
                    case "left": return self.setPositionBoxLeft(this.selectedItem, value); break;
                    case "top": return self.setPositionBoxTop(this.selectedItem, value); break;
                }
            }
        }
        this.setItemSize = function(width, height) {
            self.setBoxWidth(this.selectedItem, width);
            self.setBoxHeight(this.selectedItem, height);
        }
        this.setItemBackground = function(name, value) {
            if (this.selectedItem != null) {
                $(this.selectedItem).data($.removeMinusSign(name), value);
                var  bgcolor = $(this.selectedItem).data("backgroundcolor");
                if(bgcolor && bgcolor != "") {
                    var opacity = parseInt($(this.selectedItem).data("backgroundtransparent"));
                    var rgb = $.HexToRGB(bgcolor);
                    opacity = opacity ? opacity : 100;
                    var itemcolor = 'rgba(' + rgb.r + ',' + rgb.g + ',' + rgb.b + ',' + (opacity / 100) + ')';
                    this.selectedItem.css("background-color", itemcolor);
                } else {
                    this.selectedItem.css("backgroundColor", "transparent");
                }
            }
            return false;
        }
        this.setItemFontSize = function(name, value) {
            if (this.selectedItem != null) {
                $(this.selectedItem).data($.removeMinusSign(name), value);
                this.selectedItem.css(name, value + "px");
            }
        }
        this.setItemColor = function(value) {
            if (this.selectedItem != null) {
                $(this.selectedItem).data("color", value);
                if(value != "") {
                    this.selectedItem.css("color", "#" + value);
                } else {
                    this.selectedItem.css("color", "");
                }

            }
        }
        this.setItemBorderColor = function(name, value) {
            if (this.selectedItem != null) {
                $(this.selectedItem).data($.removeMinusSign(name), value);
                this.selectedItem.css("border-color", "#" + value);
            }
        }
        this.setItemCssPx = function(name, value) {
            if (this.selectedItem != null) {
                $(this.selectedItem).data($.removeMinusSign(name), value);
                this.selectedItem.css(name, value + "px");
            }
        }
        this.setItemCss = function(name, value) {
            if (this.selectedItem != null) {
                $(this.selectedItem).data($.removeMinusSign(name), value);
                this.selectedItem.css(name, value);
            }
        }
        this.setItemStyle = function(name, value) {
            if (this.selectedItem != null) {
                _tmpSelectedItem = this.selectedItem;
                $(_tmpSelectedItem).data(name, value);
                //var styleClasses = $('.mdt-style','#md-toolbar').find('option');
                var styleClasses = $.map($('.mdt-style option','#md-toolbar'), function(e) { return e.value; });
                $.each(styleClasses, function(i, v){
                    _tmpSelectedItem.removeClass(v);
                })
                _tmpSelectedItem.addClass(value);
            }
        }
        this.setItemOpacity = function(name, value) {
            if (this.selectedItem != null) {
                $(this.selectedItem).data(name, value);
                this.selectedItem.css(name, value/100);
            }
        }
        this.setItemTitle = function(value) {
            if (this.selectedItem != null) {
                $(this.selectedItem).data("title", value);
                if($(this.selectedItem).data("type") == "text")
                    $(this.selectedItem).find("div").html(value.replace(/\n/g, "<br />"));
                this.mdSliderTimeline.changeSelectedItemTitle();
            }
        }
        this.setImageData = function(imageid, name, thumbsrc) {
            if (this.selectedItem != null) {
                $(this.selectedItem).data("title", name);
                $(this.selectedItem).data("fileid", imageid);
                $(this.selectedItem).find("img").attr("src", thumbsrc).load(function() {
                    var newImg = new Image();
                    newImg.src = thumbsrc;
                    var width = newImg.width,
                        height = newImg.height,
                        panelWidth = self.activePanel.find(".md-objects").width(),
                        panelHeight = self.activePanel.find(".md-objects").height();
                    if(height > 0 && panelHeight > 0) {
                        if(width > panelWidth || height > panelHeight) {
                            if((width / height) > (panelWidth / panelHeight)) {
                                self.setItemSize(panelWidth, height * panelWidth / width);
                            } else {
                                self.setItemSize(width * panelHeight / height, panelHeight);
                            }
                        } else {
                            self.setItemSize(width, height);
                        }
                        self.mdSliderToolbar.changeSelectItem(self.selectedItem);
                    }
                });
                self.mdSliderTimeline.changeSelectedItemTitle();
            }
        }
        this.setItemFontWeight = function(value) {
            if (this.selectedItem != null) {
                $(this.selectedItem).data("fontweight", value);
                this.selectedItem.css("font-weight", parseInt(value));
                if(isNaN(value)) {
                    this.selectedItem.css("font-style", "italic");
                } else {
                    this.selectedItem.css("font-style", "normal");
                }
            }
        }
        this.setVideoData = function(videoid, name, thumbsrc) {
            if (this.selectedItem != null) {
                $(this.selectedItem).data("title", name);
                $(this.selectedItem).data("fileid", videoid);
                $(this.selectedItem).find("img").attr("src", thumbsrc).load(function() {
                    var newImg = new Image();
                    newImg.src = thumbsrc;
                    var width = newImg.width,
                        height = newImg.height,
                        panelWidth = self.activePanel.find(".md-objects").width(),
                        panelHeight = self.activePanel.find(".md-objects").height();
                    if(height > 0 && panelHeight > 0) {
                        if(width > panelWidth || height > panelHeight) {
                            if((width / height) > (panelWidth / panelHeight)) {
                                self.setItemSize(panelWidth, height * panelWidth / width);
                            } else {
                                self.setItemSize(width * panelHeight / height, panelHeight);
                            }
                        } else {
                            self.setItemSize(width, height);
                        }
                        self.mdSliderToolbar.changeSelectItem(self.selectedItem);
                    }
                });
                self.mdSliderTimeline.changeSelectedItemTitle();
            }
        }
        this.setItemLinkData = function(link) {
            if (this.selectedItem != null) {
                $(this.selectedItem).data("link", link);
            }
        }
        this.changeBorderPosition = function(borderposition) {
            if (this.selectedItem != null) {
                $(this.selectedItem).data("borderposition", borderposition);
                var borderstyle = $(this.selectedItem).data("borderstyle");
                self.changeBorder(borderposition, borderstyle);
            }
        }
        this.changeBorderStyle = function(borderstyle) {
            if (this.selectedItem != null) {
                $(this.selectedItem).data("borderstyle", borderstyle);
                var borderposition = $(this.selectedItem).data("borderposition");
                self.changeBorder(borderposition, borderstyle);
            }
        }
        this.changeBorder = function(borderposition, borderstyle) {
            if (this.selectedItem != null) {
                var borderStr = "";
                if(borderposition & 1) {
                    borderStr = borderstyle;
                } else {
                    borderStr = "none";
                }
                if(borderposition & 2) {
                    borderStr += " " + borderstyle;
                } else {
                    borderStr += " none";
                }
                if(borderposition & 4) {
                    borderStr += " " + borderstyle;
                } else {
                    borderStr += " none";
                }
                if(borderposition & 8) {
                    borderStr += " " + borderstyle;
                } else {
                    borderStr += " none";
                }
                $(this.selectedItem).css("border-style", borderStr);
            }
        }
        this.changeFontFamily = function(fontfamily) {
            if (this.selectedItem != null) {
                $(this.selectedItem).data("fontfamily", fontfamily);
                $(this.selectedItem).css("font-family", fontfamily);
            }
        }
        this.alignLeftSelectedBox = function() {
            var selectedItems = $(self.activePanel).find(".slider-item.ui-selected");
            if (selectedItems.size() > 1) {
                var minLeft = 10000;
                selectedItems.each(function () {
                    minLeft = ($(this).position().left < minLeft) ? $(this).position().left : minLeft;
                });
                selectedItems.each(function () {
                    self.setPositionBoxLeft(this, minLeft);
                });
            }
        }

        this.alignRightSelectedBox = function() {
            var selectedItems = $(self.activePanel).find(".slider-item.ui-selected");
            if (selectedItems.size() > 1) {
                var maxRight = 0;
                selectedItems.each(function() {
                    var thisRight = $(this).position().left + $(this).outerWidth();
                    maxRight = (thisRight > maxRight) ? thisRight : maxRight;
                });
                selectedItems.each(function() {
                    self.setPositionBoxLeft(this, maxRight - $(this).outerWidth());
                });

            }
        }

        this.alignCenterSelectedBox = function() {
            var selectedItems = $(self.activePanel).find(".slider-item.ui-selected");
            if (selectedItems.size() > 1) {
                var center = selectedItems.first().position().left + selectedItems.first().outerWidth() / 2;
                selectedItems.each(function() {
                    self.setPositionBoxLeft(this, center - $(this).outerWidth() / 2);
                });
            }
        }

        this.alignTopSelectedBox = function() {
            var selectedItems = $(self.activePanel).find(".slider-item.ui-selected");
            if (selectedItems.size() > 1) {
                var minTop = 10000;
                selectedItems.each(function() {
                    minTop = ($(this).position().top < minTop) ? $(this).position().top : minTop;
                });
                selectedItems.each(function() {
                    self.setPositionBoxTop(this, minTop);
                });
            }
        }

        this.alignBottomSelectedBox = function() {
            var selectedItems = $(self.activePanel).find(".slider-item.ui-selected");
            if (selectedItems.size() > 1) {
                var maxBottom = 0;
                selectedItems.each(function() {
                    thisBottom = $(this).position().top + $(this).outerHeight();
                    maxBottom = (thisBottom > maxBottom) ? thisBottom : maxBottom;
                });
                selectedItems.each(function() {
                    self.setPositionBoxTop(this, maxBottom - $(this).outerHeight());
                });

            }
        }

        this.alignMiddleSelectedBox = function() {
            var selectedItems = $(self.activePanel).find(".slider-item.ui-selected");
            if (selectedItems.size() > 1) {
                var center = selectedItems.first().position().top + selectedItems.first().outerHeight() / 2;
                selectedItems.each(function() {
                    self.setPositionBoxTop(this, center - $(this).outerHeight() / 2);
                });
            }
        }
        this.spaceVertical = function(spacei) {
            var selectedItems = $(self.activePanel).find(".slider-item.ui-selected");
            if (selectedItems.size() > 1) {
                spacei = parseInt(spacei);

                // sap xep thu tu top items
                var n = selectedItems.size();
                for (var i = 0; i < n - 1; i++) {
                    for (var j = i+1; j < n; j++) {
                        if ($(selectedItems[i]).position().top > $(selectedItems[j]).position().top) {
                            var swap = selectedItems[i];
                            selectedItems[i] = selectedItems[j];
                            selectedItems[j] = swap;
                        }
                    }
                }

                if (spacei > 0) {
                    for (var i = 1; i < n; i++) {
                        self.setPositionBoxTop($(selectedItems[i]), $(selectedItems[i-1]).position().top + $(selectedItems[i-1]).outerHeight() + spacei);
                    }
                } else if(n > 2) {
                    var sumHeight = 0;
                    for (var i = 0; i < n - 1; i++) {
                        sumHeight += $(selectedItems[i]).outerHeight();
                    }
                    spacei = ($(selectedItems[n-1]).position().top - $(selectedItems[0]).position().top - sumHeight) / (n - 1);
                    for (var i = 1; i < n - 1; i++) {
                        self.setPositionBoxTop($(selectedItems[i]), $(selectedItems[i-1]).position().top + $(selectedItems[i-1]).outerHeight() + spacei);
                    }
                }

            }
        }
        this.spaceHorizontal = function(spacei) {
            var selectedItems = $(self.activePanel).find(".slider-item.ui-selected");
            if (selectedItems.size() > 1) {
                spacei = parseInt(spacei);

                // sap xep thu tu left items
                var n = selectedItems.size();
                for (var i = 0; i < n - 1; i++) {
                    for (var j = i+1; j < n; j++) {
                        if ($(selectedItems[i]).position().left > $(selectedItems[j]).position().left) {
                            var swap = selectedItems[i];
                            selectedItems[i] = selectedItems[j];
                            selectedItems[j] = swap;
                        }
                    }
                }

                if (spacei > 0) {
                    for (var i = 1; i < n; i++) {
                        self.setPositionBoxLeft($(selectedItems[i]), $(selectedItems[i-1]).position().left + $(selectedItems[i-1]).outerWidth() + spacei);
                    }
                } else if(n > 2) {
                    var sumWidth = 0;
                    for (var i = 0; i < n - 1; i++) {
                        sumWidth += $(selectedItems[i]).outerWidth();
                    }
                    spacei = ($(selectedItems[n-1]).position().left - $(selectedItems[0]).position().left - sumWidth) / (n - 1);
                    for (var i = 1; i < n - 1; i++) {
                        self.setPositionBoxLeft($(selectedItems[i]), $(selectedItems[i-1]).position().left + $(selectedItems[i-1]).outerWidth() + spacei);
                    }
                }

            }
        }
        this.setPositionBoxLeft = function(el, left) {
            left = (left > 0) ? left : 0;
            var maxLeft = $(el).parent().width() - $(el).outerWidth(true);
            if(left > maxLeft)
                left = maxLeft;
            $(el).css("left", left + "px");
            $(el).data("left", left);
            return left;
        }
        this.setPositionBoxTop = function(el, top) {
            top = (top > 0) ? top : 0;
            var maxTop = $(el).parent().height() - $(el).outerHeight();
            if(top > maxTop)
                top = maxTop;
            $(el).css("top", top + "px");
            $(el).data("top", top);
            return top;
        }
        this.setBoxWidth = function(el, width) {
            if(width > 0) {
                var maxWidth = $(el).parent().width() - $(el).position().left;
                if(width > maxWidth)
                    width = maxWidth;
                $(el).width(width);
                $(el).data("width", width);
                return width;
            }
            return $(el).width();
        }
        this.setBoxHeight = function(el, height) {
            if(height > 0) {
                var maxHeight = $(el).parent().height() - $(el).position().top;
                if(height > maxHeight)
                    height = maxHeight;
                $(el).height(height);
                $(el).data("height", height);
                return height;
            }
            return $(el).height();
        }
        this.triggerChangeSettingItem = function() {
            self.mdSliderToolbar.changeToolbarValue();
        }
        this.changeSelectItem = function(item) {
            $(self.activePanel).find(".slider-item.ui-selected").removeClass("ui-selected");
            $(item).addClass("ui-selected");
            this.triggerChangeSelectItem();
        }
        this.getAllItemBox = function() {
            return $("div.slider-item", self.activePanel);
        }
        this.changeTimelineValue = function() {
            self.mdSliderToolbar.changeTimelineValue();
        }
        this.setTimelineWidth = function(timelinewidth) {
            if(self.activePanel) {
                $(self.activePanel).data("timelinewidth", timelinewidth);
            }
        }
        this.getTimelineWidth = function() {
            if(self.activePanel) {
                return $(self.activePanel).data("timelinewidth");
            }
            return null;
        }
        this.getSliderData = function() {
            var data = [];
            var ishide = false;
            $("#md-tabs .ui-tabs-nav a.tab-link").each(function() {
                var panel = $($(this).attr("href"));
                if(panel.size()) {
                    ishide = false;
                    if(panel.hasClass("ui-tabs-hide")) {
                        panel.removeClass("ui-tabs-hide");
                        ishide = true;
                    }

                    var itemsetting = $.stringToObject($("input.panelsettings", panel).val());
                    itemsetting.timelinewidth = panel.data("timelinewidth");
                    var boxitems = [];
                    $("div.slider-item", panel).each(function() {
                        boxitems.push($(this).getItemValues());
                    });
                    data.push({itemsetting: itemsetting, boxitems: boxitems});
                    if(ishide) {
                        panel.addClass("ui-tabs-hide");
                    }
                }
            });
            return data;
        }
        this.getSlideSettingValue = function() {
            var setting = {
                background_image: $("#slide-backgroundimage").val(),
                custom_thumbnail: $("#slide-thumbnail").val()
            };
            var transitions = [];
            $('#navbar-content-transitions input:checked').each(function() {
                transitions.push($(this).val());
            });
            setting.transitions = transitions;
            return setting;
        };
        this.setSlideSettingValue = function(setting) {
            if(typeof setting != 'object') {
                setting = {};
            }
            $.extend({
                background_image: "-1",
                custom_thumbnail: "-1",
                transitions: []
            }, setting);
            $("#slide-backgroundimage").val(setting.background_image);
            $("#slide-thumbnail").val(setting.custom_thumbnail);

            $('#navbar-content-transitions input').attr("checked", false);
            if(setting && setting.transitions) {
                $.each(setting.transitions, function(index, trant) {
                    $('#navbar-content-transitions input[value='+trant+']').attr("checked", true);
                });
            }
            $('#slide-thumbnail-preview').empty();
            if (setting && setting.custom_thumbnail != -1) {
                var slid = $('input[name=slider_id]').val();
                $('#slide-thumbnail-preview').append('<img width="100" height="100" alt="" >');
                $.post(Drupal.settings.basePath + '?q=admin/structure/md-slider/get-background-image', {fid: setting.custom_thumbnail, slider_id: slid}, function(response) {
                    $('#slide-thumbnail-preview img').attr('src', response);
                });
            }
            $('#slide-background-preview').empty();
            if (setting && setting.background_image != -1) {
                var slid = $('input[name=slider_id]').val();
                $('#slide-background-preview').append('<img width="100" height="100" alt="" >');
                $.post(Drupal.settings.basePath + '?q=admin/structure/md-slider/get-background-image', {fid: setting.background_image, slider_id: slid}, function(response) {
                    $('#slide-background-preview img').attr('src', response);
                });
            }
        };

    };
    window.MdSliderPanel = MdSliderPanel;

})(jQuery);