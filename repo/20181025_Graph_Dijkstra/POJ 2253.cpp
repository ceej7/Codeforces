#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include <vector>
#include <queue>
#include <string.h>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace::std;

int N=210;
int v;
int coord[2][210];
double adj[210][210];
double dis[210];
bool visited[210];
int inf = 0x3f3f3f3f;


int main()
{
	int caseCount=0;
	while (cin >> v)
	{
		caseCount++;
		if (v == 0)
		{
			break;
		}

		//initial
		for (size_t i = 1; i <= v; i++) dis[i] = (double)inf;
		memset(visited, 0, sizeof(bool)*N);

		for (size_t i = 1; i <=v; i++)
		{
			cin >> coord[0][i];
			cin >> coord[1][i];
		}

		//cin space
		char str[2];
		cin.getline(str, 2);
		cin.getline(str,2);

		for (size_t i = 1; i <=v; i++)
		{
			adj[i][i] = 0;
			for (size_t j = i+1; j <=v; j++)
			{
				adj[i][j] = adj[j][i] = sqrt((coord[0][i] - coord[0][j])*(coord[0][i] - coord[0][j]) + (coord[1][i] - coord[1][j])*(coord[1][i] - coord[1][j]));
			}
		}

		//dijkstra
		dis[1] = 0;
		for (size_t i = 1; i <= v; i++)
		{
			double small = inf;
			int smIndex = 0;
			for (size_t j = 1; j <= v; j++)
			{
				if (!visited[j] && dis[j] <= small)
				{
					small = dis[j];
					smIndex = j;
				}
			}

			visited[smIndex] = true;
			for (size_t j = 1; j <= v; j++)
			{
				if (!visited[j])
				{
					if (max(dis[smIndex], adj[smIndex][j]) < dis[j])
					{
						dis[j] = max(dis[smIndex], adj[smIndex][j]);
					}
				}
			}
		}
		
		printf("Scenario #%d\nFrog Distance = %0.3f\n\n", caseCount, dis[2]);


	}
	

}