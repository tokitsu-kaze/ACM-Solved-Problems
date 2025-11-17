#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct node{int x,y,f,v;};
char mp[505][505];
int dis[505][505][2],n,m;
int dir[4][2]={0,1,1,0,0,-1,-1,0};
int bfs(int sx,int sy)
{
	int i;
	memset(dis,0x3f,sizeof dis);
	queue<node> q;
	q.push({sx,sy,0,0});
	dis[sx][sy][0]=0;
	while(!q.empty())
	{
		node t=q.front();
		q.pop();
		if(mp[t.x][t.y]=='G') return t.v;
		for(i=0;i<4;i++)
		{
			node nex=t;
			nex.x+=dir[i][0];
			nex.y+=dir[i][1];
			nex.v++;
			if(nex.x<1||nex.x>n||nex.y<1||nex.y>m) continue;
			if(mp[nex.x][nex.y]=='#') continue;
			if(t.f==0)
			{
				if(mp[nex.x][nex.y]=='x') continue;
			}
			else
			{
				if(mp[nex.x][nex.y]=='o') continue;
			}
			if(mp[nex.x][nex.y]=='?') nex.f^=1;
			if(dis[nex.x][nex.y][nex.f]>nex.v)
			{
				dis[nex.x][nex.y][nex.f]=nex.v;
				q.push(nex);
			}
		}
	}
	return -1;
}
int main()
{
	int i,j,sx,sy;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%s",mp[i]+1);
		for(j=1;j<=m;j++)
		{
			if(mp[i][j]=='S')
			{
				sx=i;
				sy=j;
			}
		}
	}
	printf("%d\n",bfs(sx,sy));
	return 0;
}
