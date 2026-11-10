<?php

$conn = mysqli_connect("localhost", "root", "", "ajax_db");
if(!$conn){
    die("Connection failed !". mysqli_connect_error());
}

?>