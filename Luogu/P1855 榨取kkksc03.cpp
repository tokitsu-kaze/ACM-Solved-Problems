#include <bits/stdc++.h>
using namespace std;
int dp[205][205];
int main()
{
	int i,j,k,n,M,T,m,t,ans;
	scanf("%d%d%d",&n,&M,&T);
	memset(dp,0,sizeof dp);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&m,&t);
		for(j=M;j>=m;j--)
		{
			for(k=T;k>=t;k--)
			{
				dp[j][k]=max(dp[j][k],dp[j-m][k-t]+1);
			}
		}
	}
	ans=0;
	for(i=0;i<=M;i++)
	{
		for(j=0;j<=T;j++)
		{
			ans=max(ans,dp[i][j]);
		}
	}
	printf("%d\n",ans);
	return 0;
}
