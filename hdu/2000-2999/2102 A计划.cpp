////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-11 21:54:31
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2102
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1568KB
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
#define MAX 200+10
using namespace std;
//typedef __int64 ll;
typedef long long ll;
char mp[12][12][2];
int flag[12][12][2],flag1;
int n,m,k,dir[4][2]={0,1,1,0,0,-1,-1,0};
struct node
{
	int x,y,z,t;
};
int check(int x,int y,int z)
{
	if(x<0||x>=n||y<0||y>=m||flag[x][y][z]||mp[x][y][z]=='*') return 0;
	return 1;
}
void bfs()
{
	int i;
	node t,next;
	queue<node> q;
	t.x=0;
	t.y=0;
	t.z=0;
	t.t=0;
	flag[0][0][0]=1;
	q.push(t);
	flag1=0;
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		if(mp[t.x][t.y][t.z]=='P')
		{
			flag1=1;
			if(t.t<=k) puts("YES");
			else puts("NO");
			return;
		}
		if(t.t>k)
		{
			flag1=1;
			puts("NO");
			return;
		}
	//	cout<<t.t<<endl;
		for(i=0;i<4;i++)
		{
			next.x=t.x+dir[i][0];
			next.y=t.y+dir[i][1];
			next.z=t.z;
			next.t=t.t+1;
			if(check(next.x,next.y,next.z))
			{
				if(mp[next.x][next.y][next.z]=='#')
				{
					if(next.z==1) next.z=0;
					else if(next.z==0) next.z=1;
				}
				q.push(next);
				flag[next.x][next.y][next.z]=1;
			}
		}
	}
	if(!flag1) puts("NO");
}
int main()
{
	int i,j,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&k);
		mem(mp,0);
		mem(flag,0);
		for(i=0;i<n;i++)
		{
			getchar();
			for(j=0;j<m;j++)
			{
				scanf("%c",&mp[i][j][0]);
			}
		}
		getchar();
		for(i=0;i<n;i++)
		{
			getchar();
			for(j=0;j<m;j++)
			{
				scanf("%c",&mp[i][j][1]);
				if(mp[i][j][0]=='#'&&mp[i][j][1]=='*') mp[i][j][0]='*';
				if(mp[i][j][1]=='#'&&mp[i][j][0]=='*') mp[i][j][1]='*';
				if(mp[i][j][0]=='#'&&mp[i][j][1]=='#') mp[i][j][0]=mp[i][j][1]='*';
			}
		}
		bfs();
	}
    return 0;
}