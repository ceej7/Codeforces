#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue> 
#include <vector>
#include <functional>
#include <map>
#include <algorithm>
using namespace::std;

struct vertex
{
	bool operator<(const vertex& v1) const
	{
		return cost < v1.cost;
	}
	int num;
	int cost;
public:
	vertex(int a, int b)
	{
		num = a;
		cost = b;
	}
};
const int maxN = 100005;
const int inf = 0x3f3f3f3f;
priority_queue<vertex> que;
map<int, bool>visited;
int seq[maxN];
int n, m; //n access m volume


int find_nextt(int now, int num)
{
	for (int i = now + 1; i <= n; i++)
	{
		if (seq[i] == num) return i;
	}
	return n + 1;
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= n; i++)
	{
		int num;
		scanf("%d", &num);
		seq[i] = num;
		if (visited.count(seq[i]) == 0) visited.insert(make_pair(seq[i], false));
	}
	int hit = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!visited[seq[i]])
		{
			if (hit >= m)
			{
				vertex v = que.top();
				/*while (visited[v.num] == false)
				{
					que.pop();
					que.top();
				}*/
				que.pop();
				visited[v.num] = false;
			}
			hit++;
		}
		int nxt_pos = find_nextt(i, seq[i]);
		vertex v2(seq[i], nxt_pos);
		que.push(v2);
		visited[seq[i]] = true;
	}
	printf("%d\n", hit);
	
}