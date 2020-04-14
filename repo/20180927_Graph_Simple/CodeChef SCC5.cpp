#include <iostream>
#include <vector>
#include <string>
#include <cmath>

bool findInVector(std::vector<int> vec, int num)
{
	for (size_t i = 0; i < vec.size(); i++)
	{
		if (vec[i] == num)
			return true;
	}
	return false;
}


int main()
{
	int testcase = 0;
	int vertex_num, edge_num;
	int v1, v2;

	std::cin >> testcase;

	for (size_t i = 0; i < testcase; i++)
	{
		//adjacency inital
		std::cin >> vertex_num >> edge_num;
		std::vector<std::vector<int>> matrix;

		for (size_t z = 0; z <= vertex_num; z++)
		{
			std::vector<int> tmp;
			matrix.push_back(tmp);
		}

		for (size_t k = 0; k < edge_num; k++)
		{
			int from, to;
			std::cin >> from >> to;
			matrix[to].push_back(from);
		}

		//to be celebrity
		std::vector<int> candidate;

		for (size_t j = 1; j <= vertex_num; j++)
		{
			if (matrix[j].size() == vertex_num - 1)
			{
				candidate.push_back(j);
			}
		}

		std::vector<int> celebrity;
		for (size_t l = 0; l < candidate.size(); l++)
		{
			bool isCele = true;
			int person = candidate[l];
			//loop for others except the candidate
			for (size_t m = 1; m <=vertex_num ; m++)
			{
				if (m != person)
				{
					if (findInVector(matrix[m],person))
					{
						isCele = false;
						break;
					}
				}
			}

			if (isCele)
			{
				celebrity.push_back(person);
			}
		}

		if (celebrity.size() == 0)
		{
			std::cout << "dead" << std::endl;
		}
		else {
			std::cout << "alive " << celebrity.at(0)<<std::endl;
		}
		

	}
}