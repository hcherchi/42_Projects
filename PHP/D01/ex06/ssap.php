#!/usr/bin/php
<?PHP
	$i = 1;
	$res = [];
	while ($i < $argc)
	{
		$array = explode(" ", $argv[$i]);
		foreach ($array as $elem)
		{
			if ($elem)
				array_push($res, $elem);
		}
		$i += 1;
	}
	sort($res);
	foreach ($res as $elem)
		print("$elem\n");
?>