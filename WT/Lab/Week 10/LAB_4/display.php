<?php
$json = file_get_contents("employee.json");
$employees = json_decode($json, true);
?>

<!DOCTYPE html>
<html>
<head>
    <title>Employee Details</title>

    <style>
        body {
            font-family: Arial, sans-serif;
            background: #f2f2f2;
            text-align: center;
        }

        table {
            margin: 20px auto;
            border-collapse: collapse;
            width: 80%;
            background: white;
        }

        th, td {
            border: 1px solid #ccc;
            padding: 12px;
        }

        th {
            background: #007bff;
            color: white;
        }

        h2 {
            color: #333;
        }
    </style>
</head>

<body>

<h2>Employee Details</h2>

<table>
    <tr>
        <th>Employee ID</th>
        <th>Name</th>
        <th>Designation</th>
        <th>Department</th>
        <th>Salary</th>
    </tr>

    <?php
    foreach ($employees as $emp) {
        echo "<tr>";
        echo "<td>" . htmlspecialchars($emp["emp_id"]) . "</td>";
        echo "<td>" . htmlspecialchars($emp["name"]) . "</td>";
        echo "<td>" . htmlspecialchars($emp["designation"]) . "</td>";
        echo "<td>" . htmlspecialchars($emp["department"]) . "</td>";
        echo "<td>" . htmlspecialchars((string)$emp["salary"]) . "</td>";
        echo "</tr>";
    }
    ?>

</table>

</body>
</html>

