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
			<div>
				<div class = "main_content_text">
					<br/> <br />
					<em>������� ������� ������</em>
					<br/> <br />
					������ ������� ������� � ����� 2004 ���� ����������� ���������� �������� ������� (������, �������, ���������), ���������� �������� ��������� � ������� ������� ����� � �������� ����������� ������, ������� ���������� ����������.<br/> <br />
					����������� ���������� ������ ������� ����� ������ � ��������� ����� �������� ���������� �������� - ������, ������, ��������, Archontes. ����� ����������� ������ ��������� ������ ���������� ��� power metal � ������ ��������� ����������� ������� �����.<br/> <br />
					��������� ���������� ����������� ��������� ������������ � ������������� ����������, ����� ������� ������� � ����� ����������� ���.<br/> <br />
					����������� ����� ����� ������ ����-��������� ������ ������� ���������� �������� ���������� ����������������� �������� ��������� ������. �� ������ ������ ������ ��������� �������� ������ ��������� ����� �� ����� ��������� ������(������ 2005 ����) � ����� �������� ���������� ������������ (������ ��� ������� �� ������ ������ ������� ������� ��� ������������ ����� �����������)<br/> <br />
				</div>
				
			</div>
				<br />
				<div class = "main_content_img">
				<?php
				$er = $_GET['name'];
				for($i = 1; $i <=5; $i++)
				{
					
					echo ("<img src = 'images/");
					echo $er;
					echo "-";
					echo $i;
					echo '.jpg\' width = "400"><br /><br />';
				}
				?>
				</div>
				
				
			<?php require "podval.php";	?>
			</div>
			

			
		</div>
	</body>
</html>