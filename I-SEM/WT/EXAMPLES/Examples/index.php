<!DOCTYPE html>
<html>
<head>
    <title>AJAX Employee Search</title>
</head>
<body>
    <h2>Search Employee</h2>

    <input type="text" id="search"
           placeholder="Enter name, ID or department">

    <div id="result"></div>

    <script>
        const search = document.getElementById('search');
        const result = document.getElementById('result');

        search.addEventListener('input', function () {
            const query = this.value.trim();

            if (query === '') {
                result.innerHTML = '';
                return;
            }

            fetch('search.php?q=' + encodeURIComponent(query))
                .then(response => response.json())
                .then(data => {
                    result.innerHTML = '';

                    if (data.length === 0) {
                        result.textContent = 'No employees found.';
                        return;
                    }

                    const table = document.createElement('table');
                    table.border = '1';
                    table.cellPadding = '8';

                    const header = table.insertRow();
                    ['ID', 'Name', 'Department', 'Salary']
                        .forEach(text => {
                            const th = document.createElement('th');
                            th.textContent = text;
                            header.appendChild(th);
                        });

                    data.forEach(emp => {
                        const row = table.insertRow();

                        [emp.id, emp.name, emp.department, emp.salary]
                            .forEach(value => {
                                const cell = row.insertCell();
                                cell.textContent = value;
                            });
                    });

                    result.appendChild(table);
                })
                .catch(() => {
                    result.textContent = 'Error loading employee data.';
                });
        });
    </script>
</body>
</html>