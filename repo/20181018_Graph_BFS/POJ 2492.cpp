#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>
using namespace::std;

int caseNum;
int inf = 0x3f3f3f3f;

int v,e;
vector<int> matrix[2005];
queue<int> que;

int length[2005];

//calculate the distance from the source
//with the same distance, no connection BTW the two vertexes!!!

void BFS(int vertex)
{
	length[vertex] = 0;
	que.push(vertex);

	while (!que.empty())
	{
		int topVertex = que.front();
		que.pop();
		for (size_t i = 0; i < matrix[topVertex].size(); i++)
		{
			int cur = matrix[topVertex][i];
			if (length[cur] == inf)
			{
				length[cur] = length[topVertex] + 1;
				que.push(cur);
			}
		}
	}
}


int main()
{
	scanf("%d", &caseNum);
	for (size_t i = 1; i <= caseNum; i++)
	{
		memset(length, 0x3f, sizeof(int) * 2005);
		for (size_t j = 0; j < 2005; j++) matrix[j].clear();
		while (!que.empty()) que.pop();

		scanf("%d%d", &v, &e);
		for (size_t j = 0; j < e; j++)
		{
			int from, to;
			scanf("%d%d", &from, &to);
			matrix[from].push_back(to);
			matrix[to].push_back(from);
		}

		for (size_t j = 1; j <= v; j++)
		{
			if (length[j] == inf)
			{
				BFS(j);
			}
		}

		bool flg = true;
		for (size_t j = 1; j <= v; j++)
		{
			for (size_t k = 0; k < matrix[j].size(); k++)
			{
				int cur = matrix[j][k];
				if (length[j] == length[cur])
				{
					flg = false;
				}
			}
		}
		if(!flg)
			printf("Scenario #%d:\nSuspicious bugs found!\n\n", i);
		else
			printf("Scenario #%d:\nNo suspicious bugs found!\n\n", i);
	}
}
