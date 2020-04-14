#include <iostream>
#include <stdio.h>
#include <queue> 
#include <vector>
#include <functional>
using namespace::std;

int n;
int list[20005];


int main()
{
	scanf("%d", &n);
	for (size_t i = 0; i < n; i++)
	{
		scanf("%d", &list[i]);
	}
	priority_queue<int,vector<int>,greater<int>> pq(list, list + n);
	long long res = 0;
	while (pq.size() > 1)
	{
		int tmp = pq.top();
		pq.pop();
		int tmp2 = pq.top();
		pq.pop();
		int tmp3 = tmp + tmp2;
		pq.push(tmp3);
		res += tmp3;

	}
	printf("%lld\n", res);
	//system("pause");
}