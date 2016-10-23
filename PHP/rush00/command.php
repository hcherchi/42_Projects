<?PHP
session_start();
if (empty($_SESSION["super_user"]) || $_SESSION["super_user"] !== "1")
	header("Location: account.php");
	
include("elements/header.php");
$database = connect_database();
?>
<!DOCTYPE html>
<html>
	<head>
		<link rel="stylesheet" type="text/css" href="index.css">
		<meta charset="UTF-8">
		<title>Guitar & Co</title>
	</head>
	<body>
		<section>
			<div class="vitrine">
					<div id="menu_admin">
					   <div class="element_menu_admin"> <!-- Cadre correspondant à un sous-menu -->
						   <h3>Acceuil</h3> <!-- Titre du sous-menu -->
						   <ul>
							   <li><a href="admin.php">Items/acceuil</a></li>
							   <li><a href="categories.php">Categories</a></li>
							   <li><a href="command.php">Commandes</a></li>
							   <li><a href="user.php">Utilisateur</a></li>
							   <li><a href="index.php">Site normal</a></li>
						   </ul></div>
					</div>
					 
					<div id="corps">
					
		<?php $command= get_command($database);
	
	foreach($command as $selected){
	
	?>
		<h3> ID Commande :</u>  <span style="color : orange;"><?php echo "   " .$selected['id']; ?></h3></span>
		<u>Nombre d'articles :</u>  <span style="color : orange;"><?php echo "   " .$selected['item_count']; ?></span><br>
		<u>Montant de la commande :</u>  <span style="color : orange;"><?php echo "   " .$selected['price']; ?></span><br>
		<u>Client :</u>  <span style="color : orange;"><?php echo "   " .  $selected['user']; ?></span><br>
		<!--<u>Date de la commande :</u>  <span style="color : orange;"><?php /*echo "   " .$selected['date'];*/ ?></span><br>--!>
		
	-----------------<br />
		 
	
	<?php
	} close_database($database);
	?>
	


				</div>
			</div>
			<?PHP include("elements/panier.php"); ?>
		</section>
	</body>
</html>