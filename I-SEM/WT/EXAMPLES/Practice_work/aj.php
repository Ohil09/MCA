<!DOCTYPE html>
<html>
<head>
    <title>PHP AJAX Example</title>
</head>
<body>

    <h2>PHP AJAX Example</h2>
    <input type = "text" id = "name" onkeyup="SendMessage()">
    

    <p id="result"></p>

    <script>
        
        function SendMessage(){
            var x = document.getElementById("name").value;
            if(x.length == 0){
                document.getElementById("result").innerHTML = "";
                return;
            }
            let xhr = new XMLHttpRequest();
            xhr.onreadystatechange = function(){
                if(xhr.readyState == 4 && xhr.status == 200){
                    document.getElementById("result").innerHTML = xhr.responseText;
                }
            };
            xhr.open("POST","welcome.php",true);
            xhr.setRequestHeader(
                "Content-type",
                "application/x-www-form-urlencoded"
            );
            xhr.send("submit=" + encodeURIComponent(x));
        }
    </script>

</body>
</html>