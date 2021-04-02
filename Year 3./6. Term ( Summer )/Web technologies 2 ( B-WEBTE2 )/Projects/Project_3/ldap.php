<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Tr4ff1c_Tr4ck3r - LDAP Login</title>
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

if (isset($_POST['ldap_login']) && !empty($_POST['ldap_login'])) {

    $ldapuid = $_POST['ldap_login'];
    $ldappass = $_POST['password'];

    $dn = 'ou=People, DC=stuba, DC=sk';
    $ldaprdn = "uid=$ldapuid, $dn";

    $ldapconn = ldap_connect("ldap.stuba.sk")
    or die("Could not connect to LDAP server");

    $set = ldap_set_option($ldapconn, LDAP_OPT_PROTOCOL_VERSION, 3);

    if ($ldapconn) {

        $ldapbind = ldap_bind($ldapconn, $ldaprdn, $ldappass);

        if ($ldapbind) {

            $results = ldap_search($ldapconn, $dn, "uid=$ldapuid", array("givenname", "employeetype", "surname", "mail", "faculty", "cn", "uisid", "uid"), 0, 5);
            $info = ldap_get_entries($ldapconn, $results);

            // Check if User exists in Database
            $sql = "SELECT id,name,surname,email,login FROM users WHERE email=? ";
            $stm = $conn->prepare($sql);
            $stm->bindValue(1, $info[0]['mail'][0]);
            $stm->execute();
            $rows = $stm->fetch(PDO::FETCH_ASSOC);
            var_dump($info[0]['mail'][0]);
            if (!empty($rows)) {

                // If the User exists save the values in to Session
                setSessionValues($rows["email"], $rows["name"], $rows["surname"], $rows["login"]);

                $sql = "INSERT into logs (user_id,timestamp , type) VALUE (?, ?,?)";
                $stm3 = $conn->prepare($sql);

                date_default_timezone_set('Europe/Bratislava');
                $date = date('m/d/Y h:i:s a', time());

                $stm3->bindValue(1, $rows['id']);
                $stm3->bindValue(2, $date);
                $stm3->bindValue(3, "ldap");
                $stm3->execute();

                header("location: index.php");

            } else {

                // If the User does not exist insert it to Database
                $sql = "INSERT INTO users (name, surname, login, email) VALUES (?,?,?,?)";
                $stm = $conn->prepare($sql);
                $stm->bindValue(1, $info[0]['givenname'][0]);
                $stm->bindValue(2, $info[0]['sn'][0]);
                $stm->bindValue(3, $info[0]['cn'][0]);
                $stm->bindValue(4, $info[0]['mail'][0]);
                $stm->execute();

                // If there was an error in the previous query it will still work
                $sql = "SELECT id,name,surname,email,login FROM users WHERE email=? ";
                $stm = $conn->prepare($sql);
                $stm->bindValue(1, $info[0]['mail'][0]);
                $stm->execute();
                $rows = $stm->fetch(PDO::FETCH_ASSOC);

                if (!empty($rows)) {
                    setSessionValues($rows["email"], $rows["name"], $rows["surname"], $rows["login"]);

                    $sql = "INSERT into logs (user_id, timestamp, type) VALUE (?, ?,?)";
                    $stm = $conn->prepare($sql);

                    date_default_timezone_set('Europe/Bratislava');
                    $date = date('m/d/Y h:i:s a', time());

                    $stm->bindValue(1, $rows['id']);
                    $stm->bindValue(2, $date);
                    $stm->bindValue(3, "ldap");
                    $stm->execute();

                    header("location: index.php");
                }
            }
        } else { ?>
            <form method="post" id="twofac">
                <div class="heading">Wrong data try again</div>
                <br/><br/><br/>

                <?php echo
                '<button type="button" class="btn btn-control" onclick=location.href="login.php">Back to Login</button>';
                ?>
                <br/><br/><br/>
            </form>
        <?php
        }
    }
} ?>
<div class="box">
    <form method="post">

        <h1 class="green-text center">AIS Login to Tr4ff1c Tr4ck3r</h1>

        <div class="form-section">
            <label for="ldap_login" class="green-text center">AIS Login:</label> <br>
            <input required type="text" name="ldap_login" id="ldap_login" class="custom-text-field">
        </div>
        <div class="form-section">
            <label for="password" class="green-text center">Password</label> <br>
            <input required type="password" name="password" id="password" class="custom-text-field">
        </div>

        <div class="center">
            <input id="codecheck" type="submit" class="btn btn-control" value="Login"/>
            <?php echo
            '<button type="button" class="btn btn-control" onclick=location.href="login.php">Back to Login</button>';
            ?>
        </div>
    </form>
</div>
<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-beta2/dist/js/bootstrap.bundle.min.js"
        integrity="sha384-b5kHyXgcpbZJO/tY9Ul7kGkf1S0CWuKcCD38l8YkeH8z8QjE0GmW1gYU5S9FOnJ0"
        crossorigin="anonymous"></script>
</body>
</html>
