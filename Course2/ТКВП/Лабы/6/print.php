<!doctype html>
<html>
<head>
<meta charset="windows-1251">
<title>�����</title>
</head>

<body>

	<?php
		
		echo "���: ".($_POST['firstname']."\n"); 
		echo "<br />"."��������: ".htmlspecialchars($_POST['patronymic']);
		echo "<br />"."�������: ".htmlspecialchars($_POST['surname']);
		echo "<br />"."���� ��������: ".htmlspecialchars($_POST['birthday']);
		
		if($_POST['mailing'])
			echo ("<br />"."�������� ��� ���: ��");
		else
			echo ("<br />"."�������� ��� ���: ���");
		echo "<br />"."���: ".($_POST['gender']);
		echo "<br />"."������� �����: ".($_POST['movie']);
		echo "<br />"."������� ������: ";			
		foreach ($_POST['music'] as $t)
		{
			echo "<br />".$t;
		}
		echo "<br />"."�������� �����: ".htmlspecialchars($_POST['text']);

	?> 
</body>
</html>