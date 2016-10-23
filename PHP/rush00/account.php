<?php
session_start();
if ($_SESSION["user"] === "" || empty($_SESSION["user"]))
	header("Location: connect.php");
include("elements/header.php");
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
			<form class="formulaire" action="changepass.php" method="POST">
				<h1>Changer son mot de passe </h1><br />
    			<label for="">Ancien password</label><br />
    			<input type="password" name="oldpass"/><br />
    			<label for="">Nouveau password</label><br />
    			<input type="password" name="newpass"/><br />
    			<button type="submit" name="submit" value="modifpass_button">Modifier</button><br />
				<?php if (!empty($_SESSION["super_user"]) && $_SESSION["super_user"] === "1")
				{?>
					<a href="admin.php">Partie admin</a>
				<?php
				}
				else
				{?>
					<a href="delete_account.php">Supprimer son compte</a>
				<?php
				}?>
				</form>
			<?PHP include("elements/panier.php"); ?>
		</section>
		<?PHP include("elements/footer.php"); ?>
	</body>
</html>