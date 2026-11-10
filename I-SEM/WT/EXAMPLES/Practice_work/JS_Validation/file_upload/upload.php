<?php

if(isset($_POST["submit"])){

    // Check whether a file was selected
    if(isset($_FILES["resume"])){

        $filename = $_FILES["resume"]["name"];
        $filesize = $_FILES["resume"]["size"];
        $filetmp = $_FILES["resume"]["tmp_name"];
        $filetype = $_FILES["resume"]["type"];
        $fileerror = $_FILES["resume"]["error"];

        // Check upload error
        if($fileerror == 0){

            // Check file extension
            $ext = strtolower(pathinfo($filename, PATHINFO_EXTENSION));

            if($ext == "pdf"){

                // Check file size (maximum 2 MB)
                if($filesize <= 2 * 1024 * 1024){

                    // Create uploads folder if it doesn't exist
                    if(!is_dir("uploads")){
                        mkdir("uploads");
                    }

                    $destination = "uploads/" . basename($filename);

                    if(move_uploaded_file($filetmp, $destination)){
                        echo "Resume uploaded successfully!";
                    }
                    else{
                        echo "File upload failed!";
                    }

                }
                else{
                    echo "File size must be less than 2 MB!";
                }

            }
            else{
                echo "Only PDF files are allowed!";
            }

        }
        else{
            echo "Error uploading file!";
        }

    }
    else{
        echo "Please select a file!";
    }

}
?>