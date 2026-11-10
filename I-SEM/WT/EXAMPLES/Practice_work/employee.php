<?php
    $file = "emp.json";
    if(!file_exists($file)){
        file_put_contents($file, "[]");
    }

    function loadEmployees($file){
        return json_decode(file_get_contents($file), true) ?? [];
    }
    function saveEmployees($file, $employees){
        file_put_contents($file, json_encode($employees, JSON_PRETTY_PRINT));
    }
    function redirect($msg){
        header("Location: " . $_SERVER['PHP_SELF'] . "?msg=" . $msg);
        exit;
    }
    function renderTable($rows, $withActions = false){
        echo "<table><tr><th>ID</th><th>Name</th><th>Department</th><th>Salary</th>";
        if($withActions) echo "<th>Action</th>";
        echo "</tr>";
        foreach($rows as $e){
            echo "<tr>";
            foreach(['id','name','dept','salary'] as $k){
                echo "<td>" . htmlspecialchars($e[$k]) . "</td>";
            }
            if($withActions){
                echo "<td><a href='?edit=" . urlencode($e['id']) . "'>Edit</a></td>";
            }
            echo "</tr>";
        }
        echo "</table>";
    }

    // INSERT or UPDATE
    if(isset($_POST['submit'])){
        $employees = loadEmployees($file);
        $editId = $_POST['edit_id'] ?? '';
        $data = [
            "id"     => $_POST['id'],
            "name"   => $_POST['name'],
            "dept"   => $_POST['dept'],
            "salary" => $_POST['salary']
        ];

        if($editId !== ''){
            foreach($employees as &$emp){
                if((int)$emp['id'] === (int)$editId){
                    $emp['name']   = $data['name'];
                    $emp['dept']   = $data['dept'];
                    $emp['salary'] = $data['salary'];
                    break;
                }
            }
            unset($emp);
            $msg = "updated";
        } else {
            foreach($employees as $emp){
                if((int)$emp['id'] === (int)$data['id']) redirect("duplicate");
            }
            $employees[] = $data;
            $msg = "inserted";
        }

        saveEmployees($file, $employees);
        redirect($msg);
    }

    // RESET
    if(isset($_POST['reset'])){
        saveEmployees($file, []);
        redirect("cleared");
    }

    $employees = loadEmployees($file);

    // SEARCH
    $searched  = isset($_POST['search']);
    $SearchEmp = null;
    if($searched){
        foreach($employees as $emp){
            if((int)$emp['id'] === (int)$_POST['key']){
                $SearchEmp = $emp;
                break;
            }
        }
    }

    // EDIT MODE
    $editEmp = null;
    if(isset($_GET['edit'])){
        foreach($employees as $emp){
            if((int)$emp['id'] === (int)$_GET['edit']){
                $editEmp = $emp;
                break;
            }
        }
    }

    $messages = [
        "inserted"  => "Employee added.",
        "updated"   => "Employee updated.",
        "cleared"   => "All employees cleared.",
        "duplicate" => "That ID already exists."
    ];
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Employee</title>
    <style>
        body {
            font-family: sans-serif;
            max-width: 600px;
            margin: 0 auto;
            padding: 20px;
        }
        form {
            display: grid;
            grid-template-columns: 100px 1fr;
            gap: 10px;
            align-items: center;
            border: 1px solid #ccc;
            border-radius: 8px;
            padding: 16px;
            margin-bottom: 20px;
        }
        form.inline {
            display: flex;
            gap: 10px;
        }
        .actions {
            grid-column: 1 / -1;
            display: flex;
            gap: 10px;
            align-items: center;
        }
        table {
            border-collapse: collapse;
            width: 100%;
        }
        th, td {
            border: 1px solid #ccc;
            padding: 8px;
            text-align: left;
        }
        .msg {
            background: #eef;
            padding: 8px 12px;
            border-radius: 4px;
        }
    </style>
</head>
<body>
    <h1><?= $editEmp ? "Edit Employee" : "Add Employee" ?></h1>

    <?php
        if(isset($_GET['msg'], $messages[$_GET['msg']])){
            echo "<p class='msg'>" . $messages[$_GET['msg']] . "</p>";
        }
    ?>

    <form method="POST">
        <input type="hidden" name="edit_id" value="<?= htmlspecialchars($editEmp['id'] ?? '') ?>">

        <label for="id">ID</label>
        <input type="number" id="id" name="id" required
               value="<?= htmlspecialchars($editEmp['id'] ?? '') ?>"
               <?= $editEmp ? 'readonly' : '' ?>>

        <label for="name">Name</label>
        <input type="text" id="name" name="name" required
               value="<?= htmlspecialchars($editEmp['name'] ?? '') ?>">

        <label for="dept">Department</label>
        <input type="text" id="dept" name="dept" required
               value="<?= htmlspecialchars($editEmp['dept'] ?? '') ?>">

        <label for="salary">Salary</label>
        <input type="number" id="salary" name="salary" required
               value="<?= htmlspecialchars($editEmp['salary'] ?? '') ?>">

        <div class="actions">
            <input type="submit" name="submit" value="<?= $editEmp ? 'Update' : 'Submit' ?>">
            <?php if($editEmp): ?>
                <a href="<?= htmlspecialchars($_SERVER['PHP_SELF']) ?>">Cancel</a>
            <?php endif; ?>
            <button type="submit" name="reset" formnovalidate
                    onclick="return confirm('Delete ALL employees?')">Reset</button>
        </div>
    </form>

    <h2>Search Employee</h2>
    <form method="POST" class="inline">
        <input type="number" name="key" placeholder="Employee ID" required>
        <input type="submit" name="search" value="Search">
    </form>

    <?php
        if($searched){
            if($SearchEmp) renderTable([$SearchEmp]);
            else echo "<p>Employee not found.</p>";
        }
    ?>

    <h2>Employee Details</h2>
    <?php
        if($employees) renderTable($employees, true);
        else echo "<p>No employees yet.</p>";
    ?>
</body>
</html>