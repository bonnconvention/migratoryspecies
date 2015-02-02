(function($){
    $(document).ready(function(){

        // event handler for window resize
        $(window).resize(function(){
            updateUI();
        });
        updateUI();

        $('#top-link-block > a').on('click', function(e){
            e.preventDefault();
            $("body").animate({scrollTop:0},'slow');
        });

        if ( ($(window).height() + 100) < $(document).height() ) {
            $('#top-link-block').removeClass('hidden').affix({
                // how far to scroll down before link "slides" into view
                offset: {top:100}
            });
        }

    });

    // event handler for window resize
    function updateUI(){

        if($(window).width() <= 800){
            tabsToAccordions({active: false, collapsible: true, autoHeight: false});
        } else {
            accordionsToTabs();
        }

    }

    // changes tabs to accordions (jquery ui)
    function tabsToAccordions(options){
        if (typeof($.fn.tabs) != 'undefined' && typeof($.fn.accordion) != 'undefined') {
            $(".ui-tabs").each(function(){var e=$('<div class="ui-accordion">');var t=new Array;$(this).find(">ul>li").each(function(){t.push("<h3>"+$(this).html()+"</h3>")});var n=new Array;$(this).find(">div").each(function(){n.push("<div>"+$(this).html()+"</div>")});for(var r=0;r<t.length;r++){e.append(t[r]).append(n[r])}$(this).before(e);$(this).remove()});$(".ui-accordion").accordion(options)
        }
    }

    // changes accordions to tabs (jquery ui)
    function accordionsToTabs(){
        if (typeof($.fn.tabs) != 'undefined' && typeof($.fn.accordion) != 'undefined') {
            $(".ui-accordion").each(function(){var e=$('<div class="ui-tabs">');var t=0;var n=$("<ul>");$(this).find(">h3").each(function(){t++;n.append('<li><a href="#tabs-'+t+'">'+$(this).text()+"</a></li>")});var t=0;var r=$("");$(this).find(">div").each(function(){t++;r=r.add('<div id="tabs-'+t+'">'+$(this).html()+"</div>")});e.append(n).append(r);$(this).before(e);$(this).remove()});$(".ui-tabs").tabs()
        }
    }

})(jQuery);