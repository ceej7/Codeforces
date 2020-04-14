#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue> 
#include <vector>
#include <functional>
using namespace::std;

class Excha {

public:
	Excha(int nex,double r,double cm)
	{
		next = nex;
		rate = r;
		comm = cm;
	}

	int next;
	double rate;
	double comm;
};

int inf = 0x3f3f3f3f;
int n, m,s;
double dis[110];
bool flg;
vector<Excha> adj[110];
//货币之间是双向路径，从s开始，所以只要有一个正环，正换就能回到s，s能赚钱
//同时如果s能赚钱，由于是双向路径，说明可以产生正环
int main()
{

	while (scanf("%d %d %d", &n, &m, &s) != EOF)
	{
		flg = false;
		for (int i = 0; i < 110; i++)
		{
			dis[i] = -inf;
			adj[110].clear();
		}


		scanf("%lf", &dis[s]);

		while (m--)
		{
			int from, to;
			double rate, comm;
			scanf("%d%d", &from, &to);
			scanf("%lf%lf", &rate, &comm);
			Excha excha1(to, rate, comm); adj[from].push_back(excha1);
			scanf("%lf%lf", &rate, &comm);
			Excha excha2(from, rate, comm); adj[to].push_back(excha2);
		}

		for (int i = 1; i < n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				int from = j;
				for (int k = 0; k < adj[from].size(); k++)
				{
					int to = adj[from][k].next;
					double rate = adj[from][k].rate;
					double comm = adj[from][k].comm;
					if (dis[from] != -inf && (dis[from] - comm)*rate > dis[to])
					{
						dis[to] = (dis[from] - comm)*rate;
					}
				}
			}
		}

		for (int j = 1; j <= n; j++)
		{
			int from = j;
			for (int k = 0; k < adj[from].size(); k++)
			{
				int to = adj[from][k].next;
				double rate = adj[from][k].rate;
				double comm = adj[from][k].comm;
				if (dis[from] != -inf && (dis[from] - comm)*rate > dis[to])
				{
					dis[to] = (dis[from] - comm)*rate;
					flg = true;
				}
			}
		}

		if (flg) printf("YES\n");
		else printf("NO\n");
	}
}