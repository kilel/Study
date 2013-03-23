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
				<div class = "main_content_text">
				<form action = "reg_status.php", method="POST">
				<input id = "login" name = "login" TYPE="text"  SIZE=20 MAXLENGTH=99 /> <span id = "lod">Логин*</span> <span style = "font-size: smaller;">(латинские символы и цифры. длина от 3 до 20)</span> <br />
				<input id = "password" name = "password" TYPE="password"  SIZE=20 MAXLENGTH=99 /> <span id = "pass">Пароль*</span><span style = "font-size: smaller;"> (латинские символы и цифры. длина от 6 до 20)</span> <br />
				<input id = "password2" name = "password2" TYPE="password"  SIZE=20 MAXLENGTH=99 /> Повторите пароль* <br />
				<input id = "email" name = "email" TYPE="text"  SIZE=20 MAXLENGTH=99 /> <span id = "mali">e-mail*</span> <br />
				<input id = "name" name = "name" TYPE="text"  SIZE=20 MAXLENGTH=99 /> <span>Имя</span> <span style = "font-size: smaller;"> (латинские, кириллистические символы и цифры. длина от 1 до 20)</span> <br />
				<input id = "suranme" name = "surname" TYPE="text"  SIZE=20 MAXLENGTH=99 /> <span>Фамилия</span> <span style = "font-size: smaller;"> (латинские, кириллистические символы и цифры. длина от 1 до 20)</span> <br />
				<input id = "thirdname" name = "thirdname" TYPE="text"  SIZE=20 MAXLENGTH=99 /> <span>Отчество</span> <span style = "font-size: smaller;"> (латинские, кириллистические символы и цифры. длина от 1 до 20)</span> <br />
				<input id = "year" name = "year" TYPE="text"  SIZE=20 MAXLENGTH=99 /> <span id = "yy">Год рождения</span> <br />
				<input id = "day" name = "day" TYPE="text"  SIZE=20 MAXLENGTH=99 /> <span id = "dd">День рождения</span> <br />
				<select id = "month" name = "month">
				<?php 
				for($i = 1; $i <= 12; $i++)
				echo "<option> $i "
				?>
				</select> <span>Месяц рождения</span> <br />
				<span>Краткая информация о себе:</span> <br /><textarea name = "text" cols = "50" rows = "5"></textarea> <br /><br />
				<input TYPE="submit" value = "Принять" onClick = "return check_form();"/>
				<input TYPE="button" value = "Проверить" onClick = "check_form();"/>
				<br />
				<br />
				*Поля, обязательные для заполнения
				
				
				</form>
				</div>
				
			<?php require "podval.php";	?>
			</div>
			
		</div>
	</body>
</html>