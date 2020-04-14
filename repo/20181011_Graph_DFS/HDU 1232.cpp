#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <stdlib.h>

//Undirected graph, calculate diconnected connected blocks
//Egde added = Blocks num -1

bool visited[1002];
std::vector<int> matrix[1002];
int v, e;
void E(int vertex)
{
	visited[vertex] = true;
	for (size_t i = 0; i < matrix[vertex].size(); i++)
	{
		int tmp = matrix[vertex][i];
		if (visited[tmp] == false)
		{
			E(tmp);
		}
	}
}


int main()
{
	while (scanf("%d", &v) != EOF)
	{
		if (v == 0)
			break;
		scanf("%d", &e);

		//Inital DataSet
		memset(visited,false,sizeof(bool)*1002);
		for (size_t i = 0; i < 1002; i++)
		{
			matrix[i].clear();
		}

		//Readin
		while (e > 0)
		{
			int from, to;
			scanf("%d %d", &from, &to);
			std::vector<int>::iterator it=std::find(matrix[from].begin(), matrix[from].end(), to);
			if (it == matrix[from].end())
			{
				matrix[from].push_back(to);
			}
			std::vector<int>::iterator it2 = std::find(matrix[to].begin(), matrix[to].end(), from);
			if (it2 == matrix[to].end())
			{
				matrix[to].push_back(from);
			}
			e--;
		}

		//DFS for judging block
		int blockCount = 0;

		for (size_t i = 1; i <= v; i++)
		{
			if (visited[i] == false)
			{
				E(i);
				blockCount++;
			}
		}

		std::cout << blockCount-1 << std::endl;
	}


	//system("PAUSE");
}