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
					16 ������� 2010 
					<br/> <br />
					<em>������ ����� ��� ������ 3�� ������� �������!</em>
					<br/> <br />
					����� ������� ��������� ��������� �� ������ ���� ������, ������ ������� ������ ����� ����������	������ 3�� ��������������� ������� ������ !	� ������� ����������� �� ����� 10�� ����������.	�� ������ ������ �������� �������� ���������. � ������ ����-������ ��� ������� �������: <br />
					<ul>
						���� �������(������) <br />
						������� ���������(��������) <br /> 
						���� �����(�������) <br /> 
					</ul>
					��� ������� ���� ������ �������� ���� ���������(�������) � ���� ������(��������). <br /> 
					����� �� ������ ����������� � ������ �������� ���������!<br /> 
					���� �� �������� ������- 3� ������ ������� ������ � ������� 2010 ����.<br /> 
					������ ���� ����������� ����� � �������� ��� ����������� �������.<br /> 
					������� � ����!<br /> 
					<a href = "index.php"> www.charizma.ru</a> <br /> 
					<a href = "http://vkontakte.ru/club127236"> http://vkontakte.ru/club127236</a><br /> 
				</div>
				<span>______________________</span>
			</div>
				<br />
				<div>
					<div class = "main_content_text">
						10 ������� 2010
						<br /> <br />
						<em onmouseover = "changeImg();" onmouseout = "changeBackImg();", onClick = "window.open('about.php', 'about');">�����-���������, 29 �������.</em>
					</div>
					<br />
					<div class = "main_content_img">
						<img src = "images/news_1.jpg" id = "image" width = "434"  />
					</div>
					<span>______________________</span>
				</div>
			<?php require "podval.php";	?>
		</div>
	</body>
</html>