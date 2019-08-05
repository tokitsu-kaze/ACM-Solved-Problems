////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-05-17 16:12:18
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2425
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1700KB
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
int n,m,sx,sy,ex,ey;
char mp[22][22];
int flag[22][22],dir[4][2]={0,1,1,0,0,-1,-1,0};
map<char,int> v;
struct node
{
	int x,y,v;
	friend bool operator<(node a,node b)
	{
		return a.v>b.v;
	}
};
int check(int x,int y)
{
	if(x<0||y<0||x>=n||y>=m||mp[x][y]=='@') return 0;
	return 1;
}
int bfs()
{
	int i;
	node t,next;
	priority_queue<node> q;
	mem(flag,0);
	t.x=sx;
	t.y=sy;
	t.v=0;
	flag[sx][sy]=1;
	q.push(t);
	while(!q.empty())
	{
		t=q.top();
		q.pop();
		if(t.x==ex&&t.y==ey) return t.v;
		for(i=0;i<4;i++)
		{
			next=t;
			next.x+=dir[i][0];
			next.y+=dir[i][1];
			if(check(next.x,next.y))
			{
				next.v+=v[mp[next.x][next.y]];
				if(!flag[next.x][next.y])
				{
					q.push(next);
					flag[next.x][next.y]=1;
				}
			}
		}
	}
	return -1;
}
int main()
{
	int i,j,cas=1,p,s,t;
	while(~scanf("%d%d",&n,&m))
	{
		v.clear();
		scanf("%d%d%d",&p,&s,&t);
		v['#']=p;
		v['.']=s;
		v['T']=t;
		getchar();
		mem(mp,0);
		for(i=0;i<n;i++)
		{
			scanf("%s",mp[i]);
		}
		scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
		int ans=bfs();
		printf("Case %d: %d\n",cas++,ans);
	}
	return 0;
}

