#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

using namespace std;
const int MAXN = 500005;
int n;
int buf[MAXN];


long long merge_find_inverse_num(int left, int right)
{
	if (left >= right) return 0;
	int mid = (left + right) / 2;
	long long n1 = merge_find_inverse_num(left,mid);
	long long n2 = merge_find_inverse_num(mid+1,right);
	long long n3 = 0;
	int i, j=mid+1;
	long long count = 0;

	//<cn opetation for find inverse num BTW left~mid and mid+1~right
	for (i = left; i <= mid; i++)
	{
		for (; j <= right; j++)
		{
			if (buf[i] > buf[j]) count++;
			else break;
		}
		n3 += count;
	}
	/*vector<int> l; // too slow here
	vector<int> r;

	for (int k = left; k <= mid; k++)
		l.push_back(buf[k]);
	for (int k = mid+1; k <= right; k++)
		r.push_back(buf[k]);
	for (int k = left; k <= right; k++)
	{
		if (!l.empty() && !r.empty())
		{
			int tmp1 = l.front();
			int tmp2 = r.front();
			if (tmp1 < tmp2)
			{
				buf[k] = tmp1;
				l.erase(l.begin());
			}
			else {
				buf[k] = tmp2;
				r.erase(r.begin());
			}
		}
		else if (!l.empty())
		{
			buf[k] = l.front();
			l.erase(l.begin());
		}
		else if (!r.empty())
		{
			buf[k] = r.front();
			r.erase(r.begin());
		}
	}*/
	sort(buf + left, buf + right+1);
	return n1 + n2 + n3;


}


int main()
{
	while (scanf("%d", &n))
	{
		if (n == 0)return 0;
		for (size_t i = 0; i < n; i++)
		{
			scanf("%d", &buf[i]);
		}

		printf("%lld\n", merge_find_inverse_num(0, n - 1));
	}
}