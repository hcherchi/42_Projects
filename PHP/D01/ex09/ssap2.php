#!/usr/bin/php
<?PHP
	$i = 1;
	$l1 = [];
	$l2 = [];
	$l3 = [];
	while ($i < $argc)
	{
		$array = explode(" ", $argv[$i]);
		foreach ($array as $elem)
		{
			if ($elem)
			{
				if (ctype_alpha($elem[0]))
					array_push($l1, $elem);
				else if (is_numeric($elem[0]))
					array_push($l2, $elem);
				else
					array_push($l3, $elem);
			}
		}
		$i += 1;
	}
	sort($l1, SORT_STRING | SORT_FLAG_CASE);
	sort($l2, SORT_STRING | SORT_FLAG_CASE);
	sort($l3, SORT_STRING | SORT_FLAG_CASE);
	foreach ($l1 as $elem)
		print("$elem\n");
	foreach ($l2 as $elem)
		print("$elem\n");
	foreach ($l3 as $elem)
		print("$elem\n");
?>