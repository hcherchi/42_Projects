<?PHP
session_start();
if (empty($_SESSION["super_user"]) || $_SESSION["super_user"] !== "1")
	header("Location: account.php");

	  include ('database_operations.php');
	  $database = connect_database();

$id = $_GET['id'];

delete_item($database, $id);

echo "Message supprimé avec succès !";
?>
           <br /><a href=# onclick="javascript:parent.opener.location.reload();self.close('delete')">Cliquez  ici pour fermez la fenetre</a>