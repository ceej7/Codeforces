#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <algorithm>

using namespace std;

int dpArray[55][55];
int value[55];
int n,l;

int len_sum(int left, int right)
{
	int sum = 0;
	for (int pvt = left; pvt <= right; pvt++)
	{
		sum += value[pvt];
	}
	return sum;
}

int main()
{
	while (cin >> l)
	{
		if (l == 0) return 0;
		//value[i]contains the lengt of single stick
		cin >> n;
		int last = 0;
		int i;
		for (i = 1; i <= n; i++)
		{
			int tmp;
			cin >> tmp;
			value[i] = tmp - last;
			last = tmp;
		}
		value[i] = l - last;
		n++;
		//dp
		for (int cnt = 1; cnt < n; cnt++)
		{
			for (int left = 1; left <= n-cnt; left++)
			{
				int right = left + cnt;
				int sum = len_sum(left,right);
				int mx = 0x3f3f3f3f;
				for (int pvt = left; pvt < right; pvt++)
				{
					if (dpArray[left][pvt] + dpArray[pvt+1][right]+sum < mx)
					{
						mx = dpArray[left][pvt] + dpArray[pvt+1][right]+sum;
					}
				}
				dpArray[left][right] = mx;
			}
		}
		cout << "The minimum cutting is " << dpArray[1][n] <<"."<< endl;
	}
}