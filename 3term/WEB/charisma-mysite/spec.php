<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd"/>
<html>
	<head>
		<title>Неофициальный сайт группы Харизма</title>
		<link rel="stylesheet" type="text/css" href="stylesheet1.css"/>
		
	</head>	

	<body onresize = "change();">
	<script ">
				var bdc = 1000, aaa = 1000, dx = 5, timer;
				var clocks = 1;
				function change()
				{
					aaa = document.body.clientWidth;
					if(aaa > 800)
						{
						document.getElementById("main-info").setAttribute("style", "width: " + (aaa-190) + "px;");
						document.getElementById("podval").setAttribute("style", "width: " + (aaa-190) + "px;");
						}
					if(document.getElementById("main-info").clientHeight < 600)
						document.getElementById("main-info").style.height = 600;
					//body-space.style.width = aaa - 190;
					if(clocks == 1)
					{
						d = new Date();
						window.status = ""+d.getHours()+":" + d.getMinutes()+":" +d.getSeconds();
						document.getElementById("idTime").value = ""+d.getHours()+":" + d.getMinutes()+":" +d.getSeconds();
						document.getElementById("idTimer").innerHTML = ""+d.getHours()+":" + d.getMinutes()+":" +d.getSeconds();
						
					}
				}
				function setupAnimation()
				{
					timer=window.setInterval("change()",1);
				}
				function changeImg()
				{
					document.getElementById("image").setAttribute("src", "images/Leo-1.jpg");
					document.getElementById("user-info").setAttribute("style", "background-color: red;");
					
				}
				function changeBackImg()
				{
					document.getElementById("image").setAttribute("src", "images/news_1.jpg");
					document.getElementById("user-info").setAttribute("style", "background-color: #efefef;");
				}
				function write()
				{
					var t = Date();
					document.write("Поселдние измения внесены " + document.lastModified + "<br />");
					document.write("Дата и время загрузки страницы: " + t.toLocaleString()+ "<br />");
					var an = navigator.appName;
					var av = navigator.appVersion;
					var acn = navigator.appCodeName;
					var ua = navigator.userAgent;
					document.write("Версия ПА " +av+ ".");					
				}
	</script>
	
	
<?php 
	require "head.php";
?>
		<div id = "body-space" >
			<?php 
				require "body.php";
			?>
			
			<SCRIPT LANGUAGE="javascript">
				d = new Date();
				window.status = ""+d.getHours()+":" + d.getMinutes()+":" +d.getSeconds()+":";
				document.getElementById("idTime").value = ""+d.getHours()+":" + d.getMinutes()+":" +d.getSeconds();
				document.getElementById("idTimer").innerHTML = ""+d.getHours()+":" + d.getMinutes()+":" +d.getSeconds();
				setupAnimation();
			</SCRIPT>
			<div class = "main_content_text" id = "podval"">
			<script> write();  </script>
			<br/ >
			<span  style = "text-decoration: underline;"onClick = "clocks = (clocks + 1)%2;"> запустить/остановить часы</span>
			</div>
		</div>
	</body>
</html>