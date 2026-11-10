<?php
    $file = "emp.json";
    if(!file_exists($file)){
        file_put_contents($file,json_encode([], JSON_PRETTY_PRINT));
    }
    if(isset($_POST['submit'])){
        $id = $_REQUEST["id"];
        $name = $_REQUEST["name"];
        $dept = $_REQUEST["dept"];
        $sal = $_REQUEST["salary"];
        $employees = json_decode(file_get_contents($file), true) ?? [];
        $employees[] =[
            "id" => $id,
            "name" => $name,
            "dept" =>$dept,
            "salary" =>$sal
        ];
        
        file_put_contents($file, json_encode($employees,JSON_PRETTY_PRINT));
        header("Location: ". $_SERVER['PHP_SELF']."?msg=inserted");
        exit;
    }
    if(isset($_POST['reset'])){
        file_put_contents($file,json_encode([], JSON_PRETTY_PRINT));
        header("Location: ". $_SERVER['PHP_SELF']."?msg=cleared");
        exit;
    }

    // UPDATE: save the edited details
    if(isset($_POST['update'])){
        $employees = json_decode(file_get_contents($file), true) ?? [];
        $found = false;

        for($i = 0; $i < count($employees); $i++){
            if((int)$employees[$i]['id'] == (int)$_POST['id']){
                $employees[$i]['name'] = $_POST['name'];
                $employees[$i]['dept'] = $_POST['dept'];
                $employees[$i]['salary'] = $_POST['salary'];
                $found = true;
                break;
            }
        }

        if($found){
            file_put_contents($file, json_encode($employees, JSON_PRETTY_PRINT));
            header("Location: ". $_SERVER['PHP_SELF']."?msg=updated");
        } else {
            header("Location: ". $_SERVER['PHP_SELF']."?msg=updatefail");
        }
        exit;
    }

    $SearchEmp = null;

    if(isset($_POST['search'])){

        $employees = json_decode(file_get_contents($file), true) ?? [];

        $key = $_POST['key'];

        foreach($employees as $emp){

            if((int)$emp['id'] == (int)$key){

                $SearchEmp = $emp;
                break;

            }
        }
    }

    // UPDATE: load the old details of the employee to edit
    $UpdateEmp = null;

    if(isset($_POST['load'])){

        $employees = json_decode(file_get_contents($file), true) ?? [];

        $ukey = $_POST['ukey'];

        for($i = 0; $i < count($employees); $i++){

            if((int)$employees[$i]['id'] == (int)$ukey){

                $UpdateEmp = $employees[$i];
                break;

            }
        }
    }
    
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Employee</title>
    <style>
        *{
            box-sizing: border-box;
        }
        body{
            margin :0;
            padding: 0;
            display: flex;
            flex-direction: column;
            justify-content: center;
            align-items: center;
        }
        .container{
            display: flex;
            flex-direction: column;
            justify-content: center;
            align-items: center;
        }
        .forms{
            display: flex;
            flex-wrap: wrap;
            justify-content: center;
            align-items: flex-start;
            gap: 20px;
        }
        .col{
            display: flex;
            flex-direction: column;
            align-items: center;
            gap: 10px;
        }
        form{
            min-height: 300px;
            width: 300px;
            display: grid;
            justify-content: center;
            align-items: center;
            gap: 20px;
            border: 1px solid black;
            border-radius: 20px;
            padding: 10px;
            
        }
    </style>
