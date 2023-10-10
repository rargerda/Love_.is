#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h> 

struct node
{
	char inf[256];     // �������� ����������
	struct node* next; // ������ �� ��������� �������
};

struct node* top = NULL; // ��������� �� ������� �����

void push(void);      // ���������� �������� � ����
void pop(void);       // �������� �������� �� �����
void display(void);   // �������� ����������� �����
void saveToFile(void); // ���������� ������ ����� � ����
void loadFromFile(void); // �������� ������ ����� �� �����

struct node* get_struct(void)
{
	struct node* p = NULL;
	char s[256];

	if ((p = (struct node*)malloc(sizeof(struct node))) == NULL) // �������� ������ ��� ����� ������� �����
	{
		printf("������ ��� ������������� ������\n");
		exit(1);
	}

	printf("������� �������� �������: \n"); // ������ ������
	scanf("%s", s);
	if (*s == 0)
	{
		printf("������ �� ���� �����������\n");
		return NULL;
	}
	strcpy(p->inf, s);

	p->next = NULL;

	return p; // ���������� ��������� �� ��������� �������
}

/* ���������� �������� � ���� */
void push(void)
{
	struct node* p = NULL;
	p = get_struct();
	if (p != NULL)
	{
		p->next = top;
		top = p;
	}
}

/* �������� �������� �� ����� (� �������) */
void pop(void)
{
	if (top == NULL)
	{
		printf("���� ����\n");
		return;
	}

	struct node* temp = top;
	top = top->next;
	free(temp);
}

/* �������� ����������� ����� */
void display(void)
{
	struct node* struc = top;
	if (top == NULL)
	{
		printf("���� ����\n");
	}
	while (struc)
	{
		printf("%s \n", struc->inf);
		struc = struc->next;
	}
}

/* ���������� ������ ����� � ���� */
void saveToFile(void)
{
	FILE* file;
	struct node* struc = top;

	if (top == NULL)
	{
		printf("���� ����, ��� ������ ��� ����������\n");
		return;
	}

	file = fopen("stack.txt", "w");
	if (file == NULL)
	{
		printf("������ ��� �������� �����\n");
		return;
	}

	while (struc)
	{
		fprintf(file, "%s\n", struc->inf);
		struc = struc->next;
	}

	fclose(file);
	printf("������ ����� ������� ��������� � �����\n");
}

/* �������� ������ ����� �� ����� */
void loadFromFile(void)
{
	FILE* file;
	char s[256];

	file = fopen("stack.txt", "r");
	if (file == NULL)
	{
		printf("���� �� ������ ��� ������ ��� ��������\n");
		return;
	}

	while (fscanf(file, "%s", s) != EOF)
	{
		struct node* p = (struct node*)malloc(sizeof(struct node));
		if (p == NULL)
		{
			printf("������ ��� ������������� ������\n");
			exit(1);
		}
		strcpy(p->inf, s);
		p->next = top;
		top = p;
	}

	fclose(file);
	printf("������ �� ����� ������� ��������� � ����\n");
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int choice;

	while (1)
	{
		printf("\n�������� ��� ������:\n");
		printf("1. �������� ������� � ����\n");
		printf("2. ������� ������� �� �����\n");
		printf("3. ����������� ���������� �����\n");
		printf("4. ��������� ������ ����� � ����\n");
		printf("5. ��������� ������ ����� �� �����\n");
		printf("6. �����\n");
		printf("������� �����: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			push();
			break;
		case 2:
			pop();
			break;
		case 3:
			display();
			break;
		case 4:
			saveToFile();
			break;
		case 5:
			loadFromFile();
			break;
		case 6:
			exit(0);
		default:
			printf("������������ �����\n");
		}
	}
	return 0;
}
