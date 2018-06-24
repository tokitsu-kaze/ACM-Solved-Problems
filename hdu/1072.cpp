////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-04-15 15:47:57
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1072
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1568KB
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
const int MAX=100+10;
const int EDGE=100000+10;//±ßµÄÌõÊý
typedef long long ll;
int n,m,mp[11][11],flag[11][11][8];
int dir[4][2]={0,1,1,0,0,-1,-1,0};
struct node
{
	int x,y,v,b;
};
int check(int x,int y,int z)
{
	if(x<0||y<0||x>=n||y>=m||flag[x][y][z]||mp[x][y]==0) return 0;
	return 1;
}
void bfs(int x,int y)
{
	int i;
	node t,next;
	queue<node> q;
	t.x=x;
	t.y=y;
	t.v=0;
	t.b=6;
	flag[x][y][6]=1;
	q.push(t);
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		if(t.b==0) continue;
		if(mp[t.x][t.y]==3)
		{
			printf("%d\n",t.v);
			return;
		}
		if(mp[t.x][t.y]==4) t.b=6;
		for(i=0;i<4;i++)
		{
			next=t;
			next.x=t.x+dir[i][0];
			next.y=t.y+dir[i][1];
			if(check(next.x,next.y,next.b-1))
			{
				flag[next.x][next.y][next.b-1]=1;
				next.v++;
				next.b--;
				q.push(next);
			}
		}
	}
	puts("-1");
}
int main()
{
	int t,i,j,sx,sy;
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			scanf("%d%d",&n,&m);
			mem(mp,0);
			for(i=0;i<n;i++)
			{
				for(j=0;j<m;j++)
				{
					scanf("%d",&mp[i][j]);
					if(mp[i][j]==2)
					{
						sx=i;
						sy=j;
					}
				}
			}
			mem(flag,0);
			bfs(sx,sy);
		}
	}
	return 0;
}