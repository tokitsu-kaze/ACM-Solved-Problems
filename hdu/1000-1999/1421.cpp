#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fll;
ll a[2020],dp[2020][2020];
int main()
{
	int n,k,i,j;
	while(~scanf("%d%d",&n,&k))
	{
		for(i=1;i<=n;i++) scanf("%lld",&a[i]);
		for(i=2;i<=n;i++)
		{
			for(j=i-1;j;j--)
			{
				if(a[j+1]<a[j]) swap(a[j+1],a[j]);
			}
		}
		for(i=0;i<=n;i++)
		{
			for(j=0;j<=k;j++)
			{
				dp[i][j]=LLINF;
			}
		}
		dp[0][0]=dp[1][0]=0;
		for(i=2;i<=n;i++)
		{
			for(j=0;j<=min(i/2,k);j++)
			{
				dp[i][j]=min(dp[i-1][j],dp[i-2][j-1]+(a[i]-a[i-1])*(a[i]-a[i-1]));
			}
		}
		printf("%lld\n",dp[n][k]);
	}
	return 0;
}
