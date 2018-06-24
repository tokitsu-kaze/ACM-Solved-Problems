////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-04-06 09:45:39
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1026
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1944KB
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
int m,n;
char mp[111][111];
int flag[111][111];
int dir[4][2]={0,1,1,0,0,-1,-1,0};
struct node
{
	int x,y,v;
	friend bool operator<(node a,node b)
	{
		return a.v>b.v;
	} 
}pre[111][111];
int check(int x,int y)
{
	if(x<0||y<0||x>=n||y>=m||mp[x][y]=='X'||flag[x][y]) return 0;
	return 1;
}
int bfs(int sx,int sy)
{
	node t,next;
	int i;
	priority_queue<node> q;
	t.x=sx;
	t.y=sy;
	t.v=0;
	flag[sx][sy]=1;
	q.push(t);
	while(!q.empty())
	{
		t=q.top();
		q.pop();
		if(t.x==n-1&&t.y==m-1) return t.v;
		for(i=0;i<4;i++)
		{
			next.v=t.v;
			next.x=t.x+dir[i][0];
			next.y=t.y+dir[i][1];
			if(check(next.x,next.y))
			{
				if(mp[next.x][next.y]>='1'&&mp[next.x][next.y]<='9') next.v+=mp[next.x][next.y]-'0';
				next.v++;
				pre[next.x][next.y]=t;
				flag[next.x][next.y]=1;
				q.push(next);
			}
		}
	}
	return 0;
}
int main()
{
	int i,j,ans,cnt;
	node t,next;
	while(~scanf("%d%d",&n,&m))
	{
		getchar();
		mem(mp,0);
		mem(flag,0);
		for(i=0;i<n;i++)
		{
			scanf("%s",mp[i]);
		}
		ans=bfs(0,0);
		if(ans)
		{
			printf("It takes %d seconds to reach the target position, let me show you the way.\n",ans);
			stack<node> s;
			t.x=n-1;
			t.y=m-1;
			while(pre[t.x][t.y].x||pre[t.x][t.y].y)
			{
				t=pre[t.x][t.y];
				s.push(t);
			}
			cnt=1;
			printf("%ds:(0,0)->",cnt++);
			t.x=0;
			t.y=0;
			t.v=0;
			while(!s.empty())
			{
				next=s.top();
				s.pop();
				printf("(%d,%d)\n",next.x,next.y);
				if(next.v-t.v==1)
				{
					printf("%ds:(%d,%d)->",cnt++,next.x,next.y);
				}
				else
				{
					for(cnt=t.v+2;cnt<=next.v;cnt++)
					{
						printf("%ds:FIGHT AT (%d,%d)\n",cnt,next.x,next.y);
					}
					printf("%ds:(%d,%d)->",cnt++,next.x,next.y);
				}
				t=next;
			}
			printf("(%d,%d)\n",n-1,m-1);
			if(mp[n-1][m-1]>='1'&&mp[n-1][m-1]<='9')
			{
				for(i=0;i<mp[n-1][m-1]-'0';i++)
				{
					printf("%ds:FIGHT AT (%d,%d)\n",cnt++,n-1,m-1);
				}
			}
		}
		else puts("God please help our poor hero.");
		puts("FINISH");
	}
	return 0;
}