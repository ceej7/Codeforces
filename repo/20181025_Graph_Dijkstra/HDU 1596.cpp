#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>
#include <iostream>
using namespace::std;

int v;
int N = 1005;
double safeCoef[1005];
double matrix[1005][1005];
bool isFlooded[1005];

int main()
{
	while (cin >> v)
	{
		for (size_t i = 1; i <= v; i++)
		{
			for (size_t j = 1; j <= v; j++)
			{
				//cin >> matrix[i][j];
				scanf("%lf", &matrix[i][j]);
			}
		}

		int t;
		cin >> t;
		while (t--)
		{
			int from, to;
			cin >> from >> to;
			for (size_t i = 0; i < N; i++)
			{
				safeCoef[i] = 0;
			}
			memset(isFlooded, false, sizeof(bool)*N);
			safeCoef[from] = 1;

			for (size_t i = 0; i < v; i++)
			{
				int maxIndex;
				double maxCoef = 0;
				for (size_t j = 1; j <= v; j++)
				{
					if (safeCoef[j] >= maxCoef && !isFlooded[j])
					{
						maxCoef = safeCoef[j];
						maxIndex = j;
					}
				}

				isFlooded[maxIndex] = true;

				for (size_t j = 1; j <= v; j++)
				{
					double tmpCoef = matrix[maxIndex][j];
					if (!isFlooded[j])
					{
						if (tmpCoef*safeCoef[maxIndex] > safeCoef[j])
						{
							safeCoef[j] = tmpCoef * safeCoef[maxIndex];
						}
					}
				}
			}

			if (safeCoef[to] > 0)
			{
				printf("%.3lf\n", safeCoef[to]);
			}
			else {
				cout << "What a pity!" << endl;
			}

		}
	}
	

}
