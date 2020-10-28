#define _CRT_SECURE_NO_WARNINGS
#include <random>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <locale>
#include<windows.h>
#include <malloc.h>

void zadanie_1()

{

	clock_t start, end;

	int i = 0, j = 0, r = 0;

	int elem_c, n;

	printf("Enter lenght: ");

	scanf("%d", &n);

	int** a = (int**)malloc(sizeof(int*) * n);

	for (int i = 0; i < n; i++) {

		a[i] = (int*)malloc(n * sizeof(int));

	}

	int** b = (int**)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {

		b[i] = (int*)malloc(n * sizeof(int));

	}

	int** c = (int**)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {

		c[i] = (int*)malloc(n * sizeof(int));

	}

	srand(time(NULL));

	while (i < n)

	{

		while (j < n)

		{

			a[i][j] = rand() % 100 + 1;

			j++;

		}

		i++;

	}

	srand(time(NULL));

	i = 0; j = 0;

	while (i < n)

	{

		while (j < n)

		{

			b[i][j] = rand() % 100 + 1;

			j++;

		}

		i++;

	}

	start = clock();

	for (i = 0; i < n; i++)

	{

		for (j = 0; j < n; j++)

		{

			elem_c = 0;

			for (r = 0; r < n; r++)

			{

				elem_c = elem_c + a[i][r] * b[r][j];

				c[i][j] = elem_c;

			}

		}

	}

	end = clock();

	printf("Time of sort = %lf sec.", (double)(end - start) / CLK_TCK);

	free(a);

	free(b);

	free(c);

	system("pause");

}

void shell(int* items, int count) {

	int i, j, gap, k;

	int x, a[5];

	a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;

	for (k = 0; k < 5; k++) {

		gap = a[k];

		for (i = gap; i < count; ++i) {

			x = items[i];

			for (j = i - gap; (x < items[j]) && (j >= 0); j = j - gap)

				items[j + gap] = items[j];

			items[j + gap] = x;

		}

	}

}

void qs(int* items, int left, int right) {

	int i, j;

	int x, y;

	i = left; j = right;

	x = items[(left + right) / 2 - 20];

	do {

		while ((items[i] < x) && (i < right))i++;

		while ((x < items[j]) && (j > left))j--;

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

int compare(const int* i, const int* j)

{

	return *i - *j;

}

void zadani_2() {

	setlocale(LC_ALL, "RUS");
	int n;
	srand(time(NULL));
	printf("������� ������:");
	scanf("%d", &n);

	int* RAND = new int[n];
	int* RAND_3 = new int[n];
	int* RAND_2 = new int[n];

	int* UP = new int[n];
	int* UP_2 = new int[n];
	int* UP_3 = new int[n];

	int* DOWN = new int[n];
	int* DOWN_3 = new int[n];
	int* DOWN_2 = new int[n];

	int* UP_DOWN = new int[n];
	int* UP_DOWN_2 = new int[n];
	int* UP_DOWN_3 = new int[n];

	for (int i = 0; i < n; i++) {

		RAND[i] = rand() % 100;
		RAND_2[i] = RAND[i];
		RAND_3[i] = RAND[i];

	}

	for (int i = 0; i < n; i++) {

		UP[i] = i;
		UP_2[i] = UP[i];
		UP_3[i] = UP[i];
	}

	for (int i = 0; i < n; i++) {

		DOWN[i] = n - i;
		DOWN_2[i] = DOWN[i];
		DOWN_3[i] = DOWN[i];
	}

	for (int i = 0; i < n; i++) {

		if (i <= n / 2) {

			UP_DOWN[i] = i;
			UP_DOWN_2[i] = UP_DOWN[i];
			UP_DOWN_3[i] = UP_DOWN[i];
		}

		if (i > n / 2) {

			UP_DOWN[i] = n - i;
			UP_DOWN_2[i] = UP_DOWN[i];
			UP_DOWN_3[i] = UP_DOWN[i];
		}

	}

	double start = clock();
	shell(RAND, n);
	double end = clock();
	printf("����� ���������� ����� ���������� ������� = %lf\n", (end - start) / CLOCKS_PER_SEC);

	int left = 0;
	double start_new = clock();
	qs(RAND_2, left, n - 1);
	double end_new = clock();
	printf("����� ������� ���������� ���������� ������� = %lf\n", (end_new - start_new) / CLOCKS_PER_SEC);

	start = clock();
	qsort(RAND_3, n, sizeof(int), (int(*)(const void*, const void*))compare);
	end = clock();
	printf("����� ����������� ���������� ���������� ������� = %lf\n\n", (end - start) / CLOCKS_PER_SEC);
	start = clock();
	shell(UP, n);
	end = clock();
	printf("����� ���������� ����� ������������� ������� = %lf\n", (end - start) /
		CLOCKS_PER_SEC);

	start = clock();
	qs(UP_2, left, n - 1);
	end = clock();
	printf("����� ������� ���������� ������������� ������� = %lf\n", (end - start) / CLOCKS_PER_SEC);

	start = clock();
	qsort(UP_3, n, sizeof(int), (int(*)(const void*, const void*))compare);
	end = clock();
	printf("����� ����������� ���������� ������������� ������� = %lf\n\n", (end - start) / CLOCKS_PER_SEC);

	start = clock();
	shell(DOWN, n);
	end = clock();
	printf("����� ���������� ����� ���������� ������� = %lf\n", (end - start) / CLOCKS_PER_SEC);

	start = clock();
	qs(DOWN_2, left, n - 1);
	end = clock();
	printf("����� ������� ���������� ���������� ������� = %lf\n", (end - start) / CLOCKS_PER_SEC);

	start = clock();
	qsort(DOWN_3, n, sizeof(int), (int(*)(const void*, const void*))compare);
	end = clock();
	printf("����� ����������� ���������� ���������� ������� = %lf\n\n", (end - start) / CLOCKS_PER_SEC);

	start = clock();
	shell(UP_DOWN, n);
	end = clock();
	printf("����� ���������� ����� ������������� ������� = %lf\n", (end - start) / CLOCKS_PER_SEC);

	start = clock();
	qs(UP_DOWN_2, left, n - 1);
	end = clock();
	printf("����� ������� ���������� ������������� ������� = %lf\n", (end - start) / CLOCKS_PER_SEC);
	start = clock();
	qsort(UP_DOWN_3, n, sizeof(int), (int(*)(const void*, const void*))compare);
	end = clock();
	printf("����� ����������� ���������� ������������� ������� = %lf\n", (end - start) / CLOCKS_PER_SEC);


	system("pause");

}

int main()
{
	zadanie_1();
	zadani_2();
	return 0;
}
