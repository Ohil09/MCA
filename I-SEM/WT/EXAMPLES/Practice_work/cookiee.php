<?php
if(isset($_COOKIE["lastvisit"])){
    echo "Last visit : ".$_COOKIE["lastvisit"]."<br>";
}else{
    echo "Welcome! This is your first time logging in!";
}
setcookie("lastvisit",date("d-m-Y h:i:s A"), time() + (30* 24 * 60 * 60), "/");
?>