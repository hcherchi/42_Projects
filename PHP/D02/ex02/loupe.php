#!/usr/bin/php
<?PHP
	function ft_callback($match)
		return ($match[1].strtoupper($match[2]).$match[3]);
	if ($argc > 1)
	{
		$fd = fopen($argv[1], 'r');
		$buf = fread($fd, filesize($argv[1]));
		$buf = preg_replace_callback('#(<a.+>)(.+)(<.+/a>)#i', 'ft_callback', $buf);
		$buf = preg_replace_callback('#(<a.+title=)(.+)(/a>)#i', 'ft_callback', $buf);
		print("$buf\n");
	}
?>