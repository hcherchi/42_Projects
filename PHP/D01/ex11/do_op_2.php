#!/usr/bin/php
<?PHP
function multiexplode ($delimiters,$string) 
{
    
    $ready = str_replace($delimiters, $delimiters[0], $string);
    $launch = explode($delimiters[0], $ready);
    return  $launch;
}
if ($argc == 2)
{
	$split = multiexplode(array('/', '*', '+', '-', '%'), $argv[1]);
	if (count($split) == 2)
	{
		$nb1 = trim($split[0]);
		$nb2 = trim($split[1]);
		if (ctype_digit($nb1) && ctype_digit($nb2))
		{
			if (strstr($argv[1], '+'))
				print($nb1 + $nb2);
			else if (strstr($argv[1], '-'))
				print($nb1 - $nb2);
			else if (strstr($argv[1], '/') && $nb2 != 0)
				print($nb1 / $nb2);
			else if (strstr($argv[1], '%') && $nb2 != 0)
				print($nb1 % $nb2);
			else if (strstr($argv[1], '*'))
				print($nb1 * $nb2);
			print("\n");
		}
		else
			print("Syntax Error\n");
	}
	else
		print("Syntax Error\n");
}
else
	print("Incorrect Parameters\n");
?>