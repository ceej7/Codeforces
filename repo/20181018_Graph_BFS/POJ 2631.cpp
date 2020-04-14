#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>
#include <iostream>
using namespace::std;


int inf = 0x3f3f3f3f;

vector<int> matrix[10005];
int weightMatrix[10005][10005];
queue<int> que;

int length[10005];

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
				length[cur] = length[topVertex] + weightMatrix[topVertex][cur];
				que.push(cur);
			}
		}
	}
}


int main()
{
	int from, to, weight;
	while (cin>>from>>to>>weight)
	{
		matrix[from].push_back(to);
		matrix[to].push_back(from);
		weightMatrix[from][to]=weight;
		weightMatrix[to][from]=weight;
	}

	while (!que.empty()) que.pop();
	memset(length, 0x3f, sizeof(int) * 10005);
	BFS(1);
	int biggest = -1;
	int left = -1;
	for (size_t i = 0; i < 10005; i++)
	{
		if (length[i] != inf && length[i] > biggest)
		{
			left = i;
			biggest = length[i];
		}
	}

	while (!que.empty()) que.pop();
	memset(length, 0x3f, sizeof(int) * 10005);
	BFS(left);
	biggest = -1;
	int right = -1;
	for (size_t i = 0; i < 10005; i++)
	{
		if (length[i] != inf && length[i] > biggest)
		{
			right = i;
			biggest = length[i];
		}
	}

	printf("%d", biggest);
}
