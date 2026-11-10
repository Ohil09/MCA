<?php

if(isset($_POST['login'])){

    $username = $_POST['username'];
    $password = $_POST['password'];

    if($username == "admin" && $password == "123"){

        setcookie("username", $username, time() + 3600, "/");

        header("Location: home.php");
        exit();

    }
    else{

        echo "Invalid Username or Password!";

    }
}

?>

<!DOCTYPE html>
<html>
<head>
    <title>Cookie Login</title>
</head>
<body>

    <h2>Login Page</h2>

    <form method="POST">

        Username:
        <input type="text" name="username" required>
        <br><br>

        Password:
        <input type="password" name="password" required>
        <br><br>

        <button type="submit" name="login">Login</button>

    </form>

</body>
</html>