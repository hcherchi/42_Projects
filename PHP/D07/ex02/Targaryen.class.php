<?PHP
require_once 'test.php';
class Targaryen
{
	function getBurned()
	{
		if ($this->resistsFire() == true)
			return("emerges naked but unharmed");
		else
			return("burns alive");
	}
	function resistsFire()
	{
		return false;
	}
}
?>