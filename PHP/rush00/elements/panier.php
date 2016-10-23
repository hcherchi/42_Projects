<?php
session_start();

$database = connect_database();
$items = get_items($database);
$basket = $_SESSION["basket"];
?>
<aside>
	<h1 class="panier-title" >Panier</h1>
	<img class="logo-panier" src="img/logo-panier.png"/>
	<a href="add_command.php" class="commandbutton" >Commander !</a>
	<?php
	if (!empty($basket))
	{
		foreach ($basket as $val)
		{
	?>
			<div class="smallitem">
				<img src="<?php echo $val["item"]["image_url"]; ?>">
				<h1><?php echo $val["item"]["name"]; ?></h1>
				<h2><?php echo $val["item"]["price"]; ?></h2>
				<h2><?php echo $val["quantity"]; ?></h2>
				<form action="delete_in_basket.php" mode="get">
				<button type="submit" name="id" value="<?php echo $val["item"]["id"] ?>">Retirer du panier</button>
				</form>
			</div>
	<?php
		}
	}
	close_database($database);
	?>
	<a href="empty_cart.php" class="commandbutton">Vider son panier</a>
</aside>