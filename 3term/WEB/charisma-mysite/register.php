<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd"/>
<html>
	<head>
		<title>������������� ���� ������ �������</title>
		<link rel="stylesheet" type="text/css" href="stylesheet1.css"/>
		
	</head>
	
	<body onresize = "change();">
	
	
	
	<?php require "head.php"; ?>
		<div id = "body-space" >
	<?php require "left-panel.php"; ?>
			<div id = "main-info">
				<div class = "main_content_text">
				<form action = "reg_status.php", method="POST">
				<input id = "login" name = "login" TYPE="text"  SIZE=20 MAXLENGTH=99 /> <span id = "lod">�����*</span> <span style = "font-size: smaller;">(��������� ������� � �����. ����� �� 3 �� 20)</span> <br />
				<input id = "password" name = "password" TYPE="password"  SIZE=20 MAXLENGTH=99 /> <span id = "pass">������*</span><span style = "font-size: smaller;"> (��������� ������� � �����. ����� �� 6 �� 20)</span> <br />
				<input id = "password2" name = "password2" TYPE="password"  SIZE=20 MAXLENGTH=99 /> ��������� ������* <br />
				<input id = "email" name = "email" TYPE="text"  SIZE=20 MAXLENGTH=99 /> <span id = "mali">e-mail*</span> <br />
				<input id = "name" name = "name" TYPE="text"  SIZE=20 MAXLENGTH=99 /> <span>���</span> <span style = "font-size: smaller;"> (���������, ���������������� ������� � �����. ����� �� 1 �� 20)</span> <br />
				<input id = "suranme" name = "surname" TYPE="text"  SIZE=20 MAXLENGTH=99 /> <span>�������</span> <span style = "font-size: smaller;"> (���������, ���������������� ������� � �����. ����� �� 1 �� 20)</span> <br />
				<input id = "thirdname" name = "thirdname" TYPE="text"  SIZE=20 MAXLENGTH=99 /> <span>��������</span> <span style = "font-size: smaller;"> (���������, ���������������� ������� � �����. ����� �� 1 �� 20)</span> <br />
				<input id = "year" name = "year" TYPE="text"  SIZE=20 MAXLENGTH=99 /> <span id = "yy">��� ��������</span> <br />
				<input id = "day" name = "day" TYPE="text"  SIZE=20 MAXLENGTH=99 /> <span id = "dd">���� ��������</span> <br />
				<select id = "month" name = "month">
				<?php 
				for($i = 1; $i <= 12; $i++)
				echo "<option> $i "
				?>
				</select> <span>����� ��������</span> <br />
				<span>������� ���������� � ����:</span> <br /><textarea name = "text" cols = "50" rows = "5"></textarea> <br /><br />
				<input TYPE="submit" value = "�������" onClick = "return check_form();"/>
				<input TYPE="button" value = "���������" onClick = "check_form();"/>
				<br />
				<br />
				*����, ������������ ��� ����������
				
				
				</form>
				</div>
				
			<?php require "podval.php";	?>
			</div>
			
		</div>
	</body>
</html>