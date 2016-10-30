<?php
require_once('./config/database.php');

try
{
	$bdd = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
	$sql = "Camagru DB";
	$bdd -> exec($sql);
	$bdd->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
	$bdd -> create
	echo "Bb is create whit sucesse";
}
catch (Exception $e)
{
	die('Erreur : ' . $e->getMessage());
}
?>
