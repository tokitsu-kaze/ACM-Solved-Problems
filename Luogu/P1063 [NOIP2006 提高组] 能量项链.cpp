#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[205][205],a[205];
int main()
{
	int n,i,l,r,len;
	ll ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(i=n+1;i<=2*n;i++) a[i]=a[i-n];
	for(i=1;i<=2*n;i++) dp[i][i]=0;
	for(len=2;len<=n+1;len++)
	{
		for(l=1;l+len-1<=2*n;l++)
		{
			r=l+len-1;
			for(i=l+1;i<=r-1;i++)
			{
				dp[l][r]=max(dp[l][r],dp[l][i]+dp[i][r]+a[l]*a[i]*a[r]);
			}
		}
	}
	ans=0;
	for(i=1;i<=n;i++) ans=max(ans,dp[i][i+n]);
	printf("%lld\n",ans);
	return 0;
}

