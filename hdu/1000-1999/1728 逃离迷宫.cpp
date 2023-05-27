////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-16 12:05:00
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1728
////Problem Title: 
////Run result: Accept
////Run time:265MS
////Run memory:7020KB
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
#define INF 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define eps 1e-9
#define MAX 10000+10
#define EDGE 20000+10//±ßµÄÌõÊý 
using namespace std;
//typedef __int64 ll;
typedef long long ll;
int m,n,k,ex,ey,dir[4][2]={1,0,0,1,-1,0,0,-1};
int flag[111][111][111];
char mp[111][111];
struct node
{
	int x,y,v,now;
};
int check(int x,int y)
{
	if(x<1||y<1||x>m||y>n||mp[x][y]=='*') return 0;
	return 1;
}
int bfs(int x,int y)
{
	int i,cnt;
	node t,next;
	queue<node> q;
	t.x=x;
	t.y=y;
	t.v=0;
	t.now=0;
	q.push(t);
	while(!q.empty())
	{
		t=q.front();
		q.pop();
//		cout<<t.x<<" "<<t.y<<" "<<t.v<<endl;
		if(t.x==ex&&t.y==ey) return 1;
		for(i=0;i<4;i++)
		{
			next.x=t.x+dir[i][0];
			next.y=t.y+dir[i][1];
			next.v=t.v;
			if(check(next.x,next.y))
			{
				if(next.x==t.x+1)
				{
					next.now=1;
					if(next.now!=t.now&&t.now) next.v++;
				}
				else if(next.x==t.x-1)
				{
					next.now=2;
					if(next.now!=t.now&&t.now) next.v++;
				}
				else if(next.y==t.y+1)
				{
					next.now=3;
					if(next.now!=t.now&&t.now) next.v++;
				}
				else if(next.y==t.y-1)
				{
					next.now=4;
					if(next.now!=t.now&&t.now) next.v++;
				}
				if(next.v<=k)
				{
					if(!flag[next.x][next.y][next.now*20+next.v]) q.push(next);
					flag[next.x][next.y][next.now*20+next.v]=1;
				}
			}
		}
	}
	return 0;
}
int main()
{
	int t,i,j,sx,sy;
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			mem(flag,0);
			mem(mp,0);
			scanf("%d%d",&m,&n);
			for(i=1;i<=m;i++)
			{
				getchar();
				for(j=1;j<=n;j++)
				{
					scanf("%c",&mp[i][j]);
				}
			}
			scanf("%d%d%d%d%d",&k,&sy,&sx,&ey,&ex);
			if(mp[sx][sy]=='*'||mp[ex][ey]=='*')
			{
				puts("no");
				continue;
			}
			if(bfs(sx,sy)) puts("yes");
			else puts("no");
		}
	}
    return 0;
}
/*

4
5 5
...**
*.**.
.....
.....
*....
1 1 1 1 3
5 5
...**
*.**.
.....
.....
*....
2 1 1 1 3
10 10
.*********
..........
****.****.
..........
.***.*****
..........
*********.
..........
.*********
..........
7 1 1 10 10
5 5
.....
.*.*.
.....
.*.*.
.....
1 1 1 3 4


no
yes
yes
yes

*/