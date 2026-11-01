<?php
if(isset($_FILES['resume'])){
    $file = $_FILES['resume'];
    $name = $file['name'];
    $tmp = $file['tmp_name'];
    $size = $file['size'];

    $ext = strtolower(pathinfo($name, PATHINFO_EXTENSION));
    
    if($file['error'] != 0){
        echo 'Error Uploading ! ';
    }elseif($ext != "pdf"){
        echo "Only pdf files are allowed !";
    }elseif($size > 5 * 1024 * 1024){
        echo "File size must be below 5 MB";
    }else{
        if(!is_dir("resumes")){
            mkdir("resumes");
        }
        $newName = $name . ".pdf";
        if(move_uploaded_file($tmp, "resumes/". $newName)){
            echo "Successfully uploaded !";
        }else{
            echo "Upload failed !";
        }
    }
}
?>


<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Upload</title>
</head>
<body>
    <form action="file.php" method = "POST" enctype ='multipart/form-data'>
        <label>Select the file to upload</label>
        <input type = "file" name = "resume" accept=".pdf" required><br>
        <input type = "submit" value = "UPLOAD">
    </form>
</body>
</html>