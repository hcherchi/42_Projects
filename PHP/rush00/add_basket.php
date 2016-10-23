<?php
session_start();
include('database_operations.php');

if (empty($_GET) || empty($_GET['id']))
	echo "Wrong format";

$database = connect_database();
$item = get_item_by_id($database, $_GET['id']);
if ($item === false)
	echo "invalid item";
else
{
	if (empty($_SESSION["basket"]))
		$_SESSION["basket"] = array();
	if (!is_inside_basket($_SESSION["basket"], $item))
		$_SESSION["basket"][] = array("item" => $item, "quantity" => 1);
	else
		;
	header("Location: index.php");
}
close_database($database);
?>