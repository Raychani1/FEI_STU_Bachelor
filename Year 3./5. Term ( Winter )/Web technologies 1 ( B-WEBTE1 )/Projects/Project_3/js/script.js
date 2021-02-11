(function (){
    let hidden = document.getElementsByClassName("hidden");
    for (let i = 0; i < hidden.length; i++) {
        hidden[i].style.display = "none";
    }
}());

(function (){
    let changing2 = document.getElementsByClassName("changing2");
    for (let i = 0; i < changing2.length; i++) {
        changing2[i].style.display = "none";
        changing2[i].disabled = true;
    }
}());
document.getElementById("emaial_error_message").style.display = "none";
document.getElementById("first_name_error_message").style.display = "none";
document.getElementById("last_name_error_message").style.display = "none";
document.getElementById("date_error_message_1").style.display = "none";
document.getElementById("date_error_message_2").style.display = "none";
document.getElementById("age_error_message").style.display = "none";

document.getElementById("warranty").style.display = "none";
document.getElementById("no-warranty").style.display = "none";

document.getElementById("type").disabled = true;
document.getElementById("manufacturer").disabled = true;
document.getElementById("model").disabled = true;

// document.getElementById("other_type").disabled = true;
// document.getElementById("other_type").style.display = "none";
// document.getElementById("other_manufacturer").disabled = true;
// document.getElementById("other_manufacturer").style.display = "none";
// document.getElementById("other_model").disabled = true;
// document.getElementById("other_model").style.display = "none";

document.getElementById("problem").disabled = true;

function nameValidator(name){
    // let nameElement = document.getElementById(name.id)
    let validName = /[a-zA-ZöÖüÜóÓőŐúÚéÉáÁűŰľĽšŠčČťŤžŽýÝíÍäňŇô]+$/.test(name.value);
    if(validName){
        name.style.color= "#495057";
        if(name.id === "first_name"){
            document.getElementById("first_name_error_message").style.display = "none";
        } else {
            document.getElementById("last_name_error_message").style.display = "none";
        }
        return true;
    } else {
        name.style.color= "red";
        if(name.id === "first_name"){
            document.getElementById("first_name_error_message").style.display = "block";
        } else {
            document.getElementById("last_name_error_message").style.display = "block";
        }
        return false;
    }
}

function emailValidator(){
    let validEmail = /^[\w.-]{3,}@([\w-]+\.)+[a-zA-Z]{2,4}$/.test(document.getElementById("email").value);

    if(validEmail){
        document.getElementById("email").style.color= "#495057";
        document.getElementById("emaial_error_message").style.display = "none";
        return true;
            } else {
        document.getElementById("email").style.color= "red";
        document.getElementById("emaial_error_message").style.display = "block";
        return false;
    }

}

function calculateAge(today, birthdate){
    let birthYear = parseInt(birthdate.getFullYear().toString());
    let birthMonth = parseInt((birthdate.getMonth()+1).toString());
    let birthDay = parseInt(birthdate.getDate().toString());

    let todayYear = parseInt(today.getFullYear().toString());
    let todayMonth = parseInt((today.getMonth()+1).toString())
    let todayDay = parseInt(today.getDate().toString())

    if(((todayYear >= birthYear) && (todayMonth <= birthMonth) && (todayDay >= birthDay))||((todayYear >= birthYear) && (todayMonth >= birthMonth))){
        return (todayYear-birthYear);
    } else if (((todayYear >= birthYear) && (todayMonth <= birthMonth))|| ((todayYear >= birthYear) && (todayMonth === birthMonth) && (todayDay < birthDay))){
        return(todayYear-birthYear-1);
    }
}

