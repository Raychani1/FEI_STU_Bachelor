<!doctype html>
<html lang="en">
<head>
    <meta charset="utf-8">
    <link rel="stylesheet" href="css/style.css">
    <link rel="preconnect" href="https://fonts.gstatic.com">
    <link href="https://fonts.googleapis.com/css2?family=DotGothic16&display=swap" rel="stylesheet">

    <title>Pr0j3ct_1 File Upload</title>
    <link rel="icon" href=
    "img/cloud_upload2.png"
          type="image/x-icon">
</head>

<body>
<div id="file_upload">
    <div id="image">
        <img src="img/cloud_upload2.png" id="upload_icon" alt="cloud_icon">
    </div>
    <div id="form">
        <form action="upload.php" method="post" enctype="multipart/form-data">

            <div class="form-group">
                <label for="filename">Filename</label>
                <input name="filename" type="text" id="filename" class="form-control" placeholder="File name">
            </div>
            <div class="form-group">
                <label for="destination">Destination</label>

                <select name="destination" id="destination">
                    <option value="default" selected="selected">/files/ ( default )</option>
                    <option value="nested">/files/nested_files/</option>
                </select>
            </div>
            <div class="form-group">
                <label for="fileToUpload">File</label>
                <input type="file" name="fileToUpload" id="fileToUpload">

            </div>


            <input type="submit" value="Upload File" name="submit" class="control_button">
        </form>
    </div>
</div>
<button onclick="location.href='http://[ Location ]/uploaded_files.php'" class="control_button" id="nav_button">Show
    Files
</button>
</body>
</html>
<?php