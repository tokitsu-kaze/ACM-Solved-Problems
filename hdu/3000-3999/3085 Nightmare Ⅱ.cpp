////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-05-17 18:05:54
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3085
////Problem Title: 
////Run result: Accept
////Run time:421MS
////Run memory:7496KB
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
int n,m,mx,my,gx,gy,zx[3],zy[3];
char mp[811][811];
int dir[4][2]={1,0,0,1,0,-1,-1,0};
int flagm[811][811],flagg[811][811];
struct node
{
	int x,y;
};
int check(int x,int y,int t)
{
	if(x<0||y<0||x>=n||y>=m||mp[x][y]=='X') return 0;
	for(int i=0;i<2;i++)
	{
		if(abs(x-zx[i])+abs(y-zy[i])<=t*2) return 0;
	}
	return 1;
}
int bfs2()
{
	int i,j,sz,res=0;
	node t,next;
	mem(flagm,0);
	mem(flagg,0);
	queue<node> qm,qg;
	t.x=mx;
	t.y=my;
	qm.push(t);
	flagm[t.x][t.y]=1;
	t.x=gx;
	t.y=gy;
	qg.push(t);
	flagg[t.x][t.y]=1;
	while(qm.size()&&qg.size())
	{
		res++;
		for(j=0;j<3;j++)
		{
			sz=qm.size();
			while(sz--)
			{
				t=qm.front();
				qm.pop();
				if(flagg[t.x][t.y]) return res;
				if(!check(t.x,t.y,res)) continue;
				for(i=0;i<4;i++)
				{
					next.x=t.x+dir[i][0];
					next.y=t.y+dir[i][1];
					if(check(next.x,next.y,res)) 
					{
						if(flagg[next.x][next.y]) return res;
						if(!flagm[next.x][next.y])
						{
							qm.push(next);
							flagm[next.x][next.y]=1;
						}
					}
				}
			}
		}
		sz=qg.size();
		while(sz--)
		{
			t=qg.front();
			qg.pop();
			if(flagm[t.x][t.y]) return res;
			if(!check(t.x,t.y,res)) continue;
			for(i=0;i<4;i++)
			{
				next.x=t.x+dir[i][0];
				next.y=t.y+dir[i][1];
				if(check(next.x,next.y,res)) 
				{
					if(flagm[next.x][next.y]) return res;
					if(!flagg[next.x][next.y])
					{
						qg.push(next);
						flagg[next.x][next.y]=1;
					}
				}
			}
		}
	}
	return -1;
}
int main()
{
	int t,i,j,cnt;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		mem(zx,0);
		mem(zy,0);
		cnt=0;
		getchar();
		for(i=0;i<n;i++)
		{
			scanf("%s",mp[i]);
			for(j=0;j<m;j++)
			{
				if(mp[i][j]=='M')
				{
					mx=i;
					my=j;
				}
				else if(mp[i][j]=='G')
				{
					gx=i;
					gy=j;
				}
				else if(mp[i][j]=='Z')
				{
					zx[cnt]=i;
					zy[cnt++]=j;
				}
			}
		}
		int ans=bfs2();
		printf("%d\n",ans);
	}
	return 0;
}
