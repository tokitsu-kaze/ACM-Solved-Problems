////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-04-04 19:55:15
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2653
////Problem Title: 
////Run result: Accept
////Run time:171MS
////Run memory:4744KB
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
char mp[88][88];
int flag[88][88][88];
int n,m,limt,p,dir[4][2]={0,1,1,0,0,-1,-1,0};
struct node
{
	int x,y,p,v;
	friend bool operator<(node a,node b)
	{
		return a.v>b.v;
	}
};
int check(int x,int y)
{
	if(x<0||y<0||x>=n||y>=m||mp[x][y]=='#') return 0;
	return 1;
}
void bfs(int sx,int sy)
{
	int i;
	node t,next;
	priority_queue<node> q;
	t.x=sx;
	t.y=sy;
	t.p=p;
	t.v=0;
	flag[sx][sy][p]=1;
	q.push(t);
	while(!q.empty())
	{
		t=q.top();
		q.pop();
		if(t.v>limt) break;
		if(mp[t.x][t.y]=='L')
		{
			printf("Yes, Yifenfei will kill Lemon at %d sec.\n",t.v);
			return;
		}
		for(i=0;i<4;i++)
		{
			next=t;
			next.x=t.x+dir[i][0];
			next.y=t.y+dir[i][1];
			if(check(next.x,next.y))
			{
				if(mp[next.x][next.y]=='@') continue;
				else if(mp[t.x][t.y]=='@') continue;
				else
				{
					next.v+=2;
					if(!flag[next.x][next.y][next.p])
					{
						flag[next.x][next.y][next.p]=1;
						q.push(next);
					}
				}
			}
		}
		if(!t.p) continue;
		for(i=0;i<4;i++)
		{
			next=t;
			next.x=t.x+dir[i][0];
			next.y=t.y+dir[i][1];
			if(check(next.x,next.y))
			{
				if(mp[t.x][t.y]=='@'||mp[next.x][next.y]=='@')
				{
					next.p--;
					next.v++;
					if(!flag[next.x][next.y][next.p])
					{
						flag[next.x][next.y][next.p]=1;
						q.push(next);
					}
				}
				else
				{
					next.p--;
					next.v++;
					if(!flag[next.x][next.y][next.p])
					{
						flag[next.x][next.y][next.p]=1;
						q.push(next);
					}
				}
			}
		}
	}
	puts("Poor Yifenfei, he has to wait another ten thousand years.");
}
int main()
{
	int i,j,cas=1,sx,sy;
	while(~scanf("%d%d%d%d",&n,&m,&limt,&p))
	{
		getchar();
		mem(flag,0);
		mem(mp,0);
		for(i=0;i<n;i++)
		{
			scanf("%s",mp[i]);
			for(j=0;j<m;j++)
			{
				if(mp[i][j]=='Y')
				{
					sx=i;
					sy=j;
				}
			}
		}
		printf("Case %d:\n",cas++);
		bfs(sx,sy); 
	}
	return 0;
}