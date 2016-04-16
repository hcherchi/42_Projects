<?
function ft_split($p1)
{
   $split = explode(" ", $p1);
   $res = [];
   foreach ($split as $elem)
   {
   		if ($elem)
   			array_push($res, $elem);
   }
   sort($res);
   return $res;
}
?>
