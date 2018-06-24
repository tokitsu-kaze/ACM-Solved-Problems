////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-04-03 22:04:48
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2579
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:6828KB
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
char mp[MAX][MAX];
int flag[MAX][MAX][MAX];
int n,m,k;
int dir[4][2]={0,1,1,0,0,-1,-1,0};
struct node
{
	int x,y,v;
};
int check(int x,int y,int z)
{
	if(x<0||y<0||x>=n||y>=m||flag[x][y][z]) return 0;
	return 1;
}
int bfs(int sx,int sy)
{
	int i;
	node t,next;
	queue<node> q;
	t.x=sx;
	t.y=sy;
	t.v=0;
	flag[t.x][t.y][t.v]=1;
	q.push(t);
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		if(mp[t.x][t.y]=='G') return t.v;
		for(i=0;i<4;i++)
		{
			next.x=t.x+dir[i][0];
			next.y=t.y+dir[i][1];
			next.v=t.v+1;
			if(check(next.x,next.y,next.v%k))
			{
				
				if(mp[next.x][next.y]=='#')
				{
					if(next.v%k==0)
					{
						flag[next.x][next.y][next.v%k]=1;
						q.push(next);
					}
				}
				else
				{
					flag[next.x][next.y][next.v%k]=1;
					q.push(next);
				}
			}
		}
	}
	return -1;
}
int main()
{
	int i,j,sx,sy,t,ans;
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			scanf("%d%d%d",&n,&m,&k);
			mem(mp,0);
			mem(flag,0);
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
			ans=bfs(sx,sy);
			if(ans==-1) puts("Please give me another chance!");
			else printf("%d\n",ans);
		}
	}
    return 0;
}