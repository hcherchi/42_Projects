<?php

session_start();
include('database_operations.php');

if (empty($_SESSION["user"]) || $_SESSION["user"] === "")
	header("Location: connect.php");
if (empty($_SESSION["basket"]) || count($_SESSION["basket"]) <= 0)
	header("Location: index.php");
	
	$database = connect_database();
	$row = array("price" => get_basket_price($_SESSION["basket"]), "user" => $_SESSION["user"]);
	create_command($database, $row);
	close_database($database);
	header("Location: empty_cart.php");
?>