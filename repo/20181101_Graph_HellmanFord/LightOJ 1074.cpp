#include <iostream>
#include <stdio.h>
#include <queue> 
#include <vector>
#include <functional>
#include <string.h>
using namespace::std;

int n, m;
int dis[205];
int adj[205][205];
int weight[205];
bool neg[205];
int inf = 0x3f3f3f3f;
//记住 负环、重边、不连通！！！！！！
void dfs(int from)
{
	if (dis[from] == -inf) return;
	dis[from] = -inf;
	for (int k = 1; k <= n; k++)
	{
		if (adj[from][k] != inf && dis[k] != -inf)
		{
			dfs(k);
		}
	}
}

int main()
{
	int caseNum;
	scanf("%d", &caseNum);
	for (int z = 1; z <= caseNum; z++)
	{
		memset(dis, 0x3f, sizeof(int) * 205);
		memset(adj, 0x3f, sizeof(int) * 205 * 205);
		memset(neg, false, sizeof(bool) * 205);
		scanf("%d", &n);
		for (size_t i = 1; i <= n; i++)
		{
			scanf("%d", &weight[i]);
		}

		scanf("%d", &m);
		while (m--)
		{
			int from, to;
			scanf("%d%d", &from, &to);
			int tmp = weight[to] - weight[from];
			tmp = tmp * tmp*tmp;
			adj[from][to] = tmp;
		}

			dis[1] = 0;
                //Ford
		for (int i = 1; i < n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				for (int k = 1; k <= n; k++)
				{
					if (dis[j]!=inf&&adj[j][k] != inf && dis[j] + adj[j][k] < dis[k])
					{
						dis[k] = dis[j] + adj[j][k];
					}
				}
			}
		}

		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				if (dis[j] != inf && adj[j][k] != inf && dis[j] + adj[j][k] < dis[k])
				{
					dis[k] = dis[j] + adj[j][k];
					neg[k] = true;
				}
			}
		}

		for (int i = 1; i <= n; i++)
		{
			if (neg[i])
			{
				dfs(i);
			}
		}

		printf("Case %d:\n", z);
		int q;
		scanf("%d", &q);
		for (size_t i = 1; i <= q; i++)
		{
			int dest;
			scanf("%d", &dest);
			if (dis[dest] == inf || dis[dest] < 3)
			{
				printf("?\n");
			}
			else {
				printf("%d\n", dis[dest]);
			}
		}
	}

}