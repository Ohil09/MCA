<?php
$employees = array(
    array("id" => 101, "name" => "Alice", "department" => "IT"),
    array("id" => 102, "name" => "Bob", "department" => "HR"),
    array("id" => 103, "name" => "Charlie", "department" => "Sales"),
    array("id" => 104, "name" => "David", "department" => "Finance"),
    array("id" => 105, "name" => "Emma", "department" => "Marketing")
);

$name = strtolower(trim($_GET["name"] ?? ""));
$found = false;

foreach ($employees as $emp) {
    if ($name != "" &&
        strpos(strtolower($emp["name"]), $name) !== false) {

        echo "ID: " . $emp["id"] . "<br>";
        echo "Name: " . htmlspecialchars($emp["name"]) . "<br>";
        echo "Department: " . htmlspecialchars($emp["department"]) . "<br><hr>";

        $found = true;
    }
}

if (!$found) {
    echo "No employee found.";
}
?>
