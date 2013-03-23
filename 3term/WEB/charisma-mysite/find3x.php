<?php
//echo file_get_contents('mega_big_text');
$s = file_get_contents('mega_big_text');
$w = split('[[:punct:][:blank:]]+', $s);
//print_r($w);
foreach($w as $wa)
{
	$wa=strtolower($wa); 
	if(!@$test[$wa])
	{	
		$test[$wa]=1;
	}
	else
		$test[$wa]++;
}
foreach($test as $key => $value)
{
	if($value == 3)
		echo "$key ";
}
echo "<br /><br /><br /><br />";
$w = split('[,.;:\'\" %_=[:blank:]]+', $s);
foreach($w as $wa)
{
	if(ereg('(35-[0-9]{2}-[0-9]{2})', $wa, $a))
		echo "$a[1] ";	
}

?>