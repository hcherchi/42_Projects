<?php
require_once('database.php');

try
{
	$db = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
	$db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
	$sql = "CREATE DATABASE IF NOT EXISTS Camagru";
	$db -> exec($sql);
	$sql = "USE Camagru;
			CREATE TABLE `User` (`id` int(25) NOT NULL,`username` varchar(255) NOT NULL,`password` varchar(255) NOT NULL, `email` varchar(255) NOT NULL) ENGINE=MyISAM DEFAULT CHARSET=utf8;
	";
	$db -> exec($sql);
	echo "Bb is create whit sucesse\n";
}
catch (Exception $e)
{
	die('Erreur : ' . $e->getMessage());
}
?>
