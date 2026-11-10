<!DOCTYPE html>
<html>
<head>
    <title>Employee Search</title>
</head>
<body>

    <h2>Search Employees</h2>

    <input type="text" id="search" onkeyup="SendMessage()"
           placeholder="Enter Employee ID or Name">

    <div id="result"></div>

    <script>

        function SendMessage(){

            var x = document.getElementById("search").value;

            if(x.length == 0){
                document.getElementById("result").innerHTML = "";
                return;
            }

            let xhr = new XMLHttpRequest();

            xhr.onreadystatechange = function(){

                if(xhr.readyState == 4 && xhr.status == 200){

                    let employees = JSON.parse(xhr.responseText);

                    if(employees.length == 0){

                        document.getElementById("result").innerHTML =
                            "No employees found!";

                    }else{

                        let table = `
                            <table border="1" cellpadding="8">

                                <tr>
                                    <th>ID</th>
                                    <th>Name</th>
                                    <th>Department</th>
                                    <th>Salary</th>
                                </tr>
                        `;

                        for(let emp of employees){

                            table += `
                                <tr>
                                    <td>${emp.id}</td>
                                    <td>${emp.name}</td>
                                    <td>${emp.department}</td>
                                    <td>${emp.salary}</td>
                                </tr>
                            `;

                        }

                        table += "</table>";

                        document.getElementById("result").innerHTML = table;

                    }

                }
            };

            xhr.open("POST", "search.php", true);

            xhr.setRequestHeader(
                "Content-type",
                "application/x-www-form-urlencoded"
            );

            xhr.send("submit=" + encodeURIComponent(x));

        }

    </script>

</body>
</html>