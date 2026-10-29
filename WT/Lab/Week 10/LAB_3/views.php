<?php
session_start();

if (isset($_SESSION["views"]))
    $_SESSION["views"]++;
else
    $_SESSION["views"] = 1;

echo "Page Views: " . $_SESSION["views"];
?>