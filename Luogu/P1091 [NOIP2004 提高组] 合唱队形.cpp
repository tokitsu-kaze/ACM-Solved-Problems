#include <bits/stdc++.h>
using namespace std;
int dp[105][2],a[105];
int main()
{
	int n,i,j,ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	memset(dp,0,sizeof dp);
	ans=0;
	for(i=1;i<=n;i++)
	{
		dp[i][0]=1;
		for(j=1;j<i;j++)
		{
			if(a[j]<a[i]) dp[i][0]=max(dp[i][0],dp[j][0]+1);
			else if(a[j]>a[i]) dp[i][1]=max(dp[i][1],dp[j][1]+1);
		}
		dp[i][1]=max(dp[i][1],dp[i][0]);
		ans=max(ans,dp[i][1]);
	}
	printf("%d\n",n-ans);
	return 0;
}
