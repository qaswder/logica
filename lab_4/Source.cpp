#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <time.h>
#include <stack>
#include <queue>

using namespace std;
int i, j, m;
bool* visited = new bool[m];
int** graph;
stack <int> s;
stack <int> DFSstack;


void DFS_2(int vertex) {

	DFSstack.push(vertex);
	visited[vertex] = 1;
	while (!DFSstack.empty()) {
		vertex = DFSstack.top();
		printf("%d ", vertex + 1);
		DFSstack.pop();
		for (int i = m; i >= 0; i--) {
			if (graph[vertex][i] == 1 && visited[i] != 1) {
				visited[i] = 1;
				DFSstack.push(i);
			}
		}
	}

}



void DFS(int st)
{
	int r;
	printf("%d ", st + 1);
	visited[st] = true;
	for (r = 0; r <= m; r++)
		if ((graph[st][r] != 0) && (!visited[r]))
			DFS(r);
}




void DFS_main()
{
	setlocale(LC_ALL, "Rus");
	printf("Ââåäèòå ðàçìåðíîñòü ìàòðèöû: ");
	scanf_s("%d", &m);

	graph = new int*[m];
	for (int i = 0; i < m; i++) {
		graph[i] = new int[m];
	}

	int start;
	printf("Ìàòðèöà ñìåæíîñòè:\n");
	srand(time(NULL));
	for (i = 0; i < m; ++i)
		for (j = i; j < m; ++j) {
			graph[i][j] = graph[j][i] = rand() % 2;
			graph[i][i] = graph[j][j] = 0; // ÷òîáû ïåòëÿ(óçåë) íå ñîçäàâàëàñü
		}
	printf("   ");
	for (j = 0; j < m; j++)
	{
		printf("   %d ", j + 1); //ãîðèçîíò
	}
	printf("\n\n");
	for (i = 0; i < m; ++i)
	{
		printf(" %d ", i + 1); // âåðòèê
		visited[i] = false;

		for (j = 0; j < m; ++j)
			printf("%4d ", graph[i][j]); // ñàìà ìàòðèöà
		printf("\n\n");
	}

	for (i = 0; i < m; i++)
	{
		printf("\nÂåðøèíà %d ñìåæíà ñ ", i + 1);
		for (j = 0; j < m; j++) {
			if (graph[i][j] == 1)
				printf("%d ", j + 1);
		}
	}
	printf("\nÂâåäèòå âåðøèíó: ");
	scanf_s("%d", &start);
	while (start > m) {
		printf("\nÒàêàÿ âåðøèíà íå ñóùåñòâóåò!\n");
		printf("\nÂâåäè âåðøèíó: ");
		scanf_s("%d", &start);
	}

	bool* vis = new bool[m];



	printf("\nÏîðÿäîê îáõîäà(íå ðåêóðñèÿ): ");
	DFS_2(start - 1);
	for (i = 0; i < m; i++) {
		visited[i] = false;

	}
	printf("\nÏîðÿäîê îáõîäà(ðåêóðñèÿ):    ");
	DFS(start - 1);

	system("pause");
}

void main(void)
{
	DFS_main();
}

