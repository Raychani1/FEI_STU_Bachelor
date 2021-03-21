<!DOCTYPE HTML>
<html lang="sk">
<head>
    <title>Olympijské Hry - Add Person</title>
    <meta charset="UTF-8">
    <link rel="stylesheet" type="text/css" href="css/style.css">
    <link rel = "icon" href =
    "img/olympic_rings.png"
          type = "image/x-icon">
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-beta2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-BmbxuPwQa2lc/FVzBcNJ7UAyJxM6wuqIj61tLrc4wSX0szH/Ev+nYRRuWlolflfl" crossorigin="anonymous">
    <link rel="preconnect" href="https://fonts.gstatic.com">
    <link href="https://fonts.googleapis.com/css2?family=McLaren&display=swap" rel="stylesheet">
</head>
<body>
    <div class="jumbotron">
        <img src="img/olympic_rings.png" alt="rings">
        <h1>Olympijské Hry</h1>
        <div>
            <button class="btn control" onclick="location.href='index.php'">Home</button>
        </div>
    </div>
    <?php
//    ini_set('display_errors', 1);
//    ini_set('display_startup_errors', 1);
//    error_reporting(E_ALL);

    // Connect to the Database
    include("config.php");

    try {
        $conn = new PDO("mysql:host=$servername;dbname=$dbname", $username, $password);
    } catch (PDOException $e) {
        echo "Connection to " . $dbname . " failed : " . $e->getMessage();
    }

    $successfulAddPerson=false;

    if (isset($_POST['name']) && !empty($_POST['name'])){

        $sql = "INSERT INTO osoby  (name, surname, birth_day, birth_place, birth_country,death_day,death_place,death_country)
             VALUES (?,?,?,?,?,?,?,?)";

        $stm= $conn->prepare($sql);

        $stm->bindValue(1,$_POST["name"]);
        $stm->bindValue(2,$_POST["surname"]);
        $stm->bindValue(3,$_POST["birth_day"]);
        $stm->bindValue(4,$_POST["birth_place"]);
        $stm->bindValue(5,$_POST["birth_country"]);
        $stm->bindValue(6,$_POST["death_day"]);
        $stm->bindValue(7,$_POST["death_place"]);
        $stm->bindValue(8,$_POST["death_country"]);

        // SQL - Checking for duplicate values ( People with the same name )
        $duplicate ="SELECT id FROM osoby WHERE name = ? && surname=?";
        $stm2 = $conn->prepare($duplicate);
        $stm2->bindValue(1,$_POST["name"]);
        $stm2->bindValue(2,$_POST["surname"]);
        $stm2->execute();
        $rows = $stm2->fetch(PDO::FETCH_ASSOC);

        if (!empty($rows["id"])){
            echo "<h1 class='section_header warning' >Táto osoba už existuje v Databáze</h1>";
        }
        else{
            $stm->execute();
            $successfulAddPerson=true;
        }
        } else {
            $successfulAddPerson=false;
        }?>

    <div >
        <h1 class="section_header">Pridanie novej osoby</h1>
        <form method="post">
            <div class="form_field">
                <label class="input_field" for="name">Meno</label>
                <input type="text" name="name"  id="name">
            </div>
            <div class="form_field">
                <label class="input_field" for="surname">Priezvisko</label>
                <input type="text" name="surname"  id="surname">
            </div>
            <div class="form_field">
                <label class="input_field" for="birth_day">Dátum narodenia</label>
                <input type="text" name="birth_day" id="birth_day">
            </div>
            <div class="form_field">
                <label class="input_field" for="birth_place">Miesto narodenia</label>
                <input type="text" name="birth_place" id="birth_place">
            </div>
            <div class="form_field">
                <label class="input_field" for="birth_country">Krajina narodenia</label>
                <input type="text" name="birth_country"  id="birth_country">
            </div>
            <div class="form_field">
                <label class="input_field" for="death_day">Dátum úmrtia</label>
                <input type="text" name="death_day" id="death_day">
            </div>
            <div class="form_field">
                <label class="input_field" for="death_place">Miesto úmrtia</label>
                <input type="text" name="death_place" id="death_place" >
            </div>
            <div class="form_field">
                <label class="input_field" for="death_country">Krajina úmrita</label>
                <input type="text" name="death_country"  id="death_country" >
            </div>

            <button type="submit" name="save" class="btn btn-success">Save</button>

            <?php
            if ($successfulAddPerson){
                echo "<h1 class='success'>Pridaná osoba</h1>";
            }?>
        </form>
    </div>
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-beta2/dist/js/bootstrap.bundle.min.js" integrity="sha384-b5kHyXgcpbZJO/tY9Ul7kGkf1S0CWuKcCD38l8YkeH8z8QjE0GmW1gYU5S9FOnJ0" crossorigin="anonymous"></script>
</body>
</html>