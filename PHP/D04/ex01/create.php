<?PHP
function add_account()
{
	if (!file_exists("../private"))
		mkdir("../private");
	if (file_exists("../private/passwd"))
	{
		$serialized_comptes = file_get_contents("../private/passwd");
		$comptes = unserialize($serialized_comptes);
	}
	else
		$comptes = array();
	$submit = $_POST['submit'];
	if ($submit != 'OK')
		return ("ERROR\n");
	$compte = array();
	$compte['login'] = $_POST['login'];
	$compte['passwd'] = hash("whirlpool", $_POST['passwd']);
	if ($compte['login'] == '' || $compte['passwd'] == '')
		return ("ERROR\n");
	foreach ($comptes as $value)
	{
		if ($compte['login'] == $value['login'])
			return ("ERROR\n");
	}
	$comptes[] = $compte;
	$serialized_comptes = serialize($comptes);
	file_put_contents("../private/passwd", $serialized_comptes);
	return ("OK\n");
}
echo (add_account());
?>