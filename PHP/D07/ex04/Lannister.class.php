<?PHP
class Lannister
{
	function sleepWith($p)
	{
		if (get_class($p) == 'Sansa')
		{
			print("Let's do this\n");
		}
		else if (get_class($this) == 'Tyrion' && (get_class($p) == 'Cersei' || get_class($p) == 'Jaime'))
		{
			print("Not even if I'm drunk !\n");
		}
		else if (get_class($this) == 'Jaime')
		{
			if (get_class($p) == 'Cersei')
			{
				print("With pleasure, but only in a tower in Winterfell, then.\n");
			}
			else if (get_class($p) == 'Tyrion')
			{
				print("Not even if I'm drunk !\n");
			}
		}
	}
}
?>