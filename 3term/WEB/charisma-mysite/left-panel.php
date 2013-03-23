<div id = "user-info" >
		<br />
		<div ><a class = "info" href = "index.php" >Новости</a></div>
		<div><a class = "info" href = "about.php">О группе </a></div>
		<div><a class = "info" href = "albums.php">Альбомы</a></div>
		<div><a class = "info" href = "title.php">Title</a></div>
		<div><a class = "info" href = "find3x.php">Разбор</a></div>
		<br />
		<form name = "f1" id = "miniClocks" action = "log_check.php", method = "POST">
			<INPUT ID="idTime" TYPE="text"  SIZE=13 MAXLENGTH=13 /> 
			<br />
			<div id = "try_login">
				<?php 
					$slog = $_SESSION['logged'];
					if($slog) 
					{
						$sesslog = $_SESSION['log'];
						echo "<br />Добро пожаловать,<br /> $sesslog<br /><a class = 'info' href = \"graph.php\">График</a><br /> <a class = 'info' href = 'logout.php'>Выйти</a><br /><br />";
					}
					else
						echo "Вход в систему:
						<INPUT name='userName' TYPE='text'  SIZE=6 MAXLENGTH=99 /> Логин <br />
						<INPUT name='userPass' TYPE='text'  SIZE=6 MAXLENGTH=99 /> Пароль
						<INPUT TYPE='submit' value = 'Вход' />
						<a class = 'info' style = 'font-size: 12pt;' href = 'register.php'>Регистрация</a>";
				?>
			</div>
			<div id = 'birthday'>
			<?php
			if($_SESSION['logged'])
				{
				echo "Именинники:";
				
					$m = date("n");
					$handle = fopen("user", "r");
					$i = 0;
					while(!feof($handle))
					{
						
						$user = trim(fgets($handle, 1000));
						
						ereg("(m[0-9]{1,2})",$user, $uk);
						$c = substr($uk[1], 1);
						
						if($c == $m)
						{ 
							$i++;
							ereg("(_[a-zA-Z0-9]{3,20})",$user, $name);
							$name = substr($name[1], 1);
							//echo " $name";
							$no = ImageCreateFromJPEG("images/noimage.jpg");
							$is = ImageCreateFromJPEG("images/Daemon-1.jpg");
							$x = ImageSX($is);
							$y = ImageSY($is);
							ImageCopyResized($no,$is,0,0,0,0,120,180,$x,$y);
							$col = ImageColorAllocate($no, 0,0,255);
							$temp = "temp_file/file$i.jpg";
							imagestring($no,3, 0, 180, "$name", $col);
							ImageJPEG($no, $temp);
							echo "<img src = \"temp_file/file$i.jpg\">"; 
							ImageDestroy($no);
						}
					}
					}
					?>
				</div>
				
			
			
			<div id = "voting">
			<?php
			if($_SESSION['logged'])
			{
			$wanna_vote[1] = "Аниме правит миром";
			$wanna_vote[2] = "Не нравится";
			$wanna_vote[3] = "Терпимо";
			$wanna_vote[4] = "Раздражает";
			$wanna_vote[5] = "Против";
			if(!$_SESSION['voted'])
			echo'	<br />
				Как вы относитесь к аниме?<br />
				<a href = "testres.php?res=1">Аниме правит миром</a><br />
				<a href = "testres.php?res=2">Не нравится</a><br />
				<a href = "testres.php?res=3">Терпимо</a><br />
				<a href = "testres.php?res=4">Раздражает</a><br />
				<a href = "testres.php?res=5">Против</a><br />';
			else
			{
				require 'temp_test';
				$max = $a[1];
				$sum = 0;
				for($i = 1; $i <= 5; $i++)
				{
					$block[$i] = ImageCreateFromJPEG("temp_file/block.jpg");
					if($a[$i] > $max)
						$max = $a[i];
					$sum += $a[$i];					
				}
				if($max == 0)
					$max = 1;
				$block[0] = ImageCreateFromJPEG("temp_file/test_temp_block.jpg");
				for($i = 1; $i <= 5; $i++)
					{
					if($a[$i] != 0)
						ImageCopyResized($block[$i],$block[0],0,0,0,0,150*$a[$i]/$max,5,10,5);
					$temp = "temp_file/block$i.jpg";
					ImageJPEG($block[$i], $temp);
					echo "<a >$wanna_vote[$i]</a><br />";
					echo "<img src = \"temp_file/block$i.jpg\">";
					$b[$i] = $a[$i]/$sum*100;
					echo "<span style = \"font-size:smaller; \">$b[$i]% ($a[$i])</span><br/>";
					}
				}
			}
			?>
			</div>
			
			
		
		</form>
		<br />				
		<span id = "panel_span">Панель управления</span>
	
</div>