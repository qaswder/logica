#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include "stdio.h"
#include "malloc.h"
#include "locale.h"
#include "time.h"
#include <iostream>
#include <vector>
#define inf 100000000

using namespace std;
struct Edges {int u, v, w;};
const int Vmax = 1000;
const int Emax = Vmax * (Vmax - 1) / 2;
int i, j, n, e, start;
Edges edge[Emax];
int dist[Vmax];
int R;
int** mass;
FILE* save_res;

void out(int n,int* dist,int start, vector<int> p) //������� ����������
{
	save_res = fopen("����-�������.txt", "a");
	for (i = 0; i < n; i++)
	{
		if (dist[i] == inf)
		{
			printf("\n [%d]-[%d]= ��� ����", start, i + 1);
			fprintf(save_res,"\n [%d]-[%d]= ��� ����", start, i + 1);
		}
		else
		{
			printf("\n [%d]-[%d]= %d", start, i + 1, dist[i]);
			fprintf(save_res, "\n [%d]-[%d]= %d", start, i + 1, dist[i]);

		
			vector<int> path;// �������������� ����
			for (int cur = i; cur != -1; cur = p[cur])
			{
				path.push_back(cur);
			}

			reverse(path.begin(), path.end());
			printf(" (");
			fprintf(save_res, " (");
			for (size_t i = 0; i < path.size(); ++i)
				if ((i + 1) != path.size())
				{
					printf("%d->", path[i] + 1);
					fprintf(save_res, "%d->", path[i] + 1);
				}
				else
				{
					printf("%d", path[i] + 1);
					fprintf(save_res, "%d", path[i] + 1);
				}
			printf(")");
			fprintf(save_res, ")");
			

		}
		printf("\n\n");
	}
}

void bellman_ford(int n, int s) //�������� ��������-�����
{
	int i, j;

	for (i = 0; i < n; i++) 
	{ 
		dist[i] = inf;
	}
	dist[s] = 0;
	vector<int> p(n, -1);
	int x;
	for (i = 0; i < n - 1; i++)
	{
		x = -1;
		
			bool flag = false;
			for (j = 0; j < e; j++)  
				if (dist[edge[j].u]> dist[edge[j].v] + edge[j].w)
				{
					dist[edge[j].u] = max(-inf, dist[edge[j].v] + edge[j].w);
					p[edge[j].u] = edge[j].v;
					x = edge[j].u;
					flag = true;
				}
			if (!flag) break;
		}
	if(x!=-1){
		save_res = fopen("����-�������.txt", "a");
		for (i = 0; i < e; ++i) {

			for (j = 0; j < e; ++j)
			{
				printf("\n\n������! ������ ������������� ����\n\n");
				fprintf(save_res,"\n\n������! ������ ������������� ����\n");
				return;
					
			}
		}


		
	}
	

	out(n, dist,start,p);
	
}

void random() //������� �������� ����� ��������� �����
{
	printf("\n\n ���������� ������: ");
	scanf("%d", &n);

	srand(time(NULL));
	mass = new int*[n]; //��������� ������ ��� ������� 
	for (int i = 0; i < n; i++) {
		mass[i] = new int[n];
	}
	e = 0;
	for (i = 0; i < n; i++) {// ��������� �������
		for (j = 0; j < n; j++)
		{
			R = rand() % 100;
			if (R > 60) {
				int ran = (rand() % 10-5 );
				mass[i][j] = ran;
			}
			else {
				int ran = rand() % 10;
				mass[i][j] = mass[j][i] = ran;
			}
			if (i == j) {
				mass[i][j] = 0;
			}
			if (mass[i][j] != 0)// �������� �������� � ������ �����
			{
				edge[e].v = i;
				edge[e].u = j;
				edge[e].w = mass[i][j];
				e++;
			}
		}
	}
	

}
void hand() //������� ������� ����� �����
{
	printf("\n\n ���������� ������: ");
	scanf("%d", &n);

	mass = new int*[n]; //��������� ������ ��� ������� 
	for (int i = 0; i < n; i++) {
		mass[i] = new int[n];
	}
	e = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
		{
			printf("  ��� %d->%d= ", i + 1, j + 1);
			scanf(" %d", &mass[i][j]); //����������� �������


			if (mass[i][j] != 0)// �������� �������� � ������ �����
			{
				edge[e].v = i;
				edge[e].u = j;
				edge[e].w = mass[i][j];
				e++;
			}
		}
	}
}
void vyvod() //������� ������ ����� �� �����
{
	printf("\n\n");
	printf("     ");
	for (j = 0; j < n; j++)
	{
		printf(" %2d ", j + 1); 
	}
	printf("\n\n");

	for (i = 0; i < n; i++)
	{
		printf(" %d   |", i + 1); 
		for (j = 0; j < n; j++)
		{
			printf("%3d|", mass[i][j]);
		}
		printf("\n\n");
	}

}

