jQuery(document.body).ready(function($) {
    //Custom select
    function init_custom_select(selectParent) {
        var $this = selectParent, selectOptions = selectParent.children('option').length;
        $this.wrap('<div class="ct-select"></div>');
        $this.after('<div class="ct-custom-select"></div>');
    
        var $customSelect = $this.next('div.ct-custom-select');
        $customSelect.text($this.children('option:checked').text());

        var $optionlist = $('<ul />', {
            'class': 'ct-select-options'
        }).insertAfter($customSelect);

        $optionlist.hide();
        for (var i = 0; i < selectOptions; i++) {
            $('<li />', {
                text: $this.children('option').eq(i).text(),
                rel: $this.children('option').eq(i).val()
            }).appendTo($optionlist);
        }
    
        var $optionlistItems = $optionlist.children('li');
    
        $customSelect.click(function(e) {
            e.stopPropagation();
            $('div.ct-custom-select.active').not(this).each(function(){
                $(this).removeClass('active').next('ul.ct-select-options').hide();
            });
            $(this).toggleClass('active').next('ul.ct-select-options').slideToggle();
        });
    
        $optionlistItems.click(function(e) {
            e.stopPropagation();
            $customSelect.text($(this).text()).removeClass('active');
            $this.val($(this).attr('rel'));
            $this.trigger('change');
            $optionlist.hide();
        });
    
        $(document).click(function() {
            $customSelect.removeClass('active');
            $optionlist.hide();
        });
    }

    $('.ct-form-theme select').each(function(){
        init_custom_select($(this));
        console.log('até aqui')
    });
});