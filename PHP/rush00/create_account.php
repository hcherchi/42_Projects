<?php
include('database_operations.php');
session_start();

if ($_SESSION["user"] !== "")
	header("Location: index.php");

if (!empty($_POST))
{
	$database = connect_database();
	$errors = array();
	if (empty($_POST['submit']) || $_POST['submit'] !== "register_button")
		$errors['submit'] = "Mauvais code boutton";
	if (empty($_POST['username']) || !preg_match('/^[a-zA-Z0-9_]+$/', $_POST['username']) || strlen($_POST['username']) >= 20)
		$errors['username'] = "Nom d'utilisateur invalide";
	else
	{
		if (user_already_exist($database, $_POST['username']))
			$errors['username-exist'] = "Nom d'utilisateur deja pris";
	}
	if (empty($_POST['password']))
		$errors['password'] = "Vous devez rentrer un mot de passe valide";
	if ($_POST['password'] != $_POST['password_confirm'])
		$errors['password-match'] = "Le mot de passe et la confirmation du mot de passe ne sont pas equivalents";
	if (empty($errors))
	{
		add_user($database, $_POST['username'], $_POST['password']);
		header("Location: connect.php");
	}
	else
		print_r($errors);
	close_database($database);
}
?>