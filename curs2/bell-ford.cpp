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

void out(int n,int* dist,int start, vector<int> p) //функция сохранения
{
	save_res = fopen("Форд-Беллман.txt", "a");
	for (i = 0; i < n; i++)
	{
		if (dist[i] == inf)
		{
			printf("\n [%d]-[%d]= нет пути", start, i + 1);
			fprintf(save_res,"\n [%d]-[%d]= нет пути", start, i + 1);
		}
		else
		{
			printf("\n [%d]-[%d]= %d", start, i + 1, dist[i]);
			fprintf(save_res, "\n [%d]-[%d]= %d", start, i + 1, dist[i]);

		
			vector<int> path;// Восстановление путь
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

void bellman_ford(int n, int s) //алгоритм Беллмана-Форда
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
		save_res = fopen("Форд-Беллман.txt", "a");
		for (i = 0; i < e; ++i) {

			for (j = 0; j < e; ++j)
			{
				printf("\n\nОшибка! Найден отрицательный цикл\n\n");
				fprintf(save_res,"\n\nОшибка! Найден отрицательный цикл\n");
				return;
					
			}
		}


		
	}
	

	out(n, dist,start,p);
	
}

void random() //функция создания графа случайных чисел
{
	printf("\n\n Количество вершин: ");
	scanf("%d", &n);

	srand(time(NULL));
	mass = new int*[n]; //выделение памяти для массива 
	for (int i = 0; i < n; i++) {
		mass[i] = new int[n];
	}
	e = 0;
	for (i = 0; i < n; i++) {// генерация массива
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
			if (mass[i][j] != 0)// передача значений в список ребер
			{
				edge[e].v = i;
				edge[e].u = j;
				edge[e].w = mass[i][j];
				e++;
			}
		}
	}
	

}
void hand() //функция ручного ввода графа
{
	printf("\n\n Количество вершин: ");
	scanf("%d", &n);

	mass = new int*[n]; //выделение памяти для массива 
	for (int i = 0; i < n; i++) {
		mass[i] = new int[n];
	}
	e = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
		{
			printf("  Вес %d->%d= ", i + 1, j + 1);
			scanf(" %d", &mass[i][j]); //запоминание массива


			if (mass[i][j] != 0)// передача значений в список ребер
			{
				edge[e].v = i;
				edge[e].u = j;
				edge[e].w = mass[i][j];
				e++;
			}
		}
	}
}
void vyvod() //функция вывода графа на экран
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

void save() //функция сохранения
{
	save_res = fopen("Форд-Беллман.txt", "w");//создание\открытие файла для записи
	fprintf(save_res, "\n Колличество вершин %d \n\n", n);

	fprintf(save_res, "     ");// сохранение массива
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
	
	fprintf(save_res, "Список кратчайших путей:");//сохранение списка кратчайших путей
	}

int main() //главная функция
{
	setlocale(LC_ALL, "Rus");
	int choose_number, choose_number2;
	while (true)//Главный цикл
	{
		system("cls");
		printf("\n\n\t\tМеню\n\n");
		printf("\t1.Создать массив случайных чисел\n");
		printf("\t2.Ручной ввод\n");
		printf("\t3.Выход\n\n");

		printf("\tВыберите пункт меню (1-3): ");
		scanf("%d", &choose_number);
		
		while ((choose_number<1)|| (choose_number > 3))
		{
			printf("\n\tВыбран пункт, которого нет в меню!!!\n");
			printf("\n\tВыберите пункт меню (1-3): ");
			scanf("%d", &choose_number);
		}

		if (choose_number == 1)//рандомный массив
		{
			system("cls");
			random();
			vyvod();
			printf("  Хотите сохранить результат в файл?\n");
			printf("  Да-1\n");
			printf("  Нет-2\n");
			printf("  Выберите вариант - ");
			scanf("%d", &choose_number2);
			printf("  \n");
			while ((choose_number2 < 1)|| (choose_number2 > 2))
			{ 
				printf("  Выбран вариант, которого нет в меню!!!\n ");
				printf("  Да-1\n");
				printf("  Нет-2\n");
				printf("  Выберите вариант - ");
				scanf("%d", &choose_number2);
				printf("  \n");
			}
			if (choose_number2 == 1)
			{
				save();
			}
			
			printf("\n\n  Стартовая вершина = ");
			scanf("%d", &start);
			while (start > n) { 
				printf("  Выбрана вершина, которой не существует!!!\n ");
				printf("\n  Стартовая вершина = ");
				scanf("%d", &start);
				
			}
			printf("\n  Список кратчайших путей:");
			bellman_ford(n, start - 1);
			
			system("pause");
			continue;
		}

		if (choose_number == 2)//ручной ввод
		{
			system("cls");
			hand();
			vyvod();
			printf("  Хотите сохранить результат в файл?\n");
			printf("  Да-1\n");
			printf("  Нет-2\n");
			printf("  Выберите вариант - ");
			scanf("%d", &choose_number2);
			printf("  \n");
			while ((choose_number2 < 1) || (choose_number2 > 2))
			{
				printf("  Выбран вариант, которого нет в меню!!!\n ");
				printf("  Да-1\n");
				printf("  Нет-2\n");
				printf("  Выберите вариант - ");
				scanf("%d", &choose_number2);
				printf("  \n");
			}
			if (choose_number2 == 1)
			{
				save();
			}
			printf("\n\n  Стартовая вершина = ");
			scanf("%d", &start);
			while (start > n) {
				printf("  Выбрана вершина, которой не существует!!!\n ");
				printf("\n  Стартовая вершина = ");
				scanf("%d", &start);

			}
			printf("\n  Список кратчайших путей:");
			bellman_ford(n, start - 1);
			system("pause");
			continue;
		}

		if (choose_number == 3)//завершение работы
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
//	for (j = 0; j < e; j++) // v -> u, w - вес
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
//		cout << endl << " " << start << " -> " << i + 1 << " = " << "Путь отсутствует ";
//
//	}
//	else
//	{
//		cout << endl << " " << start << " -> " << i + 1 << " = " << d[i];
//
//
//		// Восстановление пути
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
//					cout << " (Отрицательный цикл)";
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