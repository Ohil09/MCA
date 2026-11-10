<?php
$file = "student.json";
// $data = [
//     "id"=>101,
//     "name"=>"ohil",
//     "department"=>"IT"
// ];
// $json = json_encode($data, JSON_PRETTY_PRINT);
// file_put_contents($file,$json);
// echo "JSON file created successfully!";


$json = file_get_contents($file);
$students = json_decode($json,true);
$newStudent = [
    "id"=>103,
    "name"=>"sajan",
    "department"=>"Lauda"
];
$students[] = $newStudent;
$json = json_encode($students, JSON_PRETTY_PRINT);
file_put_contents($file,$json);
echo"New value added successfully!";

?>