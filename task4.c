#define _CRT_SECURE_NO_WARNINGS
#define width 4
#define height 5
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <stdlib.h>

int main()
{
	srand(time(NULL)); // ����������� ��������� ����� 

	setlocale(LC_ALL, "RUS"); // ����������� �������� ����� 

	int mas[width][height];
	int ** pmas = mas;

	// ���������� ���������� ������� ���������� �������
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			*(*(mas + i) + j) = rand() % 100;
		}
	}

	printf("\t\t��������������� ������\n\n");

	// ����� ���������������� ������� 
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			printf("\t%4d", *(*(mas + i) + j));
		}
		printf("\n");
	}

	printf("\n\n");

	// ����� ��������� � ������ ������ 
	for (int i = 0; i < width; i++)
	{
		int sum_width = 0;

		for (int j = 0; j < height; j++)
		{
			sum_width += mas[i][j];
		}
		printf("����� ��������� %d ������: %d\n", i + 1, sum_width);
		printf("\n");
	}

	printf("\n");

	// ����� ��������� � ������ ������� 
	for (int i = 0; i < height; i++)
	{
		int sum_height = 0;
		for (int j = 0; j < width; j++)
		{
			sum_height += mas[j][i];
		}
		printf("����� ��������� %d �������: %d\n", i + 1, sum_height);
		printf("\n");
	}

	return 0;
}