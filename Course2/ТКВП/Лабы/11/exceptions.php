<!doctype html>
<html>
<head>
<meta charset="windows-1251">
<title>������</title>
</head>

<body>

	<?php
		
		$ok = 0;
		
		if(!empty($_POST['email']))
	        {
	           if(preg_match("|^[-0-9a-z_\.]+@[-0-9a-z_^\.]+\.[a-z]{2,6}$|i", $_POST['email']))
	           {         

				  echo $_POST['email']. "  -   ���������� email. <br />";
					$ok = 1;
	           }
	           else
	           {
	              echo $_POST['email']. "  -   �� ���������� email. <br />";  
				  $ok = 0;
	           }
	        }
	        else
	        {
	           echo "�� �� ����� email. <br />"; 
				$ok = 0;
	        } 

			
		if (preg_match("/.[0-9]+./", $_POST['telefon']) && strlen($_POST['telefon']) == 10) 
		{
			
			echo "�������  ���������� <br />";
			$ok = 1;
		}
		else
			echo "�������  ������������ <br />";
			$ok = 0;
			
			
		if (preg_match("/.[a-z]+./", $_POST['pass']))  
		{
			$ok = 1;
			echo "������ ���������� <br />";
		}
		else
		{
			$ok = 0;
			echo "������  ������������ <br />";
		}
			
		if (preg_match("/([\s])/", $_POST['pass']))
		{
			echo "������ ������ ���� ��� �������� <br />";
			$ok = 0;
		}
		
			
		if(strlen($_POST['pass']) < 9)
		{
			$ok = 0;
			echo "������ ������ ���� �� ����� 9 �������� <br />";
		}
		
		if($ok == 1)
		{
		echo "��� ������ ���������";
		}

	?> 
</body>
</html>