<?php
// 1. CONNECT TO MYSQL SERVER
$conn = mysqli_connect("localhost", "root", "");

if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}

// 2. CREATE DATABASE
$sql = "CREATE DATABASE IF NOT EXISTS library_db";

if (!mysqli_query($conn, $sql)) {
    die("Database Error: " . mysqli_error($conn));
}

// 3. SELECT DATABASE
mysqli_select_db($conn, "library_db");

// 4. CREATE TABLE
$sql = "CREATE TABLE IF NOT EXISTS books (
    accession_no VARCHAR(20) PRIMARY KEY,
    title VARCHAR(100) NOT NULL,
    authors VARCHAR(100) NOT NULL,
    edition VARCHAR(30),
    publisher VARCHAR(100)
)";

if (!mysqli_query($conn, $sql)) {
    die("Table Error: " . mysqli_error($conn));
}


// 5. CREATE AND UPDATE
if (isset($_POST['save'])) {

    $acc = $_POST['accession_no'];
    $title = $_POST['title'];
    $authors = $_POST['authors'];
    $edition = $_POST['edition'];
    $publisher = $_POST['publisher'];

    if ($_POST['old_acc'] != "") {

        // UPDATE
        $old = $_POST['old_acc'];

        $sql = "UPDATE books SET title=?, authors=?,
                edition=?, publisher=? WHERE accession_no=?";

        $stmt = mysqli_prepare($conn, $sql);

        mysqli_stmt_bind_param(
            $stmt,
            "sssss",
            $title,
            $authors,
            $edition,
            $publisher,
            $old
        );

    } else {

        // INSERT
        $sql = "INSERT INTO books VALUES (?, ?, ?, ?, ?)";

        $stmt = mysqli_prepare($conn, $sql);

        mysqli_stmt_bind_param(
            $stmt,
            "sssss",
            $acc,
            $title,
            $authors,
            $edition,
            $publisher
        );
    }

    if (mysqli_stmt_execute($stmt)) {
        header("Location: index.php");
        exit();
    } else {
        echo "Error: " . htmlspecialchars(mysqli_stmt_error($stmt));
    }
}


// 6. DELETE
if (isset($_POST['delete'])) {

    $acc = $_POST['accession_no'];

    $stmt = mysqli_prepare(
        $conn,
        "DELETE FROM books WHERE accession_no=?"
    );

    mysqli_stmt_bind_param($stmt, "s", $acc);

    if (mysqli_stmt_execute($stmt)) {
        header("Location: index.php");
        exit();
    } else {
        echo "Delete Error: " . htmlspecialchars(mysqli_stmt_error($stmt));
    }
}


// 7. EDIT - FETCH SELECTED BOOK
$editBook = null;

if (isset($_GET['edit'])) {

    $acc = $_GET['edit'];

    $stmt = mysqli_prepare(
        $conn,
        "SELECT * FROM books WHERE accession_no=?"
    );

    mysqli_stmt_bind_param($stmt, "s", $acc);
    mysqli_stmt_execute($stmt);

    $result = mysqli_stmt_get_result($stmt);
    $editBook = mysqli_fetch_assoc($result);
}
?>

<!DOCTYPE html>
<html>

<head>
    <title>Library Management</title>

    <style>
        body {
            font-family: Arial, sans-serif;
            background: #f2f2f2;
            text-align: center;
        }

        .container {
            background: white;
            width: 85%;
            margin: 30px auto;
            padding: 20px;
            border-radius: 8px;
        }

        input {
            padding: 8px;
            margin: 5px;
        }

        button,
        .edit {
            padding: 7px 12px;
            background: #007bff;
            color: white;
            border: none;
            cursor: pointer;
            text-decoration: none;
        }

        .delete {
            background: red;
        }

        table {
            width: 100%;
            border-collapse: collapse;
            margin-top: 20px;
        }

        th,
        td {
            border: 1px solid #ccc;
            padding: 10px;
        }

        th {
            background: #007bff;
            color: white;
        }
    </style>
</head>

<body>

    <div class="container">

        <h2>Library Management System</h2>

        <h3>
            <?php echo $editBook ? "Update Book" : "Add Book"; ?>
        </h3>

        <!-- CREATE / UPDATE FORM -->

        <form method="POST" action="index.php">

            <input type="hidden" name="old_acc"
                value="<?php echo htmlspecialchars($editBook['accession_no'] ?? ''); ?>">

            <input type="text" name="accession_no" placeholder="Accession Number"
                value="<?php echo htmlspecialchars($editBook['accession_no'] ?? ''); ?>" <?php echo $editBook ? "readonly" : ""; ?> required>

            <input type="text" name="title" placeholder="Title"
                value="<?php echo htmlspecialchars($editBook['title'] ?? ''); ?>" required>

            <input type="text" name="authors" placeholder="Authors"
                value="<?php echo htmlspecialchars($editBook['authors'] ?? ''); ?>" required>

            <input type="text" name="edition" placeholder="Edition"
                value="<?php echo htmlspecialchars($editBook['edition'] ?? ''); ?>">

            <input type="text" name="publisher" placeholder="Publisher"
                value="<?php echo htmlspecialchars($editBook['publisher'] ?? ''); ?>">

            <button type="submit" name="save">
                <?php echo $editBook ? "Update Book" : "Add Book"; ?>
            </button>

        </form>


        <!-- READ - DISPLAY BOOKS -->

        <h3>Book Details</h3>

        <table>

            <tr>
                <th>Accession No.</th>
                <th>Title</th>
                <th>Authors</th>
                <th>Edition</th>
                <th>Publisher</th>
                <th>Actions</th>
            </tr>

            <?php
            $result = mysqli_query($conn, "SELECT * FROM books");

            while ($row = mysqli_fetch_assoc($result)) {
                ?>

                <tr>
                    <td><?php echo htmlspecialchars($row['accession_no']); ?></td>
                    <td><?php echo htmlspecialchars($row['title']); ?></td>
                    <td><?php echo htmlspecialchars($row['authors']); ?></td>
                    <td><?php echo htmlspecialchars($row['edition'] ?? ''); ?></td>
                    <td><?php echo htmlspecialchars($row['publisher'] ?? ''); ?></td>

                    <td>

                        <!-- EDIT BUTTON -->
                        <a class="edit" href="index.php?edit=<?php echo urlencode($row['accession_no']); ?>">
                            Edit
                        </a>

                        <!-- DELETE BUTTON -->
                        <form method="POST" action="index.php" style="display:inline;">

                            <input type="hidden" name="accession_no"
                                value="<?php echo htmlspecialchars($row['accession_no']); ?>">

                            <button type="submit" name="delete" class="delete"
                                onclick="return confirm('Delete this book?')">
                                Delete
                            </button>

                        </form>

                    </td>
                </tr>

            <?php } ?>

        </table>

    </div>

</body>

</html>

<?php
// CLOSE DATABASE CONNECTION
mysqli_close($conn);
?>