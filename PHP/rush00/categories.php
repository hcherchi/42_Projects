<?php
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
					<script type="text/javascript" language="javascript">
					   function verif()
					   {
						  element=document.forms ['categorie'].elements['name'];
								if (element.value=="")
								{
								   alert("Vous devez entrer un nom d'auteur avant de poster !");
								   return false
								}
					   }
					</script>
					<h2>AJOUTER UNE CATEGORIE</h3>
					<?php
					if (empty($_POST['submit']))
						{
					?>
					<form id="categorie" action="categories.php" method="post" onsubmit="return verif()">
					<table align="center">
						<tr>
							<td>Nom categorie :</td>
							<td><input name="name" type="text" size="15" />
							<td>Categorie mere :</td>
							<td><input name="master" type="number" size="15" />
						</tr><tr>
							<td colspan="2" align="center"><input name="submit" type="submit" value="poster" /></td>
						</tr>
					</table>
					</form>
					<?php						
							}
						else
							{						
							
							$row = array("name" => $_POST["name"], "categorie-master" => $_POST["master"]);
									create_categorie($database, $row);
									echo "categorie ajouté avec succès			"?> <a href="categories.php"><?php echo "Ajouter une nouvelle categorie";?></a>
									
					<?php
							}
						
						
					$categories= get_categories($database);
					
					foreach($categories as $selected){
					
					?>
						<h3><?php echo $selected['name']; ?></h3>
						
					-------<a href=# onclick="JavaScript:window.open('delete_categorie.php?id=<?php echo $selected['id'] ?>','delete',',toolbar=no, width=300, height=200, scrollbar=no')"><img src="img/delete.png" width="50px" height="50"/></a>
								
					
					<?php
					}
					close_database($database);
					?>
					


				</div>
			</div>
			<?PHP include("elements/panier.php"); ?>
		</section>
		<?PHP include("elements/footer.php"); ?>
	</body>
</html>