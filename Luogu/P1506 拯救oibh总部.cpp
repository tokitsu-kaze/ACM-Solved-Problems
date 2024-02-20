#include <bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
char mp[505][505];
int flag[505][505],n,m;
void dfs(int x,int y)
{
	if(x<0||y<0||x>n+1||y>m+1) return;
	if(mp[x][y]=='*'||flag[x][y]) return;
	flag[x][y]=1;
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
	for(i=0;i<=n+1;i++) mp[i][0]=mp[i][m+1]='0';
	for(j=0;j<=m+1;j++) mp[0][j]=mp[n+1][j]='0';
	memset(flag,0,sizeof flag);
	dfs(0,0);
	ans=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(mp[i][j]=='0'&&!flag[i][j]) ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
