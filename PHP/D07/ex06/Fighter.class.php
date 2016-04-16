<?PHP
abstract class Fighter
{
	public $type;
	abstract function fight($t);
	function __construct($type)
	{
		$this->type = $type;
	}
}
?>