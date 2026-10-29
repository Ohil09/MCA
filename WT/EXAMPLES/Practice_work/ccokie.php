<?php
$cookie_name = "user";
$cookie_value = 2;
?>
<html>
    <body>
        <?php
            if ( isset( $_COOKIE[ $cookie_name ] ) ) {
                setCookie($cookie_name, $cookie_value, time() + (86400 * 30), "/" );
            }else{
                $new_cookie = $COOKIE[$cookie_name] + 1;
                setCookie( $cookie_name, $new_cookie_value, time() + (86400 * 30), "/" );
                echo"Cookie : ". $cookie_name ."Is set !";
                echo "Cookie values is : ".$_COOKIE[$cookie_name];
            }
        ?>
    </body>
</html>