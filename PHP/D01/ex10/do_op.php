#!/usr/bin/php
<?PHP
	if ($argc == 4)
	{
		$nb1 = trim($argv[1]);
		$nb2 = trim($argv[3]);
		$op = trim($argv[2]);
		if ($op == '+')
			print($nb1 + $nb2);
		else if ($op == '-')
			print($nb1 - $nb2);
		else if ($op == '/' && $nb2 != 0)
			print($nb1 / $nb2);
		else if ($op == '%' && $nb2 != 0)
			print($nb1 % $nb2);
		else if ($op == '*')
			print($nb1 * $nb2);
		else if ($op == '/' || $op == '%')
			print("Div by zero");
		print("\n");
	}
	else
		print("Incorrect Parameters\n");
?>