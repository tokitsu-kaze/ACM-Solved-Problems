#include <bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
char mp[105][105];
int flag[105][105],n,m;
void dfs(int x,int y)
{
	if(x<1||y<1||x>n||y>m) return;
	if(mp[x][y]=='0'||flag[x][y]) return;
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
	memset(flag,0,sizeof flag);
	ans=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(mp[i][j]=='0'||flag[i][j]) continue;
			ans++;
			dfs(i,j);
		}
	}
	printf("%d\n",ans);
	return 0;
}
