<?php
    $servername = "localhost";
    $username = "uname";
    $password = "pass";
    $dbname = "phptest";

    $conn = mysqli_connect($servername, $username, $password, $dbname);

    if (!$conn) {
        die("Connection failed: " . mysqli_connect_error());
    }
    echo "Connected successfully";

    $sql = "INSERT INTO student (name, rollno, branch) VALUES ('".$_POST['name']."', '".$_POST['rollno']."','".$_POST['branch']."')";

    if (mysqli_query($conn, $sql)) {
        echo "New record created successfully";
    } 
    else {
        echo "Error: " . $sql . "<br>" . mysqli_error($conn);
    }
    
    mysqli_close($conn);
?>
