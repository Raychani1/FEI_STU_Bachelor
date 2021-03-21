<!DOCTYPE html>
<html lang="sk">
<head>
    <meta charset="UTF-8">
    <title>Olympijské Hry</title>
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
        <button class="btn control" onclick="location.href='add_person.php'">Add Person</button>
        <button class="btn control" onclick="location.href='add_discipline.php'">Add Discipline</button>
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



// Select All the people who achieved the Gold Medal on the Olympic Games - For the Main Table
$sql = "SELECT umiestnenia.id, osoby.id as o_id, osoby.name, osoby.surname,oh.year,oh.city,oh.country,oh.type, umiestnenia.discipline
        FROM umiestnenia
            INNER JOIN oh on umiestnenia.oh_id = oh.id
            INNER JOIN osoby  on umiestnenia.person_id = osoby.id
        WHERE umiestnenia.placing=1";

// If the selected sorting order is selected use it otherwise use Ascending order
$sort = isset($_GET['sort']) ? $_GET['sort'] : 'ASC';

// If delete ( del ) is set remove the person from the Database based on his / her id
if (isset($_GET['del'])) {
    $to_delete = $_GET['del'];  // Determine which person should be removed
    $delete = $conn->prepare("DELETE FROM osoby WHERE id=?");
    $delete->bindValue(1, $to_delete);
    $delete->execute();
}
function flip_sort($sort){
    // This will be used when we will going to flip between sorting orders
    return ($sort == 'DESC') ? 'ASC':'DESC';
}

?>

<!-- Main Table -->
<section>
    <h1 class="section_header">Slovenskí olympionici</h1>
    <div>
        <table>
            <thead>
            <tr>
                <th>Meno</th>
                <th><a href="?order=surname&sort=<?php $newSort = flip_sort($sort); echo  $newSort; ?>">Priezvisko</a></th>
                <th><a href="?order=year&sort=<?php $newSort = flip_sort($sort); echo  $newSort; ?>">Rok</a></th>
                <th>Mesto</th>
                <th>Krajina</th>
                <th><a href="?order=type&sort=<?php $newSort = flip_sort($sort); echo  $newSort; ?>">Typ</a></th>
                <th>Disciplína</th>
                <th colspan="2" class="button_column"></th>
            </tr>
            </thead>
            <tbody>
            <?php

            // Determine based on what are we going to sort
            if (isset($_GET['order'])) {
                $order = $_GET['order'];
                if ($order == 'type'){
                    $sql .= " ORDER BY ".$order.",year $sort";
                } elseif ($order == 'year' || $order == 'surname'){
                    $sql .= " ORDER BY $order $sort";
                }
            } else {
                $sql .= " ORDER BY osoby.name";
            }

            $rows = $conn->query($sql)->fetchAll(PDO::FETCH_ASSOC);

            foreach ($rows as $row) {?>
                <tr>
                    <td>
                        <a href='info.php?o_id=<?php echo $row["o_id"] ?>' class="info"><?php echo $row["name"]; ?></a>
                    </td>
                    <td><?php echo $row["surname"]; ?> </td>
                    <td><?php echo $row["year"]; ?></td>
                    <td><?php echo $row["city"]; ?></td>
                    <td><?php echo $row["country"]; ?></td>
                    <td><?php echo $row["type"]; ?></td>
                    <td><?php echo $row["discipline"]; ?></td>
                    <td class="button_column">
                            <button class="btn btn-info edit" onclick="location.href='edit.php?edit=<?php echo $row["id"] ?>'">Edit</button>
                    </td>
                    <td class="button_column">
                            <button class="btn btn-danger" onclick="location.href='index.php?del=<?php echo $row["o_id"] ?>'">Delete</button>
                    </td>
                </tr>
            <?php } ?>
            </tbody>
        </table>
    </div>
</section>

<!-- Top 10 Table -->
<section>
    <h1 class="section_header">Top 10 olympionikov</h1>
    <div>
        <table>
            <thead>
                <tr>
                    <th>Meno</th>
                    <th>Priezvisko</th>
                    <th>Medaily</th>
                </tr>
            </thead>
            <tbody>
            <?php
//          https://learnsql.com/blog/case-when-with-sum/
            $sql2 = "SELECT osoby.id AS o_id,
                               osoby.name,
                               osoby.surname,
                               SUM(
                                   CASE
                                       WHEN umiestnenia.placing = 1 THEN 1
                                       ELSE 0
                                   END
                              ) AS medals
                        FROM umiestnenia
                            INNER JOIN osoby on umiestnenia.person_id = osoby.id
                        GROUP BY umiestnenia.person_id
                        ORDER BY medals DESC
                        LIMIT 10;";

            $rows2 = $conn->query($sql2)->fetchAll(PDO::FETCH_ASSOC);
            foreach ($rows2 as $row) {?>
                <tr>
                    <td>
                        <a class="info" href='info.php?o_id=<?php echo $row["o_id"] ?>'><?php echo $row["name"]; ?></a>
                    </td>
                    <td><?php echo $row["surname"]; ?> </td>
                    <td><?php echo $row["medals"]; ?></td>
                </tr>
            <?php } ?>
            </tbody>
        </table>
    </div>
</section>

<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-beta2/dist/js/bootstrap.bundle.min.js" integrity="sha384-b5kHyXgcpbZJO/tY9Ul7kGkf1S0CWuKcCD38l8YkeH8z8QjE0GmW1gYU5S9FOnJ0" crossorigin="anonymous"></script>
</body>
</html>

