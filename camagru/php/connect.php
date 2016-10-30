<?php
session_start();
require('./../config/setup.php');

if($_POST['submit'] === "register_button") {
	if (isset($_POST['username']) && isset($_POST['password'])) {
		$useranme = $db->quote($_POST['username']);
		$password = $db->quote(hash(whirlpool, $_POST['password'], false));
		$sql = "SELECT * FROM User WHERE username:=username AND password:=password";
		$select= $db->query($sql);
		if ($select->rowCount() > 0) {
			$_SESSION['Auth'] = $select->fetch();
			echo "vous etes connecter";
		}


	} else {
		echo "Messing information";

	}
} else {
	echo "503 bad get a way Forbidden";
}
?>
