#include <iostream>
#include <Windows.h>
#include <string.h>  
#define LONG_STR 1000  
#define MAX_WORD 1000 

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int i, k = 0, length, choice = 0; 
	char *word[MAX_WORD], *p, separator[] = " ,.?!;:", str[LONG_STR] = "", r, *opa[1], temp[LONG_STR];	
	printf("������� ���������� �����: ");
	scanf("%d", &choice);
	fflush(stdin);
	printf("������� �����\n");
	for (i = 0; i < choice; i++)
	{
		gets_s(temp);
		strcat(str, temp);//��������� ������
		strcat(str, " ");
	}	 
	puts("\n��� ����� � ������ �������: \n"); 
	p = strtok(str, separator); //�������� �� ������ �����
	while (p) 
	{ 
		length = strlen(p);
		for (i = 0; i < (int) (strlen(p) / 2); i++)
		{
			length--;
			r = p[i];
			p[i] = p[length];			
			p[length] = r;			
		}
		word[k++] = p;           
		p = strtok(NULL, separator);
	}  
	length = k;
	for (i = 0; i < k / 2; i++)
	{
		length--;
		opa[0] = word[i];
		word[i] = word [length];
		word [length] = opa[0];
	}
	for (i = 0; i < k; i++)	
		printf("%s ", word[i]); 
	printf("\n");
   	system("pause");
}