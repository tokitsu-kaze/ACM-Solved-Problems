////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-04-03 21:19:04
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1429
////Problem Title: 
////Run result: Accept
////Run time:156MS
////Run memory:9092KB
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
const int MAX=20+10;
const int EDGE=100000+10;//±ßµÄÌõÊý
typedef long long ll;
char mp[MAX][MAX];
int flag[MAX][MAX][(1<<11)+10];
int n,m,limt;
int dir[4][2]={0,1,1,0,0,-1,-1,0};
struct node
{
	int x,y,v,key;
};
int check(int x,int y,int z)
{
	if(x<0||y<0||x>=n||y>=m||mp[x][y]=='*'||flag[x][y][z]) return 0;
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
	t.key=0;
	flag[t.x][t.y][0]=1;
	q.push(t);
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		if(t.v>=limt) continue;
		if(mp[t.x][t.y]=='^') return t.v;
		for(i=0;i<4;i++)
		{
			next.x=t.x+dir[i][0];
			next.y=t.y+dir[i][1];
			if(check(next.x,next.y,t.key))
			{
				if(mp[next.x][next.y]>='a'&&mp[next.x][next.y]<='j')
				{
					next.v=t.v+1;
					next.key=t.key|(1<<(mp[next.x][next.y]-'a'));
					flag[next.x][next.y][next.key]=1;
					q.push(next);
				}
				else if(mp[next.x][next.y]>='A'&&mp[next.x][next.y]<='J')
				{
					if((1<<(mp[next.x][next.y]-'A'))&t.key)
					{
						next.v=t.v+1;
						next.key=t.key;
						flag[next.x][next.y][next.key]=1;
						q.push(next);
					}
				}
				else
				{
					next.v=t.v+1;
					next.key=t.key;
					flag[next.x][next.y][next.key]=1;
					q.push(next);
				}
			}
		}
	}
	return -1;
}
int main()
{
	int i,j,sx,sy;
	while(~scanf("%d%d%d",&n,&m,&limt))
	{
		mem(mp,0);
		mem(flag,0);
		for(i=0;i<n;i++)
		{
			scanf("%s",mp[i]);
			for(j=0;j<m;j++)
			{
				if(mp[i][j]=='@')
				{
					sx=i;
					sy=j;
				}
			}
		}
		printf("%d\n",bfs(sx,sy));
	}
    return 0;
}