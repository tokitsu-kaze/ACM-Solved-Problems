////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-05-17 20:41:15
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1401
////Problem Title: 
////Run result: Accept
////Run time:670MS
////Run memory:28380KB
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

int sx[5],sy[5];
bool flag1[8][8][8][8][8][8][8][8];
int dir[4][2]={0,1,1,0,0,-1,-1,0};
int mp[11][11];
struct node
{
	int x[4],y[4],v;
};
int check(int x,int y)
{
	if(x<0||y<0||x>=8||y>=8) return 0;
	return 1;
}
int judge(node a)
{
	for(int i=0;i<4;i++)
	{
		if(!mp[a.x[i]][a.y[i]]) return 0;
	}
	return 1;
}
int empty(node a,int k)
{
	for(int i=0;i<4;i++)
	{
		if(i!=k)
		{
			if(a.x[i]==a.x[k]&&a.y[i]==a.y[k]) return 0;
		}
	}
	return 1;
}
int bfs()
{
	int i,j;
	mem(flag1,0);
	node t,next;
	queue<node> q;
	for(i=0;i<4;i++)
	{
		t.x[i]=sx[i];
		t.y[i]=sy[i];
	}
	t.v=0;
	q.push(t);
	flag1[t.x[0]][t.y[0]][t.x[1]][t.y[1]][t.x[2]][t.y[2]][t.x[3]][t.y[3]]=true;
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		if(t.v>=8) return 0;
		if(judge(t)) return 1;
		t.v++;
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
				next=t;
				next.x[i]=t.x[i]+dir[j][0];
				next.y[i]=t.y[i]+dir[j][1];
				if(empty(next,i))
				{
					if(check(next.x[i],next.y[i]))
					{
						if(judge(next)) return 1;
						if(!flag1[next.x[0]][next.y[0]][next.x[1]][next.y[1]][next.x[2]][next.y[2]][next.x[3]][next.y[3]])
						{
							flag1[next.x[0]][next.y[0]][next.x[1]][next.y[1]][next.x[2]][next.y[2]][next.x[3]][next.y[3]]=true;
							q.push(next);
						}
					}
				}
				else
				{
					next.x[i]+=dir[j][0];
					next.y[i]+=dir[j][1];
					if(empty(next,i))
					{
						if(check(next.x[i],next.y[i]))
						{
							if(judge(next)) return 1;
							if(!flag1[next.x[0]][next.y[0]][next.x[1]][next.y[1]][next.x[2]][next.y[2]][next.x[3]][next.y[3]])
							{
								flag1[next.x[0]][next.y[0]][next.x[1]][next.y[1]][next.x[2]][next.y[2]][next.x[3]][next.y[3]]=true;
								q.push(next);
							}
						}
					}
				}
			}
		}
	}
	return 0;
}
int main()
{
	int i,x,y;
	while(~scanf("%d%d%d%d%d%d%d%d",&sx[0],&sy[0],&sx[1],&sy[1],&sx[2],&sy[2],&sx[3],&sy[3]))
	{
		for(i=0;i<4;i++)
		{
			sx[i]-=1;
			sy[i]-=1;
		}
		mem(mp,0);
		for(i=0;i<4;i++)
		{
			scanf("%d%d",&x,&y);
			x-=1;
			y-=1;
			mp[x][y]=1;
		}
		int ans=bfs();
		if(ans) puts("YES");
		else puts("NO");
	}
	return 0;
}