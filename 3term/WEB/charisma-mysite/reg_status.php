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
			<br /><br />
				<div class = "main_content_text">
				<?php
					function checkLP($A, $i)
					{
						ereg("([a-zA-Z0-9]{".$i.",20})", $A, $a);
						if(strcasecmp($a[1], $A) == 0  )
							return false;
						else return true;
					}
					function checkNS($A)
					{
						ereg("([а-яА-Яa-zA-Z0-9]{1,20})", $A, $a);
						if(strcasecmp($a[1], $A) == 0)
							return false;
						else return true;
					}
					$wtf = 1;
					$name = $_POST['name'];
					$sur = $_POST['surname'];
					$third = $_POST['thirdname'];
					$email = $_POST['email'];
					$login = $_POST['login'];
					$pass = $_POST['password'];
					if ( checkLP($login, 3))
					{
						echo "Некорректно введён логин! \"$login\"<br />";
						$wtf = 0;
					}
					if( checkLP($pass, 6))
					{
						echo "Некорректно введён пароль! <br />";
						$wtf = 0;
					}
					if( checkNS($name))
					{
						echo "Некорректно введено имя! \"$name\"<br />";	
						$wtf = 0;
					}
					if( checkNS($sur))
					{
						echo "Некорректно введена фамилия! \"$sur\"<br />";	
						$wtf = 0;
					}
					if(checkNS($third))
					{
						echo "Некорректно введено отчество! \"$third\"<br />";	
						$wtf = 0;
					}
					
					if($wtf == 1)
					{
						echo "<br /><br />";
						$handle = fopen("login.txt", "r");
						$changed = 0;
						while(!feof($handle))
						{
							$l = trim(fgets($handle, 1000));
							$p = trim(fgets($handle, 1000));
							if($l == $login)
							{
								echo "Пользователь под таким логином уже зарегестирован. Выберите другой логин.";
								$changed = 1;
								break;
							}
						}
						if($changed == 0 && strlen($login) > 2)
						{
						
							fclose($handle);
							$handle = fopen("login.txt", "at");
							fputs($handle, "\r\n");
							fputs($handle, $login);
							fputs($handle, "\r\n");
							fputs($handle, $pass);
							fclose($handle);
							$handle = fopen("user", "at");
							fputs($handle, "\r\n");
							fputs($handle, "_".$login);
							fputs($handle, "|");
							fputs($handle, $name);
							fputs($handle, "|");
							fputs($handle, $sur);
							fputs($handle, "|");
							fputs($handle, $third);
							fputs($handle, "|");
							fputs($handle, "d".$_POST['day']);
							fputs($handle, "|");
							fputs($handle, "m".$_POST['month']);
							fputs($handle, "|");
							fputs($handle, "y".$_POST['year']);
							fclose($handle);
							echo "Пользователь под логином $login был успешно зарегестрирован";
						}
						else
							echo "вы дурак, зачем открыли эту страницу напрямую?";
					}
				?>
				</div>
				<br /><br />
				<?php require "podval.php";	?>
			</div>
			
			
		</div>
	</body>
</html>