#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <stdlib.h>

int main()
{
	srand(time(NULL)); // Подключение случайных чисел 

	setlocale(LC_ALL, "RUS"); // Подключение русского языка 

	int mas[10];

	for (int i = 0; i < 10; i++) // Проход по массиву 
	{
		mas[i] = rand() % 1000; // Инициализация массива случайными числами
	}

	printf("\n");

	printf("Сгенерированный массив из 10 элементов:");

	for (int i = 0; i < 10; i++)
	{
		printf(" %d", mas[i]); // Вывод сгенерированного массива 
	}

	printf("\n");

	return 0;
}