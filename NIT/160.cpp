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
const int MAX=1000000+10;
const ll mod=1e6;
int n,m,sx,sy,cnt,dis,ans;
char mp[1111][1111];
int flag[1111][1111];
int dir[4][2]={1,0,0,1,0,-1,-1,0};
struct node
{
	int x,y,v;
};
int check(int x,int y)
{
	if(x<0||y<0||x>=n||y>=m||mp[x][y]=='#') return 0;
	return 1;
}
void bfs()
{
	int i;
	node t,next;
	queue<node> q;
	mem(flag,0);
	dis=-1;
	ans=0;
	t.x=sx;
	t.y=sy;
	t.v=0;
	q.push(t);
	flag[t.x][t.y]=1;
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		if(mp[t.x][t.y]=='X')
		{
			if(dis==-1) dis=t.v;
			ans++;
			if(ans==cnt) break;
		}
		for(i=0;i<4;i++)
		{
			next=t;
			next.x+=dir[i][0];
			next.y+=dir[i][1];
			next.v++;
			if(check(next.x,next.y)&&!flag[next.x][next.y])
			{
				q.push(next);
				flag[next.x][next.y]=1;
			}
		}
	}
	if(dis==-1) puts("0 0");
	else printf("%d %d\n",dis,ans);
}
int main()
{
	int i,j;
	while(~scanf("%d%d",&n,&m))
	{
		mem(mp,0);
		getchar();
		cnt=0;
		for(i=0;i<n;i++)
		{
			scanf("%s",mp[i]);
			for(j=0;j<m;j++)
			{
				if(mp[i][j]=='X') cnt++;
			}
		}
		scanf("%d%d",&sx,&sy);
		sx--;
		sy--;
		bfs();
	}
	return 0;
}