
<html>
<head>
<meta charset="windows-1251">
<title>10 lab</title>
</head>

<body>
<h2>�������</h2>
	<p>������� � ������<br />
	<strong>� 6 ��� ����� � �����</strong></p>
	<hr/>
	<h2>�����</h2>

	<p>�������� � ����� � 2001 ����<br />
	��������� � ��� 11 ���<br />
	<em>� 2012 �������� �����</em></p>
	<hr/>
	<h2>������</h2>
	<p><strong>� 2012 �������� � �����</strong><br/>
	...</p>
<?php

session_start(); 
		$day = $_SESSION['test11'];
		$month = $_SESSION['test22'];
		$year = $_SESSION['test33'];
		$week = $_SESSION['test44'];
		$born = $_SESSION['born'];
echo "����: ".dates()."<br />";
echo "���� � �����: ".datetime()."<br />";
echo "���� ��������: ".dateBorn()."<br />";
echo "���� �� ��� ��������: ".dateBorn2()."<br />";

//foreach(dateBorn3() as $key => $value )
//		echo "$key = $value <br />";
foreach(birthday($born) as $key => $value )
		echo "$key = $value <br />";

	function dates()
	{
		$date = date("j-m-Y");
		return $date;
		
	}
	
	function datetime()
	{
		$date = date("r");
		return $date;
	}
	
	function dateBorn()
	{
		$date = $GLOBALS["day"]."-".$GLOBALS["month"]."-".$GLOBALS["year"];
		return $date;	
	}
	
	function dateBorn2()
	{
		$dayto = 0;
		$date = $GLOBALS["day"]."-".$GLOBALS["month"]."-".date("Y");
		$date2 = date("j-m-Y");
		$dayto = 365 - abs(floor((strtotime($date)-strtotime($date2))/(3600*24)));
		return $dayto;	
	}
	
	
	function birthday($sec_birthday)
	{
		$sec_now = time();
		$happy2 = array();
		for($time = $sec_birthday, $month = 0; $time < $sec_now; $time += date('t', $time) * 86400, $month++)
			$rtime = $time;
		$month = $month - 1;
		$year = intval($month / 12);
		$month = $month % 12;
		$day = 365 - dateBorn2();
		$week = abs($GLOBALS["week"] - date("W"));
		$hours = (365 - dateBorn2()) * 24;
		$minute = (365 - dateBorn2()) * 24 * 60;
		$happy["day"] = $day;
		$happy["month"] = $month;
		$happy["year"] = $year;
		$happy["week"] = $week;
		$happy["hours"] = $hours;
		$happy["minute"] = $minute;
		return $happy;
	}
	
?>

</body>
</html>