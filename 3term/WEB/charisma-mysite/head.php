<?php session_start();?>
<script >
				var bdc = 1000, aaa = 1000, dx = 5, timer;
				var clocks = 1;
				var do_once = 1;
				function change()
				{
					aaa = document.body.clientWidth;
					if(aaa > 820)
						{
						document.getElementById("main-info").setAttribute("style", "width: " + (aaa-190) + "px;");
						document.getElementById("podval").setAttribute("style", "width: " + (aaa-190) + "px;");
						}
					if(do_once == 1)
					{
					do_once = 0;
					aaa = document.getElementById("main-info").clientHeight;
						document.getElementById("main-info").setAttribute("style", "height: "+ (600)+ "px;");
						
					bbb =  document.getElementById("birthday").clientHeight + document.getElementById("voting").clientHeight;
					document.getElementById("user-info").setAttribute("style", "height: " + (bbb + 300)+ "px;");
					if(document.getElementById("user-info").clientHeight < 400)
					document.getElementById("user-info").setAttribute("style", "height: 400px;");
					}
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
					ui = document.getElementById("user-info");
					document.getElementById("image").setAttribute("src", "images/Leo-1.jpg");
					bbb =  document.getElementById("birthday").clientHeight + document.getElementById("voting").clientHeight;
					ui.setAttribute("style", "height: " + (bbb + 300)+ "px;background-color: red;");
					if(document.getElementById("user-info").clientHeight < 400)
					ui.setAttribute("style", "height: 400px;background-color: red;");
				}
				function changeBackImg()
				{
					document.getElementById("image").setAttribute("src", "images/news_1.jpg");
					document.getElementById("user-info").setAttribute("style", "background-color: #efefef;");
					do_once = 1;
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
				function check_form()
				{
					CANSEND = 1
					var p1 = document.getElementById("password").value;
					var p2 = document.getElementById("password2").value;
					var year = document.getElementById("year").value;
					var day = document.getElementById("day").value;
					var mali = document.getElementById("email").value;
					var log = document.getElementById("login").value;
					if((p1 != p2) || !p1)
						{
						document.getElementById("pass").setAttribute("style", "color: red");
						CANSEND = 0;
						}
					else
						document.getElementById("pass").setAttribute("style", "color: green");
					if((year <= 2000 && year >= 1920) || !year)
						document.getElementById("yy").setAttribute("style", "color: green");
					else
					{
						document.getElementById("yy").setAttribute("style", "color: red");
						CANSEND = 0;
					}
					if((day >= 1 && day <= 31) || !day)
						document.getElementById("dd").setAttribute("style", "color: green");
					else
						{
						CANSEND = 0;
						document.getElementById("dd").setAttribute("style", "color: red");
						}
					if(mali.match(/^([-a-zA-Z0-9._]+@[-a-zA-Z0-9.]+(\.[-a-zA-Z0-9]+)+)*$/i) && mali)
						document.getElementById("mali").setAttribute("style", "color: green");
					else
					{
						document.getElementById("mali").setAttribute("style", "color: red");
						CANSEND = 0;
					}
					if(!log)
						{
						CANSEND = 0;
						document.getElementById("lod").setAttribute("style", "color: red");
						}
					else
						document.getElementById("lod").setAttribute("style", "color: green");
						
					if(CANSEND == 0)
						return false;
				}
	</script>
	
	
	<div id = "logo">
		<div class = "one">
			<a class = "logo" href = "index.php">Харизма</a> 
		</div>
		<div class = "two" id = "idTimer">
			sssss
		</div>
	</div>