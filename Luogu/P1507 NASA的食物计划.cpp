#include <bits/stdc++.h>
using namespace std;
int dp[505][505];
int main()
{
	int i,j,k,n,H,T,h,t,ans;
	scanf("%d%d",&H,&T);
	scanf("%d",&n);
	memset(dp,0,sizeof dp);
	while(n--)
	{
		scanf("%d%d%d",&h,&t,&k);
		for(i=H;i>=h;i--)
		{
			for(j=T;j>=t;j--)
			{
				dp[i][j]=max(dp[i][j],dp[i-h][j-t]+k);
			}
		}
	}
	ans=0;
	for(i=0;i<=H;i++)
	{
		for(j=0;j<=T;j++)
		{
			ans=max(ans,dp[i][j]);
		}
	}
	printf("%d\n",ans);
	return 0;
}
