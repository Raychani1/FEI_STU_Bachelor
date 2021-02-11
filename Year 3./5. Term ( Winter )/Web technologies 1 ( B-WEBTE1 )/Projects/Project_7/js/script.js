let cboxOptions = {
    width: '95%',
    height: '95%',
    maxWidth: '960px',
    maxHeight: '960px',
}

$('.cbox-link').colorbox(cboxOptions);

$(window).resize(function () {
    $.colorbox.resize({
        width: window.innerWidth > parseInt(cboxOptions.maxWidth) ? cboxOptions.maxWidth : cboxOptions.width,
        height: window.innerHeight > parseInt(cboxOptions.maxHeight) ? cboxOptions.maxHeight : cboxOptions.height
    });
});

$(document).ready(function () {
    display();
});

function setCookie(cname, cvalue, exdays) {
    let date = new Date();
    date.setTime(date.getTime() + (exdays * 24 * 60 * 60 * 1000));
    let expires = "expires=" + date.toGMTString();
    document.cookie = cname + "=" + cvalue + ";" + expires + ";path=/";
}

function getCookie(cname) {
    let name = cname + "=";
    let decodedCookie = decodeURIComponent(document.cookie);
    let ca = decodedCookie.split(';');
    for (let i = 0; i < ca.length; i++) {
        let c = ca[i];
        while (c.charAt(0) === ' ') {
            c = c.substring(1);
        }
        if (c.indexOf(name) === 0) {
            return c.substring(name.length, c.length);
        }
    }
    return "";
}

function checkCookie() {
    let user_cookie = getCookie("order");
    if (user_cookie === "") {
        alert("This site use cookie(s), press OK to continue!");
        user_cookie = ["0", "1", "2", "3", "4", "5"];
        setCookie("order", user_cookie, 30);
        display();
    }
}

function display() {
    let order = getCookie("order");
    if (order !== "") {
        $.getJSON("photos.json", function (myObj) {
            for (let i = 0; i < 11; i = i + 2) {
                // + myObj.photos[order[i]].title +
                $("#pictures").append("<a class='dog_pictures' id=" + myObj.photos[order[i]].id + "  href=" + myObj.photos[order[i]].src + " title='<h4>" + myObj.photos[order[i]].title + "</h4> " + myObj.photos[order[i]].description + "'   > <img class='dogs' alt='picture_of_a_dog' src=" + myObj.photos[order[i]].src + '  ></a>');
            }
            lightbox();
        });

    }
}

function lightbox() {
    //Examples of how to assign the Colorbox event to elements
    $(".dog_pictures").colorbox({
        rel: 'dog_pictures',
        slideshow: true,
        slideshowAuto: false,
        width: "75%",
        height: "75%"
    });
    $(".ajax").colorbox();
    $(".youtube").colorbox({iframe: true, innerWidth: 640, innerHeight: 390});
    $(".vimeo").colorbox({iframe: true, innerWidth: 500, innerHeight: 409});
    $(".iframe").colorbox({iframe: true, width: "80%", height: "80%"});
    $(".inline").colorbox({inline: true, width: "50%"});
    $(".callbacks").colorbox({
        onOpen: function () {
            alert('onOpen: colorbox is about to open');
        },
        onLoad: function () {
            alert('onLoad: colorbox has started to load the targeted content');
        },
        onComplete: function () {
            alert('onComplete: colorbox has displayed the loaded content');
        },
        onCleanup: function () {
            alert('onCleanup: colorbox has begun the close process');
        },
        onClosed: function () {
            alert('onClosed: colorbox has completely closed');
        }
    });

    $('.non-retina').colorbox({rel: 'group5', transition: 'none'})
    $('.retina').colorbox({rel: 'group5', transition: 'none', retinaImage: true, retinaUrl: true});

    //Example of preserving a JavaScript event for inline calls.
    $("#click").click(function () {
        $('#click').css({
            "background-color": "#f00",
            "color": "#fff",
            "cursor": "inherit"
        }).text("Open this window again and this message will still be here.");
        return false;
    });
}

(function ($) {
    $(document).ready(function () {
        $("#search_bar").keyup(function () {
            // Retrieve the input field text and reset the count to zero
            escape = function (text) {
                return text.replace(/[-[\]{}()*+?.,\\^$|#\s]/g, "\\$&");
            };

            let filter = escape($(this).val());

            $('#pictures a').remove();

            if (filter === '') {
                display();
            } else {
                console.log("filter : ", filter);
                $.getJSON('photos.json', function (data) {
                    $.each(data.photos, function (i, f) {
                        if (f.title.includes(filter) || f.description.includes(filter)) {
                            $("#pictures").append("<a class='dog_pictures' id=" + f.id + "  href=" + f.src + "  title=" + f.title + "   > <img class='dogs' alt='picture_of_a_dog' src=" + f.src + '  ></a>');
                        }
                    });
                    lightbox();
                });
            }
        });
    })
})(jQuery)

dragula([document.querySelector('#pictures')]).on("dragend", function () {
    let order = getCookie("order");
    let original_order = [];

    for (let i = 0; i < 11; i = i + 2) {
        original_order.push(order[i])
    }

    let new_order = []; // reset elems
    $('.dog_pictures').each(function (i, obj) {
        new_order.push(obj.id);
    });
    let final_order = [];
    if (new_order.length !== 6) {
        let new_order_offset = 0;
        for (let i = 0; i < original_order.length; i++) {
            if (new_order.includes(original_order[i])) {
                final_order.push(new_order[new_order_offset]);
                new_order_offset++;
            } else {
                final_order.push(original_order[i]);
            }
        }
    } else {
        final_order = new_order;
    }
    setCookie("order", final_order, 30);
});