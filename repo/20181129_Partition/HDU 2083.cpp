#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue> 
#include <vector>
#include <functional>
#include <map>
#include <algorithm>
using namespace::std;
const int MAXN = 505;
int buf[MAXN];
int n;

int cmp(const void *a1,const void * a2)
{
	return *(int *)a1 - *(int *)a2;
}

int main()
{
	int caseN;
	scanf("%d", &caseN);
	while (caseN--)
	{
		scanf("%d", &n);
		for (size_t i = 0; i < n; i++)
		{
			scanf("%d", &buf[i]);
		}
		qsort(buf, n, sizeof(int), cmp);

		int mid = n / 2;
		long long sum=0;
		for (size_t i = 0; i < n; i++)
		{
			if (i < mid)
				sum += buf[mid] - buf[i];
			else
				sum += buf[i] - buf[mid];
		}
		printf("%lld\n", sum);
	}
}