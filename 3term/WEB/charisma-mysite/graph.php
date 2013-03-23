<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd"/>
<html>
	<head>
		<title>Неофициальный сайт группы Харизма</title>
		<link rel="stylesheet" type="text/css" href="stylesheet1.css"/>
		
	</head>	

	<body onresize = "change();">
		<?php require "head.php"; ?>
		<div id = "body-space" >
		<?php require "left-panel.php"; ?>
		<div id = "main-info">
			<div>
				<div class = "main_content_img">
					<?php
					$stream = fopen("user", "r");
					$login = $_SESSION['log'];
					while(!feof($stream))
					{
						$user = trim(fgets($stream, 1000));
						ereg("(_[a-zA-Z0-9]{3,20})",$user, $name);
						$name = substr($name[1], 1);
						if($name == $login)
						{
							//echo $user;
							break;
						}
					}
					ereg("(d[0-9]{1,2})",$user, $d);
					ereg("(m[0-9]{1,2})",$user, $m);
					ereg("(y[0-9]{4})",$user, $y);
					$d = substr($d[1], 1);
					$m = substr($m[1], 1);
					$y = substr($y[1], 1);
					//echo "$d $m $y";
					//print_r($y);
					$birth = floor((date("Y") - $y)*365.25);
					//echo " $birth";
					$month = Array(0,31,28,31,30,31,30,31,31,30,31,30,31);
					for($i = 1; $i < $m; $i++)
						$birth -= $month[$i];
					$birth -= $d;
					//нарисовать кучу линий plot(sin(x*Pi*2/5 - 2*Pi*2/5), x = -2..5);
					//периодами:физический-22,6884 дня, эмоциональный-28,4261 дня,интеллектуальный-33,1638 дня
					$imag = ImageCreateFromJPEG("temp_file/8600.jpg");
					$a[1] = sin(($birth-10)*6.28/22.6884);
					$a[2] = sin(($birth-10)*6.28/28.4261);
					$a[3] = sin(($birth-10)*6.28/33.1638);
					$i = -10;
					$blue = ImageColorAllocate($imag, 0,0,255);
					$green = ImageColorAllocate($imag, 0,255,0);
					$red = ImageColorAllocate($imag, 255,0,0);
					$black = ImageColorAllocate($imag, 0,0,0);
					while($i < 10)
					{
						$a[1] = sin(($birth+$i)*6.28/22.6884);
						$a[2] = sin(($birth+$i)*6.28/28.4261);
						$a[3] = sin(($birth+$i)*6.28/33.1638);
						$a[4] = sin(($birth+$i+0.5)*6.28/22.6884);
						$a[5] = sin(($birth+$i+0.5)*6.28/28.4261);
						$a[6] = sin(($birth+$i+0.5)*6.28/33.1638);
						imageline($imag, ($i+10)*40, $a[1]*250+250, ($i+10.5)*40, $a[4]*250+250, $blue);
						imageline($imag, ($i+10)*40, $a[2]*250+250, ($i+10.5)*40, $a[5]*250+250, $green);
						imageline($imag, ($i+10)*40, $a[3]*250+250, ($i+10.5)*40, $a[6]*250+250, $red);
						$i += 0.5;
					}
					imagestring($imag,5, 700, 530, "Strength", $blue);
					imagestring($imag,5, 700, 555, "Emotions", $green);
					imagestring($imag,5, 700, 580, "Intellect", $red);
					imagestring($imag,5, 405, 305, "Now!", $black);
					imageline($imag, 0, 300, 800, 300, $black);
					imageline($imag, 785, 305, 815, 300-5, $black);
					imageline($imag, 785, 300-5, 815, 300+5, $black);
					imageline($imag, 400, 600, 400, 0, $black);
					imageline($imag, 400-5, 15, 400+5, -15, $black);
					imageline($imag, 400+5, 15, 400-5, -15, $black);
					ImageJPEG($imag, 'temp_file/8800.jpg', 100);
					
					echo "<img src = \"temp_file/8800.jpg\">";
					?>
				</div>
				<span>______________________</span>
			</div>
			
			<?php require "podval.php";	?>
		</div>
	</body>
</html>