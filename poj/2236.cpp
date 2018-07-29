#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#define INF 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define MAX 10000000+10
using namespace std;
//typedef __int64 ll;
typedef long long ll;
int n,d,flag[1111];
struct node
{
	int x,y;
	int pre;
}p[1111];
void init()
{
	int i;
	for(i=1;i<=n;i++)
	{
		p[i].pre=i;
	}
}
int find(int x)
{
	if(p[x].pre!=x)
	{
		p[x].pre=find(p[x].pre);
	}
	return p[x].pre;
}
void merge(node a,node b)
{
	int ta,tb;
	ta=find(a.pre);
	tb=find(b.pre);
	if(ta!=tb)
	{
		if((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)<=d*d)
		{
			p[ta].pre=tb;
		}
	}
}
int main()
{
	int i,a,b;
	char op;
	while(~scanf("%d%d",&n,&d))
	{
		init();
		mem(flag,0);
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&p[i].x,&p[i].y);
		}
		while(~scanf("%c",&op))
		{
			if(op=='O')
			{
				scanf("%d",&a);
				flag[a]=1;
				for(i=1;i<=n;i++)
				{
					if(flag[i]&&i!=a) merge(p[i],p[a]);
				}
			}
			else if(op=='S')
			{
				scanf("%d%d",&a,&b);
				if(find(a)==find(b)) puts("SUCCESS");
				else puts("FAIL");
			}
		}
	}
	return 0;
}