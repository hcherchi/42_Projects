#!/usr/bin/php
<?PHP
	date_default_timezone_set("Europe/Paris");
	$fd = fopen('/var/run/utmpx', r);
	while($buf = fread($fd, 628))
	{
		$res = unpack("a256Usr/a4Id/a32name/ipid/itype/l2time/a256host/i16donno", $buf);
		if ($res["type"] == 7)
			$user[$res["name"]] = array("Usr" => $res["Usr"], "time" => $res["time1"]);
	}
	ksort($user);
	foreach($user as $line => $data)
	{
		$date = date("M  j H:i", $data["time"]);
		print("$data[Usr] $line  $date\n");
 	}
?>