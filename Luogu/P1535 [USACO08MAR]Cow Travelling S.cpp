#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[105][105][17];
char mp[105][105];
int n,m,t,sx,sy,tx,ty;
ll dfs(int x,int y,int t)
{
	if(dp[x][y][t]!=-1) return dp[x][y][t];
	if(x==tx&&y==ty&&t==0) return 1;
	if(t==0) return 0;
	dp[x][y][t]=0;
	if(x+1<=n && mp[x+1][y]!='*') dp[x][y][t]+=dfs(x+1,y,t-1);
	if(x-1>=1 && mp[x-1][y]!='*') dp[x][y][t]+=dfs(x-1,y,t-1);
	if(y+1<=m && mp[x][y+1]!='*') dp[x][y][t]+=dfs(x,y+1,t-1);
	if(y-1>=1 && mp[x][y-1]!='*') dp[x][y][t]+=dfs(x,y-1,t-1);
	return dp[x][y][t];
}
int main()
{
	int i,j;
	scanf("%d%d%d",&n,&m,&t);
	for(i=1;i<=n;i++) scanf("%s",mp[i]+1);
	scanf("%d%d%d%d",&sx,&sy,&tx,&ty);
	memset(dp,-1,sizeof dp);
	printf("%lld\n",dfs(sx,sy,t));
}
