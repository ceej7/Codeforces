#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>
#include <iostream>
using namespace::std;


int inf = 0x3f3f3f3f;

struct point
{
	int x, y;
};

queue<point> que;
int dis[65];

int border1=1,border2=8;

int N = 8;
int dirX[8] = {-1,1,2,2,1,-1,-2,-2};
int dirY[8] = {2,2,1,-1,-2,-2,-1,1};


int main()
{
	char point1[3], point2[3];
	while (cin>>point1>>point2)
	{
		//initial
		while (!que.empty()) que.pop();
		memset(dis, 0x3f, sizeof(int) * 65);


		point from, to;
		from.x = point1[0] - 'a' + 1;
		from.y = point1[1] - '1' + 1;
		to.x= point2[0] - 'a' + 1;
		to.y = point2[1] - '1' + 1;

		que.push(from);
		dis[(from.x - 1) * 8 + from.y]=0;
		while (!que.empty())
		{
			point tmp;
			tmp.x = que.front().x;
			tmp.y = que.front().y;
			que.pop();

			for (size_t i = 0; i < N; i++)
			{
				point tmp2;
				tmp2.x = tmp.x + dirX[i];
				tmp2.y = tmp.y + dirY[i];
				if (dis[(tmp2.x - 1) * 8 + tmp2.y] == inf && tmp2.x >= border1 && tmp2.x <= border2 && tmp2.y >= border1 && tmp2.y <= border2)
				{
					que.push(tmp2);
					dis[(tmp2.x - 1) * 8 + tmp2.y] = dis[(tmp.x - 1) * 8 + tmp.y] + 1;
				}

			}

		}

		cout << "To get from "<<point1<<" to "<<point2<<" takes "<< dis[(to.x - 1) * 8 + to.y] <<" knight moves." << endl;



	}
}
