<?php
require('./../config/setup.php');
if ($_POST['submit'] === "register_button") {
	if (isset($_POST['username']) && isset($_POST['password']) && isset($_POST['email']) && isset($_POST['password_confirm'])) {
		if($_POST['password_confirm'] === $_POST['password']) {
			$username = $db->quote($_POST['username']);
			$email = $db->quote($_POST['email']);
			$password = $db->quote(hash(whirlpool,$_POST['password'], false));
			$select = $db->query("SELECT * FROM User WHERE username=$username OR email=$email");

			if ($select->rowCount() == 0) {
				$db->query("INSERT INTO User SET username=$username, password=$password, email=$email");
				mail( $_POST['email'] , "New account" , "Welcome ".$_POST['username']."\nYou successefully regiter to Camagru.\n http://localhost:8080/42_Projects/camagru/" );
			}
		} else {
			echo "Password and confirm passwor do not match";
		}

	} else {
		echo "Messing Information";
	}
} else {
	echo "503 bag get a way Forbidden";
}
?>
