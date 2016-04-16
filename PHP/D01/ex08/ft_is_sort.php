<?PHP
	function ft_is_sort($tab)
	{
		$i = 0;
		while ($i < count($tab) - 1)
		{
			if (strcmp($tab[$i], $tab[$i + 1]) > 0)
				return (false);
			$i += 1;
		}
		return (true);
	}
?>