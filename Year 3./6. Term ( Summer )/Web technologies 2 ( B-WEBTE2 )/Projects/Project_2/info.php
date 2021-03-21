<!DOCTYPE html>
<html lang="sk">
<head>
    <meta charset="UTF-8">
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

if (isset($_GET['o_id'])){
    $info=$_GET['o_id'];
    $personal_info = "SELECT * FROM osoby WHERE id =?;";
    $stm = $conn->prepare($personal_info);
    $stm->bindValue(1,$info,PDO::PARAM_INT);
    $stm->execute();
    $person = $stm->fetch(PDO::FETCH_ASSOC);

    if ( !empty( $person["id"])){?>
        <title>Olympijské Hry - Info - <?php echo $person["name"]." ".$person["surname"] ?></title>
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
            <section>
                <h1 class="section_header"><?php echo $person["name"]." ".$person["surname"]; ?></h1>
                <h1 class="section_header"><?php echo "Narodenie: <br>".$person["birth_day"].", ".$person["birth_place"].", ".$person["birth_country"];?></h1>
                <h1 class="section_header"><?php echo "Úmrtie: <br>";
                    if ( !empty($person["death_day"])){
                        echo $person["death_day"].", ".$person["death_place"].", ".$person["death_country"];
                    }
                    else{
                        echo "Žijúci(a)";
                    }?></h1>
                <div>
                    <table>
                        <thead>
                            <tr>
                                <th>Typ</th>
                                <th>Rok</th>
                                <th>Mesto</th>
                                <th>Krajina</th>
                                <th>Disciplína</th>
                                <th>Umiestnenie</th>
                            </tr>
                        </thead>
                        <tbody>
                            <?php
                            $sport_info = "SELECT type,year, city,country,discipline,placing FROM umiestnenia
                                                    INNER JOIN osoby on umiestnenia.person_id = osoby.id
                                                    INNER JOIN oh ON oh.id=umiestnenia.oh_id
                                            WHERE osoby.id= ?;";
                            $stm = $conn->prepare($sport_info);
                            $stm->bindValue(1,$info,PDO::PARAM_INT);
                            $stm->execute();
                            $olympics = $stm->fetchAll(PDO::FETCH_ASSOC);

                            foreach ($olympics as $game) { ?>
                                <tr>
                                    <td><?php echo $game["type"]; ?></td>
                                    <td><?php echo $game["year"]; ?> </td>
                                    <td><?php echo $game["city"]; ?></td>
                                    <td><?php echo $game["country"]; ?></td>
                                    <td><?php echo $game["discipline"]; ?></td>
                                    <td><?php echo $game["placing"]; ?></td>
                                </tr>
                            <?php } ?>
                        </tbody>
                    </table>
                </div>
            </section>
            <?php
        }
        else{
            echo "<h1>Osoba sa nanašla v Databáze</h1>";
        }
    }
    else{
        echo "<h1>Osoba sa nanašla v Databáze</h1>";
    }
    ?>
        <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-beta2/dist/js/bootstrap.bundle.min.js" integrity="sha384-b5kHyXgcpbZJO/tY9Ul7kGkf1S0CWuKcCD38l8YkeH8z8QjE0GmW1gYU5S9FOnJ0" crossorigin="anonymous"></script>
</body>

</html>
