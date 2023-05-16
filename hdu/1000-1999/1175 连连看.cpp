////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-04-06 10:34:01
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1175
////Problem Title: 
////Run result: Accept
////Run time:1700MS
////Run memory:12384KB
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
int n,m;
int mp[1011][1011];
int flag[1011][1011];
int dir[5][2]={0,0,1,0,0,1,0,-1,-1,0};
struct node
{
	int x,y,flag,v;
	friend bool operator<(node a,node b)
	{
		return a.v>b.v;
	}
};
int check(int x,int y,int ex,int ey)
{
	if(x<1||y<1||x>n||y>m||flag[x][y]||(mp[x][y]&&!(x==ex&&y==ey))) return 0;
	return 1;
}
int bfs(int sx,int sy,int ex,int ey)
{
	int i;
	node t,next;
	priority_queue<node> q;
	mem(flag,0);
	t.x=sx;
	t.y=sy;
	t.flag=0;
	t.v=0;
	q.push(t);
	flag[sx][sy]=1;
	while(!q.empty())
	{
		t=q.top();
		q.pop();
//		cout<<t.x<<" "<<t.y<<" "<<t.v<<endl;
		if(t.x==ex&&t.y==ey) return 1;
		for(i=1;i<=4;i++)
		{
			next=t;
			next.x=t.x+dir[i][0];
			next.y=t.y+dir[i][1];
			if(check(next.x,next.y,ex,ey))
			{
				if(t.flag&&t.flag!=i) next.v++;
				if(next.v>2) continue;
				next.flag=i;
				flag[next.x][next.y]=1;
				q.push(next);
			}
		}
	}
	return 0;
} 
int main()
{
	int i,j,t,x1,y1,x2,y2,flag1,flag2;
	while(~scanf("%d%d",&n,&m)&&(n+m))
	{
		mem(mp,0);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				scanf("%d",&mp[i][j]);
			}
		}
		scanf("%d",&t);
		while(t--)
		{
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			if(!mp[x1][y1]||!mp[x2][y2]||mp[x1][y1]!=mp[x2][y2]) puts("NO");
			else
			{
				flag1=bfs(x1,y1,x2,y2);
				flag2=bfs(x2,y2,x1,y1);
				if(flag1||flag2) puts("YES");
				else puts("NO");
			}
		}
	}
	return 0;
}
/*
3 4
5 0 1 0 
0 0 0 0 
1 4 0 5
2
3 4 1 1
1 1 3 4
3 4
1 1 0 5
0 0 0 0
5 0 1 0
2
3 1 1 4
1 4 3 1 

YES
YES
YES
YES
*/