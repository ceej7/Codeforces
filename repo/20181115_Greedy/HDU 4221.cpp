#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue> 
#include <vector>
#include <functional>
#include <map>
#include <algorithm>
using namespace::std;


const int maxN = 100005;
int idx[maxN];
long long C[maxN];
long long D[maxN];
int n;
bool cmp(int a, int b)
{
	if (D[a] == D[b])
	{
		return C[a] > C[b];
	}
	else {
		return D[a] < D[b];

	}
}

int main()
{
	int caseNum;
	int t = 0;
	scanf("%d", &caseNum);
	while (caseNum--)
	{
		t++;
		scanf("%d", &n);
		for (size_t i = 0; i < n; i++)
		{
			idx[i] = i+1;
		}
		for (size_t i = 1; i <=n; i++)
		{
			scanf("%d%d", &C[i], &D[i]);
		}
		sort(idx, idx + n, cmp);
		long long start=0;
		long long penal = 0;
		for (size_t i = 0; i < n; i++)
		{
			long long cost = C[idx[i]];
			long long deadline = D[idx[i]];
			start += cost;
			long long pen = start - deadline;
			if (pen>0&&pen > penal) penal = pen;
		}
		printf("Case %d: %lld\n", t,penal);
	}
}