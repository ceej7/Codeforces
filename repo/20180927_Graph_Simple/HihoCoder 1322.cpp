#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>

//node
struct vertex
{
	int v;
	vertex * next=NULL;
};

void Explore(vertex** adjacency_matrix, bool* visited,int todo)
{
	visited[todo] = true;
	if (adjacency_matrix[todo-1] != NULL)
	{
		vertex* pvt = adjacency_matrix[todo-1];
		do {
			if (visited[pvt->v] == false)
			{
				Explore(adjacency_matrix, visited, pvt->v);
			}
			pvt = pvt->next;
		} while (pvt != NULL);
	}
}

int main()
{
	// Concepts:
	// |E| = |V| -1
	//     &&
	// Connected from any vertex

	//initial
	int testcase = 0;
	int vertex_num, edge_num;
	int v1, v2;
	vertex** adjacency_matrix;
	bool* visited;

	std::cin >> testcase;

	for (size_t i = 0; i < testcase; i++)
	{
		//adjacency inital
		std::cin >> vertex_num >> edge_num;
		adjacency_matrix = (vertex**)malloc(sizeof(vertex*)*vertex_num);
		for (size_t k = 0; k < vertex_num; k++)
		{
			adjacency_matrix[k] = NULL;
		}

		//adding edge
		for (size_t j = 0; j < edge_num; j++)
		{
			std::cin >> v1 >> v2;
			// for v1->v2
			if (adjacency_matrix[v1 - 1] == NULL)
			{
				vertex* tmp=(vertex*)malloc(sizeof(vertex));
				tmp->next = NULL;
				adjacency_matrix[v1 - 1] = tmp;
				adjacency_matrix[v1 - 1]->v = v2;
			}
			else {
				vertex* pvt = adjacency_matrix[v1 - 1];
				while (pvt->next != NULL)
				{
					pvt = pvt->next;
				}
				vertex* tmp = (vertex*)malloc(sizeof(vertex));
				tmp->next = NULL;
				pvt->next = tmp;
				pvt->next->v = v2;
			}

			// for v2->v1
			if (adjacency_matrix[v2 - 1] == NULL)
			{
				vertex* tmp = (vertex*)malloc(sizeof(vertex));
				tmp->next = NULL;
				adjacency_matrix[v2 - 1] = tmp;
				adjacency_matrix[v2 - 1]->v = v1;
			}
			else {
				vertex* pvt = adjacency_matrix[v2 - 1];
				while (pvt->next != NULL)
				{
					pvt = pvt->next;
				}
				vertex* tmp = (vertex*)malloc(sizeof(vertex));
				tmp->next = NULL;
				pvt->next = tmp;
				pvt->next->v = v1;
			}

		}

		visited = (bool *)malloc(sizeof(bool)*(vertex_num + 1));
		for (size_t l = 0; l <= vertex_num; l++)
		{
			visited[l] = false;
		}
		Explore(adjacency_matrix, visited, 1);
		
		int counting = 0;
		for (size_t m = 1; m <= vertex_num; m++)
		{
			if (visited[m] == true)
			{
				counting++;
			}
		}
		if (counting == vertex_num && vertex_num == (edge_num + 1))
			std::cout << "YES" << std::endl;
		else
			std::cout << "NO" << std::endl;

	}


	system("PAUSE");
}