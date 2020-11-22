#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include <conio.h>

#include <time.h>

#include <stack>

#include <queue>

#include <stdio.h>

#include <Windows.h>

#include <stdlib.h>

using namespace std;

queue <int> Q;

int i, j, N, st;

int** graph; // ������� ���������

int* visited; // ��������� �������

void BFS(int st)

{

	Q.push(st);

	visited[st] = true;

	while (!Q.empty())

	{

		st = Q.front();

		Q.pop();

		printf("%d ", st + 1);

		for (j = 0; j < N; j++)

		{

			if ((graph[st][j] == 1) && (!visited[j]))

			{

				visited[j] = true;

				Q.push(j);

			}

		}

	}

}

int main(void)

{

	SetConsoleCP(1251);

	SetConsoleOutputCP(1251);

	printf("������ ������ ������� ");

	scanf_s("%d", &N);

	srand(time(NULL));

	graph = new int*[N];

	visited = new int[N];

	for (int i = 0; i < N; i++) {

		graph[i] = new int[N];

	}

	for (i = 0; i < N; ++i)

	{

		for (j = i; j < N; ++j)

		{

			graph[i][j] = graph[j][i] = rand() % 2;

			graph[i][i] = graph[j][j] = 0; // ����� �����(����) �� �����������

		}

	}

	printf(" ");

	for (j = 0; j < N; j++)

	{

		printf("%4d ", j + 1); //��������

	}

	printf("\n\n");

	for (i = 0; i < N; i++) {

		printf(" %d ", i + 1); // ������

		for (j = 0; j < N; j++)

		{

			printf("%4d ", graph[i][j]);

		}

		printf("\n\n");

	}

	for (i = 0; i < N; i++)

	{

		printf("\n������� %d ������ � ", i + 1);

		for (j = 0; j < N; j++)

		{

			if (graph[i][j] == 1)

				printf("%d ", j + 1);

		}

	}

	printf("\n������� �������: ");

	scanf_s("%d", &st);

	while (st > N) {

		printf("\n����� ������� �� ����������!\n");

		printf("\n����� �������: ");

		scanf_s("%d", &st);

	}

	for (i = 0; i < N; i++)

	{

		visited[i] = false;

	}

	printf("\n ��������� ������ ������� ��������� ����� � ������:\n");

	BFS(st - 1);

	system("pause");

}