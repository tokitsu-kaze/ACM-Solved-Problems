////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-04-03 20:43:05
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1254
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1928KB
//////////////////System Comment End//////////////////
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
#include <set>
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-12;
const int MAX=10+10;
const int EDGE=100000+10;//±ßµÄÌõÊý
typedef long long ll;
int mp[MAX][MAX];
int flag[MAX][MAX][MAX*10+MAX];
int n,m,e;
int dir[4][2]={0,1,1,0,0,-1,-1,0};
struct node
{
	int x,y,v,tx,ty;
	friend bool operator<(node a,node b)
	{
		return a.v>b.v;
	}
};
int check(int x,int y)
{
	if(x<0||y<0||x>=n||y>=m||mp[x][y]==1) return 0;
	return 1;
}
int bfs(int sx,int sy,int tx,int ty)
{
	int i;
	node t,next;
	priority_queue<node> q;
	mem(flag,0);
	t.x=sx;
	t.y=sy;
	t.v=0;
	t.tx=tx;
	t.ty=ty;
	flag[t.x][t.y][t.tx*10+t.ty]=1;
	q.push(t);
	while(!q.empty())
	{
		t=q.top();
		q.pop();
		if(mp[t.tx][t.ty]==3) return t.v;
		for(i=0;i<4;i++)
		{
			next=t;
			next.x=t.x+dir[i][0];
			next.y=t.y+dir[i][1];
			if(check(next.x,next.y)&&!flag[next.x][next.y][next.tx*10+next.ty])
			{
				if(next.x==next.tx&&next.y==next.ty)
				{
					if(check(next.x+dir[i][0],next.y+dir[i][1]))
					{
						next.tx=next.x+dir[i][0];
						next.ty=next.y+dir[i][1];
						next.v=t.v+1;
						flag[next.x][next.y][next.tx*10+next.ty]=1;
						q.push(next);
					}
				}
				else
				{
					flag[next.x][next.y][next.tx*10+next.ty]=1;
					q.push(next);
				}
			}
		}
	}
	return -1;
}
int main()
{
	int i,j,t,sx,sy,x,y,ans;
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			scanf("%d%d",&n,&m);
			mem(mp,0);
			mem(flag,0);
			for(i=0;i<n;i++)
			{
				for(j=0;j<m;j++)
				{
					scanf("%d",&mp[i][j]);
					if(mp[i][j]==4)
					{
						sx=i;
						sy=j;
					}
					else if(mp[i][j]==2)
					{
						x=i;
						y=j;
					}
				}
			}
			printf("%d\n",bfs(sx,sy,x,y));
		}
	}
    return 0;
}