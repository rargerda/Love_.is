#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <string.h>

struct Student
{
	char surname[15]; // ������� 
	char name[15]; // ���
	char group[7]; // ������
	char data[11]; // ���� �������� 
} student1 = { "Baikov", "Alexey", "22���3", "19.05.2004" }, student2 = { "Geraskina", "Daria", "22���3", "19.05.2004" },
student3 = { "Yrtaev", "Dmitriy", "22���2", "20.06.2004" }, student4 = { "Dulatov", "Denis", "22���3", "14.11.2004" },
student5 = { "Razin", "Dmitriy", "22��1", "30.08.2004" }; // ������������ ���������

int main()
{
	int i = 0;
	char surname_res[15]; // ������ ��� ����� ������� �������� 

	setlocale(LC_ALL, "RUS"); // ����������� �������� �����

	printf("\n������� ������� ��������(Baikov, Geraskina, Yrtaev, Dulatov, Razin): ");

	scanf("%s", &surname_res); // ���� ������������� ������� 

	printf("\n");

	// ����� ���������� � ��������� �������� 
	strcmp(surname_res, student1.surname) == 0 ? printf("�������: %s\n���: %s\n������: %s\n���� ��������: %s\n", student1.surname, student1.name,
		student1.group, student1.data) : +i;
	strcmp(surname_res, student2.surname) == 0 ? printf("�������: %s\n���: %s\n������: %s\n���� ��������: %s\n", student2.surname, student2.name,
		student2.group, student2.data) : +i;
	strcmp(surname_res, student3.surname) == 0 ? printf("�������: %s\n���: %s\n������: %s\n���� ��������: %s\n", student3.surname, student3.name,
		student3.group, student3.data) : +i;
	strcmp(surname_res, student4.surname) == 0 ? printf("�������: %s\n���: %s\n������: %s\n���� ��������: %s\n", student4.surname, student4.name,
		student4.group, student4.data) : +i;
	strcmp(surname_res, student5.surname) == 0 ? printf("�������: %s\n���: %s\n������: %s\n���� ��������: %s\n", student5.surname, student5.name,
		student5.group, student5.data) : +i;

	return 0;
}