#include <stdio.h>
#include <Windows.h>

int main()
{
	int m = 0, number, last, penultimate, temp, inc = 0, dec = 0;
	int increase_array[10000], decrease_array[10000];
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf("\t ����� ��� ����������� �����, �� ������������� ��������� m, ����������");
	printf("\n ������ ������� ���� ������ ������������� ��� ������ ���������");
	printf("\n ������������������ ���� \n \n \n");
	printf("\t ������� ����������� ����� m:");
	scanf_s("%d", &m);
	if (m > 0)
	{
		for (number = 10; number <= m; ++number)
		{
			temp = number;
			last = temp % 10;	//��������� ����� � �����
			penultimate = (temp % 100) / 10;//������������� ����� � �����			
			if (last > penultimate)
			{
				while (temp >= 10)
				{
					temp = temp / 10;
					last = penultimate;	//��������� ����� � �����
					penultimate = (temp % 100) / 10;//������������� ����� � �����
					if (last <= penultimate)
						break;
				}
				if (temp < 10)
				{
					increase_array[inc] = number;
					++inc;
				}
			}
			else if (last < penultimate)
			{
				while (temp >= 10)
				{
					temp = temp / 10;
					last = penultimate;	//��������� ����� � �����
					penultimate = (temp % 100) / 10;//������������� ����� � �����
					if (last >= penultimate)
						break;
				}
				if (temp < 10)
				{
					decrease_array[dec] = number;
					++dec;
				}
			}
		}
		printf("\n");
		printf("\t ������������� ������������������ ����:");
		for (number = 0; number < inc; ++number)
			printf("%d ", increase_array[number]);
		printf("\n \n \t ��������� ������������������ ����:");
		for (number = 0; number < dec; ++number)
			printf("%d ", decrease_array[number]);
	}
	else
		printf("\n\t������! ������� ����������� �����");
	printf("\n \n");
	system("pause");
	return 0;
}
