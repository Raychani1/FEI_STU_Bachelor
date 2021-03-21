<!DOCTYPE HTML>
<html lang="sk">
<head>
    <title>Olympijské Hry - Add Discipline</title>
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
    ini_set('display_errors', 1);
    ini_set('display_startup_errors', 1);
    error_reporting(E_ALL);

    // Connect to the Database
    include("config.php");

    try {
        $conn = new PDO("mysql:host=$servername;dbname=$dbname", $username, $password);
    } catch (PDOException $e) {
        echo "Connection to " . $dbname . " failed : " . $e->getMessage();
    }

    $sql = "SELECT id AS osoba_id, name,surname FROM osoby";
    $stm = $conn->query($sql);
    $rows = $stm->fetchAll(PDO::FETCH_ASSOC);

    $successfulAddDiscipline = false;

    if (isset($_POST['placing']) && !empty($_POST['placing']) && isset($_POST['discipline']) && !empty($_POST['discipline'])){
        $sql = "INSERT INTO umiestnenia (person_id,oh_id,placing,discipline ) VALUES (?,?,?,?)";
        $stm= $conn->prepare($sql);
        $stm->bindValue(1,$_POST["person"]);
        $stm->bindValue(2,$_POST["oh"]);
        $stm->bindValue(3,$_POST["placing"]);
        $stm->bindValue(4,$_POST["discipline"]);
        $stm->execute();

        $successfulAddDiscipline = true;
    }
    else{
        $successfulAddDiscipline = false;
    }?>
    <div >
        <h1 class="section_header">Pridať disciplínu</h1>
        <form method="post">
            <div class="form_field">
                <label class="input_field" for="person_select">Osoba</label>
                <select name="person" id="person_select">
                    <?php
                    foreach ($rows as $row) {?>
                        <option id="person" value="<?php echo $row["osoba_id"]?>"><?php  echo $row["name"]." ".$row["surname"];?></option>
                    <?php }?>
                </select>
            </div>
            <div class="form_field">
                <label class="input_field" for="oh_select">Olympia</label>
                <select name="oh" id="oh_select">
                    <?php
                    $sql = "SELECT id, year, city, country FROM oh ";
                    $stm = $conn->query($sql);
                    $rows = $stm->fetchAll(PDO::FETCH_ASSOC);

                    foreach ($rows as $row) {?>
                        <option name="oh" value="<?php echo $row["id"]?>"><?php echo $row["year"]." ".$row["city"]." ".$row["country"];?></option>
                    <?php }?>
                </select>
            </div>

            <div class="form_field">
                <label class="input_field" for="placing">Placing</label>
                <input  type="number" min="1" name="placing" id="placing" >
            </div>
            <div class="form_field">
                <label class="input_field" for="discipline">Discipline</label>
                <input type="text" name="discipline" id="discipline">
            </div>
            <?php
            if ($successfulAddDiscipline){
                echo "<h1 class='success'>Pridaná disciplína</h1>";
            }?>
            <button type="submit" name="save" class="btn btn-success" >Save</button>
        </form>
    </div>
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-beta2/dist/js/bootstrap.bundle.min.js" integrity="sha384-b5kHyXgcpbZJO/tY9Ul7kGkf1S0CWuKcCD38l8YkeH8z8QjE0GmW1gYU5S9FOnJ0" crossorigin="anonymous"></script>
</body>
</html>