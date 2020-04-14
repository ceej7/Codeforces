#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

using namespace std;

int dpArray[1005][1005];
int volum[1005];
int value[1005];

int main()
{
	int caseNum;
	scanf("%d", &caseNum);
	while (caseNum--)
	{
		memset(dpArray, 0, sizeof(dpArray));
		memset(volum, 0, sizeof(volum));
		memset(value, 0, sizeof(value));
		int n, v;
		scanf("%d%d", &n,&v);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &value[i]);
		}
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &volum[i]);
		}

		for (int i = 1; i <= n; i++)
		{
			for (int w = 0; w <= v; w++)
			{
				if (volum[i] <= w)
				{
					dpArray[w][i]=dpArray[w - volum[i]][i - 1]+value[i];
				}
				if (dpArray[w][i-1] > dpArray[w][i])
				{
					dpArray[w][i] = dpArray[w][i - 1];
				}

			}
		}
		printf("%d\n", dpArray[v][n]);

	}

}