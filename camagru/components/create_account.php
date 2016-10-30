<?php
session_start();
require('./../config/setup.php');
if ($_POST['submit'] === "register_button") {
	if (isset($_POST['username']) && isset($_POST['password']) && isset($_POST['email'])) {
		echo "whech alors";
		$username = $db->quote($_POST['username']);
		$email = $db->quote($_POST['email']);
		$password = $db->quote(sha1($_POST['password']));
		$select = $db->query("SELECT * FROM User WHERE username=$username OR email=$email");

		if ($select->rowCount() == 0) {
			$db->query("INSERT INTO User SET username=$username, password=$password, email=$email");
			mail( $_POST['email'] , "new count" , "Welcom to you ".$_POST['username'].", you successefully regiter to Camagru. lets start !!" );
		}

	} else {
		echo "Messing Information";
	}
} else {
	echo "503 bag get a way Forbiden";
}
?>

