#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fll;
ll a[2020],dp[2020][2020];
int main()
{
	int n,k;
	while(~scanf("%d%d",&n,&k))
	{
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		sort(a+1,a+1+n);
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=k;j++)
			{
				dp[i][j]=LLINF;
			}
		}
		dp[0][0]=dp[1][0]=0;
		for(int i=2;i<=n;i++)
		{
			for(int j=0;j<=min(i/2,k);j++)
			{
				dp[i][j]=min(dp[i-1][j],dp[i-2][j-1]+(a[i]-a[i-1])*(a[i]-a[i-1]));
			}
		}
		printf("%lld\n",dp[n][k]);
	}
	return 0;
}
