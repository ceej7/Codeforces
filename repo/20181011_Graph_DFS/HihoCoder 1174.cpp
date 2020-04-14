#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <cstring>
bool visited[100002];
std::vector<int> matrix[100002];
int exitTime[100002];
int time1=0;
int v, e;

void E(int vertex)
{
	time1++;
	visited[vertex] = true;
	for (size_t i = 0; i < matrix[vertex].size(); i++)
	{
		int tmp = matrix[vertex][i];
		if (visited[tmp] == false)
		{
			E(tmp);
		}
	}
	time1++;
	exitTime[vertex] = time1;
}


int main()
{
	int t;
	std::cin >> t;
	while (t-- > 0)
	{
		std::cin >> v >> e;

		time1 = 0;
		memset(visited, false, sizeof(bool) * 100002);
		memset(exitTime, 0, sizeof(int) * 100002);

		for (size_t i = 0; i < 100002; i++)
		{
			matrix[i].clear();
		}

		while (e-- > 0)
		{
			int from; int to;
			std::cin >> from >> to;
			matrix[from].push_back(to);
		}

		for (size_t i = 1; i <= v; i++)
		{
			if(visited[i]==false)
				E(i);
		}


		bool flg=true;
		for (size_t i = 1; i <= v; i++)
		{
			for (size_t j = 0; j < matrix[i].size(); j++)
			{
				if (exitTime[i] < exitTime[matrix[i][j]])
				{
					flg = false;
				}
			}
		}
		if (flg)
			std::cout << "Correct" << std::endl;
		else
			std::cout << "Wrong" << std::endl;
	}
	//system("PAUSE");
}