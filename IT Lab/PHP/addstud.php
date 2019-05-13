<?php
    $servername = "localhost";
    $username = "root";
    $password = "root";
    $dbname = "phptest";

    $conn = mysqli_connect($servername, $username, $password, $dbname);

    if (!$conn) {
        die("Connection failed: " . mysqli_connect_error());
    }
    echo "Connected successfully<br>";

    $rollno = $_POST['rollno'];
	$name = $_POST['name'];
	$gender = $_POST['gender'];
	$branch = $_POST['branch'];
	$email = $_POST['email'];
    $address = $_POST['address'];
    
    $sql = "INSERT INTO student (name, rollno, gender, branch, email, address) VALUES ('$name','$rollno','$gender','$branch','$email','$address')";

    if (mysqli_query($conn, $sql)) {
        echo "New record created successfully";
    } 
    else {
        echo "Error: " . $sql . "<br>" . mysqli_error($conn);
    }
    
    mysqli_close($conn);

    echo '<p><a href="mainmenu.html">Go back to Main Menu</a></p>';
?>