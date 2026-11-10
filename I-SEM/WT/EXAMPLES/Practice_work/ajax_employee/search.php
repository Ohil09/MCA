<?php

header("Content-Type: application/json");

$key = $_POST['submit'] ?? '';

$file = __DIR__ . "/emp_ajax.json";

$employees = json_decode(file_get_contents($file), true) ?? [];

$dispEmp = [];

foreach($employees as $emp){

    if((string)$emp['id'] == $key ||
       stripos($emp['name'], $key) !== false){

        $dispEmp[] = $emp;

    }

}

echo json_encode($dispEmp);

?>