#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue> 
#include <vector>
#include <functional>
using namespace::std;

int inf = 0x3f3f3f3f;
int n, m;
int dis[10005];

//Do not store the adj or exceed the memory
int main()
{
	memset(dis, 0, sizeof(dis));
	scanf("%d", &n);

	for (size_t i = 1; i <= n; i++)
	{
		int wei;
		scanf("%d", &wei);
		scanf("%d", &m);
		if (m == 0)
		{
			dis[i] = wei;
			continue;
		}

		for (size_t j = 1; j <= m; j++)
		{
			int from;
			scanf("%d", &from);
			int to = i;
			if (dis[from] + wei > dis[to])
			{
				dis[to] = dis[from] + wei;
			}
		}
	}

	int res = -inf;
	for (size_t i = 1; i <= n; i++)
	{
		if (dis[i] > res) res = dis[i];
	}
	printf("%d\n", res);
}