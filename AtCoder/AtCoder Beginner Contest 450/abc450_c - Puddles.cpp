#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e3+10;
char mp[MAX][MAX];
int vis[MAX][MAX],n,m;
void dfs(int x,int y)
{
	if(x<1||x>n||y<1||y>m) return;
	if(vis[x][y]) return;
	if(mp[x][y]=='#') return;
	vis[x][y]=1;
	dfs(x+1,y);
	dfs(x-1,y);
	dfs(x,y+1);
	dfs(x,y-1);
}
int main()
{
	int i,j,ans;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%s",mp[i]+1);
	memset(vis,0,sizeof vis);
	ans=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(vis[i][j]) continue;
			if(mp[i][j]=='#') continue;
			dfs(i,j);
			ans++;
		}
	}
	memset(vis,0,sizeof vis);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(vis[i][j]) continue;
			if(mp[i][j]=='#') continue;
			if(i==1 || i==n || j==1 || j==m)
			{
				dfs(i,j);
				ans--;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
