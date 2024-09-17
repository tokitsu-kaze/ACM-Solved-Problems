#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=3e5+10;
int a[MAX];
ll dp[MAX][2];
int main()
{
	int n,i;
	ll ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	memset(dp[1],0x3f,sizeof dp[1]);
	dp[1][0]=a[n];
	for(i=2;i<n;i++)
	{
		dp[i][0]=min(dp[i-1][1],dp[i-1][0]+a[i]);
		dp[i][1]=min(dp[i-1][0],dp[i-1][1])+a[i];
	}
	ans=min(dp[n-1][0],dp[n-1][1]);
	memset(dp[1],0x3f,sizeof dp[1]);
	dp[1][1]=a[1];
	for(i=2;i<=n;i++)
	{
		dp[i][0]=min(dp[i-1][1],dp[i-1][0]+a[i]);
		dp[i][1]=min(dp[i-1][0],dp[i-1][1])+a[i];
	}
	ans=min({ans,dp[n][0],dp[n][1]});
	printf("%lld\n",ans);
	return 0;
}

