////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-04-04 20:34:03
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2531
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1644KB
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
const int MAX=1000000+10;
const int EDGE=100000+10;//±ßµÄÌõÊý
typedef long long ll;
char mp[111][111];
int ms[22][2],k;
int flag[111][111];
int n,m,dir[4][2]={0,1,1,0,0,-1,-1,0};
struct node
{
	int x,y,v;
};
int check(int x,int y)
{
	if(x<0||y<0||x>=n||y>=m) return 0;
	return 1;
}
int recheck1(int sx,int sy)
{
	int l,x,y;
	for(l=0;l<k;l++)
	{
		x=ms[l][0]+sx;
		y=ms[l][1]+sy;
		if(!check(x,y)||mp[x][y]=='O') return 0;
	}
	return 1;
}
int recheck2(int x,int y)
{
	int i;
	for(i=0;i<k;i++)
	{
		if(mp[ms[i][0]+x][ms[i][1]+y]=='Q') return 1;
	}
	return 0;
}
void bfs(int sx,int sy)
{
	int i;
	node t,next;
	queue<node> q;
	t.x=sx;
	t.y=sy;
	t.v=0;
	flag[sx][sy]=1;
	q.push(t);
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		if(mp[t.x][t.y]=='Q'||recheck2(t.x,t.y))
		{
			printf("%d\n",t.v);
			return;
		}
		for(i=0;i<4;i++)
		{
			next=t;
			next.x=t.x+dir[i][0];
			next.y=t.y+dir[i][1];
			if(check(next.x,next.y)&&mp[next.x][next.y]!='O'&&!flag[next.x][next.y])
			{
				if(recheck1(next.x,next.y))
				{
					next.v++;
					flag[next.x][next.y]=1;
					q.push(next);
				}
			}
		}
	}
	puts("Impossible");
}
int main()
{
	int i,j,sx,sy;
	while(~scanf("%d%d",&n,&m)&&(n+m))
	{
		getchar();
		mem(flag,0);
		mem(mp,0);
		mem(ms,0);
		sx=sy=-1;
		k=0;
		for(i=0;i<n;i++)
		{
			scanf("%s",mp[i]);
			for(j=0;j<m;j++)
			{
				if(mp[i][j]=='D')
				{
					if(sx==-1)
					{
						sx=i;
						sy=j;
					}
					else
					{
						ms[k][0]=i-sx;
						ms[k++][1]=j-sy;
					}
				}
			}
		}
		bfs(sx,sy); 
	}
	return 0;
}