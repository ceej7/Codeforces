#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>
#include <stdio.h>
using namespace::std;
const int maxN = 1005;

bool visited[maxN];
vector<int> matrix[maxN];

bool revVisited[maxN];
vector<int> revMatrix[maxN];

int colors[maxN];
int colorNum;

vector<int> smallMatrix[maxN];
int degIn[maxN];

int vertexNum, edgeNum;
int lastOne;

vector<int> tp;

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
	tp.push_back(vertex);
}

void E(int vertex,int col)
{
	visited[vertex] = true;
	colors[vertex] = col;
	for (size_t i = 0; i < matrix[vertex].size(); i++)
	{
		int to = matrix[vertex][i];
		if (visited[to] == false)
		{
			E(to, col);
		}
	}
}


int main()
{
	int caseNum;
	scanf("%d", &caseNum);
	while (caseNum-- > 0)
	{
		scanf("%d%d", &vertexNum, &edgeNum);

		memset(visited, false, sizeof(bool)*maxN);
		memset(revVisited, false, sizeof(bool)*maxN);
		memset(colors, 0, sizeof(int)*maxN);
		memset(degIn, 0, sizeof(int)*maxN);
		colorNum = 0;
		tp.clear();

		for (size_t i = 0; i < maxN; i++)
		{
			matrix[i].clear();
			smallMatrix[i].clear();
			revMatrix[i].clear();
		}
		//readin
		while(edgeNum-->0)
		{ 
			int from, to;
			scanf("%d%d", &from, &to);
			matrix[from].push_back(to);
			revMatrix[to].push_back(from);
		}

		//得到tp的list
		for (size_t i = 1; i <= vertexNum; i++)
		{
			if (!revVisited[i])
			{
				revE(i);
			}
		}

		//正想图dps上色
		for (int i = tp.size()-1; i >=0; --i)
		{
			int vert = tp[i];
			if (!visited[vert])
			{
				colorNum++;
				E(vert, colorNum);
			}
		}

		//Build small matrix depends on color
		for (size_t i = 1; i <= colorNum; i++)
		{
			for (size_t j = 1; j <=vertexNum; j++)
			{
				if (colors[j] == i)
				{
					for (size_t k = 0; k < matrix[j].size(); k++)
					{
						int to = matrix[j][k];// j -> to
						int colTo = colors[to];//color i -> colTo;

						//如果缩图中没有存在，则放入i -> colTo的通量
						if (i != colTo)
						{
							vector<int>::iterator it = find(smallMatrix[i].begin(), smallMatrix[i].end(), colTo);
							if (it == smallMatrix[i].end())
							{
								smallMatrix[i].push_back(colTo);
								degIn[colTo]++;
							}
						}
						
						
					}
				}
			}
		}

		//拓扑迭代判断入度为0的结点是否大于1

		int cnt = colorNum;
		bool colorVisited[maxN];
		bool flg = true;
		memset(colorVisited, false, sizeof(bool)*maxN);
		while (cnt-- > 0)
		{
			int zeroDegIn = 0;
			int from;
			for (size_t i = 1; i <=colorNum; i++)
			{
				if (colorVisited[i] == false && degIn[i] == 0)
				{
					from = i;
					zeroDegIn++;
				}
			}
			if (zeroDegIn == 1)
			{
				colorVisited[from] = true;
				for (size_t i = 0; i < smallMatrix[from].size(); i++)
				{
					int to = smallMatrix[from][i];
					degIn[to]--;
				}
			}
			else {
				flg = false;
				break;
			}
		}

		if (flg)
		{
			printf("Yes\n");
		}
		else {
			printf("No\n");
		}

	}
}
