<div>
	<SCRIPT LANGUAGE="javascript">
		d = new Date();
		window.status = ""+d.getHours()+":" + d.getMinutes()+":" +d.getSeconds()+":";
		document.getElementById("idTime").value = ""+d.getHours()+":" + d.getMinutes()+":" +d.getSeconds();
		document.getElementById("idTimer").innerHTML = ""+d.getHours()+":" + d.getMinutes()+":" +d.getSeconds();
		setupAnimation();
	</SCRIPT>
	<div class = "main_content_text" id = "podval">
	<script> write(); </script>
	<br/ >
	<span style = "text-decoration: underline;"onClick = "clocks = (clocks + 1)%2;"> запустить/остановить часы</span>
	</div>
</div>