<?php
$conn = mysqli_connect("localhost", "root", "", "employee_db");
if(!$conn){
    die("Connection failed ". mysqli_connect_error());
}
if(isset($_POST['insert'])){
    $id = $_POST['emp_id'];
    $name = $_POST['name'];
    $dept = $_POST['department'];
    $salary = $_POST['salary'];
    $email = $_POST['email'];

    $sql = "INSERT INTO employee VALUES (?,?,?,?,?);";
    $stmt = mysqli_prepare($conn, $sql);
    mysqli_stmt_bind_param($stmt, "issds", $id, $name,$dept, $salary, $email);
    if(mysqli_stmt_execute($stmt)){
        echo "Inserted successfully !";
    }else{
        echo "Error : ".mysqli_error($conn);
    }
    mysqli_stmt_close($stmt);
}

?>
<!DOCTYPE html>
<html>

<head>
    <title>Employee CRUD</title>
</head>

<body>

    <h2>Employee Management System</h2>

    <!-- INSERT / UPDATE FORM -->

    

    <form method="POST">

        Employee ID:
        <input type="number" name="emp_id" required>
        <br><br>

        Name:
        <input type="text" name="name"required>
        <br><br>

        Department:
        <input type="text" name="department"  required>
        <br><br>

        Salary:
        <input type="number" step="10" name="salary"  required>
        <br><br>

        Email:
        <input type="email" name="email" >
        <br><br>

        <button type="submit" name="insert">Insert Employee</button>


    </form>

    <hr>

    <!-- DISPLAY OPERATION -->

    <h3>Employee Details</h3>

    <table border="1" cellpadding="10">

        <tr>
            <th>ID</th>
            <th>Name</th>
            <th>Department</th>
            <th>Salary</th>
            <th>Email</th>
            <th>Action</th>
        </tr>
        <?php
            $sql = "SELECT * from employee";
            $res = mysqli_query($conn,$sql);
            while($row = mysqli_fetch_assoc($res)){
        ?>
        <tr>
            <td><?php echo htmlspecialchars($row['emp_id']); ?></td>
            <td><?php echo htmlspecialchars($row['name']); ?></td>
            <td><?php echo htmlspecialchars($row['department']); ?></td>
            <td><?php echo htmlspecialchars($row['salary']); ?></td>
            <td><?php echo htmlspecialchars($row['email'] ?? ''); ?></td>

            <td>
        </tr>
        <?php } ?>
</table>
</body>
</html>