function ageValidator(){
    let age = parseInt(document.getElementById("age").value);
    let date = document.getElementById("birthdate");

    let birthdate = new Date(document.getElementById("birthdate").value);
    let today = new Date();

    if(birthdate > today){
        date.style.color = "red";
        date.className = date.className + " error";
        document.getElementById("date_error_message_1").style.display = "block";
    }
    else{
        date.style.color = "#495057";
        date.className = date.className.replace(" error", "");
        document.getElementById("date_error_message_1").style.display = "none";

       if(calculateAge(today,birthdate) !== age){
           date.style.color = "red";
           date.className = date.className + " error";
           document.getElementById("date_error_message_2").style.display = "block";
           document.getElementById("age").style.color = "red";
           document.getElementById("age_error_message").style.display = "block";
           return false;
       }
       else {
           date.style.color = "#495057";
           date.className = date.className.replace(" error", "");
           document.getElementById("date_error_message_2").style.display = "none";
           document.getElementById("age").style.color = "#495057";
           document.getElementById("age_error_message").style.display = "none";
           return true;
       }

    }
    // return (calculateAge(today,birthdate) === age);
}

//
// MULTISELECT
let Select_List_Data = {

    'manufacturer': {
        notebook: {
            text: ['MSI', 'ASUS', 'HP'],
            value: ['msi', 'asus', 'hp']
        },
        smartphone: {
            text: ['Apple', 'Samsung', 'Xiaomi'],
            value: ['apple', 'samsung', 'xiaomi']
        },
        tablet: {
            text: ['Apple', 'Samsung', 'Lenovo'],
            value: ['apple2', 'samsung2', 'lenovo']
        }
    },

    'model': {
        msi: {
            text: ['Prestige 14', 'GE75 Raider', 'Bravo 17'],
            value: ['prestige_14', 'ge75_raider', 'bravo_17']
        },
        asus: {
            text: ['VivoBook 15', 'ZenBook 15', 'ROG Strix G17'],
            value: ['vivobook_15', 'zenbook_15', 'rog_strix_g17']
        },
        hp: {
            text: ['Pavilon x360', '470 G7', 'ProBook 450 G7'],
            value: ['pavilon_x360', '470_g7', 'probook_450_g7']
        },
        apple: {
            text: ['iPhone SE', 'iPhone 11', 'iPhone 12'],
            value: ['iphone_se', 'iphone_11', 'iphone_12']
        },
        samsung: {
            text: ['Galaxy A71', 'Galaxy Note 20', 'Galaxy A51'],
            value: ['galaxy_a71', 'galaxy_note_20', 'galaxy_a51']
        },
        xiaomi: {
            text: ['Redmi Note 9 Pro', 'Poco F2 Pro', 'Redmi 9A'],
            value: ['redmi_note_9_pro', 'poco_f2_pro', 'redmi_9a']
        },
        apple2: {
            text: ['iPad Pro', 'iPad Mini', 'iPad Air'],
            value: ['ipad_pro', 'ipad_mini', 'ipad_air']
        },
        samsung2: {
            text: ['Galaxy Tab A 10.1', 'Galaxy Tab S6', 'Galaxy Tab S6 Lite'],
            value: ['galaxy_tab_a_10_1', 'galaxy_tab_s6', 'galaxy_tab_s6_lite']
        },
        lenovo: {
            text: ['TAB M10', 'TAB M8', 'Yoga Smart Tab 3'],
            value: ['tab_m10', 'tab_m8', 'yoga_smart_tab_3']
        }
    }
};

function removeAllOptions(sel) {
    let len, par;

    len = sel.options.length;
    for (let i=len; i; i--) {
        par = sel.options[i-1].parentNode;
        par.removeChild( sel.options[i-1] );
    }
}

function appendDataToSelect(sel, obj) {
    let f = document.createDocumentFragment();
    let labels = [], group, opts;

    function addOptions(obj) {
        let f = document.createDocumentFragment();
        let o;

        for (let i=0, len=obj.text.length; i<len; i++) {
            o = document.createElement('option');
            o.appendChild( document.createTextNode( obj.text[i] ) );

            if ( obj.value ) {
                o.value = obj.value[i];
            }

            f.appendChild(o);
        }
        return f;
    }

    if ( obj.text ) {
        opts = addOptions(obj);
        f.appendChild(opts);
    } else {
        for ( let prop in obj ) {
            if ( obj.hasOwnProperty(prop) ) {
                labels.push(prop);
            }
        }

        for (let i=0, len=labels.length; i<len; i++) {
            group = document.createElement('optgroup');
            group.label = labels[i];
            f.appendChild(group);
            opts = addOptions(obj[ labels[i] ] );
            group.appendChild(opts);
        }
    }
    sel.appendChild(f);
}

