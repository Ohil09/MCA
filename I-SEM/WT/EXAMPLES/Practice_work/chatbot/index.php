<?php

$file = "messages.json";

// LOAD MESSAGES
if(isset($_GET["action"]) && $_GET["action"] == "load"){

    header("Content-Type: application/json");

    if(file_exists($file)){
        echo file_get_contents($file);
    }
    else{
        echo "[]";
    }

    exit();
}


// SEND MESSAGE
if(isset($_POST["action"]) && $_POST["action"] == "send"){

    header("Content-Type: application/json");

    $messages = [];

    if(file_exists($file)){
        $messages = json_decode(file_get_contents($file), true);
    }

    $user = $_POST["user"];
    $message = trim($_POST["message"]);

    if(($user == "User 1" || $user == "User 2") && $message != ""){

        $newMessage = [
            "user" => $user,
            "message" => $message,
            "time" => date("h:i A")
        ];

        $messages[] = $newMessage;

        file_put_contents(
            $file,
            json_encode($messages, JSON_PRETTY_PRINT),
            LOCK_EX
        );

        echo json_encode(["status" => "success"]);

    }
    else{
        echo json_encode(["status" => "error"]);
    }

    exit();
}

?>

<!DOCTYPE html>
<html>

<head>

    <title>JSON Chat Application</title>

    <style>

        body{
            font-family: Arial;
            text-align: center;
        }

        #chatbox{
            width: 400px;
            height: 350px;
            border: 1px solid black;
            margin: auto;
            padding: 10px;
            overflow-y: auto;
        }

        .message{
            padding: 10px;
            margin: 8px;
            border-radius: 8px;
            text-align: left;
        }

        .own{
            background-color: lightgreen;
        }

        .other{
            background-color: lightcoral;
        }

        img{
            width: 35px;
            height: 35px;
            border-radius: 50%;
            vertical-align: middle;
            object-fit: cover;
        }

    </style>

</head>

<body>

    <h2>Two User Chat Application</h2>

    <label>Select User:</label>

    <select id="currentUser" onchange="loadMessages()">
        <option value="User 1">User 1</option>
        <option value="User 2">User 2</option>
    </select>

    <br><br>

    <label>Set Profile Picture:</label>

    <input type="file" id="profilePic" accept="image/*"
           onchange="setProfile()">

    <br><br>

    <div id="chatbox"></div>

    <br>

    <input type="text" id="message" placeholder="Enter message">

    <button onclick="sendMessage()">Send</button>


    <script>

        // PROFILE PICTURE HANDLING

        function setProfile(){

            let user = document.getElementById("currentUser").value;

            let file = document.getElementById("profilePic").files[0];

            if(file){

                if(!file.type.startsWith("image/")){
                    alert("Please select an image!");
                    return;
                }

                let reader = new FileReader();

                reader.onload = function(){

                    localStorage.setItem(user, reader.result);

                    loadMessages();

                };

                reader.readAsDataURL(file);

            }

        }


        // SEND MESSAGE

        function sendMessage(){

            let user = document.getElementById("currentUser").value;

            let msg = document.getElementById("message").value;

            if(msg.trim() == ""){
                alert("Enter a message!");
                return;
            }

            let xhr = new XMLHttpRequest();

            xhr.open("POST", "index.php", true);

            xhr.setRequestHeader(
                "Content-Type",
                "application/x-www-form-urlencoded"
            );

            xhr.onload = function(){

                if(xhr.status == 200){

                    loadMessages();

                    document.getElementById("message").value = "";

                }

            };

            xhr.send(
                "action=send&user=" + encodeURIComponent(user) +
                "&message=" + encodeURIComponent(msg)
            );

        }


        // LOAD AND DISPLAY MESSAGES

        function loadMessages(){

            let user = document.getElementById("currentUser").value;

            let xhr = new XMLHttpRequest();

            xhr.open("GET", "index.php?action=load", true);

            xhr.onload = function(){

                if(xhr.status == 200){

                    let messages = JSON.parse(xhr.responseText);

                    let chatbox = document.getElementById("chatbox");

                    chatbox.innerHTML = "";

                    messages.forEach(function(m){

                        let div = document.createElement("div");

                        div.className = "message " +
                            (m.user == user ? "own" : "other");

                        let img = document.createElement("img");

                        img.src = localStorage.getItem(m.user) ||
                                  "https://via.placeholder.com/35";

                        let name = document.createElement("b");

                        name.textContent = " " + m.user + ": ";

                        let text = document.createElement("span");

                        text.textContent = m.message;

                        let time = document.createElement("small");

                        time.textContent = " (" + m.time + ")";

                        div.appendChild(img);
                        div.appendChild(name);
                        div.appendChild(text);
                        div.appendChild(time);

                        chatbox.appendChild(div);

                    });

                    chatbox.scrollTop = chatbox.scrollHeight;

                }

            };

            xhr.send();

        }


        // LOAD MESSAGES WHEN PAGE OPENS

        window.onload = loadMessages;

    </script>

</body>

</html>