#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>
#include <iostream>
using namespace::std;


int inf = 0x3f3f3f3f;
int N = 205;
int dist[205];

vector<int> matrix[205];
vector<int> unflooded;
int roadMatrix[205][205];

int findMin()
{
	int tmpDis = inf;
	int lastNum;
	int indexToErase;
	for (size_t i = 0; i < unflooded.size(); i++)
	{
		int tmpVertex = unflooded[i];
		if (dist[tmpVertex] <= tmpDis)
		{
			tmpDis = dist[tmpVertex];
			lastNum = tmpVertex;
			indexToErase = i;
		}
	}
	vector<int>::iterator   iter = unflooded.begin() + indexToErase;
	unflooded.erase(iter);
	return lastNum;
}

//切记注意！！！！没说边不重复则要判断城镇之间的重复路径
int main()
{
	int v, e;
	while (cin >> v >> e)
	{
		memset(dist, 0x3f, sizeof(int) * N);
		memset(roadMatrix, 00, sizeof(int) * N *N);
		for (size_t i = 0; i < N; i++) matrix[i].clear();
		unflooded.clear();
		while (e--)
		{
			int a, b, c;
			cin >> a>>b>>c;
			a++;
			b++;
			if (roadMatrix[a][b] == 0)
			{
				matrix[a].push_back(b);
				matrix[b].push_back(a);
				roadMatrix[a][b] = c;
				roadMatrix[b][a] = c;
			}
			else if (c < roadMatrix[a][b])
			{
				roadMatrix[a][b] = c;
				roadMatrix[b][a] = c;
			}
			
		}
		int start, end;
		cin >> start >> end;
		start++;
		end++;


		//dijkstra
		dist[start] = 0;

		for (size_t i = 1; i <= v; i++)
		{
			unflooded.push_back(i);
		}
		
		while (unflooded.size() != 0)
		{
			int least = findMin();
			for (size_t i = 0; i < matrix[least].size(); i++)
			{
				int tmpVertex = matrix[least][i];
				if (dist[least] + roadMatrix[least][tmpVertex] < dist[tmpVertex])
				{
					dist[tmpVertex] = dist[least] + roadMatrix[least][tmpVertex];
				}
			}
		}

		if(dist[end]<inf)
		{
			cout << dist[end] << endl;
		}
		else {
			cout << -1 << endl;
		}

	}
}
