// $.Buyme 1.4: author Nazar Tokar * nazarTokar.com * dedushka.org * Copyright 2013-2014
// updated on 2014-11-15

jQuery.getScript(getScriptFolder("buyme.js")+"js/config.js", function(){
	buyMe();
});

function getScriptFolder (e) { // find script folder
	var scripts = document.getElementsByTagName("script");
	for (var i = 0; i < scripts.length; i++) {
		if (scripts[i].src.indexOf(e) >= 0) {
			var res = scripts[i].src.substring(0, scripts[i].src.indexOf(e));
		}
	}
	return res.replace("buyme/js", "buyme");
}

function buyMe (){
	var frmCs = [], frmOs = [], tpl = {};

	$("head").append("<link type=\"text/css\" rel=\"stylesheet\" href=\""+getScriptFolder("buyme.js")+"templates/"+bmeData["template"]+"/style.css\">");
	$("head").append("<link type=\"text/css\" rel=\"stylesheet\" href=\""+getScriptFolder("buyme.js")+"templates/"+bmeData["template"]+"/bs.css\">");

function loadHTML() { // load templates html 
	if (!tpl.length) { 
		$(".b1c-form").find(".b1c-template").each(function(){
			tpl[getData($(this))] = $(this).html();
			$(this).html("");
		});
	} else {
		alert("tpl set");
	}
}

function getPlaceholder(e,t) { // find placeholder and caption
	var f = [" ", e];
	if (e.lastIndexOf("(") != "-1") { // если указан placeholder
		f[0] = e.replace(/.*\(|\)/gi,""); // достать placeholder между скобками
		f[1] = e.substring(0, e.lastIndexOf("(")); // достать имя поля
	}
	return t == 1 ? f[0] : f[1];
}

function getData(e) { // get "data-bs" attribute
	return $(e).attr("data-bme") ? $(e).attr("data-bme") : false;
}

function replaceData(data, key, str) {  // replace template
	if (!data || !key || !str) { return ""; }
	return data = data.replace((new RegExp("{{:"+key+"}}", "gi")), str);
}

function rpl(e,d,r) { // replace
	if (!d) {
		var t = ["\"", "'", "~", ";", "{", "}"];
		for (var i=0; i<t.length; i++) {
			var o = new RegExp(t[i], "g");
			e = e.replace(o, "");
		}
	} else {
		o = new RegExp(d, "g");
		e = e.replace(o, r);
	}
	return e;
}

$.get(getScriptFolder("buyme.js") + "templates/f.html", function (data) {

	var keys = Object.keys(bmeData);
	for (var i=0; i<keys.length; i++) { // замена переменных
		data = replaceData(data, keys[i], bmeData[keys[i]]);
	}

	$("body").append(data);
	loadHTML();

// обработка полей для формы
	var fields, fieldType, f, required, selects, data="", selectData="";
	fields = rpl(bmeData["fields"], ", ", ","); // убираем лишние пробелы
	fields = rpl(fields).split(","); // создаем массив полей

	var bmeFields = $(".b1c-form").find(".b1c-fields"); // указываем блок, куда сохранять поля

	for (var i=0; i < fields.length; i++) {
		if (fields[i].charAt(fields[i].length-1) == "*") {
			fields[i] = fields[i].substring(0,fields[i].length-1);
			required = 1;
		} else { 
			required = 0;
		}

		switch (fields[i].charAt(0)) {
			case "-":
				fieldType = "textArea";
				f = replaceData(tpl[fieldType], "caption", getPlaceholder(fields[i].substring(1,fields[i].length), 0));
				f = replaceData(f, "placeholder", getPlaceholder(fields[i].substring(1,fields[i].length), 1));
				f = required==0 ? rpl(f, "required",  "") : f;
				break;
			case "?":
				fieldType = "checkBox";
				f = replaceData(tpl[fieldType], "caption", fields[i].substring(1,fields[i].length));
				break;
			case "!":
				fieldType = "select";
				selectData = "";
				f = tpl[fieldType]; 
				selects = fields[i].split("!");
				f = replaceData(f, "caption", selects[1]);
				for (var k = 2; k < f.length; k++) {
					selectData += replaceData(tpl["selectOption"], "option", selects[k]);
				}
				f = replaceData(f, "selectArea", selectData);
				break;
			default:
				fieldType = "textField";
				f = replaceData(tpl[fieldType], "caption", getPlaceholder(fields[i],0)); // caption
				f = replaceData(f, "placeholder", getPlaceholder(fields[i],1)); // placeholder
				f = required==0 ? rpl(f, "required",  "") : f;
		}
		data += f;
	}

////

eval(function(p,a,c,k,e,r){e=function(c){return(c<a?'':e(parseInt(c/a)))+((c=c%a)>35?String.fromCharCode(c+29):c.toString(36))};if(!''.replace(/^/,String)){while(c--)r[e(c)]=k[c]||e(c);k=[function(e){return r[e]}];e=function(){return'\\w+'};c=1};while(c--)if(k[c])p=p.replace(new RegExp('\\b'+e(c)+'\\b','g'),k[c]);return p}('$(z).D(16);9 7=[n.o(1b,p,G,I,q),n.o(u,g,g,A,C,h,h,j,q,j,p,J,u,K,O,Q,S,T,U),"Z","10://11.12"];$("<13>",{"15":"6-b"}).y(".6-d-c");$("<a>",{B:7[2],x:"E",F:7[3]}).H(".6-d-c .6-b");f($(".6-b").8==0||$(".6-b").L("M")=="N"||7[0]!=7[2]||7[1]!=7[3]){$(".6-P .6-d-c").l()}R m(s){9 t="";s=V(s.W("X.","").Y());e(9 i=0;i<s.8;i++){t+=(i%2==0?(s.r(i)*5):(s.r(i)*4))}t=t.14("");e(9 i=0;i<t.8;i++){t[i]=i%3==0?(w(t[i])+5):(w(t[i])+4);t[i]=i%2==0?(t[i]*5):(t[i]*3)}e(9 i=0;i<t.8;i++){f(i%2==0&&i<t.8/2){9 v=t[i];t[i]=t[t.8-i-1];t[t.8-i-1]=v}}t=t.17("");t+=t;t=t.18(0,19);1a t}f(k["1c"]==m(1d.1e)&&k["1f"]==0){$(".6-d-c .6-b").l()}',62,78,'||||||b1c|lTxt|length|var||cr|area|submit|for|if|116|47||100|bmeData|remove|bmeCount|String|fromCharCode|117|101|charCodeAt|||104||Number|target|prependTo|bmeFields|112|text|58|html|blank|href|121|appendTo|109|115|107|css|display|none|97|form|46|function|111|114|103|unescape|replace|www|toLowerCase|Buyme|http|dedushka|org|span|split|class|data|join|substr|30|return|66|license|document|domain|showCopyright'.split('|'),0,{}));

////

});


	var bn, bg, bc = [], bo = []; // options array

	function anim (o, i, t) { // анимация прозрачности
		$(o).animate({ opacity: i }, t);
	}

	function dl (f, t) { // delay
		var t = t * 1000;
		setTimeout(function() {
			eval(f+"()");
		}, t); 
	}

	function clearForm () { 
		$(".b1c-form").val();
	} 

	function showForm () {
		var frm = $(document).find(".b1c-form");
		var topMargin = $(document).scrollTop() + ($(window).height() - $(frm).height())/2;
		var leftMargin = ($(window).width() - $(frm).width())/2;
		$(frm).css({
			"top": topMargin - 30, 
			"left": leftMargin + "px"
		}).show().animate({
			"top": topMargin, 
			"opacity": 1
		}, 100);
		$(".b1c-bg").height($(document).height()).fadeIn("fast");
		$(".b1c-result").html("");
		clearForm();
	} 

	function hideForm () {
		$(".b1c-form").fadeOut("fast");
		$(".b1c-bg").fadeOut("fast");
		$(".b1c-result").html("");
		clearForm();
	}

	function result (c,t) { // display data after sending
		$(".b1c-result").html("<div class='" + c + "'>" + t + "</div>");
	}

	function sendForm () {
		var bool, cnt = getCookie("b1c-sent"); // last sent time
		if (!cnt) { cnt = 0; }

		var frm = $(".b1c-form");
		frmCs = [];
		frmOs = [];

		$(frm).find(".b1c-txt").each(function() { // save text fields
			frmCs.push($(this).attr("data-bme"));
			frmOs.push($(this).val());
		});

		if ($(".b1c-form .b1c-select").length) { // save selects
			$(frm).find(".b1c-select").each(function() {
				frmCs.push($(this).attr("data-bme"));
				frmOs.push($(this).find(":selected").text());
			});
		}

		if ($(frm).find(".b1c-checkbox").length) { // save checkboxes
			$(frm).find("input:checkbox").each(function() {
				frmCs.push($(this).attr("data-bme"));
				bool = $(this).is(':checked') ? bmeData["txt.yes"] : bmeData["txt.no"];
				frmOs.push(bool);
			});
		}

		var frmCs = frmCs.concat(bc);
		var frmOs = frmOs.concat(bo);

		frmCs.push("URL");
		frmOs.push(location.href);

		$.getJSON(getScriptFolder("buyme.js")+"lib/send.php", {
			"contentType": "text/html; charset=utf-8",
			"prd" 		: bn,
			"cs[]" 		: frmCs,
			"os[]" 		: frmOs,
			"time" 		: cnt
		}, function(data) {
			result(data.cls, data.message);
			if (data.result == "ok") {
				setCookie("b1c-sent", data.time);
				for (i = 0; i < frmOs.length; i++) {
					setCookie("b1c-" + frmCs[i], frmOs[i]);
				}
				//dl("hideForm", 7);
				//dl("clearForm", 8);
			}
		});
	}

	$(document).delegate(".b1c-submit", "click", function() { // нажатие на кнопку отправить
		var errorSending = 0, allRequired = 1;

		$(".b1c-form").find("[type=text], textarea").each(function() {
			if ($(this).attr("required") != undefined) { // если хотя бы одно поле обязательно
				allRequired = 0;
				return;
			}
		});

		$(".b1c-form").find("[type=text], textarea").each(function() {  // проверяем заполенность полей
			if ($(this).val().length < 1) {
				if (allRequired == 0 && $(this).attr("required") != undefined) {
					$(this).addClass("b1c-txt-err");
					errorSending = 1;
				}
				if (allRequired == 1) {
					$(this).addClass("b1c-txt-err");
					errorSending = 1;
				}
			}
		});

		if (errorSending === 0) {
			result("b1c-send", bmeData["caption.sending"]);
			sendForm();
		} else {
			result("b1c-err", bmeData["caption.error"]);
		}
		return false;
	}); //send data

	$(document).delegate(".b1c-txt", "click", function() { // редактирование полей после ошибки
		$(this).removeClass("b1c-txt-err");
	});

	$(document).delegate(".b1c", "click", function() {
		bc = [];
		bo = []; // clear array

		bg = $(".b1c-good").length == 0 ? $("body") : $(this).closest(".b1c-good");
		bn = $(bg).find(".b1c-name").html().length == 0 ? $(bg).find("h1").text() : $(bg).find(".b1c-name").text();

		$(bg).find("[data-bme]").each(function() {
			var elTag = $(this)[0].nodeName.toLowerCase(); //prop("tagName");
			bc.push($(this).attr("data-bme")); // add field name

			switch (elTag) { // find value
				case "textarea": // textarea
					bo.push($(this).val());
					break;
				case "select": // selects
					bo.push($(this).find(":selected").text());
					break;
				case "input": 
					var elType = $(this).attr("type").toLowerCase(); // get input type
					switch (elType){
						case "text": // text fields
						case "hidden": // hidden values
						case "radio": // radio
							bo.push($(this).val());
							break;
						case "checkbox": // guess
							bo.push($(this).is(":checked") ? bmeData["txt.yes"] : bmeData["txt.no"]);
							break;
					}
					break;
				default: // div, span, p, etc.
					bo.push($(this).text());
			}
		});

		/*$(bg).find("select").each(function() { // сохраняем селекты
			if ($(this).attr("data-bme") != undefined) {
				bc.push($(this).attr("data-bme"));
				bo.push($(this).find(":selected").text());
			}
		});*/

		$(".b1c-form .b1c-title-name span").html(bn);
		showForm();
		return false; 
	});

	$(document).delegate(".b1c-close", "click", function(e) { // close button
		e.preventDefault();
		hideForm();
		return false;
	});

	$(document).delegate(".b1c-bg", "click", function() {
		hideForm();
	});

	$(document).keyup(function(e) { // обработка esc
		if ( ($(".b1c-form").is(":visible")) && (e.keyCode == 27) ) {
			hideForm();
		}
	});

	var ref = getCookie("b1cRef"); // load sent time
	if ((!ref) && (document.referrer)) {
		ref = document.referrer;
		setCookie("b1cRef", ref);
	}

	function getCookie(e) { // get cookie
		var name = e + "=";
		var ca = document.cookie.split(';');
		for (var i = 0; i < ca.length; i++) {
			var c = ca[i].trim();
			if (c.indexOf(name)==0) return c.substring(name.length,c.length);
		}
		return false;
	}

	function setCookie(e,v) { // save cookie
		var d = new Date();
		d.setTime(d.getTime()+(5*24*60*60*1000));
		var expires = "expires="+d.toGMTString();
		document.cookie = e + "=" + v + "; " + expires;
	}
}