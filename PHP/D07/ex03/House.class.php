<?PHP
abstract class House
{
	abstract function getHouseName();
	abstract function getHouseMotto();
	abstract function getHouseSeat();
	function introduce()
	{
		print('House ' . $this->getHouseName() . ' of ' . $this->getHouseSeat() . ' : "' . $this->getHouseMotto() . '"' . PHP_EOL);
	}
}
?>