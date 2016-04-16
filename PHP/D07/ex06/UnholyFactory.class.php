<?PHP
class UnholyFactory
{
	private $_types = array();
	function absorb($fighter)
	{
		if (is_subclass_of($fighter, 'Fighter') == false)
		{
			print("(Factory can't absorb this, it's not a fighter)\n");
			return ;
		}
		else
		{
			foreach ($this->_types as $class => $type)
			{
				if ($class == get_class($fighter))
				{
					print("(Factory already absorbed a fighter of type " . $fighter->type . ")\n");
					return ;
				}
			}
			$this->_types[get_class($fighter)] = $fighter->type;
			print("(Factory absorbed a fighter of type " . $fighter->type . ")\n");
		}
	}

	function fabricate($fighter)
	{
		foreach ($this->_types as $class => $type)
		{
			if ($fighter == $type)
			{
				print("(Factory fabricated a fighter of type " . $fighter . ")\n");
				return (new $class());
			}
		}
		print("(Factory hasn't absorbed any fighter of type " . $fighter . ")\n");
		return (NULL);
	}
}
?>