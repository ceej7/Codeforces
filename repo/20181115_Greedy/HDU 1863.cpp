#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue> 
#include <vector>
#include <functional>
using namespace::std;

const int inf = 0x3f3f3f3f;
const int maxN = 105;
int adj[maxN][maxN];
int cost[maxN];
int n, m;
bool visit[maxN];
int main()
{
	
	while (scanf("%d%d",&n,&m) )
	{
		memset(visit, false, sizeof(visit));
		memset(adj, 0x3f, sizeof(adj));
		memset(cost, 0x3f, sizeof(cost));
		if (n == 0)break;
		while (n--)
		{
			int from, to, wei;
			scanf("%d%d%d", &from, &to, &wei);
			if (adj[from][to] > wei)
			{
				adj[from][to] = wei;
				adj[to][from] = wei;
			}
		}
		cost[1] = 0;
		int flg = false;
		for(int p=1;p<=m;p++)
		{
			int from = 0;
			int minTmp = inf;
			for (size_t i = 1; i <= m; i++)
			{
				if (!visit[i] && cost[i] < minTmp)
				{
					from = i;
					minTmp = cost[i];
				}
			}
			if (from == 0)
			{
				flg = true;
				break;
			}
			else {
				visit[from] = true;
			}


			for (size_t i = 1; i <= m; i++)
			{
				int to = i;
				if (adj[from][to] != inf && !visit[to]&&adj[from][to] < cost[to])
				{
					cost[to] = adj[from][to];
				}
			}
		}

		if (flg)
		{
			printf("?\n");
		}
		else {
			int sum = 0;
			for (size_t i = 1; i <= m; i++)
			{
				sum += cost[i];
			}
			printf("%d\n", sum);
		}
	}
}	