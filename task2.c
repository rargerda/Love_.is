#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <stdlib.h>

int main()
{
	srand(time(NULL)); // ����������� ��������� ����� 

	setlocale(LC_ALL, "RUS"); // ����������� �������� ����� 

	int mas[10];

	for (int i = 0; i < 10; i++) // ������ �� ������� 
	{
		mas[i] = rand() % 1000; // ������������� ������� ���������� �������
	}

	printf("\n");

	printf("��������������� ������ �� 10 ���������:");

	for (int i = 0; i < 10; i++)
	{
		printf(" %d", mas[i]); // ����� ���������������� ������� 
	}

	printf("\n");

	return 0;
}