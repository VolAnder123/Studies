<!doctype html>
<html>
<head>
<meta charset="windows-1251">
<title>�������������� ����������</title>
</head>

<body>
	<?php
		echo "������ 50 ������ �������������� ����������:"."<br/>";
		$bn = $_POST['b0'];
		$summa = 0;
		for($n = 1; $n <= 50; $n++)
		{
			echo ' '.(float)$bn;
			$summa += $bn;
			$bn = (float)pow((-1), $n) * 1.5 * $bn;			
		}
	echo '<br/>'."����� = ".$summa;
	?> 
</body>
</html>