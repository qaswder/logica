#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "ctime"
#include <locale>
#include <Windows.h>



int main(void)
{
	setlocale(LC_ALL, "RUS");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(0));
	int a[10], a_max, a_min, a_a;

	printf(" ������� �1\n\n ");
	for (int i = 0; i <= 9; i++) { a[i] = rand() % 100 - 20; printf("%3d ", a[i]); }

	a_max = a[0];
	printf("\n");
	for (int i = 0; i <= 9; i++) { if (a[i] >= a_max) a_max = a[i]; }
	printf("\n ������������ ������� �������: %d", a_max);

	a_min = a[0];
	for (int i = 0; i <= 9; i++) { if (a[i] <= a_min)a_min = a[i]; }
	printf("\n ����������� ������� �������: %d", a_min);
	a_a = a_max - a_min;
	printf("\n ������� ����� max � min ����������: %d\n", a_a);


	printf("\n ������� �2\n ");
	printf("������ �������� �����\n\n");

	int b[10];
	for (int i = 0; i <= 9; i++) { a[i] = rand() % 100 - 20; printf("%3d ", a[i]); }

	printf("\n\n ������� �3\n ");

	int g;
	int* array;
	do
	{
		printf("������� ������ �������: ");
		scanf_s("%d", &g);
	} while (g < 1);
	array = (int*)malloc(g * sizeof(int));
	for (int i = 0; i < g; i++) {
		array[i] = rand() % 200 - 100;
		printf(" array[%d] = %d \n", i, array[i]);
	}
	free(array);

	printf("\n\n ������� �4\n ");

	int i, j;
	int arrr[5][5];
	int sum = 0;

	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {

			arrr[i][j] = rand() % 10;
		}
	}

	for (i = 0; i < 5; i++) {
		sum = 0;
		for (j = 0; j < 5; j++) {

			printf("%d ", arrr[i][j]);
			sum = sum + arrr[i][j];

		}
		printf(" ����� ��������� ������ ����� %d", sum);
		printf("\n ");
	}

	printf("\n\n ������� �5\n ");

	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	int e;
	struct student
	{
		char famil[30];
		char name[30], facult[30];
		char Nomzach[5];
	} stud[3];

	for (e = 0; e < 3; e++)
	{
		printf("������� ������� ��������\n "); scanf("%20s", stud[e].famil);
	}
	for (e = 0; e < 3; e++)
	{
		printf("������� ��� �������� %s\n ", stud[e].famil); scanf("%20s", stud[e].name);
	}
	for (e = 0; e < 3; e++)
	{
		printf("������� �������� ���������� �������� %s %s\n ", stud[e].famil, stud[e].name); scanf("%20s", stud[e].facult);
	}
	for (e = 0; e < 3; e++)
	{
		printf("������� ����� �������� ������ �������� %s %s\n ", stud[e].famil, stud[e].name); scanf("%s", &stud[e].Nomzach);
	}
	for (e = 0; e < 3; e++) {
		for (e = 0; e < 3; e++) {
			printf(" C������ %s %s ��������� �� ���������� %s, ����� �������� ������ %s \n", stud[e].famil, stud[e].name,
				stud[e].facult, stud[e].Nomzach);
		}
		char poisk[20];
		printf("�����: ");
		scanf("%s", &poisk);
		for (i = 0;i < 3;i++)
		{

			if ((strcmp(stud[i].famil, poisk) == 0) || (strcmp(stud[i].Nomzach, poisk) == 0) || (strcmp(stud[i].name, poisk) == 0) || (strcmp(stud[i].facult, poisk) == 0)) {
				printf("\nC������ %s %s ��������� �� ���������� %s, ����� �������� ������ %s\n", stud[i].famil, stud[i].name, stud[i].facult, stud[i].Nomzach);
			}
		}



		printf("\n");
		system("pause");
	}
}