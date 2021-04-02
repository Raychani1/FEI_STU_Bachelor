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

?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Tr4ff1c_Tr4ck3r - Statistics</title>
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
    <div id="logged_in">
        <h1>Welcome<br><span id="logged_in_user"><?php echo $_SESSION['username'] ?></span></h1>
        <?php echo
        '<button type="button" class="btn btn-control btn-logout" onclick=location.href="logout.php">Logout</button>';
        ?>
    </div>
</div>

<h1 class="green-text center">Your Logs</h1>
<div class="table_content">
    <table>
        <thead>
        <tr>
            <th>Log Date</th>
            <th>Type</th>
        </tr>
        </thead>
        <tbody> <?php
        $sql = "SELECT timestamp ,type FROM logs WHERE user_id  = ? ";
        $stm = $conn->prepare($sql);
        $stm->bindValue(1, $_SESSION['id']);
        $stm->execute();
        $rows = $stm->fetchAll(PDO::FETCH_ASSOC);
        foreach ($rows as $row) { ?>
            <tr>
                <td>
                    <?php echo $row["timestamp"] ?>
                </td>
                <td>
                    <?php echo $row["type"]; ?>
                </td>
            </tr>
        <?php } ?>
        </tbody>
    </table>
    <?php

    $sql = "SELECT COUNT(id) FROM logs where type = 'google';";
    $stm = $conn->prepare($sql);
    $stm->execute();
    $row = $stm->fetch(PDO::FETCH_ASSOC);
    $google = $row['COUNT(id)'];

    $sql = "SELECT COUNT(id) FROM logs where type = 'ldap';";
    $stm = $conn->prepare($sql);
    $stm->execute();
    $row = $stm->fetch(PDO::FETCH_ASSOC);
    $ldap = $row['COUNT(id)'];

    $sql = "SELECT COUNT(id) FROM logs where type = 'login';";
    $stm = $conn->prepare($sql);
    $stm->execute();
    $row = $stm->fetch(PDO::FETCH_ASSOC);
    $login = $row['COUNT(id)'];

    ?>
</div>
<h1 class="green-text center">Statistics</h1>
<div class="table_content">
    <table>
        <thead>
        <tr>
            <th>Login</th>
            <th>Google</th>
            <th>LDAP</th>
        </tr>
        </thead>
        <tbody>
        <tr>
            <td>
                <?php echo $login; ?>
            </td>
            <td>
                <?php echo $google; ?>
            </td>
            <td>
                <?php echo $ldap; ?>
            </td>
        </tr>
        </tbody>
    </table>
</div>
</body>
</html>
