#include <bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
int dis[22][22],dp[(1<<20)+5][22];
int main()
{
	int n,i,j,s,ans;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&dis[i][j]);
		}
	}
	memset(dp,0x3f,sizeof dp);
	dp[1][0]=0;
	for(s=0;s<(1<<n);s++)
	{
		for(i=0;i<n;i++)
		{
			if(!((s>>i)&1)) continue;
			for(j=0;j<n;j++)
			{
				if((s>>j)&1) continue;
				dp[s|(1<<j)][j]=min(dp[s|(1<<j)][j],dp[s][i]+dis[i][j]);
			}
		}
	}
	ans=INF;
	for(i=0;i<n;i++) ans=min(ans,dp[(1<<n)-1][i]+dis[i][0]);
	printf("%d\n",ans);
	return 0;
}
