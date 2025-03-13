#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=800+10;
ll dp[MAX][MAX];
int a[MAX];
int main()
{
	int T,n,i,l,r,len;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=n+1;i<2*n;i++) a[i]=a[i-n];
		for(i=1;i<2*n;i++)
		{
			dp[i][i-1]=dp[i][i]=dp[i][i+1]=0;
			dp[i][i+2]=1LL*a[i]*a[i+1]*a[i+2];
		}
		for(len=4;len<=n;len++)
		{
			for(l=1;l+len-1<2*n;l++)
			{
				r=l+len-1;
				dp[l][r]=max(dp[l+1][r],dp[l][r-1]);
				for(i=l;i<=r;i++) dp[l][r]=max(dp[l][r],dp[l][i]+dp[i+1][r]);
				for(i=l+1;i<=r-1;i++)
				{
					dp[l][r]=max(dp[l][r],dp[l+1][i-1]
										+dp[i+1][r-1]
										+1LL*a[l]*a[i]*a[r]);
				}
			}
		}
		ans=0;
		for(i=n;i<2*n;i++) ans=max(ans,dp[i-n+1][i]);
		printf("%lld\n",ans);
	}
	return 0;
}
/*
2
6
2 2 2 5 5 5
9
2 2 2 5 5 5 1 1 1
*/
