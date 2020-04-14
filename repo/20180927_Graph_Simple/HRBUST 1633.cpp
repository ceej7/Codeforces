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

int main()
{
	int testcase = 0;
	std::cin >> testcase;

	for (size_t i = 0; i < testcase; i++)
	{
		int wordcase;
		int deg_add[26] = {0};
		int deg_min[26] = {0};
		std::cin >> wordcase;

		for (size_t j = 0; j < wordcase; j++)
		{
			std::string strtmp;
			std::cin >> strtmp;
			deg_add[strtmp.at(0) - 'a']++;
			deg_min[strtmp.at(strtmp.size() - 1) - 'a']++;
		}

		int not_eql = 0, deg_out_1 = 0, deg_in_1 = 0;

		for (size_t j = 0; j < 26; j++)
		{
			if (deg_add[j]!=deg_min[j])
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
		
		if (not_eql == 0)
		{
			std::cout << "circle" << std::endl;
		}
		else if (not_eql == 2&&deg_out_1 == 1 && deg_in_1 == 1)
		{
			std::cout << "path" << std::endl;
		}
		else {
			std::cout << "oh no" << std::endl;
		}
	}
}