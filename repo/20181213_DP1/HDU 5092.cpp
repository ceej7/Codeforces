#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <algorithm>

using namespace std;

int dpArray[105][105];
int value[105][105];
int from[105][105];
int m, n;
void dp_recur_printf(int _m, int _n)
{
	if (_m == 0) return;
	dp_recur_printf(_m - 1, from[_m][_n]);
	if (_m == m) printf("%d\n", _n);
	else printf("%d ", _n);

}

int main()
{
	int caseConst;
	int caseNum;
	cin >> caseNum;
	caseConst = caseNum;
	while (caseNum--)
	{
		memset(dpArray, 0, sizeof(dpArray));
		scanf("%d%d",&m,&n);
		for(int i= 1; i <= m; i++)
		{
			for (int j = 1;j <= n; j++)
			{
				scanf("%d", &value[i][j]);
			}
		}

		//f(i,j)=min{f(i-1,j-1),f(i-1,j),f(i-1,j+1)}+v(i,j)
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				int minDis = 0x3f3f3f3f;
				//f(i - 1, j - 1)
				if (j != 1&&dpArray[i-1][j-1]+value[i][j]<=minDis)
				{
					minDis = dpArray[i - 1][j - 1] + value[i][j];
					from[i][j] = j - 1;
				}
				//f(i - 1, j)
				if (dpArray[i - 1][j] + value[i][j] <= minDis)
				{
					minDis = dpArray[i - 1][j] + value[i][j];
					from[i][j] = j;
				}
				//f(i - 1, j+1)
				if (j != n&& dpArray[i - 1][j+1] + value[i][j] <= minDis)
				{
					minDis = dpArray[i - 1][j+1] + value[i][j];
					from[i][j] = j+1;
				}
				dpArray[i][j] = minDis;
			}
		}
		int minRes = 0x3f3f3f3f;
		int pivot=0;
		for (int i = 1; i <= n; i++)
		{
			if (dpArray[m][i] <= minRes)
			{
				minRes = dpArray[m][i];
				pivot = i;
			}
		}
		printf("Case %d\n", caseConst - caseNum);
		dp_recur_printf(m,pivot);

	}
}