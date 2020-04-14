#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue> 
#include <vector>
#include <functional>
using namespace::std;

class Vert
{
public:

    Vert *pvl;
    Vert *pvr;
	int num;
	Vert(int n, Vert *left, Vert *right)
	{
		num = n;
		pvl = left;
		pvr = right;
	}
};

//May be wrong
int calculateSum( Vert *vp,int i)
{
	if (vp->pvl != NULL && vp->pvr != NULL)
	{
		return calculateSum(vp->pvl, i + 1) + calculateSum(vp->pvr, i + 1);
	}
	else {
		return i * vp->num;
	}
		
}

bool cmp1(const Vert *pa, const Vert *pb) {
	return pa->num < pb->num;
}

vector<Vert *> verts;
char str[100005];
int aplbt[31];
int len;
int est;
int main()
{
	
	while (cin >> str)
	{
		if (strcmp(str, "END") == 0)
		{
			break;
		}
		est = 0;
		verts.clear();
		memset(aplbt, 0, sizeof(aplbt));
		len = strlen(str);
		for (size_t i = 0; i < len; i++)
		{
			aplbt[str[i] - 'A']++;
		}
		for (size_t i = 0; i < 31; i++)
		{
			if (aplbt[i] != 0)
			{
				Vert* pvert=new Vert(aplbt[i], NULL, NULL);
				verts.push_back(pvert);
				est++;
			}
		}
		int fin;
		if (est != 1)
		{
			for (size_t i = 1; i < est; i++)
			{
				sort(verts.begin(), verts.end(), cmp1);
				Vert *pv1 = verts.front();
				verts.erase(verts.begin());
				Vert *pv2 = verts.front();
				verts.erase(verts.begin());
				int sm = pv1->num + pv2->num;
				Vert *pv3 = new Vert(sm, pv1, pv2);
				verts.push_back(pv3);
			}
			fin = calculateSum(verts.front(), 0);
		}
		else {
			fin = len;
		}
		
		printf("%d %d %.1lf\n", 8 * len, fin, (8.0 * len) / fin);

	}
	
}