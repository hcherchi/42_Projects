<?php
session_start();
include('database_operations.php');

if (empty($_GET) || empty($_GET['id']))
	exit (0);

if (empty($_SESSION["basket"]))
	$_SESSION["basket"] = array();
if (count($_SESSION["basket"]) == 1)
	header("Location: empty_cart.php");
$id = get_basket_item($_SESSION["basket"], $_GET['id']);
unset($_SESSION["basket"][$id]);
header("Location: index.php");
?>