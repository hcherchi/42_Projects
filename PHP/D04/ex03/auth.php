<?PHP
	function auth($login, $passwd)
	{
		if (file_exists("../private/passwd"))
		{
			$serialized_comptes = file_get_contents("../private/passwd");
			$comptes = unserialize($serialized_comptes);
		}
		else
			$comptes = array();
		foreach ($comptes as $key => $value)
		{
			if ($value['login'] == $login && $value['passwd'] == hash("whirlpool", $passwd))
				return (true);
		}
		return (false);
	}
?>