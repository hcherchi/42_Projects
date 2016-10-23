<?php

include('database_operations.php');

session_start();

if ($_SESSION["user"] === "" || empty($_POST))
	header("Location: login.php");

$database = connect_database();
if (empty($_POST["submit"]) || $_POST["submit"] !== "modifpass_button")
	die ("Mauvais code boutton");
else
{
	if (empty($_POST["oldpass"]) || empty($_POST["newpass"]))
		die ("Ancien pass/Nouveau pass invalide");
	else
	{
		$account = NULL;
		if (authenticate($database, $_SESSION["user"], $_POST["oldpass"], $account))
		{
			change_password($database, $_SESSION["user"], $_POST["newpass"]);
			header("Location: account.php");
		}
		else
			die ("Mauvais ancien password");
	}
}
close_database($database);

?>
