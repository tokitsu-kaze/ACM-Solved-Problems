#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
int n,m,vis[22][22];
ll ans;
ll mp[22][22];
void dfs(int x,int y,ll now)
{
	int nx,ny;
	if(x==n && y==m)
	{
		ans=max(ans,now);
		return;
	}
	if(y==m)
	{
		nx=x+1;
		ny=1;
	}
	else
	{
		nx=x;
		ny=y+1;
	}
	dfs(nx,ny,now);
	if(vis[x][y]) return;
	if(x+1<=n && !vis[x+1][y])
	{
		vis[x][y]=1;
		vis[x+1][y]=1;
		dfs(nx,ny,now^mp[x][y]^mp[x+1][y]);
		vis[x][y]=vis[x+1][y]=0;
	}
	if(y+1<=m && !vis[x][y+1])
	{
		vis[x][y]=1;
		vis[x][y+1]=1;
		dfs(nx,ny,now^mp[x][y]^mp[x][y+1]);
		vis[x][y]=vis[x][y+1]=0;
	}
}
int main()
{
	int i,j;
	ll tmp;
	scanf("%d%d",&n,&m);
	tmp=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%lld",&mp[i][j]);
			tmp^=mp[i][j];
		}
	}
	ans=0;
	dfs(1,1,tmp);
	printf("%lld\n",ans);
	return 0;
}
