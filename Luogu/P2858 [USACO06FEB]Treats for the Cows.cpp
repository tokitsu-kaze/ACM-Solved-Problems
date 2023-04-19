#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[2020][2020],a[2020];
int main()
{
	int n,i,len,l,r;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%lld",&a[i]);
	memset(dp,0,sizeof dp);
	for(i=1;i<=n;i++) dp[i][i]=n*a[i];
	for(len=2;len<=n;len++)
	{
		for(l=1;l+len-1<=n;l++)
		{
			r=l+len-1;
			dp[l][r]=max(dp[l+1][r]+a[l]*(n-len+1),dp[l][r-1]+a[r]*(n-len+1));
		}
	}
	printf("%lld\n",dp[1][n]);
	return 0;
}
