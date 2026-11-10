<!DOCTYPE html>
<html>
<body>

<h2>User Information</h2>

Name:
<input type="text" id="name"><br><br>

Age:
<input type="number" id="age"><br><br>

<button onclick="saveInfo()">Save</button>
<button onclick="displayInfo()">Display</button>

<p id="result"></p>

<script>

function saveInfo(){

    let name = document.getElementById("name").value;
    let age = document.getElementById("age").value;

    if(name.trim() == "" || age == ""){
        alert("Enter all details!");
        return;
    }

    document.cookie =
        "name=" + encodeURIComponent(name) +
        "; max-age=86400; path=/";

    document.cookie =
        "age=" + encodeURIComponent(age) +
        "; max-age=86400; path=/";

    alert("Information saved!");

}

function displayInfo(){

    let cookies = document.cookie.split("; ");

    let name = "";
    let age = "";

    cookies.forEach(function(c){

        let parts = c.split("=");

        if(parts[0] == "name"){
            name = decodeURIComponent(parts.slice(1).join("="));
        }

        if(parts[0] == "age"){
            age = decodeURIComponent(parts.slice(1).join("="));
        }

    });

    if(name != "" && age != ""){

        document.getElementById("result").innerHTML =
            "Name: " + name + "<br>Age: " + age;

    }
    else{
        document.getElementById("result").innerHTML =
            "User information not found!";
    }

}

</script>

</body>
</html>