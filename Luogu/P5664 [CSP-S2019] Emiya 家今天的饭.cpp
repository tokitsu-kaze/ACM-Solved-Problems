#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
const int MAX=2000+10;
int a[105][MAX],sum[MAX],dp[105][205];
const int delta=101;
int main()
{
	int n,m,i,j,k;
	ll ans;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		sum[i]=0;
		for(j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
			sum[i]=(sum[i]+a[i][j])%mod;
		}
	}
	memset(dp,0,sizeof dp);
	dp[0][0]=1;
	for(i=1;i<=n;i++)
	{
		dp[i][0]=dp[i-1][0];
		for(k=1;k<=i;k++)
		{
			dp[i][k]=(dp[i-1][k]+1LL*dp[i-1][k-1]*sum[i])%mod;
		}
	}
	ans=0;
	for(i=1;i<=n;i++) ans=(ans+dp[n][i])%mod;
	for(j=1;j<=m;j++)
	{
		memset(dp,0,sizeof dp);
		dp[0][delta]=1;
		for(i=1;i<=n;i++)
		{
			for(k=-i;k<=i;k++)
			{
				dp[i][k+delta]=(dp[i-1][k+delta]
						+1LL*dp[i-1][k-1+delta]*a[i][j]
						+1LL*dp[i-1][k+1+delta]*(sum[i]-a[i][j]+mod))%mod;
			}
		}
		for(i=1;i<=n;i++) ans=(ans-dp[n][i+delta]+mod)%mod;
	}
	printf("%lld\n",ans);
	return 0;
}

