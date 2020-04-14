#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue> 
#include <vector>
#include <functional>
#include <map>
#include <algorithm>
using namespace::std;
const long long MAXN = 10005;
long long buf[MAXN];
long long n,k;

long long find_num(long long len)
{
	long long count = 0;
	for (int i = 0; i < n; i++)
	{
		count += buf[i] / len;
	}
	return count;

}

int main()
{
	while (scanf("%d%d", &n, &k) != EOF)
	{
		long long max = 0;
		for (int i = 0; i < n; i++)
		{
			double length;
			scanf("%lf", &length);
			buf[i] = length * 100;
			if (buf[i] > max) max = buf[i];
		}
		long long left = 1; long long right = max;
		if (find_num(1) < k)
		{
			printf("0.00\n");
		}
		else
		{
			while (left < right)
			{
				long long mid = (left + right) / 2;
				long long tmp = find_num(mid);
				if (tmp < k) right = mid;
				else left = mid;
				if (left == right)
				{
					printf("%.2f\n", (float)left / 100);
					break;
				}
				else if (left + 1 == right)
				{
					if (find_num(right) >= k)
					{
						printf("%.2f\n", (float)right / 100);
						break;
					}
					else
					{
						printf("%.2f\n", (float)left / 100);
						break;
					}
				}
			}
		}
		
	}
	
}