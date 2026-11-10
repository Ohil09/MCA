<?php

// DATABASE CONNECTION

$conn = mysqli_connect("localhost", "root", "", "employee_db");

if (!$conn) {
    die("Connection Failed: " . mysqli_connect_error());
}

// INSERT OPERATION

if (isset($_POST['insert'])) {

    $id = $_POST['emp_id'];
    $name = $_POST['name'];
    $dept = $_POST['department'];
    $salary = $_POST['salary'];
    $email = $_POST['email'];

    $sql = "INSERT INTO employee VALUES (?, ?, ?, ?, ?)";

    $stmt = mysqli_prepare($conn, $sql);
    mysqli_stmt_bind_param($stmt, "issds", $id, $name, $dept, $salary, $email);

    if (mysqli_stmt_execute($stmt)) {
        echo "Employee Inserted Successfully!";
    } else {
        echo "Error: " . mysqli_error($conn);
    }

    mysqli_stmt_close($stmt);
}

// DELETE OPERATION

if (isset($_GET['delete'])) {

    $id = $_GET['delete'];

    $sql = "DELETE FROM employee WHERE emp_id = ?";

    $stmt = mysqli_prepare($conn, $sql);
    mysqli_stmt_bind_param($stmt, "i", $id);

    if (mysqli_stmt_execute($stmt)) {
        echo "Employee Deleted Successfully!";
    }

    mysqli_stmt_close($stmt);
}

// UPDATE OPERATION

if (isset($_POST['update'])) {

    $id = $_POST['emp_id'];
    $name = $_POST['name'];
    $dept = $_POST['department'];
    $salary = $_POST['salary'];
    $email = $_POST['email'];

    $sql = "UPDATE employee
            SET name = ?, department = ?, salary = ?, email = ?
            WHERE emp_id = ?";

    $stmt = mysqli_prepare($conn, $sql);
    mysqli_stmt_bind_param($stmt, "ssdsi", $name, $dept, $salary, $email, $id);

    if (mysqli_stmt_execute($stmt)) {
        echo "Employee Updated Successfully!";
    }
     header("Location: ".$_SERVER['PHP_SELF']);
    mysqli_stmt_close($stmt);
}

// FETCH EMPLOYEE FOR EDITING

$editEmp = null;

if (isset($_GET['edit'])) {

    $id = $_GET['edit'];

    $sql = "SELECT * FROM employee WHERE emp_id = ?";

    $stmt = mysqli_prepare($conn, $sql);
    mysqli_stmt_bind_param($stmt, "i", $id);
    mysqli_stmt_execute($stmt);

    $result = mysqli_stmt_get_result($stmt);

    $editEmp = mysqli_fetch_assoc($result);

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

    <h3>
        <?php echo ($editEmp != null) ? "Update Employee" : "Add Employee"; ?>
    </h3>

    <form method="POST">

        Employee ID:
        <input type="number" name="emp_id" value="<?php echo $editEmp['emp_id'] ?? ''; ?>"
            <?php echo ($editEmp != null) ? 'readonly' : ''; ?> required>
        <br><br>

        Name:
        <input type="text" name="name" value="<?php echo $editEmp['name'] ?? ''; ?>" required>
        <br><br>

        Department:
        <input type="text" name="department" value="<?php echo $editEmp['department'] ?? ''; ?>" required>
        <br><br>

        Salary:
        <input type="number" step="10" name="salary" value="<?php echo $editEmp['salary'] ?? ''; ?>" required>
        <br><br>

        Email:
        <input type="email" name="email" value="<?php echo $editEmp['email'] ?? ''; ?>">
        <br><br>

        <?php if ($editEmp != null) { ?>

        <button type="submit" name="update">Update Employee</button>

        <?php } else { ?>

        <button type="submit" name="insert">Insert Employee</button>

        <?php } ?>

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

        $sql = "SELECT * FROM employee";

        $result = mysqli_query($conn, $sql);

        while ($row = mysqli_fetch_assoc($result)) {

            ?>

        <tr>

            <td><?php echo htmlspecialchars($row['emp_id']); ?></td>
            <td><?php echo htmlspecialchars($row['name']); ?></td>
            <td><?php echo htmlspecialchars($row['department']); ?></td>
            <td><?php echo htmlspecialchars($row['salary']); ?></td>
            <td><?php echo htmlspecialchars($row['email'] ?? ''); ?></td>

            <td>

                <a href="prog_2.php?edit=<?php echo $row['emp_id']; ?>">
                    Edit
                </a>

                |

                <a href="prog_2.php?delete=<?php echo $row['emp_id']; ?>"
                    onclick="return confirm('Are you sure you want to delete?')">
                    Delete
                </a>

            </td>

        </tr>

        <?php } ?>

    </table>

</body>

</html>

<?php

mysqli_close($conn);

?>