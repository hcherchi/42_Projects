<?PHP include("elements/header.php"); ?>
<!DOCTYPE html>
<html>
	<head>
		<link rel="stylesheet" type="text/css" href="index.css">
		<meta charset="UTF-8">
		<title>Guitar & Co</title>
	</head>
	<body>
		<section>
            <form class="formulaire" action="create_account.php" method="POST">
            	<h1>S'inscrire</h1>
                <label for="">Nom de compte: </label><br/>
                <input type="text" name="username"/><br />
                <label for="">Mot de passe: </label><br/>
                <input type="password" name="password"/><br/>
                <label for="">Confirmez votre mot de passe: </label><br/>
                <input type="password" name="password_confirm"><br/>
                <button type="submit" name="submit" value="register_button">M'inscrire</button>
            </form>
			<?PHP include("elements/panier.php"); ?>
		</section>
		<?PHP include("elements/footer.php"); ?>
	</body>
</html>