<?php

include('database_operations.php');
session_start();

if (!empty($_POST) || $_SESSION["user"] === "")
{
	$database = connect_database();
	if (empty($_POST['submit']) || $_POST['submit'] !== "login_button")
		die ("Mauvais code boutton");
	if (empty($_POST['username']) || !user_already_exist($database, $_POST['username']))
		die ("Nom d'utilisateur non existant");
	else
	{
		$account = NULL;
		if (empty($_POST['password']))
			die ("Rentrez votre mot de passe");
		if (authenticate($database, $_POST["username"], $_POST["password"], $account))
		{
			$_SESSION["user"] = $account["username"];
			$_SESSION["super_user"] = $account["super_user"];
			header("Location: index.php");
		}
		else
		{
			$_SESSION["user"] = "";
			$_SESSION["super_user"] = "0";
			die ("Nom d'utilisateur et mot de passe ne correspondent pas");
		}
	}
	close_database($database);
}
