<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Tr4ff1c_Tr4ck3r - Registration</title>
    <link rel="stylesheet" type="text/css" href="css/style.css">
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-beta2/dist/css/bootstrap.min.css" rel="stylesheet"
          integrity="sha384-BmbxuPwQa2lc/FVzBcNJ7UAyJxM6wuqIj61tLrc4wSX0szH/Ev+nYRRuWlolflfl" crossorigin="anonymous">
    <link rel="preconnect" href="https://fonts.gstatic.com">
    <link href="https://fonts.googleapis.com/css2?family=Inconsolata:wght@500&display=swap" rel="stylesheet">
    <link rel="icon" href="img/tr4ff1c_tr4ck3er_logo.png" type="image/x-icon">
</head>
<body>
<div class="jumbotron">
    <img src="img/tr4ff1c_tr4ck3er_logo.png" id="logo" alt="logo">
    <h1 id="title">Tr4ff1c_Tr4ck3r</h1>
</div>
<?php

session_start();

// Load Files
require_once 'configs/config.php';
require_once 'google/google_authenticator/PHPGangsta/GoogleAuthenticator.php';

// Connect to the Database
try {
    $conn = new PDO("mysql:host=$servername;dbname=$dbname", $username, $password);
} catch (PDOException $e) {
    echo "Connection to $dbname failed : " . $e->getMessage();
}

// Display errors
ini_set('display_errors', 1);
ini_set('display_startup_errors', 1);
error_reporting(E_ALL);

$successfulSignUp = !empty($_POST['firstname']);

if (isset($_POST['firstname']) && !empty($_POST['firstname'])) {
    $sql = "INSERT INTO users (name, surname, email, login, password, google_password) VALUES (?,?,?,?,?,?)";
    $stm = $conn->prepare($sql);
    $stm->bindValue(1, $_POST["firstname"]);
    $stm->bindValue(2, $_POST["surname"]);
    $stm->bindValue(3, $_POST["email"]);
    $stm->bindValue(4, $_POST["login"]);
    $stm->bindValue(5, password_hash($_POST["password"], PASSWORD_DEFAULT));
} ?>

<div>
    <?php
    if (!$successfulSignUp) { ?>
        <div class="box">
            <form method="post" action="registration.php" id="registration-form">
                <div class="center">
                    <h1 class="green-text">Sign up to T4ff1c_Tr4ck3r</h1>
                </div>
                <div>
                    <div class="form-section">
                        <label for="login" class="green-text">Login name</label> <br>
                        <input required type="text" name="login" id="login" class="custom-text-field"> <br>
                        <span class="error" id="login_error"></span><br>
                    </div>

                    <div class="form-section">
                        <label for="firstname" class="green-text">Name</label> <br>
                        <input required type="text" name="firstname" id="firstname" class="custom-text-field"> <br>
                    </div>

                    <div class="form-section">
                        <label for="surname" class="green-text">Surname</label> <br>
                        <input required type="text" name="surname" id="surname" class="custom-text-field"> <br>
                    </div>

                    <div class="form-section">
                        <label for="email" class="green-text">Email</label> <br>
                        <input required type="email" name="email" id="email" class="custom-text-field"> <br>
                        <span class="error" id="email_error"></span><br>
                    </div>

                    <div class="form-section">
                        <label for="password" class="green-text">Password</label> <br>
                        <input required type="password" name="password" id="password" class="custom-text-field"> <br>
                        <span class="error" id="password_error"></span><br>
                    </div>

                    <div class="center">
                        <input type="submit" class="btn btn-control" value="Register">
                    </div>
                </div>
            </form>
            <div class="center">
                <h4 class="green-text">Already have an account? <a href=" login.php"> Login </a></h4>
            </div>
        </div>
        <?php
    } else { ?>
        <div class="box" id="twofac">
            <?php
            $ga = new PHPGangsta_GoogleAuthenticator();
            $secret = $ga->createSecret();
            $qrCodeUrl = $ga->getQRCodeGoogleUrl('Tr4ff1c_Tr4ck3r', $secret);

            echo "<h3 class='green-text center'>Your Two-Factor Authentication QR code:  </h3>
                  <br><br>
                  <p class='green-text center'>Scan this code:</p>
                  <img id='qr' src=$qrCodeUrl alt='2FA_QR'>
                  <br><br>
                  <p class='green-text center'>1 - Open the Authenticator app on your device.</p>
                  <br>
                  <p class='green-text center'>2 - Tap + and read QR code</p>
                  <br>";

            $stm->bindValue(6, $secret);
            $stm->execute();

            echo
            '<div class="center"><button type="button" class="btn btn-control" onclick=location.href="login.php">Continue</button></div>'; ?>
        </div>
        <?php
    } ?>
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-beta2/dist/js/bootstrap.bundle.min.js"
            integrity="sha384-b5kHyXgcpbZJO/tY9Ul7kGkf1S0CWuKcCD38l8YkeH8z8QjE0GmW1gYU5S9FOnJ0"
            crossorigin="anonymous"></script>
    <script src="js/script.js"></script>
</body>
</html>
