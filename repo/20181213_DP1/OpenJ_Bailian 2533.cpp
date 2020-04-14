#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <algorithm>

using namespace std;

// the longest end at i
int dpArray[1005];
int num_tab[1005];
int find_first_smaller_number_before_pvt(int pivot)
{
	for (int i = pivot-1; i >= 1; i--)
	{
		if (num_tab[i] < num_tab[pivot])
			return i;
	}
	return 0;
}


int main()
{
	int n;
	while (cin >> n)
	{
		num_tab[0] = 0;
		memset(dpArray, 0, sizeof(dpArray));
		for (int i = 1; i <= n; i++)
		{
			cin >> num_tab[i];
		}
		for (int i = 1; i <= n; i++)
		{
			dpArray[i] = 1;
			int limit = find_first_smaller_number_before_pvt(i);
			for (int j = 1; j <= limit; j++)
			{
				if (num_tab[j]<num_tab[i]&&dpArray[i] < dpArray[j] + 1)
					dpArray[i] = dpArray[j] + 1;
			}
				
		}
		int biggest = 0;
		for (int i = 1; i <= n; i++)
		{
			if (dpArray[i] > biggest)
			{
				biggest = dpArray[i];
			}
		}
		cout << biggest << endl;
	}
}