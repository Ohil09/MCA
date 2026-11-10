<?php
$message = "";
if ($_SERVER['REQUEST_METHOD'] == 'POST' && isset($_FILES['resume'])) {
    $file = $_FILES['resume'];
    $fileName = $file['name'];
    $fileTmpName = $file['tmp_name'];
    $fileSize = $file['size'];
    $fileError = $file['error'];
    
    $fileExt = strtolower(pathinfo($fileName, PATHINFO_EXTENSION));
    
    if ($fileError === 0) {
        if ($fileExt === 'pdf') {
            if ($fileSize < 5000000) { // Limit: 5MB
                $uploadDir = 'uploads/';
                if (!is_dir($uploadDir)) {
                    mkdir($uploadDir, 0777, true);
                }
                $newFileName = uniqid('resume_', true) . '.pdf';
                $fileDestination = $uploadDir . $newFileName;
                
                if (move_uploaded_file($fileTmpName, $fileDestination)) {
                    $message = "Resume uploaded successfully!";
                } else {
                    $message = "Error moving the uploaded file.";
                }
            } else {
                $message = "File is too large! Maximum allowed size is 5MB.";
            }
        } else {
            $message = "Invalid file type! Only PDF files are allowed.";
        }
    } else {
        $message = "Error uploading file.";
    }
}
?>
<!DOCTYPE html>
<html>
<head>
    <title>Resume Upload</title>
</head>
<body>
    <h2>Upload Resume (PDF)</h2>
    <?php if ($message): ?>
        <p><strong><?php echo $message; ?></strong></p>
    <?php endif; ?>
    <form action="" method="POST" enctype="multipart/form-data">
        <label for="resume">Select PDF Resume:</label>
        <input type="file" name="resume" id="resume" accept=".pdf" required>
        <br><br>
        <button type="submit">Upload Resume</button>
    </form>
</body>
</html>