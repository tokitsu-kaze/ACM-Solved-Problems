#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int m,dp[1010][1010],a,b;
int dfs(int x,int y)
{
	if(x==0||y==0) return 1;
	if(dp[x][y]!=-1) return dp[x][y];
	dp[x][y]=0;
	dp[x][y]|=dfs(y,(b*x+a*y)%m);
	return dp[x][y];
}
int main()
{
	int x,y,ans;
	memset(dp,-1,sizeof dp);
	scanf("%d%d%d",&m,&a,&b);
	ans=0;
	for(x=0;x<=m-1;x++)
	{
		for(y=0;y<=m-1;y++)
		{
			ans++;
			if(dfs(x,y)) ans--;
		}
	}
	printf("%d\n",ans);
	return 0;
}
