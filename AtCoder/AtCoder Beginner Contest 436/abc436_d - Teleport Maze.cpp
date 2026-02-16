#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1000+10;
struct node{int x,y;};
char mp[MAX][MAX];
vector<node> pos[26];
int n,m,dir[4][2]={0,1,1,0,0,-1,-1,0};
int dis[MAX][MAX],vis[26];
int bfs(int x,int y)
{
	int i;
	node t,nex;
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	queue<node> q;
	dis[x][y]=0;
	q.push({x,y});
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		if(t.x==n && t.y==m) return dis[t.x][t.y];
		for(i=0;i<4;i++)
		{
			nex=t;
			nex.x+=dir[i][0];
			nex.y+=dir[i][1];
			if(nex.x<1||nex.x>n||nex.y<1||nex.y>m) continue;
			if(mp[nex.x][nex.y]=='#') continue;
			if(dis[nex.x][nex.y]>dis[t.x][t.y]+1)
			{
				dis[nex.x][nex.y]=dis[t.x][t.y]+1;
				q.push(nex);
			}
		}
		if(mp[t.x][t.y]>='a' && mp[t.x][t.y]<='z')
		{
			if(vis[mp[t.x][t.y]-'a']) continue;
			vis[mp[t.x][t.y]-'a']=1;
			for(auto &nex:pos[mp[t.x][t.y]-'a'])
			{
				if(dis[nex.x][nex.y]>dis[t.x][t.y]+1)
				{
					dis[nex.x][nex.y]=dis[t.x][t.y]+1;
					q.push(nex);
				}
			}
		}
	}
	return -1;
}
int main()
{
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=0;i<26;i++) pos[i].clear();
	for(i=1;i<=n;i++)
	{
		scanf("%s",mp[i]+1);
		for(j=1;j<=m;j++)
		{
			if(mp[i][j]>='a' && mp[i][j]<='z')
			{
				pos[mp[i][j]-'a'].push_back({i,j});
			}
		}
	}
	printf("%d\n",bfs(1,1));
	return 0;
}
