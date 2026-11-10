<?php

if(!isset($_COOKIE['username'])){

    header("Location: login.php");
    exit();

}

?>

<!DOCTYPE html>
<html>
<head>
    <title>Home</title>
</head>
<body>

    <h2>Welcome, <?php echo htmlspecialchars($_COOKIE['username']); ?>!</h2>

    <p>You have successfully logged in.</p>

    <a href="logout.php">Logout</a>

</body>
</html>