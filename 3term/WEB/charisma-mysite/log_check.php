<?php
	$login = trim($_POST["userName"]);
	$pass = trim($_POST["userPass"]);
	$stream = fopen("login.txt", "r");
	$changed = 0;
	while(!feof($stream))
	{
		$l = trim(fgets($stream, 1000));
		$p = trim(fgets($stream, 1000));
		
		if($l == $login && $p == $pass)
		{
			session_start();
			$_SESSION['logged'] = true;
			$_SESSION['log'] = $login;
			$_SESSION['voted'] = false;
			//setcookie("log_charisma", $login, time() + 999999);
			echo("<html> <head> <META HTTP-EQUIV='Refresh' Content='2, URL=index.php' /> </head> јвторизаци€ успешна, переходим на главную страницу..</html>");
			
			$changed = 1;
			break;
		}
	}
	if($changed == 0)
		echo "ƒанна€ св€зка логин-пароль не зарегестрирована на сервере. <br /> <a href = 'index.php'>¬ернутьс€ на главную страницу</a>";
	fclose($stream);
?>