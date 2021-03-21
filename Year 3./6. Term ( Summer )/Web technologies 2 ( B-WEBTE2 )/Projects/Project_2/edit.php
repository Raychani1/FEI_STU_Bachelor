<!DOCTYPE HTML>
<html lang="sk">

<head>
    <title>Olympijské Hry - Edit</title>
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

    if (isset($_POST['name']) && !empty($_POST['name']) ){
        $sql = "UPDATE osoby SET 
                     name=?, 
                     surname=?, 
                     birth_day=?, 
                     birth_place=?, 
                     birth_country=?,
                     death_day=?,
                     death_place=?,
                     death_country=?
                WHERE id=?";
        $stm = $conn->prepare($sql);

        $stm->bindValue(1,$_POST["name"]);
        $stm->bindValue(2,$_POST["surname"]);
        $stm->bindValue(3,$_POST["birth_day"]);
        $stm->bindValue(4,$_POST["birth_place"]);
        $stm->bindValue(5,$_POST["birth_country"]);
        $stm->bindValue(6,$_POST["death_day"]);
        $stm->bindValue(7,$_POST["death_place"]);
        $stm->bindValue(8,$_POST["death_country"]);
        $stm->bindValue(9,$_POST["id"]);

        $stm->execute();

        $successfulUpdate=true;

    }
    else{
        $successfulUpdate=false;
    }

    if (isset($_GET['edit']) && !empty($_GET['edit'])){

        $to_edit = $_GET['edit'];

        $sql = "SELECT osoby.id,name,surname,birth_place,city,country,birth_day,birth_place, birth_country,death_day,death_place,death_country
                FROM osoby
                    INNER JOIN umiestnenia on umiestnenia.person_id = osoby.id
                    INNER JOIN oh ON oh.id=umiestnenia.oh_id                    
                WHERE umiestnenia.id=?  ;";
        
        $stm = $conn->prepare($sql);
        $stm->bindValue(1,$to_edit,PDO::PARAM_INT);
        $stm->execute();
        $row = $stm->fetch(PDO::FETCH_ASSOC);

        if ( !empty( $row["id"])){?>
            <h1 class="section_header">Edit Data pre <?php echo $row["name"]." ".$row["surname"]; ?></h1>
            <div >
                <form  method="post">
                    <div class="form_field">
                        <input type="hidden" id="id" name="id" value= <?php echo $row["id"]; ?> >
                    </div>
                    <div class="form_field">
                        <label class="input_field" for="name">Meno</label>
                        <input type="text" id="name" name="name" value= <?php echo $row["name"]; ?> >
                    </div>
                    <div class="form_field">
                        <label class="input_field" for="surname">Priezvisko</label>
                        <input type="text" id="surname" name="surname" value= <?php echo $row["surname"]; ?> >
                    </div>
                    <div class="form_field">
                        <label class="input_field" for="birth_day">Dátum narodenia</label>
                        <input type="text" id="birth_day" name="birth_day" value= <?php echo $row["birth_day"]; ?> >
                    </div>
                    <div class="form_field">
                        <label class="input_field" for="birth_place">Miesto narodenia</label>
                        <input type="text" id="birth_place" name="birth_place" value= <?php echo $row["birth_place"]; ?> >
                    </div>
                    <div class="form_field">
                        <label class="input_field" for="birth_country">Krajina narodenia</label>
                        <input type="text" id="birth_country" name="birth_country" value= <?php echo $row["birth_country"]; ?> >
                    </div>
                    <div class="form_field">
                        <label class="input_field" for="death_day">Dátum úmrtia</label>
                        <input type="text" id="death_day" name="death_day" value= <?php echo $row["death_day"]; ?> >
                    </div>
                    <div class="form_field">
                        <label class="input_field" for="death_place">Miesto úmrtia</label>
                        <input type="text" id="death_place" name="death_place" value= <?php echo $row["death_place"]; ?> >
                    </div>
                    <div class="form_field">
                        <label class="input_field" for="death_country">Krajina úmrtia</label>
                        <input type="text" id="death_country" name="death_country" value= <?php echo $row["death_country"]; ?> >
                    </div>
                    <div class="form_field">
                        <button type="submit" name="save" class="btn btn-success">Save</button>
                    </div>
                    <?php
                    if ($successfulUpdate){
                        echo "<h1>Úspešná aktualizácia !</h1>";
                    }
                    ?>
                </form>
            <?php
            }else{
                echo "<h1 class='section_header'>Osoba sa nanašla v Databáze</h1>";
            }
        }
        else{
            echo "<h1 class='section_header'>Osoba sa nanašla v Databáze</h1>";
        }
        ?>
    </div>


    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-beta2/dist/js/bootstrap.bundle.min.js" integrity="sha384-b5kHyXgcpbZJO/tY9Ul7kGkf1S0CWuKcCD38l8YkeH8z8QjE0GmW1gYU5S9FOnJ0" crossorigin="anonymous"></script>
</body>
</html>