</head>
<body>
    <div class = "container">
        <h1>Employee form</h1>
        <?php
            if(isset($_GET['msg'])){
                if($_GET['msg'] == "inserted") echo"<p>Inserted new employee successfully!</p>";
                if($_GET['msg'] == "cleared") echo"<p>All employees cleared!</p>";
                if($_GET['msg'] == "notfound") echo"<p>No search emp ID to find!</p>";
                if($_GET['msg'] == "updated") echo"<p>Employee updated successfully!</p>";
                if($_GET['msg'] == "updatefail") echo"<p>Employee to update was not found!</p>";
            }
        ?>

        <div class="forms">

            <!-- INSERT -->
            <div class="col">
                <h2>Insert Employee</h2>
                <form action="" method = "POST">
                    <div class ="row">
                    ID <input type="number" name="id" required>
                    </div>
                    <div class ="row">
                    Name <input type="text" name="name" required>
                    </div>
                    <div class ="row">
                    Department <input type="text" name="dept" required>
                    </div>
                    <div class ="row">
                    Salary <input type="number" name="salary" required>
                    </div>
                    <div class ="row">
                    <input type="submit" name="submit" value = "submit">
                    </div>
                    <div class ="row">
                    <button name = "reset" formnovalidate >Reset</button > 
                    </div>
                </form>
            </div>

            <!-- SEARCH -->
            <div class="col">
                <h2>Search Employee</h2>
                <form method="POST">

                    Enter Employee ID:
                    <input type="number" name="key" >

                    <input type="submit" name="search" value="Search">

                </form>
            </div>

            <!-- UPDATE -->
            <div class="col">
                <h2>Update Employee</h2>
                <form method="POST">

                    Enter Employee ID:
                    <input type="number" name="ukey" required>

                    <input type="submit" name="load" value="Load">

                </form>

                <?php
                if (isset($_POST['load'])) {

                    if ($UpdateEmp != null) {
                ?>
                        <form method="POST">
                            <div class="row">
                            ID <input type="number" name="id" value="<?php echo htmlspecialchars($UpdateEmp['id']); ?>" readonly>
                            </div>
                            <div class="row">
                            Name <input type="text" name="name" value="<?php echo htmlspecialchars($UpdateEmp['name']); ?>" required>
                            </div>
                            <div class="row">
                            Department <input type="text" name="dept" value="<?php echo htmlspecialchars($UpdateEmp['dept']); ?>" required>
                            </div>
                            <div class="row">
                            Salary <input type="number" name="salary" value="<?php echo htmlspecialchars($UpdateEmp['salary']); ?>" required>
                            </div>
                            <div class="row">
                            <input type="submit" name="update" value="Update">
                            </div>
                        </form>
                <?php
                    } else {
                        echo "<h3>Employee Not Found!</h3>";
                    }
                }
                ?>
            </div>

        </div>

        <h2>Search Result</h2>

        <?php
        if (isset($_POST['search'])) {

            if ($SearchEmp != null) {

                echo "<table border='1' cellpadding='10'>";

                echo "<tr>";
                echo "<th>ID</th>";
                echo "<th>Name</th>";
                echo "<th>Department</th>";
                echo "<th>Salary</th>";
                echo "</tr>";

                echo "<tr>";
                echo "<td>" . htmlspecialchars($SearchEmp['id']) . "</td>";
                echo "<td>" . htmlspecialchars($SearchEmp['name']) . "</td>";
                echo "<td>" . htmlspecialchars($SearchEmp['dept']) . "</td>";
                echo "<td>" . htmlspecialchars($SearchEmp['salary']) . "</td>";
                echo "</tr>";

                echo "</table>";

            } else {

                echo "<h3>Employee Not Found!</h3>";

            }
        }
        ?>
        <h1>Employee Details</h1>
        <table border="1" cellpadding="10">
            <tr>
                <th>ID</th>
                <th>Name</th>
                <th>Department</th>
                <th>Salary</th>
            </tr>
            <?php
            $json = file_get_contents($file);
            $employees = json_decode($json,true);
            foreach($employees as $employee){
            echo "<tr>";
                echo"<td>".htmlspecialchars($employee['id'])."</td>";
                echo"<td>".htmlspecialchars($employee['name'])."</td>";
                echo"<td>".htmlspecialchars($employee['dept'])."</td>";
                echo"<td>".htmlspecialchars($employee['salary'])."</td>";
            echo"</tr>";
            }
            ?>
        </table>
        
    </div>
</body>
</html>