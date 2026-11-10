<?php

include "db.php";

header("Content-Type: application/json");

$id = $_POST['id'] ?? '';

$sql = "SELECT * FROM employee WHERE id = '$id'";

$result = mysqli_query($conn, $sql);

if(mysqli_num_rows($result) > 0){

    $emp = mysqli_fetch_assoc($result);

    echo json_encode($emp);

}
else{

    echo json_encode(null);

}

?>