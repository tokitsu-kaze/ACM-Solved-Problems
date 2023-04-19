#include <bits/stdc++.h>
using namespace std;
int dp[1010][1010],a[1010];
int main()
{
	int n,i,j,ans;
	memset(dp,0,sizeof dp);
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=i-1;j++)
		{
			dp[i][j]=max(dp[i-1][j-1],dp[i-1][j]+(a[i]==i-j));
		}
	}
	ans=0;
	for(i=0;i<=n-1;i++) ans=max(ans,dp[n][i]);
	printf("%d\n",ans);
	return 0;
}
