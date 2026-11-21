<?php
header('Content-Type: application/json; charset=utf-8');

$query = trim($_GET['q'] ?? '');
$json = file_get_contents('employees.json');
$employees = json_decode($json, true);

$results = [];

if (is_array($employees) && $query !== '') {
    foreach ($employees as $emp) {
        if (
            stripos((string)$emp['id'], $query) !== false ||
            stripos($emp['name'], $query) !== false ||
            stripos($emp['department'], $query) !== false
        ) {
            $results[] = $emp;
        }
    }
}

echo json_encode($results);
?>