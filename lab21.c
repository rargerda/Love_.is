#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#define q 8000
#define w 8000
#pragma comment(linker, "/STACK:615246573000")
int main(void)
{
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);

	setlocale(LC_ALL, "RUS");

	clock_t start, end; // ��������� ���������� ��� ����������� ������� ����������

	int i = 0, j = 0, r;
	int a[q][w], b[q][w], c[q][w], elem_c;

	srand(time(NULL)); // �������������� ��������� ���������� ��������� �����
	while (i < q)
	{
		while (j < w)
		{
			a[i][j] = rand() % 100 + 1; // ��������� ������ ���������� �������
			j++;
		}
		i++;
	}
	srand(time(NULL)); // �������������� ��������� ���������� ��������� �����
	i = 0; j = 0;
	while (i < q)
	{
		while (j < w)
		{
			b[i][j] = rand() % 100 + 1; // ��������� ������ ���������� �������
			j++;
		}
		i++;
	}
	start = clock(); // ������ ������� ������� 
	for (i = 0; i < q; i++)
	{
		for (j = 0; j < w; j++)
		{
			elem_c = 0;
			for (r = 0; r < w; r++)
			{
				elem_c = elem_c + a[i][r] * b[r][j];
				c[i][j] = elem_c;
			}
		}
	}
	end = clock() - start; // ����� ������� ������� 
	printf("������ ������� %dx%d\n\n", q, w);
	printf("����� ������: %lf", (double)end / CLOCKS_PER_SEC);
	return(0);
}
