<!DOCTYPE html>
<html>
<head>
    <title>AJAX MySQL Search</title>
</head>
<body>

    <h2>Search Employee</h2>

    Enter Employee ID:
    <input type="text" id="empid" onkeyup="searchEmployee()">

    <button >Search</button>

    <p id="result"></p>

    <script>

        function searchEmployee(){

            var id = document.getElementById("empid").value;

            let xhr = new XMLHttpRequest();

            xhr.onreadystatechange = function(){

                if(xhr.readyState == 4 && xhr.status == 200){

                    let emp = JSON.parse(xhr.responseText);

                    if(emp === null){

                        document.getElementById("result").innerHTML =
                            "Employee Not Found!";

                    }
                    else{

                        document.getElementById("result").innerHTML =
                            "ID: " + emp.id +
                            "<br>Name: " + emp.name +
                            "<br>Department: " + emp.department +
                            "<br>Salary: " + emp.salary;

                    }

                }

            };

            xhr.open("POST", "search.php", true);

            xhr.setRequestHeader(
                "Content-type",
                "application/x-www-form-urlencoded"
            );

            xhr.send("id=" + encodeURIComponent(id));

        }

    </script>

</body>
</html>