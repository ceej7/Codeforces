#include <vector>
#include <string>
#include <cmath>
#include <cstring>
#include <stdio.h>
using namespace::std;
const int maxN = 10005;

bool visited[maxN];
vector<int> matrix[maxN];

bool revVisited[maxN];
vector<int> revMatrix[maxN];


int vertexNum, edgeNum;
int lastOne;


void revE(int vertex)
{
	revVisited[vertex] = true;
	for (size_t i = 0; i < revMatrix[vertex].size(); i++)
	{
		int to = revMatrix[vertex][i];
		if (revVisited[to] == false)
		{
			revE(to);
		}
	}
	lastOne = vertex;
}

void E(int vertex)
{
	visited[vertex] = true;
	for (size_t i = 0; i < matrix[vertex].size(); i++)
	{
		int to = matrix[vertex][i];
		if (visited[to] == false)
		{
			E(to);
		}
	}
}


int main()
{
	while (scanf("%d%d", &vertexNum, &edgeNum) != EOF)
	{
		if (vertexNum == 0 && edgeNum == 0)
			break;
		memset(visited, false, sizeof(bool) * maxN);
		memset(revVisited, false, sizeof(bool) * maxN);
		for (size_t i = 0; i < maxN; i++)
		{
			matrix[i].clear();
			revMatrix[i].clear();
		}
		while (edgeNum-- > 0)
		{
			int from, to;
			scanf("%d%d", &from, &to);
			matrix[from].push_back(to);
			revMatrix[to].push_back(from);
		}

		for (size_t i = 1; i <= vertexNum; i++)
		{
			if (revVisited[i] == false)
			{
				revE(i);
			}
		}

		E(lastOne);

		int flg = true;

		for (size_t i = 1; i <= vertexNum; i++)
		{
			if (!visited[i])
			{
				flg = false;
				break;
			}
		}
		
		if (flg)printf("Yes\n");
		else printf("No\n");


	}

}
