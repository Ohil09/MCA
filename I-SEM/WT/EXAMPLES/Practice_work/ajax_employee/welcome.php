<?php
    header("Content-type: application/json");

    $key = $_POST['submit'] ?? '';
    $file = "emp_ajax.json";
    $employees = json_decode(file_get_contents($file),true) ?? [];
    $dispEmp = null;
    foreach($employees as $emp){
        if((int)$emp["id"] == (int)$key){
            $dispEmp = $emp;
            break;
        }
    }
    echo json_encode($dispEmp);
?>