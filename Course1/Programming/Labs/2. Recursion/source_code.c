#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <io.h>

void main (void)
{
	void positive_element (int massiv[50], int index);
	int replacement (int n);
	int choice = 0, massiv[50], index = 0, temp_int = 0, n = 0, answer;	
	unsigned i;
	char string[100]="", temp[10]="";
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);	
	printf("��� ������?");
	printf("\n1 - �������� ���������� ��������� ������� �� ��������  n-�� ����� ���������");
	printf("\n2 - ������� ���������� ������������� ��������� � �������\n\n");
	printf("������� ����� �������� (1 ��� 2): ");
	scanf_s("%d%*c", &choice);	
	while(choice != 1 && choice != 2 )
    {
		printf("������! ������� ����� 1 ��� 2: ");	
		fflush(stdin);
		scanf_s("%d%*c", &choice);
    }
	if (choice == 1)//����� ���������
	{
		printf("������� ����� ����������� ����� n: ");
		scanf_s("%d", &n);
		while(n < 1)
		{
			printf("������! ������� ����������� �����: ");	
			fflush(stdin);
			scanf_s("%d%*c", &n);
		}
		answer = replacement(n - 1);
		printf("%d-�� ���� ����� ��������� ����� %d\n",n,answer);
		system("pause");
	}
	if (choice == 2)// ������������� �������� �������
	{
		printf("\n������� �������� �������(����� ������): ");		
		gets_s(string, 100);
		n = strlen(string);
 		for (i =  0; i <= strlen(string); ++i)
			if (string[i] != ' ' && string[i] != '\0')
			{
				temp[temp_int] = string[i];
				++temp_int;
			}
			else
				if (temp != "")
				{
					massiv[index] = atoi(temp);
					++index;
					temp_int = 0;
					ZeroMemory(temp,10);
				}		
		positive_element(massiv, index);	
	}	
}

void positive_element (int massiv[50], int index)
{
	int index_p = 0, positive_mass[50], i;
	for (i = 0; i <= index - 1; ++i)
		if (massiv[i] >0)
		{
			positive_mass[index_p] = massiv[i];
			++index_p;
		}
	printf("������������� �������� �������:");
	for (i = 0; i <= index_p - 1; ++i)
		printf("%d ", positive_mass[i]);
	printf(". �����: %d", index_p);
	printf("\n");
	system("pause");	
}

int replacement (int n)
{
	int Fibonacci (int number, int first, int second);
	int first = 0, second = 1;
	n = Fibonacci(n, first, second);
	return n;	
}

int Fibonacci (int number, int first, int second)
{
	if (number == 0)
		return first;
	else
		return Fibonacci (number - 1, second, first + second);
}