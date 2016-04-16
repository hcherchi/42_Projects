#!/usr/bin/php
<?PHP
	if ($argc > 2)
	{
		$i = 2;
		while ($i < $argc)
		{
			$split = explode(":", $argv[$i]);
			if ($split[0] == $argv[1])
				print("$split[1]\n");
			$i++;
		}
	}
?>