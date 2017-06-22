#include <iostream>
#include <Windows.h>
#define xmax 100
#define ymax 100

void main (void)
{  
	int matrix[ymax][xmax], x, y, i, j, row = 0, col = 0, m, n, size = 0;
	double dim = 0;
	bool Exit, answer = false, null = true;	
	char temp[40];
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf("���������� ����� �������, m = ");
	scanf_s("%d", &m);	
	printf("���������� �������� �������, n = ");
    scanf_s("%d", &n);	
	printf("������� �������� ������� (0 ��� 1)\n");	
	for (i = 0; i <= (m - 1); i++)
	{
		fflush(stdin);											
		gets_s(temp);
		x = 0;
		for (j = 0; j <= ((int) strlen(temp) - 1); j++)  //���� �������
			if (temp[j] != ' ') 
			{
				matrix[i][x] = temp[j] - '0';
				x++;
			}
	} 
	printf("������� ����������� ������� ����������: ");
	scanf_s("%d", &size);	
	for (y = 0; y <= (m - 1); y++)
		for (x = 0; x <= (n - 1); x++)
		{
			Exit = true;
			while (matrix[y][x] == 0 && Exit) //���� �������, ������ ���� � ��������� ����������, � ������� �� �������
			{
				i = y;
				j = x;			
				dim = 0;				
				for (;;)
				{
					if ((matrix[y][j] != 0) || (matrix[i][x] != 0) || (i >= m) || (j >= n))//���� ������ � ���� �� ������� �� ����������
					{
						Exit = false;
						i--;
						j--;                                                              //��������, ���� �� �������� ������� ��� ����� �������	
						break;						
					}	
					else
					{
						i++;
						j++;
					}
				}	
				row = 0;
				col = 0;
				Exit = false;				
				while (!Exit && row <= i && col <= j)										//���������, �������� �� ��� ��������� ���������� �������		
					for (row = y; row <= i; row++)
						for (col = x; col <= j; col++)
						{
							if (matrix[row][col] != 0)
							{																
								null = false;
								col = j;
								row = i;
							}
							else
								dim++;
						}
				if (null)			//���� ���������� �������, ��	
				{
					dim = sqrt(dim);  //������� �� �����������
					if (dim == size)					
						answer = true;
				}
			}
		}
	if (answer)
		printf("������� ���������� ������������ %d ����������\n", size);		//���� ����������� ��� ������� ����� �������� �����������, �� ������� ��� ������
	else printf("������� ���������� ������������ %d �� ����������\n", size);	//���� �� �����, �� ���	
	system("pause");
}	