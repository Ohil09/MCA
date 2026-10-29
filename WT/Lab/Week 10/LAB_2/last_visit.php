<?php
date_default_timezone_set("Asia/Kolkata");

if (isset($_COOKIE["lastvisit"])) {
    echo "Last Visit: " . $_COOKIE["lastvisit"] . "<br>";
} else {
    echo "Welcome! This is your first visit.<br>";
}

setcookie("lastvisit", date("d-m-Y h:i:s A"), time() + 86400, "/");
?>