<?php
$q = $_REQUEST["q"];
var_dump('hellloooo');
var_dump($q);
require('./../config/setup.php');

$url = $db->quote($q);
$select = $db->prepare("SELECT * FROM Image WHERE url:=url");
$db->query("INSERT INTO Image SET url=$url");
?>
