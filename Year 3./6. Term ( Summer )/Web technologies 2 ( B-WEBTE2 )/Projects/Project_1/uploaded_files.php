<!DOCTYPE html>
<html lang="en">
<head>
    <link rel="stylesheet" href="css/uploaded_files_style.css">
    <link rel="preconnect" href="https://fonts.gstatic.com">
    <link href="https://fonts.googleapis.com/css2?family=DotGothic16&display=swap" rel="stylesheet">

    <title>Pr0j3ct_1 Uploaded Files</title>
    <link rel="icon" href=
    "img/cloud_upload2.png"
          type="image/x-icon">
</head>
<body>

<table class="sortable">
    <thead>
    <tr>
        <th>Name</th>
        <th>Size</th>
        <th>Date</th>
    </tr>
    </thead>
    <tbody>

    <?php

    if (isset($_GET["path"])) {
        $dir = "../files/" . $_GET["path"] . "/";
        $count = 4;
        $order = 1;
    } else {
        $dir = "../files/";
        $count = 0;
        $order = 0;
    }

    $a = scandir($dir);

    foreach ($a as $file) {
        $link = "?path=" . $file;

        // Show the back option in the nested_files folder

        if ($order == 1 && $count == 4) {
            echo "<tr><td><a href='http://[ Location ]/uploaded_files.php'>{$file}</a></td></tr>";
            $count = 0;
            $order = 0;
        }

        // Make the "." , ".." elements disappear

        $count++;
        if ($count >= 3) {
            if (is_dir("../files/" . $file)) {
                // Print directory info ( Name as anchor tag )

                echo "<tr>
                        <td>
                            <a href = {$link}>{$file}</a>
                        </td>
                      </tr>";
            } else {
                // Print every other element which is not a directory

                echo "<tr>
                        <td>{$file}</td>                        
                        <td>" . filesize($dir . $file) . "</td>
                        <td>" . date("F d Y H:i:s.", filemtime($dir . $file)) . "</td>
                      </tr>";
            }
        }
    }
    ?>

    </tbody>
</table>

<button onclick="location.href='http://[ Location ]/'" class="control_button" id="nav_button">Upload Files</button>
<script src="js/sortable.js"></script>
</body>

</html>
