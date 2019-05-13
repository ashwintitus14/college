<?php

$servername = "localhost";
$username = "root";
$password = "root";
$db = "phptest";

$conn = mysqli_connect($servername, $username, $password, $db);

if (!$conn) {
    die("Connection failed" . mysqli_connect_error());
}
else {
    echo "Connected successfully<br>";
}

$roll = $_POST['rollno'];

$sql = "DELETE FROM student WHERE rollno='$roll'";
$sql1 = "SELECT * FROM student WHERE rollno='$roll'";

$result = mysqli_query($conn, $sql1);

if (mysqli_num_rows($result) > 0) {    
    if (mysqli_query($conn, $sql)) {
        echo "Record deleted successfully";
    } else {
        echo "Error deleting record: " . mysqli_error($conn);
    }
}
else {
    echo "Record does not exist";
}

mysqli_close($conn);
?>