#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;
const int MAXN = 100005;
int n, k;
int buf[MAXN];

long long two_divide_find_pair(int left, int right)
{
	if (left >= right) return 0;
	int mid = (left + right) / 2;


	long long tmp1 = two_divide_find_pair(left, mid);
	long long tmp2 = two_divide_find_pair(mid + 1, right);
	long long tmp3 = 0;
	long long lastCount = 0;
	int start;
	int j = mid + 1;
	for (start = mid; start >= left; start--)
	{
		if (start < left || buf[mid + 1] - buf[start] > k) break;
	}
	start++;
	for (int i = start; i <= mid; i++)
	{
		for (; j <= right; j++)
		{
			if (buf[j] - buf[i] <= k) lastCount++;
			else break;
		}
		tmp3 += lastCount;

	}
	return tmp1 + tmp2 + tmp3;
}

int main()
{
	int caseN;
	scanf("%d", &caseN);
	while (caseN--)
	{
		scanf("%d%d", &n, &k);
		for (size_t i = 0; i < n; i++)
		{
			scanf("%d", &buf[i]);
		}
		sort(buf, buf + n);
		printf("%lld\n", two_divide_find_pair(0, n - 1));
	}
}