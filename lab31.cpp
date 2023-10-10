#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char inputFileName[] = "lear.txt"; // ���� ��� �������� ������� 
char outputFileName[] = "lear.txt"; // ���� ��� ���������� �������

struct node {
	char inf[256];      // �������� ����������
	int priority;       // ���������
	struct node* next;  // ������ �� ��������� �������
};

struct node* head = NULL, * last = NULL, * f = NULL; // ��������� �� ������ � ��������� �������� ������
int len = 0;

struct node* get_struct(void) {
	struct node* p = NULL;
	char s[256];
	int priority;

	if ((p = (struct node*)malloc(sizeof(struct node))) == NULL) {  // �������� ������ ��� ����� ������� ������
		printf("������ ��� ������������� ������\n");
		exit(1);
	}

	printf("������� �������� �������: \n");   // ������ ������
	scanf("%s", s);
	if (*s == 0) {
		printf("������ �� ���� �����������\n");
		return NULL;
	}
	strcpy(p->inf, s);

	printf("\n������� ��������� �������: \n");   // ������ ���������
	scanf("%d", &priority);
	p->priority = priority;

	p->next = NULL;

	return p;       // ���������� ��������� �� ��������� �������
}

/* ���������������� ���������� � ������ �������� (� ������������ � �����������) */
void spstore(void) {
	struct node* p = NULL;
	p = get_struct();
	if (head == NULL && p != NULL) {    // ���� ������ ���, �� ������������� ������ ������
		head = p;
		last = p;
	}
	else if (head != NULL && p != NULL) { // ������ ��� ����, �� ��������� � ������������ � �����������
		struct node* current = head;
		struct node* prev = NULL;

		while (current != NULL && p->priority >= current->priority) {
			prev = current;
			current = current->next;
		}

		if (prev == NULL) {
			// ��������� � ������ ������
			p->next = head;
			head = p;
		}
		else {
			// ��������� ����� prev � current
			prev->next = p;
			p->next = current;
			if (current == NULL) {
				last = p; // ���� p �������� � ����� ������, ��������� last
			}
		}
	}
}

/* �������� ����������� ������. */
void review(void) {
	struct node* struc = head;
	if (head == NULL) {
		printf("\n������ ����\n");
	}
	while (struc) {

		printf("��� - %s, ��������� - %d\n", struc->inf, struc->priority);
		struc = struc->next;
	}
}

/* ����� �������� �� �����������. */
struct node* find(char* name) {
	struct node* struc = head;
	if (head == NULL) {
		printf("\n������ ����\n");
	}
	while (struc) {
		if (strcmp(name, struc->inf) == 0) {
			return struc;
		}
		struc = struc->next;
	}
	printf("\n������� �� ������\n");
	return NULL;
}

/* �������� �������� �� �����������. */
void del(char* name) {
	struct node* struc = head; // ���������, ���������� �� ������ ���������� �� ������ ������
	struct node* prev = NULL;  // ��������� �� �������������� ���������� ��������
	int flag = 0;             // ��������� ���������� ���������� �������� � ������

	if (head == NULL) // ���� ������ ������ ����� NULL, �� ������ ����
	{
		printf("\n������ ����\n");
		return;
	}

	if (strcmp(name, struc->inf) == 0) // ���� ��������� ������� - ������
	{
		flag = 1;
		head = struc->next; // ������������� ������ �� ��������� �������
		free(struc);  // ������� ������ �������
		struc = head; // ������������� ��������� ��� ����������� ������
	}
	else {
		prev = struc;
		struc = struc->next;
	}

	while (struc) // ������ �� ������ � ����� ���������� ��������
	{
		if (strcmp(name, struc->inf) == 0) // ���� �����, ��
		{
			flag = 1;         // ���������� ���������
			if (struc->next)  // ���� ��������� ������� �� ��������� � ������
			{
				prev->next = struc->next; // ������ ���������
				free(struc);        // �������  �������
				struc = prev->next; // ������������� ��������� ��� ����������� ������
			}
			else            // ���� ��������� ������� ��������� � ������
			{
				prev->next = NULL; // �������� ��������� ��������������� ��������
				free(struc);    // �������  �������
				last = prev;    // ��������� last
				return;
			}
		}
		else    // ���� �� �����, ��
		{
			prev = struc; // ������������� ��������� ��� ����������� ������
			struc = struc->next;
		}
	}

	if (flag == 0) // ���� ���� = 0, ������ ������ ������� �� ������
	{
		printf("\n������� �� ������\n");
		return;
	}
}

void SaveFile(const char* filename) {
	FILE* file = fopen(filename, "w");
	if (file == NULL) {
		printf("\n������ ��� �������� ����� ��� ������\n");
		return;
	}

	struct node* struc = head;
	while (struc) {
		fprintf(file, "%s %d\n", struc->inf, struc->priority);
		struc = struc->next;
	}

	fclose(file);
	printf("\n������� ������� ��������� � ���� %s\n", filename);
}

void LoadFile(const char* filename) {
	FILE* file = fopen(filename, "r");
	if (file == NULL) {
		printf("\n������ ��� �������� ����� ��� ������\n");
		return;
	}

	// ������� ������������ �������
	struct node* current = head;
	while (current != NULL) {
		struct node* next = current->next;
		free(current);
		current = next;
	}
	head = last = NULL;

	char inf[256];
	int priority;
	while (fscanf(file, "%s %d", inf, &priority) != EOF) {
		struct node* p = (struct node*)malloc(sizeof(struct node));
		if (p == NULL) {
			printf("\n������ ��� ������������� ������\n");
			fclose(file);
			exit(1);
		}
		strcpy(p->inf, inf);
		p->priority = priority;
		p->next = NULL;

		// ������� �������� � ��������������� �������
		if (head == NULL || priority < head->priority) {
			// ������� � ������
			p->next = head;
			head = p;
		}
		else {
			struct node* current = head;
			struct node* prev = NULL;
			while (current != NULL && priority >= current->priority) {
				prev = current;
				current = current->next;
			}
			// ������� ����� prev � current
			prev->next = p;
			p->next = current;
			if (current == NULL) {
				last = p; // ���������� last, ���� p �������� � �����
			}
		}
	}

	fclose(file);
	printf("\n������� ��������� �� ����� %s\n", filename);
}

int main() {
	setlocale(LC_ALL, "Rus");
	int choice;
	char name[256];
	struct node* found = NULL;

	while (true)
	{
		printf("\n1. ����������� �������\n");
		printf("2. �������� ������� � �������\n");
		printf("3. ����� �������\n");
		printf("4. ������� �������\n");
		printf("5. ��������� ������� � ����\n");
		printf("6. ��������� ������� �� �����\n");
		printf("7. �����\n");
		printf("\n�������� ��������: ");
		scanf("%d", &choice);
		printf("\n");

		switch (choice)
		{
		case 1:
			review();
			break;
		case 2:
			spstore();
			break;
		case 3:
			printf("������� �������� ������� ��� ������: ");
			scanf("%s", name);
			found = find(name);
			if (found != NULL) {
				printf("��������� �������: ��� - %s, ��������� - %d\n", found->inf, found->priority);
			}
			break;
		case 4:
			printf("����� ������ ������?: ");
			scanf("%s", name);
			del(name);
			break;
		case 5:
			SaveFile(outputFileName); // Function to save the queue to a file
			break;
		case 6:
			LoadFile(inputFileName); // Function to load the queue from a file
			break;
		case 7:
			exit(0);
		default:
			printf("�������� �����. ����������, �������� �����.\n");
		}
	}
	return 0;
}