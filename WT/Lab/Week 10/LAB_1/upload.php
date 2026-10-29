<?php
if (isset($_FILES['resume'])) {
    $file = $_FILES['resume'];
    $name = $file['name'];
    $tmp = $file['tmp_name'];
    $size = $file['size'];

    $ext = strtolower(pathinfo($name, PATHINFO_EXTENSION));

    if ($file['error'] != 0) {
        echo "<p class='error'>Error uploading file</p>";
    } elseif ($ext != "pdf") {
        echo "<p class='error'>Only PDF files are allowed</p>";
    } elseif ($size > 5 * 1024 * 1024) {
        echo "<p class='error'>File size must be below 5 MB</p>";
    } else {
        if (!is_dir("resumes")) {
            mkdir("resumes");
        }

        $newName = uniqid() . ".pdf";

        if (move_uploaded_file($tmp, "resumes/" . $newName))
            echo "<p class='success'>Resume uploaded successfully!</p>";
        else
            echo "<p class='error'>Upload failed</p>";
    }
}
?>

<!DOCTYPE html>
<html>
<head>
    <title>Resume Upload</title>

    <style>
        body {
            font-family: Arial, sans-serif;
            background-color: #f2f2f2;
            text-align: center;
            padding: 50px;
        }

        .container {
            background: white;
            width: 350px;
            margin: auto;
            padding: 25px;
            border-radius: 10px;
            box-shadow: 0 0 10px #ccc;
        }

        h2 {
            color: #333;
        }

        input[type="file"] {
            margin: 15px;
            width: 100%;
        }

        input[type="submit"] {
            background-color: #007bff;
            color: white;
            border: none;
            padding: 10px 20px;
            border-radius: 5px;
            cursor: pointer;
        }

        input[type="submit"]:hover {
            background-color: #0056b3;
        }

        .success {
            color: green;
        }

        .error {
            color: red;
        }
    </style>
</head>

<body>

<div class="container">
    <h2>Upload Resume</h2>

    <form action="upload.php" method="POST"
          enctype="multipart/form-data">

        <label>Select PDF Resume (Max 5 MB):</label><br>

        <input type="file" name="resume"
               accept=".pdf" required><br>

        <input type="submit" value="Upload">
    </form>
</div>

</body>
</html>

