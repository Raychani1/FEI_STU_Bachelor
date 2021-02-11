document.getElementById("generate").onclick = function () {
    if (validateInput(document.getElementById("x")) && validateInput((document.getElementById("y")))) {
        document.getElementById("myModal").style.display = "block";
        tableCreate();
    } else {
        alert("Please enter a valid input");
    }
}

document.getElementById("close").onclick = function () {
    document.getElementById("modal_content_container").innerHTML = "";
    document.getElementById("myModal").style.display = "none";
}

function validateInput(number) {
    if (parseInt(number.value) < 1 || parseInt(number.value) > 9 || number.value === "") {
        document.getElementById(number.id).style.borderColor = "red";
        if (number.id === "x") {
            document.getElementById("x_error").style.display = "block";
        } else {
            document.getElementById("y_error").style.display = "block";
        }

        return false
    } else {
        document.getElementById(number.id).style.borderColor = "#fff";
        if (number.id === "x") {
            document.getElementById("x_error").style.display = "none";
        } else {
            document.getElementById("y_error").style.display = "none";
        }

        return true
    }
}

document.getElementById("x").addEventListener("blur", function () {
    validateInput(this);
})
document.getElementById("y").addEventListener("blur", function () {
    validateInput(this);
})

function tableCreate() {

    let myTableContainer = document.getElementById("modal_content_container");

    let table = document.createElement('TABLE');
    table.border = '1';

    let tableBody = document.createElement('tbody');

    table.appendChild(tableBody);
    table.style.width = '90%';
    table.style.height = "80px";
    table.style.margin = "2% 5%"
    table.style.color = "#fff";
    table.style.textAlign = "center";
    table.style.fontSize = "1.5rem";
    table.style.backgroundColor = "#571452";
    table.style.borderColor = "#fff"
    table.style.borderCollapse = "collapse";
    table.style.borderRadius = "10px";
    table.style.borderStyle = "hidden";

    let x = parseInt(document.getElementById("x").value);
    let y = parseInt(document.getElementById("y").value);
    for (let i = 0; i < y + 1; i++) {
        let table_row = document.createElement('tr');
        tableBody.appendChild(table_row);

        for (let j = 0; j < x + 1; j++) {
            let table_data = document.createElement('td');
            if (j === 0 && i === 0) {
                table_data.appendChild(document.createTextNode(""));
                table_row.appendChild(table_data);
            } else if (i === 0 && j !== 0) {
                table_data.appendChild(document.createTextNode("X = " + j));
                table_row.appendChild(table_data);
            } else if (j === 0 && i !== 0) {
                table_data.appendChild(document.createTextNode("Y = " + i));
                table_row.appendChild(table_data);
            } else {
                table_data.appendChild(document.createTextNode(j - i));
                table_row.appendChild(table_data);
            }
        }
    }
    myTableContainer.appendChild(table);
}
