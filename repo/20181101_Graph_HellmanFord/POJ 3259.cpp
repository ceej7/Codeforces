#include <iostream>
#include <stdio.h>
#include <queue> 
#include <vector>
#include <functional>
#include <string.h>
using namespace::std;

int n,m,w;
int dis[505];
int adj[505][505];
int inf = 0x3f3f3f3f;

int main()
{
	int caseNum;
	scanf("%d", &caseNum);
	while (caseNum--)
	{
		memset(dis, 0x3f, sizeof(int) * 505);
		memset(dis, 0x3f , sizeof(int) * 505 * 505);

		scanf("%d%d%d", &n, &m, &w);
		for (size_t i = 0; i < m; i++)
		{
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			if (c < adj[a][b] && c < adj[b][a])
			{
				adj[a][b] = adj[b][a] = c;
			}
		}
		for (size_t i = 0; i < w; i++)
		{
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			if (-c < adj[a][b] )
			{
				adj[a][b]= -c;
			}
		}
		bool flg = true;
		dis[1] = 0;
		for (int i = 1; i < n; i++)
		{
			bool Update = false;
			for (int j = 1; j <= n; j++)
			{
				for (int k = 1; k <= n; k++)
				{
					if (adj[j][k] != inf && dis[j] + adj[j][k] < dis[k])
					{
						dis[k] = dis[j] + adj[j][k];
						Update = true;
					}
				}
			}
			if (!Update)
			{
				flg = false;
				break;
			}
		}
		
		
		if (!flg) printf("NO\n");
		else printf("YES\n");
	}
	//system("pause");
}