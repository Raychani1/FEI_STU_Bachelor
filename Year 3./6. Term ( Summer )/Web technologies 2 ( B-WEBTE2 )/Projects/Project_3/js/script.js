function checkForm() {
    let login = $("#login").val();
    let email = $("#email").val();
    let pass = $("#password").val();
    let result;
    if (login !== "" && email !== "") {
        $.ajax({
            url: "checkForm.php",
            type: "POST",
            async: false,
            cache: false,
            data: {login: login, email: email, pass: pass},
            success: function (data) {
                if (!JSON.parse(data).login) {
                    $("#login_error").text('Login already exists');
                } else {
                    $("#login_error").empty();
                }

                if (!JSON.parse(data).email) {
                    $("#email_error").text('E-mail already exists');
                } else {
                    $("#email_error").text('');
                }

                if (!JSON.parse(data).pass) {
                    $("#password_error").text('Password should be at least 8 characters in length and should include at least one upper case letter, one number, and one special character.');
                } else {
                    $("#password_error").text('');
                }
                result = (JSON.parse(data).login && JSON.parse(data).email && JSON.parse(data).pass);
            }
        });
    }
    return result;
}

$(document).ready(function () {
    $("#registration-form").on("submit", function () {
        console.log("Submitting");
        return checkForm();
    });
});