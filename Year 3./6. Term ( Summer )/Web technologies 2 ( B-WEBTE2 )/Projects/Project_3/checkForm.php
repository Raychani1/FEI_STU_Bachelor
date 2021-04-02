<?php

require_once 'configs/config.php';

// Connect to the Database
try {
    $conn = new PDO("mysql:host=$servername;dbname=$dbname", $username, $password);
} catch (PDOException $e) {
    echo "Connection to $dbname failed : " . $e->getMessage();
}

$login = $_POST["login"];

$sql = "SELECT id FROM users WHERE login = ?";
$stm = $conn->prepare($sql);
$stm->bindValue(1, $login);
$stm->execute();
$rows = $stm->fetch(PDO::FETCH_ASSOC);


$email = $_POST["email"];

$sql = "SELECT id FROM users WHERE email = ?";
$stm = $conn->prepare($sql);
$stm->bindValue(1, $email);
$stm->execute();
$rows2 = $stm->fetch(PDO::FETCH_ASSOC);

function checkPassword($password)
{
    // Validate password strength
    $uppercase = preg_match('@[A-Z]@', $password);
    $lowercase = preg_match('@[a-z]@', $password);
    $number = preg_match('@[0-9]@', $password);
    $specialChars = preg_match('@[^\w]@', $password);

    return !(!$uppercase || !$lowercase || !$number || !$specialChars || strlen($password) < 8);
}

$response = (empty($rows["id"]));
$response2 = (empty($rows2["id"]));

$result = array("login" => $response, "email" => $response2, "pass" => checkPassword($_POST["pass"]));

echo json_encode($result);