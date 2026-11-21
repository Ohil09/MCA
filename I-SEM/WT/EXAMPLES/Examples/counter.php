<?php
session_start();

if (isset($_SESSION['page_views'])) {
    $_SESSION['page_views']++;
} else {
    $_SESSION['page_views'] = 1;
}
?>
<!DOCTYPE html>
<html>
<head>
    <title>Session Page Views Counter</title>
</head>
<body>
    <h2>Page Views Counter (Session-Based)</h2>
    <p>You have viewed this page <strong><?php echo $_SESSION['page_views']; ?></strong> times during this session.</p>
    <p><a href="">Refresh Page</a></p>
</body>
</html>