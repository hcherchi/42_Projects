<?PHP session_start();
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
					
		<?php $users= get_users($database);
	
	foreach($users as $selected){
	?>
		<h3> ID Utilisateur :</u>  <span style="color : orange;"><?php echo "   " .$selected['id']; ?></h3></span>
		<u>Nom d'Utilisateur :</u>  <span style="color : orange;"><?php echo "   " .$selected['username']; ?></span><br>
		<u>Super-admin :</u>  <span style="color : orange;"><?php echo "   " .$selected['super_user']; ?></span><br>
		
	
		
	-------<a href=# onclick="JavaScript:window.open('delete_user.php?id=<?php echo $selected['id'] ?>','delete',',toolbar=no, width=300, height=200, scrollbar=no')"><img src="img/delete.png" width="50px" height="50"/></a>
	-----------------<br />
	
	<?php
	} close_database($database);
	?>
	


				</div>
			</div>
			<?PHP include("elements/panier.php"); ?>
		</section>
		<?PHP include("elements/footer.php"); ?>
	</body>
</html>