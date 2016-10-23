<?php

session_start();

if (empty($_SESSION["user"]) || $_SESSION["user"] === "")
	header("Location: connect.php");

include ('database_operations.php');
$database = connect_database();

delete_user_by_name($database, $_SESSION["user"]);
close_database($database);
header("Location: logout.php");
?>