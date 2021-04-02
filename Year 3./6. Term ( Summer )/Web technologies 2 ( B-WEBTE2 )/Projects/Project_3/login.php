<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Tr4ff1c_Tr4ck3r - Login</title>
    <link rel="stylesheet" type="text/css" href="css/style.css">
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-beta2/dist/css/bootstrap.min.css" rel="stylesheet"
          integrity="sha384-BmbxuPwQa2lc/FVzBcNJ7UAyJxM6wuqIj61tLrc4wSX0szH/Ev+nYRRuWlolflfl" crossorigin="anonymous">
    <link rel="preconnect" href="https://fonts.gstatic.com">
    <link href="https://fonts.googleapis.com/css2?family=Inconsolata:wght@500&display=swap" rel="stylesheet">
    <link rel="icon" href="img/tr4ff1c_tr4ck3er_logo.png" type="image/x-icon">
</head>
<?php

session_start();

// Load Files
require_once 'configs/config.php';
require_once 'google/google_api/vendor/autoload.php';
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

function setSessionValues($email, $firstname, $lastname, $login)
{
    $_SESSION["email"] = $email;
    $_SESSION["firstname"] = $firstname;
    $_SESSION["lastname"] = $lastname;
    $_SESSION["username"] = $login;
}

// Create Client Request to access Google API
$client = new Google_Client();
$client->setClientId($clientID);
$client->setClientSecret($clientSecret);
$client->setRedirectUri($redirectUri);
$client->addScope("email");
$client->addScope("profile");

// Authenticate code from Google OAuth Flow
if (isset($_GET['code'])) {
    $token = $client->fetchAccessTokenWithAuthCode($_GET['code']);
    $client->setAccessToken($token['access_token']);

    // Get profile info
    $google_oauth = new Google_Service_Oauth2($client);
    $google_account_info = $google_oauth->userinfo->get();
    $email = $google_account_info->email;
    $firstname = $google_account_info->givenName;
    $lastname = $google_account_info->familyName;
    $login = $google_account_info->name;

    $sql = "SELECT id FROM users WHERE email=? && login=?";
    $stm = $conn->prepare($sql);
    $stm->bindValue(1, $email);
    $stm->bindValue(2, $login);
    $stm->execute();
    $rows = $stm->fetch(PDO::FETCH_ASSOC);

    if (!empty($rows)) {
        // If the User exist in the Database
        setSessionValues($email, $firstname, $lastname, $login);

        // Add new Google log
        $sql = "INSERT into logs (user_id,timestamp , type) VALUE (?, ?,?)";
        $stm = $conn->prepare($sql);

        date_default_timezone_set('Europe/Bratislava');
        $date = date('m/d/Y h:i:s a', time());

        $stm->bindValue(1, $rows['id']);
        $stm->bindValue(2, $date);
        $stm->bindValue(3, "google");
        $stm->execute();

        header("location: index.php");
    } else {
        // If it's a new User
        $sql = "INSERT INTO users (name, surname, email, login) VALUES (?,?,?,?)";

        $stm = $conn->prepare($sql);
        $stm->bindValue(1, $firstname);
        $stm->bindValue(2, $lastname);
        $stm->bindValue(3, $email);
        $stm->bindValue(4, $login);
        $stm->execute();

        setSessionValues($email, $firstname, $lastname, $login);

        header("location: index.php");
    }
}

if (isset($_POST['email']) && !empty($_POST['email'])){
    $sql = "SELECT id, password FROM users WHERE email=?";
    $stm = $conn->prepare($sql);
    $stm->bindValue(1, $_POST["email"]);
    $stm->execute();
    $rows = $stm->fetch(PDO::FETCH_ASSOC);

    // 2FA after entering the correct password
    if (!empty($rows["id"]) && (password_verify($_POST["password"], $rows["password"]))) {
        ?>
        <div class="box">
            <form method="post" id="2FA">
                <div class="form-section">
                    <input type="hidden" name="id" value="<?php echo $rows["id"] ?>">
                    <label for="codeInput" class="green-text center">Please enter your code from the Authenticator App
                        :</label><br>
                    <input required type="text" name="code" id="codeInput" class="custom-text-field"><br>
                </div>
                <div class="center">
                    <input id="codeCheck" type="submit" class="btn btn-control" value="Submit"/>
                    <?php echo
                    '<button type="button" class="btn btn-control" onclick=location.href="login.php">Back to Login</button>';
                    ?>
                </div>
            </form>
        </div>
        <?php
    } else {
        // Redirect to the same site in case of bad credentials
        header("location: login.php");
    }
}
else{
?>
<body>
<div class="jumbotron">
    <img src="img/tr4ff1c_tr4ck3er_logo.png" id="logo" alt="logo">
    <h1 id="title">Tr4ff1c_Tr4ck3r</h1>
</div>
<div class="box">
    <div class="center">
        <h1 class="green-text">Login to Tr4ff1c Tr4ck3r</h1>
    </div>
    <form method="post" id="login-form">
        <div class="form-section">
            <label for="email" class="green-text">Email</label><br>
            <input required type="email" name="email" id="email" class="custom-text-field">
        </div>

        <div class="form-section">
            <label for="password" class="green-text">P4ssw0rd</label><br>
            <input required type="password" name="password" id="password" class="custom-text-field">
        </div>

        <div class="center">
            <input type="submit" class="btn btn-control" value="Login">
            <?php echo
            '<button type="button" class="btn btn-control" onclick=location.href="registration.php">Sign Up</button>';
            ?>
        </div>
    </form>

    <div class="center">
        <div class="connect green-text">or connect with</div>
        <?php echo
        '<button type="button" class="btn btn-control btn-stu" onclick=location.href="ldap.php"><i class="stu"></i></button>';
        ?>
        <?php echo
            '<button type="button" class="btn btn-control btn-google" onclick=location.href="' . $client->createAuthUrl() . '"><i class="google"></i>Sign in with Google</button>';
        ?>
    </div>
</div>
<?php
}

// Authentication
if (isset($_POST['code']) && !empty($_POST['code'])) {
    $sql = "SELECT id,name,surname,email,google_password,login FROM users WHERE id = ? ";
    $stm = $conn->prepare($sql);
    $stm->bindValue(1, $_POST["id"]);
    $stm->execute();
    $rows = $stm->fetch(PDO::FETCH_ASSOC);


    $ga = new PHPGangsta_GoogleAuthenticator();

    $checkResult = $ga->verifyCode($rows["google_password"], $_POST['code'], 1);

    if ($checkResult) {
        setSessionValues($rows["email"], $rows["name"], $rows["surname"], $rows["login"]);

        // Add new login log
        $sql = "INSERT into logs (user_id,timestamp , type) VALUE (?, ?,?)";
        $stm3 = $conn->prepare($sql);

        date_default_timezone_set('Europe/Bratislava');
        $date = date('m/d/Y h:i:s a', time());

        $stm3->bindValue(1, $rows['id']);
        $stm3->bindValue(2, $date);
        $stm3->bindValue(3, "login");
        $stm3->execute();

        header("location: index.php");

    } else {
        echo 'Authentication failed';
    }
} ?>

<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-beta2/dist/js/bootstrap.bundle.min.js"
        integrity="sha384-b5kHyXgcpbZJO/tY9Ul7kGkf1S0CWuKcCD38l8YkeH8z8QjE0GmW1gYU5S9FOnJ0"
        crossorigin="anonymous"></script>
</body>
</html>