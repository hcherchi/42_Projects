#!/usr/bin/php
<?PHP
	if ($argc > 1)
	{
		$ticket = curl_init($argv[1]);
		curl_setopt($ticket, CURLOPT_RETURNTRANSFER, true);
		$html = curl_exec($ticket);
		if ($html)
		{
			$folder = preg_replace('#https?://#', '', $argv[1]);
			$folder = explode("/", $folder)[0];
			$folder = getcwd().'/'.$folder;
			if (!is_dir($folder))
				mkdir($folder);
			preg_match_all('/<img.+src="([^"]*)"/i', $html, $matches);
			foreach ($matches[1] as $photo_url)
			{
				$img = preg_replace('#https?://.+/#', '', $photo_url);
				$path_img = $folder.'/'.$img;
				fopen($path_img, w);
				file_put_contents($path_img, file_get_contents($photo_url));
			}
		}
	}
?>