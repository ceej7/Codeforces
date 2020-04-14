#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue> 
#include <vector>
#include <functional>
#include <map>
#include <algorithm>
using namespace::std;
const int MAXN = 100005;
long long buf[MAXN];
int n,c;

//find the number of cows which can be placed in the barn with the porvided minimized distance
//Keep in mind that the cow will be must be placed in the buf[0]
//counter-evidence - if not, first element is i
//move i to 0 will equal to 
int can_in_place_num_with_MD(int md)
{
	int count = 1;
	int from = 0;
	for (int i = 1; i < n; i++)
	{
		if (buf[i] - buf[from] >= md)
		{
			count++;
			from = i;
		}
	}
	return count;
}

int main()
{
	scanf("%d%d", &n, &c);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &buf[i]);
	}
	sort(buf, buf + n);
	long long left = 0;
	long long right = 1000000010;
	while (left < right-1)
	{
		long long mid = (left + right) / 2;
		if (can_in_place_num_with_MD(mid) >= c)
			left = mid;
		else
			right = mid;
	}
	if (can_in_place_num_with_MD(right) >= c)
	{
		printf("%lld\n", right);
	}
	else {
		printf("%lld\n", left);
	}
}