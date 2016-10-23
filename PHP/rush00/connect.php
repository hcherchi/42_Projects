<?php
session_start();

if ($_SESSION["user"] !== "")
	header("Location: account.php");
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
            <form class="formulaire" action="login.php" method="POST">
            	<h1>Se connecter</h1>
                <label for="">Nom de compte: </label><br/>
                <input type="text" name="username"/><br/>
                <label for="">Mot de passe: </label><br/>
                <input type="password" name="password"/><br/>
                <button type="submit" name="submit" value="login_button">Connexion</button>
            </form>
			<?PHP include("elements/panier.php"); ?>
		</section>
		<?PHP include("elements/footer.php"); ?>
	</body>
</html>