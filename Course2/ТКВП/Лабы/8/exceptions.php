<!doctype html>
<html>
<head>
<meta charset="windows-1251">
<title>8 ����</title>
</head>

<body>
<?php

if (isset($_POST['submitt'])) {
	$error = '';	
	if ((!preg_match("/^[a-zA-Z]+$/", $_POST['firstname'])) ) 
	$error.= "<p style=color:red>������ � ���� ���<br></p>";
	
	if ((!preg_match("/^[a-zA-Z]+$/", $_POST['patronymic']))) 
	$error.= "<p style=color:red>������ � ���� ��������<br></p>";
	
	if ((!preg_match("/^[a-zA-Z]+$/", $_POST['surname']))) 
	$error.= "<p style=color:red>������ � ���� �������<br></p>";	
	
	if ($error)
	echo "<b style=color:red>��������� ������: ".$error."</b>";
	else {
		echo $_POST['surname']." ".$_POST['firstname']." ".$_POST['patronymic'];
		
		if ($_POST['gender'] == "Male")
			echo " ������� ";
		else 
			echo " �������� ";
		echo $_POST['birthday']."<br>";		
		
		echo "����� ����� ".$_POST['movie']."<br>";
		
		if (!empty($_POST['music'])) 
		{
			echo "����� ������: ";
			foreach ($_POST['music'] as $song){
				echo "<br>".$song;
				}
		}
		else
			echo "�� ����� ������";
	}
}
?>

<?
if (!isset($_POST['send']) || $error):
?>

<form action="?" method="post">
			<h2><b>������ ����������</b></h2>
			<p><b>���:</b>
				<input type="text" name="firstname" size="40">
			</p>	
			<p><b>��������:</b>
				<input type="text" name="patronymic" size="40">
			</p>
			<p><b>�������:</b>
				<input type="text" name="surname" size="40">
			</p>
			<p><b>���� ��������:</b>
				<input type="text" name="birthday" size="40">
			</p>
			<p><b>��� ���:</b></p>
			<p>
				<input type="radio" name="gender" value="Male" checked="true">�������<Br>
				<input type="radio" name="gender" value="Female">�������<Br>
			</p>
			<p><b>����������� �� ��������</b>
				<input type="checkbox" name="mailing" size="40" checked = "true">
			</p>			
			<hr/>
			
			<h2><b>������������</b></h2>
			<p><b>������� �����:</b>
				<select name='movie'>
					<option>Back in the future</option>
					<option>Inglorious bustards</option>
					<option>Pirate of the Caribbean</option>
					<option>Predator</option>
				</select>
			</p>
			<p><b>������� ����� ������:</b></p>
			<p>
				<select name='music[]' multiple='multiple' size='3'>
					<option>Trance</option>
					<option>Pop</option>
					<option>Rock</option>
				</select>
			</p>	
			<hr/>	
			
			<h2><b>�������� �����</b></h2>
			<p><textarea rows="10" cols="45" name="text"></textarea></p>
			<hr/>
			
			<input type="submit" name="submitt" size="40">
		</form>		







<?
endif;
?>
</body>
</html>