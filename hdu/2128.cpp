////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-04-02 23:14:40
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2128
////Problem Title: 
////Run result: Accept
////Run time:811MS
////Run memory:15132KB
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
const int EDGE=20000+10;//±ßµÄÌõÊý
typedef long long ll;
typedef unsigned long long ull;
int n,m,sx,sy;
char mp[11][11];
int wall[11][11],boom[11][11];
int dir[4][2]={0,1,1,0,0,-1,-1,0};
int cntw,cntb;
struct node
{
	int x,y,v,boom;
	ull boomflag,wallflag;
	friend bool operator<(node a,node b)
	{
		return a.v>b.v;
	}
};
vector<node> flag[11][11][8*8*9+10];
int check(node a)
{
	int i;
	for(i=0;i<flag[a.x][a.y][a.boom].size();i++)
	{
		if(flag[a.x][a.y][a.boom][i].boomflag==a.boomflag&&flag[a.x][a.y][a.boom][i].wallflag==a.wallflag) return 0;
	}
	return 1;
}
int bfs(int x,int y)
{
	int i;
	node t,next;
	priority_queue<node> q;
	t.x=x;
	t.y=y;
	t.v=0;
	t.boom=0;
	t.wallflag=(1ull<<cntw)-1;
	t.boomflag=0;
	q.push(t);
	while(!q.empty())
	{
		t=q.top();
		q.pop();
		for(i=0;i<4;i++)
		{
			next=t;
			next.x=t.x+dir[i][0];
			next.y=t.y+dir[i][1];
			if(next.x<0||next.y<0||next.x>=n||next.y>=m);
			else
			{
				if(mp[next.x][next.y]=='D') return next.v+1;
				if(mp[next.x][next.y]=='X'&&((1ull<<wall[next.x][next.y])&next.wallflag))
				{
					if(next.boom>0)
					{
						next.boom--;
						next.v+=2;
						next.wallflag^=(1ull<<wall[next.x][next.y]);
						q.push(next);
						flag[next.x][next.y][next.boom].push_back(next);
					}
				}
				else if(mp[next.x][next.y]>='1'&&mp[next.x][next.y]<='9'&&((1ull<<boom[next.x][next.y])&next.boomflag)==0)
				{
					next.boom+=(mp[next.x][next.y]-'0');
					next.v++;
					next.boomflag|=(1ull<<boom[next.x][next.y]);
					flag[next.x][next.y][next.boom].push_back(next);
					q.push(next);
				}
				else
				{
					next.v++;
					if(flag[next.x][next.y][next.boom].empty()||check(next))
					{
						flag[next.x][next.y][next.boom].push_back(next);
						q.push(next);
					}
				}
			}
		}
	}
	return -1;
}
void init()
{
	int i,j,k;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			for(k=0;k<8*8*9+10;k++)
			{
				flag[i][j][k].clear();
			}
		}
	}
}
int main()
{
	int i,j;
	while(~scanf("%d%d",&n,&m)&&(n+m))
	{
		init();
		mem(mp,0);
		mem(wall,0);
		mem(boom,0);
		cntw=cntb=0;
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
				}
				else if(mp[i][j]=='X') wall[i][j]=cntw++;
				else if(mp[i][j]>='1'&&mp[i][j]<='9') boom[i][j]=cntb++;
			}
		}
		printf("%d\n",bfs(sx,sy));
	}
	return 0;
}