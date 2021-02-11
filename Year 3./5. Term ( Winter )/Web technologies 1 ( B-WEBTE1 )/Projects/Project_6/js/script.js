let slider_value = 0;

// SOURCE for Slider : https://stackoverflow.com/questions/55338812/placing-text-inside-range-slider + Some Modification
let app = (() => {
    function updateSlider(element) {
        if (element) {
            let parent = element.parentElement,
                lastValue = parent.getAttribute('data-slider-value');

            if (lastValue === element.value) {
                return; // No value change, no need to update then
            }
            parent.setAttribute('data-slider-value', element.value);
            let $thumb = parent.querySelector('.range-slider__thumb'),
                $bar = parent.querySelector('.range-slider__bar'),
                pct = element.value * ((parent.clientHeight * 3.7 + $thumb.clientHeight) / $bar.clientWidth)-1;
            slider_value = element.value;
            document.querySelector('.input').value = slider_value;

            $thumb.style.left = `${pct}%`;
            $bar.style.height = `calc(${pct}% + ${$thumb.clientHeight / 2}px)`;
            $thumb.textContent = `${element.value}`;
        }
    }
    return {
        updateSlider: updateSlider };
})();

// SOURCE for Spinner ( Text Input For Numbers with Arrows ): https://codepen.io/riccardoerra/pen/yVMzwg + Some modification
let spinner = document.querySelector('.input');
let buttonUp = document.querySelector('.up');
let buttonDown = document.querySelector('.down');

function setting(value){
    spinner.value = value;
    slider_value = value;
    document.getElementById("slider").value = document.getElementById("value").value;
    let element = document.getElementById("slider");
    let parent = element.parentElement;
    let $thumb = parent.querySelector('.range-slider__thumb');
    let $bar = parent.querySelector('.range-slider__bar');
    let pct = element.value * ((parent.clientHeight * 3.7 + $thumb.clientHeight) / $bar.clientWidth)-1;
    $thumb.style.left = `${pct}%`;
    $thumb.textContent = `${element.value}`;
}

buttonUp.onclick = function() {
    let value = parseFloat(spinner.value);
    if(value<=9.5) {
        value = isNaN(value) ? 0 : value;
        value+=0.5;
    }
    setting(value);
};

buttonDown.onclick = function() {
    let value = parseFloat(spinner.value);
    if(value > 1) {
        value = isNaN(value) ? 0 : value;
        value-=0.5;
    }
    setting(value);
};

(function initAndSetupTheSliders() {
    const inputs = [].slice.call(document.querySelectorAll('.range-slider input'));
    inputs.forEach(input => input.setAttribute('value', '1'));
    inputs.forEach(input => app.updateSlider(input));
    // Cross-browser support where value changes instantly as you drag the handle, therefore two event types.
    inputs.forEach(input => input.addEventListener('input', element => app.updateSlider(input)));
    inputs.forEach(input => input.addEventListener('change', element => app.updateSlider(input)));
})();

document.getElementById("range_slider").style.display = "none";
document.getElementById("text_spinner").style.display = "none";

function validateNumberInput(element) {
    let numberInput = /[0-9]*/.test(element.value);
    if(!numberInput){
        return !(parseFloat(element.value) < 1 || parseFloat(element.value) > 10);
    }
    return false;
}

document.getElementById("value").addEventListener("blur", function () {
    let validInput = validateNumberInput(document.getElementById("value"));
    if(validInput) {
        document.getElementById("slider").value = document.getElementById("value").value;
        setting(document.getElementById("value").value);
    }
    else{
        document.getElementById("value").value = 1;
        document.getElementById("slider").value = 1;
        setting(1);
    }
})

function toggleInput(inputID){
    let element = document.getElementById(inputID);
    if(element.style.display === "none"){
        element.style.display = "block";
        setting(slider_value);
    } else {
        element.style.display = "none";
    }
}

/* Graph Base Setup */
let xArray = [];
let y1Array = [];
let y2Array = [];

let layout = {
    showlegend: false,
};

let config = {
    displaylogo: false,
    modeBarButtons: [["zoom2d", "zoomIn2d", "zoomOut2d", "pan2d", "autoScale2d"]]
}
let show = {
    visible: true
};

let hide = {
    visible: "legendonly"
};

let running = true;

/*Initial Values*/
document.getElementById("sine").checked = true;
document.getElementById("cosine").checked = true;

/* Show-Hide traces */
function showHide() {
    let sin = (document.getElementById("sine").checked);
    let cos = (document.getElementById("cosine").checked);
    let graph = document.getElementById('graph');
    if (running === true) {
        if (sin === true) {
            Plotly.restyle(graph, show, 0);
        } else {
            Plotly.restyle(graph, hide, 0);
        }
        if (cos === true) {
            Plotly.restyle(graph, show, 1);
        } else {
            Plotly.restyle(graph, hide, 1);
        }
    }
}

/* Plotting traces from SSE response*/
Plotly.plot('graph', [{
    y: [],
    name: 'sine',
    mode: 'lines'
}, {
    y: [],
    name: 'cosine',
    mode: 'lines'
}], layout, config);

source = new EventSource("http://vmzakova.fei.stuba.sk/sse/sse.php");

if ((typeof (EventSource) !== "undefined") && (running === true)) {
    source.onmessage = function (event) {
        let text = event.data;
        let sseValues = JSON.parse(text);
        sseValues.y1 = parseFloat(sseValues.y1) * slider_value;
        sseValues.y2 = parseFloat(sseValues.y2) * slider_value;

        xArray.push(sseValues.x);
        y1Array.push(sseValues.y1);
        y2Array.push(sseValues.y2);

        Plotly.extendTraces('graph', {
            y: [[sseValues.y1], [sseValues.y2]]
        }, [0, 1])
    }
} else {
    alert("Sorry, your browser does not support server-sent events...");
}