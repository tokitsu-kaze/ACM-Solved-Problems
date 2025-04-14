#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=800+10;
ll dp[MAX][MAX];
int c[MAX],x[MAX];
int main()
{
	int n,i,l,r,len;
	ll ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&c[i]);
	for(i=1;i<=n;i++) scanf("%d",&x[i]);
	for(i=n+1;i<=2*n;i++) c[i]=c[i-n];
	memset(dp,0x3f,sizeof dp);
	for(i=1;i<=2*n;i++)
	{
		dp[i][i]=1+x[c[i]];
		dp[i][i-1]=0;
	}
	for(len=2;len<=n;len++)
	{
		for(l=1;l+len-1<=2*n;l++)
		{
			r=l+len-1;
			for(i=l+1;i<=r;i++)
			{
				if(c[i]==c[l]) dp[l][r]=min(dp[l][r],dp[i][r]+dp[l+1][i-1]+(i-l));
			}
			for(i=r-1;i>=l;i--)
			{
				if(c[i]==c[r]) dp[l][r]=min(dp[l][r],dp[l][i]+dp[i+1][r-1]+(r-i));
			}
			for(i=l+1;i<=r;i++)
			{
				dp[l][r]=min(dp[l][r],dp[l][i-1]+dp[i][r]);
			}
		}
	}
	ans=LLINF;
	for(i=1;i<=n;i++) ans=min(ans,dp[i][i+n-1]);
	printf("%lld\n",ans);
	return 0;
}
