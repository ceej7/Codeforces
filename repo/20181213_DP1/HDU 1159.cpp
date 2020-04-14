#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <algorithm>

using namespace std;

// 
int dpArray[2005][2005];

int main()
{
	string s1;
	string s2;
	while (cin >> s1 >> s2)
	{
		for (int i = 0; i <= s1.length(); i++)
		{
			dpArray[i][0] = 0;
		}
		for (int i = 0; i <= s2.length(); i++)
		{
			dpArray[0][i] = 0;
		}
		for (int i = 1; i <= s1.length(); i++)
		{
			for (int j = 1; j <= s2.length(); j++)
			{
				int tmp1 = (s1[i-1] == s2[j-1] ? 1 : 0) + dpArray[i - 1][j - 1];
				int tmp2 = dpArray[i - 1][j];
				int tmp3 = dpArray[i][j - 1];
				int sm = tmp1;
				if (tmp2 > sm) sm = tmp2;
				if (tmp3 > sm) sm = tmp3;
				dpArray[i][j] = sm;
			}
		}
		cout << dpArray[s1.length()][s2.length()] << endl;

	}
}