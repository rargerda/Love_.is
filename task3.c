#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <malloc.h>

int main()
{
	setlocale(LC_ALL, "RUS"); // Подключение русского языка 

	int size_mas;
	int* mas;

	printf("Введите размер массива(Натуральное число): ");

	scanf("%d", &size_mas); // Ввод размера массива

	mas = (int*)malloc(size_mas * sizeof(int)); // Расширение в памяти 

	// Инициализация массива 
	for (int i = 0; i != size_mas; i++)
	{
		printf("\nВведите элемент массива: ");
		int num = 0;
		scanf("%d", &num);
		mas[i] = num;
	}

	printf("\nСодержимое массива:");

	// Вывод массива
	for (int i = 0; i != size_mas; i++)
	{
		printf(" %d", mas[i]);
	}
	printf("\n");

	free(mas); // Освобождение памяти 

	return 0;
}