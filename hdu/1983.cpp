////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-04-03 19:13:55
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1983
////Problem Title: 
////Run result: Accept
////Run time:2168MS
////Run memory:1612KB
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
const int MAX=100000+10;
const int EDGE=100000+10;//±ßµÄÌõÊý
typedef long long ll;
int n,m,limt,sx,sy;
char mp[11][11];
int flag[11][11][2];
int dir[4][2]={0,1,1,0,-1,0,0,-1};
struct node
{
	int x,y,flag,v;
};
int check(int x,int y)
{
	if(x<0||y<0||x>=n||y>=m||mp[x][y]=='#') return 0;
	return 1;
}
int bfs()
{
	int i;
	node t,next;
	queue<node> q;
	mem(flag,0);
	t.x=sx;
	t.y=sy;
	t.flag=0;
	t.v=0;
	q.push(t);
	flag[sx][sy][0]=1;
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		if(t.v>limt) continue;
		if(mp[t.x][t.y]=='E'&&t.flag) return 0;
		for(i=0;i<4;i++)
		{
			next.x=t.x+dir[i][0];
			next.y=t.y+dir[i][1];
			if(check(next.x,next.y)&&!flag[next.x][next.y][t.flag])
			{
				if(mp[next.x][next.y]=='J') next.flag=1;
				else next.flag=t.flag;
				next.v=t.v+1;
				flag[next.x][next.y][next.flag]=1;
				q.push(next);
			}
		}
	}
	return 1;
}
int dfs(int v)
{
	int i,j;
	char temp;
	if(v==0) return bfs();
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(mp[i][j]=='.'||mp[i][j]=='J')
			{
				temp=mp[i][j];
				mp[i][j]='#';
				if(dfs(v-1)) return 1; 
				mp[i][j]=temp;
			}
		}
	}
	return 0;
}
int main()
{
	int t,i,j;
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			scanf("%d%d%d",&n,&m,&limt);
			mem(mp,0);
			for(i=0;i<n;i++)
			{
				getchar();
				scanf("%s",mp[i]);
				for(j=0;j<m;j++)
				{
					if(mp[i][j]=='S')
					{
						sx=i;
						sy=j;
						break;
					}
				}
			}
			if(bfs()) puts("0");
			else if(dfs(1)) puts("1");
			else if(dfs(2)) puts("2");
			else if(dfs(3)) puts("3");
			else puts("4");
		}
	}
    return 0;
}