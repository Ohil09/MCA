<!DOCTYPE html>
<html>
<head>
    <title>Employee Details</title>
</head>
<body>
    <h2>Employee Details</h2>

    <table border="1" cellpadding="8">
        <tr>
            <th>ID</th>
            <th>Name</th>
            <th>Department</th>
            <th>Salary</th>
        </tr>

        <?php
        $json = file_get_contents('employees.json');
        $employees = json_decode($json, true);

        if (is_array($employees)) {
            foreach ($employees as $emp) {
                echo "<tr>";
                echo "<td>" . htmlspecialchars((string)$emp['id']) . "</td>";
                echo "<td>" . htmlspecialchars($emp['name']) . "</td>";
                echo "<td>" . htmlspecialchars($emp['department']) . "</td>";
                echo "<td>" . htmlspecialchars((string)$emp['salary']) . "</td>";
                echo "</tr>";
            }
        } else {
            echo "<tr><td colspan='4'>Unable to read employee data.</td></tr>";
        }
        ?>
    </table>
</body>
</html>