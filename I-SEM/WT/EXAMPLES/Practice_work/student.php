<?php
$file = "stud.json";
if(!file_exists($file)){
    file_put_contents($file,json_encode([],JSON_PRETTY_PRINT));
}
if(isset($_POST['submit'])){
    $students = json_decode(file_get_contents($file),true) ?? [];
    $students[] = [
        "name" => $_POST['name'],
        "roll" => $_POST['roll'],
        "sub" => $_POST['sub'],
        "marks" => $_POST['marks'],
    ];
    file_put_contents($file, json_encode($students,JSON_PRETTY_PRINT));
    header("Location: ".$_SERVER['PHP_SELF']);
    exit;
}
if(isset($_POST['reset'])){
    file_put_contents($file, json_encode([], JSON_PRETTY_PRINT));
    header("Location: ".$_SERVER['PHP_SELF']);
    exit;
}
if(isset($_POST['del'])){
    $students = json_decode(file_get_contents($file),true) ?? [];
    $key = $_POST['delRoll'];
    foreach($students as $i => $stud){
        if((int)$stud['roll'] == (int)$key){
            unset($students[$i]);
            break;

        }
    }
    $students = array_values($students);
    file_put_contents($file, json_encode($students,JSON_PRETTY_PRINT));
    header("Location: ".$_SERVER['PHP_SELF']);
    exit;
}
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Student</title>
    <style>
        *{
            box-sizing: border-box;
        }
        body{
            margin:0;
            display: flex;
            flex-direction: column;
            justify-content: center;
            align-items: center;
            gap:20px;
        }
        form{
            padding: 20px;
            border: 1px solid black;
            border-radius: 20px;
            display: flex;
            flex-direction: column;
            justify-content: center;
            align-items: center;
            gap:20px;
        }
        table{
            border-collapse: collapse;
        }
    </style>
</head>
<body>
    <h1>Student form</h1>
    <form action="" method="POST">
        <div class="row" >Name <input type="text" name ="name" required></div>
        <div class="row" >Roll no <input type="number" name ="roll" required></div>
        <div class="row" >Subject <input type="text" name ="sub" required></div>
        <div class="row" >Marks <input type="number" name ="marks" required></div>
        <div class="row" ><input type = "submit" name="submit" value="Insert"></div>
        <div class="row" ><button name="reset" formnovalidate >Clear</button></div>
    </form>
    <table border="1" cellpadding = "10">
        <tr>
            <th>Name</th>
            <th>Roll no</th>
            <th>Subject</th>
            <th>Marks</th>
        </tr>
    <?php
    $students = json_decode(file_get_contents($file),true) ?? [];
    foreach($students as $stud){
        echo "<tr>";
        echo "<td>".htmlspecialchars($stud['name'])."</td>";
        echo "<td>".htmlspecialchars($stud['roll'])."</td>";
        echo "<td>".htmlspecialchars($stud['sub'])."</td>";
        echo "<td>".htmlspecialchars($stud['marks'])."</td>";
        echo "</tr>";
    }
    ?>
    </table>
     <form action="" method="POST">
        <div class="row" >Enter roll no to delete <input type="number" name ="delRoll" required></div>
        <div class="row" ><input type = "submit" name="del" value="Delete"></div>
    </form>
    
</body>
</html>