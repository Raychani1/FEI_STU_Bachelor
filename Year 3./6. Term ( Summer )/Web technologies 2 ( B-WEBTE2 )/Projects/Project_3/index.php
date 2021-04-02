<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Tr4ff1c_Tr4ck3r</title>
    <link rel="stylesheet" type="text/css" href="css/style.css">
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-beta2/dist/css/bootstrap.min.css" rel="stylesheet"
          integrity="sha384-BmbxuPwQa2lc/FVzBcNJ7UAyJxM6wuqIj61tLrc4wSX0szH/Ev+nYRRuWlolflfl" crossorigin="anonymous">
    <link rel="preconnect" href="https://fonts.gstatic.com">
    <link href="https://fonts.googleapis.com/css2?family=Inconsolata:wght@500&display=swap" rel="stylesheet">
    <link rel="icon" href="img/tr4ff1c_tr4ck3er_logo.png" type="image/x-icon">
</head>
<body>
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

if (!isset($_SESSION['email'])) {
    $_SESSION['email'] = $_COOKIE["session"];
}

if (isset($_SESSION['email']) && !empty($_SESSION['email'])) {
    setcookie('session', $_SESSION['email'], time() + (86400 * 30)); ?>
    <div class="jumbotron">
        <img src="img/tr4ff1c_tr4ck3er_logo.png" id="logo" alt="logo">
        <h1 id="title">Tr4ff1c_Tr4ck3r</h1>
        <div id="logged_in">
            <h1>Welcome<br><span id="logged_in_user"><?php echo $_SESSION['username'] ?></span></h1>
            <?php echo
            '<button type="button" class="btn btn-control btn-logout" onclick=location.href="logout.php">Logout</button>';
            ?>
        </div>
    </div>

    <?php

    $sql = "SELECT id, name, surname, login FROM users WHERE email  = ? ";
    $stm = $conn->prepare($sql);
    $stm->bindValue(1, $_SESSION['email']);
    $stm->execute();

    $row = $stm->fetch(PDO::FETCH_ASSOC);

    $_SESSION['id'] = $row['id'];
    $_SESSION["firstname"] = $row['name'];
    $_SESSION["lastname"] = $row['surname'];
    $_SESSION["username"] = $row['login'];


    echo
    '<div class="center">
            <button type="button" class="btn btn-control" onclick=location.href="stats.php">Statistics</button>
         </div>';

} else {
    header("location: login.php");
}
?>
<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-beta2/dist/js/bootstrap.bundle.min.js"
        integrity="sha384-b5kHyXgcpbZJO/tY9Ul7kGkf1S0CWuKcCD38l8YkeH8z8QjE0GmW1gYU5S9FOnJ0"
        crossorigin="anonymous"></script>
</body>
</html>