#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <malloc.h>

int main()
{
	setlocale(LC_ALL, "RUS"); // ����������� �������� ����� 

	int size_mas;
	int* mas;

	printf("������� ������ �������(����������� �����): ");

	scanf("%d", &size_mas); // ���� ������� �������

	mas = (int*)malloc(size_mas * sizeof(int)); // ���������� � ������ 

	// ������������� ������� 
	for (int i = 0; i != size_mas; i++)
	{
		printf("\n������� ������� �������: ");
		int num = 0;
		scanf("%d", &num);
		mas[i] = num;
	}

	printf("\n���������� �������:");

	// ����� �������
	for (int i = 0; i != size_mas; i++)
	{
		printf(" %d", mas[i]);
	}
	printf("\n");

	free(mas); // ������������ ������ 

	return 0;
}