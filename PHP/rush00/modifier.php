<?PHP session_start();
if (empty($_SESSION["super_user"]) || $_SESSION["super_user"] !== "1")
	header("Location: account.php");
	
 include('database_operations.php');
	  $database = connect_database();
?>

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
						  element=document.forms ['items'].elements['cate'];
								if (element.value=="")
								{
								   alert("Vous devez entrer un commentaire avant de poster !");
								   return false
								}
						  element=document.forms ['items'].elements['desc'];
								if (element.value=="")
								{
								   alert("Vous devez entrer un commentaire avant de poster !");
								   return false
								}
   }
</script>
<?php
$id = $_GET['id'];
$row= get_item_by_id($database, $id);

$name = $row['name'];
$price = $row['price'];
$cate = $row['categories'];
$desc = $row['description'];
$message = str_replace("<br />","",$desc);

?>

<form id="news" action="modifier.php?id=<?php echo $id; ?>" method="post" onsubmit="return verif()">
<table align="center">
    <tr>
        <td>name :</td>
        <td><input name="name" type="text" size="15" value="<?php echo $name ?> "/>
		<td>price :</td>
        <td><input name="price" type="text" size="15" value="<?php echo $price ?> "/>
	</tr>
    <tr>
        <td>categories :</td>
        <td><input name="cate" type="text" size="45" value="<?php echo $cate ?>" /></td>
    </tr>
    <tr>
        <td>description:</td>
        <td colspan="2"><textarea name="desc" cols="50" rows="10"><?php echo $message ?></textarea></td>
    </tr>
    <tr>
        <td colspan="2" align="center"><input name="submit" type="submit" value="poster" /></td>
    </tr>
</table>
</form>

<?php update_item($database, $id, $row);?>
 <br /><a href=# onclick="javascript:parent.opener.location.reload();self.close('modifier')">Cliquez  ici pour fermez la fenetre</a>