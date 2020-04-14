#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>
using namespace::std;

int caseNum;
int inf = 0x3f3f3f3f;

int v, e;
vector<int> matrix[2005];
queue<int> que;

int length[2005];
int visited[2005];

//as for every subTree, the the min number of bianry vertex should be accumulated to result.!!!!!

void BFS(int vertex)
{
	length[vertex] = 0;
	visited[vertex] = true;
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
				visited[cur] = true;
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
			matrix[from+1].push_back(to+1);
			matrix[to+1].push_back(from+1);
		}

		int bigger=0;

		for (size_t j = 1; j <= v; j++)
		{
			if (length[j] == inf)
			{
				memset(visited, 0, sizeof(bool) * 2005);
				BFS(j);
				int even = 0;
				int odd = 0;
				for (size_t j = 1; j < v + 1; j++)
				{
					if (visited[j])
					{
						int tmp = length[j];
						if (tmp % 2 == 0)
						{
							even++;
						}
						else odd++;
					}				
				}
				int tmp2 = even > odd ? odd : even;
				if (tmp2 == 0)tmp2 = 1;
				bigger += tmp2;
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
		if (!flg)
			printf("-1\n");
		else
		{
			printf("%d\n", bigger);
		}
			
	}
}