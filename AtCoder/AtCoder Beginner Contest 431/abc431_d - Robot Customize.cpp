#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=500*500*2+10;
int w[505],h[505],b[505];
ll dp[2][MAX];
const int delta=500*500;
int main()
{
	int n,i,j,f;
	ll ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d%d%d",&w[i],&h[i],&b[i]);
	f=0;
	memset(dp[f],-0x3f,sizeof dp[f]);
	dp[f][delta]=0;
	for(i=1;i<=n;i++)
	{
		f^=1;
		memset(dp[f],-0x3f,sizeof dp[f]);
		for(j=0;j<MAX;j++)
		{
			if(j-w[i]>=0) dp[f][j]=max(dp[f][j],dp[!f][j-w[i]]+b[i]);
			if(j+w[i]<MAX) dp[f][j]=max(dp[f][j],dp[!f][j+w[i]]+h[i]);
		}
	}
	ans=-LLINF;
	for(i=delta;i<MAX;i++) ans=max(ans,dp[f][i]);
	printf("%lld\n",ans);
	return 0;
}