(function() {
    let form = document.forms['contactForm'];

    let sel = form.elements['type'];
    sel.selectedIndex = 0;

    let relName = 'manufacturer';
    let rel = form.elements[ relName ];

    let data = Select_List_Data[ relName ][ sel.value ];

    appendDataToSelect(rel, data);

    sel = form.elements['manufacturer'];
    sel.selectedIndex = 0;

    relName = 'model';

    rel = form.elements[ relName ];

    data = Select_List_Data[ relName ][ sel.value ];

    appendDataToSelect(rel, data);
}());

function showAdditionalForm(id1,id2){
    let selects = document.getElementById(id1);
    let selects2 = document.getElementById(id2);
    let displaySetting = selects.style.display;

    if (displaySetting === 'none') {
        selects.style.display = 'block';
        selects.disabled = false;
    }
    selects2.style.display = 'none';
    selects.style.display = 'block';

    if(id1==="warranty" && id2 === "no-warranty"){
        document.getElementById("type").disabled = false;
        document.getElementById("manufacturer").disabled = false;
        document.getElementById("model").disabled = false;
        document.getElementById("problem").disabled = true;
    } else {
        document.getElementById("problem").disabled = false;
        document.getElementById("type").disabled = true;
        document.getElementById("manufacturer").disabled = true;
        document.getElementById("model").disabled = true;
    }
}

function changeValues(elements){
    if((elements[0].disabled === true)
        && (elements[1].disabled === true)
        && (elements[2].disabled === true)){
        for(let i=0;i<elements.length;++i){
            elements[i].disabled = false;
        }
    } else {
        for(let i=0;i<elements.length;++i){
            elements[i].disabled  = true;
        }
    }
    return elements;
}

function showOtherOptions(){
    let selects = document.getElementsByClassName("changing");
    // selects = changeValues(selects);

    let other_selects = document.getElementsByClassName("changing2");
    // other_selects = changeValues(other_selects);

    let displaySetting = other_selects[0].style.display;

    if (displaySetting === 'none') {
        selects = changeValues(selects);
        other_selects = changeValues(other_selects);
        for(let i=0;i<other_selects.length;++i){
            other_selects[i].style.display = "block";
        }
        for(let i=0;i<other_selects.length;++i){

            selects[i].style.display = "none";
        }
    } else {
        selects = changeValues(selects);
        other_selects = changeValues(other_selects);
        for(let i=0;i<other_selects.length;++i){
            other_selects[i].style.display = "none";
        }
        for(let i=0;i<other_selects.length;++i){

            selects[i].style.display = "block";
        }
    }
}


document.getElementById("first_name").addEventListener("blur", function () {
    nameValidator(this);
})
document.getElementById("last_name").addEventListener("blur", function () {
    nameValidator(this);
})
document.getElementById("email").addEventListener("blur", function () {
    emailValidator();
})
document.getElementById("age").addEventListener("blur", function () {
    ageValidator();
})
document.getElementById("birthdate").addEventListener("blur", function (){
    ageValidator();
})

document.getElementById("send").addEventListener("click",function (event){
    if( nameValidator(document.getElementById("first_name")) && nameValidator(document.getElementById("last_name")) && emailValidator() && ageValidator()) {
        return true;
    } else {
        event.preventDefault();
        return false;
    }
})

document.forms['contactForm'].elements['type'].onchange = function() {
    let relName = 'manufacturer';
    let relList = this.form.elements[ relName ];
    let obj = Select_List_Data[ relName ][ this.value ];
    removeAllOptions(relList);
    appendDataToSelect(relList, obj);

    relName = 'model';
    let rel = document.forms['contactForm'].elements[relName];
    let data = Select_List_Data[relName][document.forms['contactForm'].elements['manufacturer'].value];
    removeAllOptions(rel);
    appendDataToSelect(rel, data);
};

document.forms['contactForm'].elements['manufacturer'].onchange = function() {
    let relName = 'model';
    let relList = this.form.elements[ relName ];
    let obj = Select_List_Data[ relName ][ this.value ];
    removeAllOptions(relList);
    appendDataToSelect(relList, obj);
};




