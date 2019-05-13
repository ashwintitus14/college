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

$sql = "SELECT * FROM student WHERE rollno='$roll'";

$result = mysqli_query($conn, $sql);

if (mysqli_num_rows($result) > 0) {
    
    while($row = mysqli_fetch_assoc($result)) {
        echo "<b>Roll No: </b>" . $row["rollno"]. "<b> Name: </b>" . $row["name"]. "<b> Gender: </b>" . $row["gender"]. "<b> Branch: </b>" . $row["branch"] . "<b> Email: </b>". $row["email"] . "<b> Address: </b>". $row["address"] . "<br>";
    }
} else {
    echo "A student with this roll number <b>does not exist</b>.";
}

mysqli_close($conn);
echo '<p><a href="mainmenu.html">Go back to Main Menu</a></p>';
?>