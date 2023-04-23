#include <bits/stdc++.h>
using namespace std;
int dp[800005];
int main()
{
	const int delta=400000;
	int n,i,j,s,f,ans;
	scanf("%d",&n);
	memset(dp,-0x3f,sizeof dp);
	dp[delta]=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&s,&f);
		if(s<0)
		{
			for(j=0;j<=2*delta;j++)
			{
				if(j-s<0 || j-s>2*delta) continue;
				dp[j]=max(dp[j],dp[j-s]+f);
			}
		}
		else
		{
			for(j=2*delta;j>=0;j--)
			{
				if(j-s<0 || j-s>2*delta) continue;
				dp[j]=max(dp[j],dp[j-s]+f);
			}
		}
	}
	ans=0;
	for(i=delta;i<=2*delta;i++)
	{
	//	printf("%d %d\n",i,dp[i]);
		if(dp[i]>=0) ans=max(ans,i-delta+dp[i]);
	}
	printf("%d\n",ans);
	return 0;
}
