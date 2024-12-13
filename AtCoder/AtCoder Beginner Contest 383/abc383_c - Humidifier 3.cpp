#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=3e5+10;
const int mod=998244353;
struct node{int x,y;};
char mp[1010][1010];
int n,m,d,dis[1010][1010];
int dir[4][2]={0,1,1,0,0,-1,-1,0};
void bfs()
{
	int i,j;
	queue<node> q;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			dis[i][j]=INF;
			if(mp[i][j]=='H')
			{
				q.push({i,j});
				dis[i][j]=0;
			}
		}
	}
	while(!q.empty())
	{
		node t=q.front();
		q.pop();
		for(i=0;i<4;i++)
		{
			node nex=t;
			nex.x+=dir[i][0];
			nex.y+=dir[i][1];
			if(nex.x<1 || nex.x>n || nex.y<1 || nex.y>m) continue;
			if(mp[nex.x][nex.y]=='#') continue;
			if(dis[nex.x][nex.y]>dis[t.x][t.y]+1)
			{
				dis[nex.x][nex.y]=dis[t.x][t.y]+1;
				q.push(nex);
			}
		}
	}
}
int main()
{
	int i,j,ans;
	scanf("%d%d%d",&n,&m,&d);
	for(i=1;i<=n;i++) scanf("%s",mp[i]+1);
	bfs();
	ans=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(dis[i][j]<=d) ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
