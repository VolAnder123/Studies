<!doctype html>
<html>
<head>
<meta charset="windows-1251">
<title>������ 50 ������ �����. ����������</title>
</head>

<body>

	<?php
		echo "������ 50 ������ �������������� ����������:"."<br/>";
		$an = $_POST['a0'];
		$summa = 0;
		for($i = 0; $i < 50; $i++)
		{
			echo ' '.$an;
			$an = ($an - 1) + 15;
			$summa += $an;
		}
	echo "<br/>"."����� = ".$summa;
	?> 
</body>
</html>