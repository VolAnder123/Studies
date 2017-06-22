use strict;
use Search;

my $choice = 1;
while($choice != 0)
{
	system("clear");
	my $title = "\tРасписание транспорта г. Минск\n";
	print $title . "1-Поиск по номеру\n2-Поиск по остановке\n0-Выход из программы\nВведите номер операции: ";
	$choice = <STDIN>;
	if ($choice == 1)
	{
		$title = $title . "\tПоиск по номеру\n";	
		#вводим вид транспорта	
		system("clear");
		print $title . "1-Автобус\n2-Троллейбус\n3-Трамвай\nВыберите вид транспорта: ";
		my $kind = <STDIN>;	
	
		#вводим номер маршрута	
		print "Введите номер маршрута: ";
		my $number = <STDIN>;


		#ищем введенный маршрут	
		my @route = Search->SearchTransport($number, $kind);
	
		system("clear");
		if(@route > 1)
		{
			$title = $title . "\t" . $route[0] . " " . $route[1] . "\n";		
			my $message = "Выберите направление движения: ";
			print $title . "1 - $route[2] --> $route[@route - 1]\n2 - $route[@route - 1] --> $route[2]\n$message";
			my $input = <STDIN>;	
			if($input == "2")
			{			
				for(my $i = 2; $i < (@route-2)/2 + 2; $i++)
				{
					my $temp = $route[$i];
					$route[$i] = $route[@route - $i + 1];
					$route[@route - $i + 1] = $temp;
				}
		
			}		

			system("clear");
			$title = $title . "\t$route[2] --> $route[@route - 1]\n";
			print $title;
			for(my $i = 2; $i < @route; $i++) 
			{
				my $number = $i - 1;		
				print "$number - $route[$i] \n";
			}
			print "Выберите остановку: ";
			$input = <STDIN>;
			$title = $title . "\t$route[$input + 2 - 1]\n";

			system("clear");
			if(@route >= $input + 2)
			{
				#номер, вид транспорта,	искомая остановка, последняя остановка маршрута		
				print $title . Search->SearchShedule($route[0], $route[1], $route[$input + 2 - 1], $route[@route - 1]);
			}
			else
			{	
				print $title . "Вы неправильно выбрали остановку\n";
			}		
		}
		else 
		{
			print $title . "Такой маршрут не найден\n";
		}
	

	}
	elsif($choice == "2")
	{
		$title = $title . "\tПоиск по остановке\n";	

		#вводим вид транспорта	
		system("clear");	
		print $title . "Введите название остановки: ";
		my $input = <STDIN>;
		my @stops = Search->GetStops($input);
		if(@stops > 0)
		{
			my $myStop = $stops[0];

			#если в результате поиска подходят несколько остановок, то выбираем
			#из них одну 
			if(@stops > 1)
			{
				for(my $i = 0; $i < @stops; $i++) 
				{
					my $number = $i + 1;		
					print "$number - $stops[$i] \n";
				}
				print "Выберите остановку: ";
				$input = <STDIN>;
				$myStop = $stops[$input - 1];
			}
		
			$title = $title . "\t" . $myStop . "\n";
			system("clear");

			my @justArray = localtime();
			my $timeNow = $justArray[2] . ":" . $justArray[1];

			print $title;
			print "1 - Вывести расписание после текущего времени ($timeNow)\n";
			print "2 - Вывести расписание на весь день\nВведите номер операции: ";
			$input = <STDIN>;
		
			if($input == 1)
			{
				$title = $title . "\tРасписание после " . $timeNow . "\n";
			}
			else
			{
				$title = $title . "\tРасписание на весь день\n";
			}

			system("clear");
			print $title . "\nВремя Номер Вид Конечная остановка\n" . Search->SearchTransportStop($myStop, $input);		

		}
		else
		{
			print "\nПоиск не дал результатов\n";
		}
	}

	if($choice != "0")
	{
		print "\nНажмите Enter для продолжения...";
		<STDIN>;
	}
}

