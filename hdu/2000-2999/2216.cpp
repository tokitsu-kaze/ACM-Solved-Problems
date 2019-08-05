////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-05-17 15:52:23
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2216
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:2648KB
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
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=100000+10;
const ll mod=1e6;
int n,m,sx,sy,zx,zy;
char mp[22][22];
int dir[4][2]={1,0,0,1,-1,0,0,-1};
int flag[22][22][22][22];
struct node
{
	int zx,zy,v;
	int sx,sy;
};
int check(int x,int y)
{
	if(x<0||y<0||x>=n||y>=m||mp[x][y]=='X') return 0;
	return 1;
}
int judge(int x1,int y1,int x2,int y2)
{
	int a=abs(x1-x2);
	int b=abs(y1-y2);
	if(a+b<2) return 1;
	return 0;
}
int bfs()
{
	int i;
	node t,next,next1;
	queue<node> q;
	t.zx=zx;
	t.zy=zy;
	t.sx=sx;
	t.sy=sy;
	t.v=0;
	mem(flag,0);
	flag[t.zx][t.zy][t.sx][t.sy]=1;
	q.push(t);
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		if(judge(t.zx,t.zy,t.sx,t.sy)) return t.v;
		for(i=0;i<4;i++)
		{
			next=t;
			next.zx+=dir[i][0];
			next.zy+=dir[i][1];
			next.v++;
			if(check(next.zx,next.zy))
			{
				next1=next;
				next1.sx-=dir[i][0];
				next1.sy-=dir[i][1];
				if(check(next1.sx,next1.sy))
				{
					if(!flag[next1.zx][next1.zy][next1.sx][next1.sy])
					{
						q.push(next1);
						flag[next1.zx][next1.zy][next1.sx][next1.sy]=1;
					}
				}
				else
				{
					if(!flag[next.zx][next.zy][next.sx][next.sy])
					{
						q.push(next);
						flag[next.zx][next.zy][next.sx][next.sy]=1;
					}
				}
			}
		}
	}
	return -1;
}
int main()
{
	int i,j;
	while(~scanf("%d%d",&n,&m))
	{
		getchar();
		mem(mp,0);
		for(i=0;i<n;i++)
		{
			scanf("%s",mp[i]);
			for(j=0;j<m;j++)
			{
				if(mp[i][j]=='S')
				{
					sx=i;
					sy=j;
				}
				else if(mp[i][j]=='Z')
				{
					zx=i;
					zy=j;
				}
			}
		}
		int ans=bfs();
		if(ans==-1) puts("Bad Luck!");
		else printf("%d\n",ans);
	}
	return 0;
}

