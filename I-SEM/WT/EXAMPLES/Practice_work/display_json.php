<?php
    $json = file_get_contents("student.json");
    $students = json_decode($json, true);
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>JSON</title>
</head>
<body>
    <h1>Student details</h1>
    <table border ="1" cellpadding="10">
        <tr>
            <th>ID</th>
            <th>Name</th>
            <th>Department</th>
        </tr>
        <?php
            foreach($students as $student){
                echo"<tr>";
                echo "<td>".htmlspecialchars($student['id'])."</td>";
                echo "<td>".htmlspecialchars($student['name'])."</td>";
                echo "<td>".htmlspecialchars($student['department'])."</td>";
                echo"</tr>";
            }
        ?>
    </table>
</body>
</html>