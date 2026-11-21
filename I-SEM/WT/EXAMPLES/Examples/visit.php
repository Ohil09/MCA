<?php
$cookie_name = "last_visit";
$current_time = date("Y-m-d H:i:s");

if (isset($_COOKIE[$cookie_name])) {
    $last_visit = $_COOKIE[$cookie_name];
} else {
    $last_visit = "First time visiting!";
}

// Set cookie to expire in 30 days
setcookie($cookie_name, $current_time, time() + (86400 * 30), "/");
?>
<!DOCTYPE html>
<html>
<head>
    <title>Last Visit Tracker</title>
</head>
<body>
    <h2>Welcome to our website!</h2>
    <p>Your last visit was: <strong><?php echo htmlspecialchars($last_visit); ?></strong></p>
    <p>Current visit time: <?php echo $current_time; ?></p>
</body>
</html>