#include<bits/stdc++.h>
using namespace std;
int dp[1505][1505][2];
int main()
{
	int n,m,i,j,x,ans;
	scanf("%d%d",&n,&m);
	memset(dp,0,sizeof dp);
	ans=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%d",&x);
			dp[i][j][x]=min({dp[i-1][j][x^1],
						  dp[i][j-1][x^1],
						  dp[i-1][j-1][x]})+1;
			ans=max(ans,dp[i][j][x]);
		}
	}
	printf("%d\n",ans);
	return 0;
}
