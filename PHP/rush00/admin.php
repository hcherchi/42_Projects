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
						   </ul>
						  </div>
					</div>
					 
					<div id="corps">
					<script type="text/javascript" language="javascript">
					   function verif()
					   {
						  element=document.forms ['items'].elements['name'];
								if (element.value=="")
								{
								   alert("Vous devez entrer un nom d'auteur avant de poster !");
								   return false
								}
						  element=document.forms ['items'].elements['price'];
								if (element.value=="")
								{
								   alert("Vous devez entrer une description avant de poster !");
								   return false
								}
						  element=document.forms ['items'].elements['categories'];
								if (element.value=="")
								{
								   alert("Vous devez entrer un commentaire avant de poster !");
								   return false
								}
						  element=document.forms ['items'].elements['description'];
								if (element.value=="")
								{
								   alert("Vous devez entrer un commentaire avant de poster !");
								   return false
								}
					   }
					</script>
					<h2>AJOUTER UN ARTICLE</h3>
					<?php
					if (empty($_POST['submit']))
						{
					?>
					<form id="items" action="admin.php" method="post" onsubmit="return verif()">
					<table align="center">
						<tr>
							<td>Nom article :</td>
							<td><input name="name" type="text" size="15" />
						</tr>
						<tr>
							<td>Prix</td>
							<td colspan="2"><input name="price" type="text" size="15"></textarea></td>
						</tr>
						<tr>
							<td>description</td>
							<td colspan="2"><textarea name="description" cols="50" rows="10"></textarea></td>
						</tr>
						<tr>
							<td>categories :</td>
							<td><input name="categories" type="text" size="45" /></td>
						</tr>
						
						<tr>
							<td colspan="2" align="center"><input name="submit" type="submit" value="poster" /></td>
						</tr>
					</table>
					</form>
					<?php						
							}
						else
							{						
							
							$row = array("name" => $_POST["name"],
										"description" => $_POST["description"],
										"categories" => $_POST["categories"],
										"price" => $_POST["price"],
										"image_url" => $path);
									create_item($database, $row);
									echo "article ajouté avec succès			"?> <a href="admin.php"><?php echo "Ajouter un nouvel article"?></a><?php ;
						}
						
					?>
					<?php
					$items= get_items($database);
					
					foreach($items as $selected){
					
					?>
						<h3> ID Items :</u>  <span style="color : orange;"><?php echo "   " .$selected['id']; ?></h3></span>
						<u>Nom Article :</u>  <span style="color : orange;"><?php echo "   " .$selected['name']; ?></span><br>
						<u>Montant article :</u>  <span style="color : orange;"><?php echo "   " .$selected['price']; ?></span><br>
						<u>Categories :</u>  <span style="color : orange;"><?php echo "   " .  $selected['categories']; ?></span><br>
					
											
					-------<a href=# onclick="JavaScript:window.open('delete.php?id=<?php echo $selected['id'] ?>','delete',',toolbar=no, width=300, height=200, scrollbar=no')"><img src="img/delete.png" width="50px" height="50"/></a>
					---------<a href=# onclick="JavaScript:window.open('modifier.php?id=<?php echo $selected['id'] ?>','modifier',',toolbar=no, width=500, height=500, scrollbar=no')"><img src="img/modifier.png" width="50px" height="50"/></a>-------
							</td><br /><br />
								
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