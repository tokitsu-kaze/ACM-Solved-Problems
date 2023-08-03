#include<bits/stdc++.h>
using namespace std;
int dp[105][105];
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
			if(!x) continue;
			dp[i][j]=min({dp[i-1][j],
						  dp[i][j-1],
						  dp[i-1][j-1]})+1;
			ans=max(ans,dp[i][j]);
		}
	}
	printf("%d\n",ans);
	return 0;
}
