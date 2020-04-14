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

int N=1010;
int n,m,s;
int adj[1010][1010]; //1
int dis[1010];
bool visited[1010];
int inf = 0x3f3f3f3f;

void dijk(int from)
{
	memset(dis, 0x3f, sizeof(int)*N);
	memset(visited, 0, sizeof(bool)*N);
	
	dis[from] = 0;

	for (size_t i = 0; i < n; i++)
	{
		//find smallest;
		int sm = inf; int smIndex = 0;
		for (size_t j = 1; j <= n; j++)
		{
			if (!visited[j] && dis[j] <= sm)
			{
				sm = dis[j];
				smIndex = j;
			}
		}

		visited[smIndex] = true;
		for (size_t j = 1; j <= n; j++)
		{
			if (!visited[j] && adj[smIndex][j]!=0&&dis[smIndex]+ adj[smIndex][j]<dis[j])
			{
				dis[j] = dis[smIndex] + adj[smIndex][j];
			}
		}
	}

}

int main()
{
	while (scanf("%d%d%d",&n,&m,&s)!=EOF)
	{
		memset(adj, 0, sizeof(int)*N*N);
		while (m--)
		{
			int t1, t2, l;
			scanf("%d%d%d", &t1, &t2, &l);
			if (adj[t2][t1] == 0)
				adj[t2][t1] = l;
			else if(l< adj[t2][t1])	
				adj[t2][t1] = l;
		}
		int least = inf;
		int caseInt;
		dijk(s);
		scanf("%d", &caseInt);
		while (caseInt--)
		{
			int from;
			scanf("%d", &from);
			if (dis[from] < least) least = dis[from];
		}
		if (least == inf) least = -1;
		cout << least << endl;
	}
	

}