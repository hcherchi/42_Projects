<?PHP
function change_pwd()
{
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
	$compte['newpw'] = hash("whirlpool", $_POST['newpw']);
	$compte['oldpw'] = hash("whirlpool", $_POST['oldpw']);
	if ($compte['login'] == '' || $compte['newpw'] == '' || $compte['oldpw'] == '')
		return ("ERROR\n");
	foreach ($comptes as $key => $value)
	{
		if ($compte['login'] == $value['login'])
			$index = $key;
	}
	if ($key && $comptes[$key]['passwd'] == $compte['oldpw'])
	{
		$comptes[$key]['passwd'] = $compte['newpw'];
		$serialized_comptes = serialize($comptes);
		file_put_contents("../private/passwd", $serialized_comptes);
		return ("OK\n");
	}
	else
		return ("ERROR\n");
}
echo (change_pwd());
?>