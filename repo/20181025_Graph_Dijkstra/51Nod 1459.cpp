#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>
#include <iostream>
using namespace::std;

int inf = 0x3f3f3f3f;
int N = 505;

int v;

int score[505];
int perf[505];
int dis[505];
int prevV[505];
int adj[505][505];
int visited[505];


int main()
{
	int e, start, end;
	while (cin >> v >> e >> start >> end)
	{
		start++; end++;
		memset(dis, 0x3f, sizeof(int)*N);
		memset(perf, 0, sizeof(int)*N);
		memset(prevV, 0, sizeof(int)*N);
		memset(adj, 0, sizeof(int)*N*N);
		memset(visited, false, sizeof(int)*N);
		for (size_t i = 0; i < v; i++)
		{
			cin >> score[i + 1];
		}

		int t1, t2, t3;
		while (e--)
		{
			cin >> t1 >> t2 >> t3;
			t1++;
			t2++;
			adj[t1][t2] = t3;
			adj[t2][t1] = t3;
		}

		dis[start] = 0;
		perf[start] = score[start];
		for (size_t i = 0; i < v; i++)
		{
			//find the smallest
			int smallest=inf;
			int smIndex;
			for (size_t j = 1; j <=v; j++)
			{
				if (!visited[j] && dis[j] <= smallest)
				{
					smallest = dis[j];
					smIndex = j;
				}
			}
			visited[smIndex] = true;

			for (size_t j = 1; j <=v; j++)
			{
				if (!visited[j] && adj[smIndex][j] != 0)
				{
					if (dis[smIndex] + adj[smIndex][j] < dis[j]||(dis[smIndex] + adj[smIndex][j] == dis[j]&&score[j]+perf[smIndex]>perf[j]))
					{
						dis[j] = dis[smIndex] + adj[smIndex][j];
						perf[j] = score[j] + perf[smIndex];
						prevV[j] = smIndex;
					}
				}
			}

		}

		cout << dis[end] << " " << perf[end] << endl;


	}
}