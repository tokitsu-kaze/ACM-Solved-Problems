////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-04-03 20:01:00
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2612
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:2148KB
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
const int MAX=200+10;
const int EDGE=100000+10;//±ßµÄÌõÊý
typedef long long ll;
char mp[MAX][MAX];
int flag[MAX][MAX];
int n,m,sum[MAX][MAX][2];
int dir[4][2]={0,1,1,0,0,-1,-1,0};
struct node
{
	int x,y,v;
};
int check(int x,int y)
{
	if(x<0||y<0||x>=n||y>=m||flag[x][y]||mp[x][y]=='#') return 0;
	return 1;
}
void bfs(int sx,int sy,int tag)
{
	int i;
	node t,next;
	queue<node> q;
	mem(flag,0);
	t.x=sx;
	t.y=sy;
	t.v=0;
	flag[t.x][t.y]=1;
	q.push(t);
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		if(mp[t.x][t.y]=='@') sum[t.x][t.y][tag]=min(sum[t.x][t.y][tag],t.v);
		for(i=0;i<4;i++)
		{
			next.x=t.x+dir[i][0];
			next.y=t.y+dir[i][1];
			if(check(next.x,next.y))
			{
				next.v=t.v+1;
				flag[next.x][next.y]=1;
				q.push(next);
			}
		}
	}
}
int main()
{
	int i,j,k,ans,sx1,sy1,sx2,sy2;
	while(~scanf("%d%d",&n,&m))
	{
		mem(mp,0);
		mem(sum,0x3f);
		for(i=0;i<n;i++)
		{
			getchar();
			scanf("%s",mp[i]);
			for(j=0;j<m;j++)
			{
				if(mp[i][j]=='Y')
				{
					sx1=i;
					sy1=j;
				}
				else if(mp[i][j]=='M')
				{
					sx2=i;
					sy2=j;
				}
			}
		}
		bfs(sx1,sy1,0);
		bfs(sx2,sy2,1);
		ans=INF;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(mp[i][j]=='@')
				{
					ans=min(ans,sum[i][j][0]+sum[i][j][1]);
				}
			}
		}
		printf("%d\n",ans*11);
	}
    return 0;
}