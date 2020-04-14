#include <iostream>
#include <vector>
#include <string>
#include <cmath>

//Euler circle, path
//regard "a"~"z" as vertex
//if all of deg+ == deg-, Euler circle
//else if exists one that deg+=deg- -1 
//else if exists one that deg+=deg- +1 

//Please! Never try to build the adjacency matrix first
//First consider how is the algorithm.



void Explore(std::vector<int>* _matrix, int v, bool* visited)
{
	visited[v] = true;
	for (size_t i = 0; i < _matrix[v].size(); i++)
	{
		if (visited[_matrix[v][i]] == false)
		{
			Explore(_matrix, _matrix[v][i], visited);
		}
	}
}


int main()
{
	int testcase = 0;
	std::cin >> testcase;
	
	for (size_t i = 0; i < testcase; i++)
	{
		int wordcase;
		
		std::cin >> wordcase;
		std::vector<int> in;
		std::vector<int> out;

		std::vector<int> matrix[26];

		bool isVertex[26] = { false };
		int deg_add[26] = { 0 };//out in graph
		int deg_min[26] = { 0 };//in

		for (size_t j = 0; j < wordcase; j++)
		{
			std::string strtmp;
			std::cin >> strtmp;
			deg_add[strtmp.at(0) - 'a']++;
			deg_min[strtmp.at(strtmp.size() - 1) - 'a']++;
			in.push_back(strtmp.at(0) - 'a');
			out.push_back(strtmp.at(strtmp.size() - 1) - 'a');
			isVertex[strtmp.at(0) - 'a'] = isVertex[strtmp.at(strtmp.size() - 1) - 'a'] = true;
		}

		for (size_t j = 0; j < wordcase; j++)
		{
			matrix[in[j]].push_back(out[j]);
		}

		
		//连通性
		bool bigConnected = false;
		for (size_t j = 0; j < 26; j++)
		{
			if (isVertex[j])
			{
				bool visited[26] = { false };
				Explore(matrix, j, visited);

				bool connected = true;

				for (size_t j = 0; j < 26; j++)
				{
					if (visited[j] == false && isVertex[j] == true)
					{
						connected = false;
						break;
					}
				}
				if (connected)
				{
					bigConnected = true;
				}
			}
		}
		

		

		int not_eql = 0, deg_out_1 = 0, deg_in_1 = 0;

		for (size_t j = 0; j < 26; j++)
		{
			if (deg_add[j] != deg_min[j])
			{
				not_eql++;
				if (deg_add[j] == deg_min[j] + 1)
				{
					deg_in_1++;
				}
				if (deg_add[j] == deg_min[j] - 1)
				{
					deg_out_1++;
				}
			}
		}

		if (not_eql == 0&& bigConnected)
		{
			std::cout << "Ordering is possible." << std::endl;
		}
		else if (not_eql == 2 && deg_out_1 == 1 && deg_in_1 == 1 && bigConnected)
		{
			std::cout << "Ordering is possible." << std::endl;
		}
		else {
			std::cout << "The door cannot be opened." << std::endl;
		}
	}
}