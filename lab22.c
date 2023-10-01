#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void shell(int* items, int count)
{
    clock_t  start_s, end_s;
    int i, j, gap, k;
    int x, a[5];

    a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;
    start_s = clock(); // ������ ������� ������� ������ ������� shell
    for (k = 0; k < 5; k++) {
        gap = a[k];
        for (i = gap; i < count; ++i) {
            x = items[i];
            for (j = i - gap; (x < items[j]) && (j >= 0); j = j - gap)
                items[j + gap] = items[j];
            items[j + gap] = x;
        }
    }
    end_s = clock() - start_s; // ����� ������� ������� ������ ������� shell
    printf("%lf", (double)end_s / CLOCKS_PER_SEC); // ����� ������� ������ ������� shell
}

void qs(int* items, int left, int right) //����� �������: qs(items, 0, count-1);
{
    int i, j;
    int x, y;

    i = left; j = right;

    /* ����� ���������� */
    x = items[(left + right) / 2];

    do {
        while ((items[i] < x) && (i < right)) i++;
        while ((x < items[j]) && (j > left)) j--;

        if (i <= j) {
            y = items[i];
            items[i] = items[j];
            items[j] = y;
            i++; j--;
        }
    } while (i <= j);

    if (left < j) qs(items, left, j);
    if (i < right) qs(items, i, right);
}

// ������� ��� ������ qsort
int comp(const void* i1, const void* i2)
{
    return (*(int*)i1 - *(int*)i2);
}
void work_w_file(char name[14], int* items)
{
    int count = 0;
    clock_t  start_qs3, end_qs3; // ����� ������ qs
    // ���������� ����� �����
    FILE* file_3 = fopen(name, "r");
    fseek(file_3, 0, SEEK_SET);
    while (true)
    {
        int val;
        if (fscanf(file_3, "%d", &val) == 1)
        {
            count++;
        }
        if (feof(file_3))
        {
            break;
        }
    }
    fclose(file_3);
    items = (int*)malloc(count * sizeof(int)); // ���������� ������
    //
    // ������ � ������ �� ����� ��������� �����
    file_3 = fopen(name, "r");
    fseek(file_3, 0, SEEK_SET);
    for (int i = 0; i < count; ++i) {
        fscanf(file_3, "%d", &(*(items + i)));
    }
    fclose(file_3);
    //

    clock_t start3 = clock(), end3; // ������ ������� ������� qsort

    qsort(items, count, sizeof(int), comp); // ����� ������� qsort

    end3 = clock() - start3; // ����� ������ qsort

    printf("  %lf  ", (double)end3 / CLOCKS_PER_SEC); // ����� ������� ������ qsort

    file_3 = fopen(name, "r");
    fseek(file_3, 0, SEEK_SET);
    for (int i = 0; i < count; ++i) {
        fscanf(file_3, "%d", &(*(items + i)));
    }
    fclose(file_3);

    shell(items, count); // ����� ������� shell

    file_3 = fopen(name, "r");
    fseek(file_3, 0, SEEK_SET);
    for (int i = 0; i < count; ++i) {
        fscanf(file_3, "%d", &(*(items + i)));
    }
    fclose(file_3);

    start_qs3 = clock(); // ������ ������� ������� ������ qs
    qs(items, 1, count - 1); // ����� ������� qsort
    end_qs3 = clock() - start_qs3; // ����� ������� ������� ������ qs

    printf("  %lf\n", (double)end_qs3 / CLOCKS_PER_SEC); // ����� ������� ������ qsort
    free(items); // ������������ ������
}

int main(clock_t end_s)
{
    setlocale(LC_ALL, "RUS"); // ����������� �������� �����
    srand(time(NULL)); // ����������� ��������� �����
    char name1[14] = "HeightMas.txt"; // ���� � ������������ ������������������� ����� 
    char name2[14] = "DownMas.txt"; // ���� � ��������� ������������������� ����� 
    char name3[14] = "HeDowMas.txt"; // ���� � ������������-��������� ������������������� ����� 
    int* items; // ��������� 
    int count = 40000; // ������� 

    clock_t  start_qs, end_qs; // ����� ������ qs
    int what; // ��� ����������� ���� ������

    // 1 �������
    printf("\n������\t     qsort      shell      qs\n");
    printf("%d(:::)", count);

    items = (int*)malloc(count * sizeof(int)); // ���������� ������

    // ���������� ���������� ������� 
    for (int i = 0; i < count; i++) {
        *(items + i) = rand() % 100;
    }
    clock_t start = clock(), end; // ������ ������� ������� ������ qsort
    qsort(items, count, sizeof(int), comp); // ����� qsort
    end = clock() - start; // ����� ������� ������� ������ qsort
    printf("  %lf  ", (double)end / CLOCKS_PER_SEC); // ����� ������� ������ qsort


    for (int i = 0; i < count; i++) {
        *(items + i) = rand() % 100;
    }

    shell(items, count); // ����� shell

    for (int i = 0; i < count; i++) {
        *(items + i) = rand() % 100;
    }

    start_qs = clock(); // ������ ������� ������� ������ qs
    qs(items, 0, count - 1); // ����� qs
    end_qs = clock() - start_qs; // ����� ������� ������� ������ qs
    printf("  %lf\n", (double)end_qs / CLOCKS_PER_SEC); // ����� ������� ������ qs
    free(items); // ������������ ������

    // 2 �������
    printf("40000(/)");
    work_w_file(name1, items);

    // 3 �������
    printf("40000(\\)");
    work_w_file(name2, items);


    // 4 �������

    printf("40000(/\\)");
    work_w_file(name3, items);

    return 0;
}

