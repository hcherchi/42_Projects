#!/usr/bin/php
<?PHP
	if ($argc > 1)
	{
		$split = explode(" ", $argv[1]);
   		$res = [];
   		foreach ($split as $elem)
   		{
   			if ($elem)
   				array_push($res, $elem);
   		}
		array_push($res, array_shift($res));
		$i = 0;
		while ($i < count($res))
		{
			if ($i != 0)
				print(" ");
			print("$res[$i]");
			$i++;
		}
		print("\n");
	}
?>