<?PHP
class NightsWatch
{
	public $troupe = array();
	function recruit($man)
	{
		foreach (class_implements(get_class($man)) as $interface) 
		{
			if ($interface == 'IFighter')
				$this->troupe[] = $man;
		}
	}
	function fight()
	{
		foreach ($this->troupe as $man)
		{
			$man->fight();
		}
	}
}
?>