void save() //������� ����������
{
	save_res = fopen("����-�������.txt", "w");//��������\�������� ����� ��� ������
	fprintf(save_res, "\n ����������� ������ %d \n\n", n);

	fprintf(save_res, "     ");// ���������� �������
	for (j = 0; j < n; j++)
	{
		fprintf(save_res, " %2d ", j + 1);
	}
	fprintf(save_res, "\n\n");

	for (i = 0; i < n; i++)
	{
		fprintf(save_res, " %d   |", i + 1);
		for (j = 0; j < n; j++)
		{
			fprintf(save_res, "%3d|", mass[i][j]);
		}
		fprintf(save_res, "\n\n");
	}
	
	fprintf(save_res, "������ ���������� �����:");//���������� ������ ���������� �����
	}

int main() //������� �������
{
	setlocale(LC_ALL, "Rus");
	int choose_number, choose_number2;
	while (true)//������� ����
	{
		system("cls");
		printf("\n\n\t\t����\n\n");
		printf("\t1.������� ������ ��������� �����\n");
		printf("\t2.������ ����\n");
		printf("\t3.�����\n\n");

		printf("\t�������� ����� ���� (1-3): ");
		scanf("%d", &choose_number);
		
		while ((choose_number<1)|| (choose_number > 3))
		{
			printf("\n\t������ �����, �������� ��� � ����!!!\n");
			printf("\n\t�������� ����� ���� (1-3): ");
			scanf("%d", &choose_number);
		}

		if (choose_number == 1)//��������� ������
		{
			system("cls");
			random();
			vyvod();
			printf("  ������ ��������� ��������� � ����?\n");
			printf("  ��-1\n");
			printf("  ���-2\n");
			printf("  �������� ������� - ");
			scanf("%d", &choose_number2);
			printf("  \n");
			while ((choose_number2 < 1)|| (choose_number2 > 2))
			{ 
				printf("  ������ �������, �������� ��� � ����!!!\n ");
				printf("  ��-1\n");
				printf("  ���-2\n");
				printf("  �������� ������� - ");
				scanf("%d", &choose_number2);
				printf("  \n");
			}
			if (choose_number2 == 1)
			{
				save();
			}
			
			printf("\n\n  ��������� ������� = ");
			scanf("%d", &start);
			while (start > n) { 
				printf("  ������� �������, ������� �� ����������!!!\n ");
				printf("\n  ��������� ������� = ");
				scanf("%d", &start);
				
			}
			printf("\n  ������ ���������� �����:");
			bellman_ford(n, start - 1);
			
			system("pause");
			continue;
		}

		if (choose_number == 2)//������ ����
		{
			system("cls");
			hand();
			vyvod();
			printf("  ������ ��������� ��������� � ����?\n");
			printf("  ��-1\n");
			printf("  ���-2\n");
			printf("  �������� ������� - ");
			scanf("%d", &choose_number2);
			printf("  \n");
			while ((choose_number2 < 1) || (choose_number2 > 2))
			{
				printf("  ������ �������, �������� ��� � ����!!!\n ");
				printf("  ��-1\n");
				printf("  ���-2\n");
				printf("  �������� ������� - ");
				scanf("%d", &choose_number2);
				printf("  \n");
			}
			if (choose_number2 == 1)
			{
				save();
			}
			printf("\n\n  ��������� ������� = ");
			scanf("%d", &start);
			while (start > n) {
				printf("  ������� �������, ������� �� ����������!!!\n ");
				printf("\n  ��������� ������� = ");
				scanf("%d", &start);

			}
			printf("\n  ������ ���������� �����:");
			bellman_ford(n, start - 1);
			system("pause");
			continue;
		}

		if (choose_number == 3)//���������� ������
		{
			break;
		}
	}
}

























 
//for (i = 0; i < n - 1; i++)
//{
//
//
//	bool change = false;
//
//	for (j = 0; j < e; j++) // v -> u, w - ���
//		if (d[edge[j].v] + edge[j].w < d[edge[j].u])
//		{
//			d[edge[j].u] = max(-inf, d[edge[j].v] + edge[j].w);
//			p[edge[j].u] = edge[j].v;
//			change = true;
//		}
//
//	if (!change)  break;
//
//}
//
//
//
//for (i = 0; i < n; i++)
//{
//	if (d[i] == inf)
//	{
//		cout << endl << " " << start << " -> " << i + 1 << " = " << "���� ����������� ";
//
//	}
//	else
//	{
//		cout << endl << " " << start << " -> " << i + 1 << " = " << d[i];
//
//
//		// �������������� ����
//
//
//		if (d[i] >= 0 && d[i] < 10)
//		{
//			cout << " ";
//
//		}
//
//		vector<int> path;
//
//		for (int cur = i; cur != -1; cur = p[cur])
//		{
//
//
//			for (size_t i2 = 0; i2 < path.size(); i2++)
//				if (cur == path[i2] && path.size() > 1)
//				{
//					path.push_back(cur);
//					cout << " (������������� ����)";
//
//					goto negative;
//				}
//
//
//			path.push_back(cur);
//
//		}
//
//	negative:
//		reverse(path.begin(), path.end());
//		cout << "  (";
//
//		for (size_t i = 0; i < path.size(); ++i)
//			if ((i + 1) != path.size())
//			{
//				cout << path[i] + 1 << " -> ";
//
//			}
//			else
//			{
//				cout << path[i] + 1;
//
//			}
//		cout << ")";
//
//
//	}
//
//}