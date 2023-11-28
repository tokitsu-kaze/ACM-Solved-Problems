#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005],mp[1005][1005];
int main()
{
	int n,m,i,j,x,y,ans;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			mp[i][j]=1;
		}
	}
	while(m--)
	{
		scanf("%d%d",&x,&y);
		mp[x][y]=0;
	}
	memset(dp,0,sizeof dp);
	ans=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(!mp[i][j]) continue;
			dp[i][j]=min({dp[i-1][j],
						  dp[i][j-1],
						  dp[i-1][j-1]})+1;
			ans=max(ans,dp[i][j]);
		}
	}
	printf("%d\n",ans);
	return 0;
}
