<?PHP
session_start();
$_SESSION['submit'] = $_GET['submit'];
if ($_SESSION['submit'] == 'OK')
{
	$_SESSION['login'] = $_GET['login'];
	$_SESSION['passwd'] = $_GET['passwd'];
}
?>
<html><body>
<form action="index.php" method="get">
Identifiant: <input type="text" name="login" value="<?=$_SESSION['login']?>" />
<br />
Mot de passe: <input type="password" name="passwd" value="<?=$_SESSION['passwd']?>" />
<input type="submit" name="submit" value="OK"/>
</form>
</body></html>
