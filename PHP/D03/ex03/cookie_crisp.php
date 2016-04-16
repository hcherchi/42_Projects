<?PHP
	$action = $_GET[action];
	if ($action == 'set')
		setcookie($_GET[name], $_GET[value]);
	else if ($action == 'get')
	{
		if ($_COOKIE[$_GET[name]])
			echo($_COOKIE[$_GET[name]]."\n");
	}
	else if ($action == 'del')
	{
		setcookie($_GET[name], 'toto', time(-1));
	}
?>
