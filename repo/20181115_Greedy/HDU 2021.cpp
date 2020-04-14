#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue> 
#include <vector>
#include <functional>
#include <map>
#include <algorithm>
using namespace::std;


const int maxN = 105;
int seq[maxN];
int n; //n access m volume


int main()
{
	while (1)
	{
		int count = 0;
		scanf("%d", &n);
		if (n == 0)break;
		for (size_t i = 1; i <= n; i++)
		{
			scanf("%d", &seq[i]);
		}
		//100
		for (size_t i = 1; i <= n; i++)
		{
			int tm = seq[i] / 100;
			count += tm;
			seq[i] = seq[i] - tm * 100;
		}
		//50
		for (size_t i = 1; i <= n; i++)
		{
			int tm = seq[i] / 50;
			count += tm;
			seq[i] = seq[i] - tm * 50;
		}
		//10
		for (size_t i = 1; i <= n; i++)
		{
			int tm = seq[i] / 10;
			count += tm;
			seq[i] = seq[i] - tm * 10;
		}
		//5
		for (size_t i = 1; i <= n; i++)
		{
			int tm = seq[i] / 5;
			count += tm;
			seq[i] = seq[i] - tm * 5;
		}
		//2
		for (size_t i = 1; i <= n; i++)
		{
			int tm = seq[i] / 2;
			count += tm;
			seq[i] = seq[i] - tm * 2;
		}
		//1
		for (size_t i = 1; i <= n; i++)
		{
			int tm = seq[i];
			count += tm;
		}
		cout << count << endl;
	}
	
}