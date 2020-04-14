#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstring>
#include <limits.h>
#include <stdio.h>
using namespace::std;
const int maxVertexNum = 100005;

int fee[maxVertexNum];
bool visited[maxVertexNum];
int records[maxVertexNum];
int degIn[maxVertexNum];

vector<int> matrix[maxVertexNum];

int v, e;


//fee of from any src to vertex i
//transfer function
//if records[i]+fee[to]>records[to], update records[to]
int main()
{
	while (scanf("%d%d", &v, &e) != EOF)
	{

		memset(fee, 0, sizeof(int)*maxVertexNum);
		memset(visited, false, sizeof(bool)*maxVertexNum);
		memset(degIn, 0, sizeof(int)*maxVertexNum);
		for (size_t i = 1; i <= v; i++)
		{
			records[i] = INT_MIN;
		}

		for (size_t i = 1; i <= v; i++)
		{
			matrix[i].clear();
		}
		for (size_t i = 1; i <= v; i++)
		{
			scanf("%d", &fee[i]);
		}
		for (size_t i = 0; i < e; i++)
		{
			int from, to;
			scanf("%d%d", &from, &to);
			matrix[from].push_back(to);
			degIn[to]++;
		}

		for (size_t i = 1; i <= v; i++)
		{
			if (degIn[i] == 0)
			{
				records[i] = fee[i];
			}
		}

		int cnt = 0;
		while (cnt < v)
		{
			for (size_t i = 1; i <= v; i++)
			{
				if (!visited[i] && degIn[i] == 0)
				{
					visited[i] = true;
					cnt++;
					for (size_t j = 0; j < matrix[i].size(); j++)
					{
						int tmpV = matrix[i][j];
						degIn[tmpV]--;
						int tmpRecord = records[i] + fee[tmpV];
						records[tmpV] = (tmpRecord > records[tmpV]) ? (records[i] + fee[tmpV]) : records[tmpV];
					}
				}
			}
		}

		int maximumFee = INT_MIN;

		for (size_t i = 1; i <= v; i++)
		{
			if (matrix[i].size() == 0)
			{
				if (records[i] > maximumFee)
				{
					maximumFee = records[i];
				}
			}
		}
		cout << maximumFee << endl;
		//system("PAUSE");
	}

}
