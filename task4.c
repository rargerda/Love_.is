#define _CRT_SECURE_NO_WARNINGS
#define width 4
#define height 5
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <stdlib.h>

int main()
{
	srand(time(NULL)); // Подключение случайных чисел 

	setlocale(LC_ALL, "RUS"); // Подключение русского языка 

	int mas[width][height];
	int ** pmas = mas;

	// Заполнение двумерного массива случайными числами
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			*(*(mas + i) + j) = rand() % 100;
		}
	}

	printf("\t\tСгенерированный массив\n\n");

	// Вывод сгенерированного массива 
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			printf("\t%4d", *(*(mas + i) + j));
		}
		printf("\n");
	}

	printf("\n\n");

	// Сумма элементов в каждой строке 
	for (int i = 0; i < width; i++)
	{
		int sum_width = 0;

		for (int j = 0; j < height; j++)
		{
			sum_width += mas[i][j];
		}
		printf("Сумма элементов %d строки: %d\n", i + 1, sum_width);
		printf("\n");
	}

	printf("\n");

	// Сумма элементов в каждом столбце 
	for (int i = 0; i < height; i++)
	{
		int sum_height = 0;
		for (int j = 0; j < width; j++)
		{
			sum_height += mas[j][i];
		}
		printf("Сумма элементов %d столбца: %d\n", i + 1, sum_height);
		printf("\n");
	}

	return 0;
}