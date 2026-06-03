#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
ll dp[MAX];
int main()
{
	int n,W,i,j,w,v;
	ll ans;
	scanf("%d%d",&n,&W);
	memset(dp,0,sizeof dp);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&w,&v);
		for(j=W;j>=w;j--) dp[j]=max(dp[j],dp[j-w]+v);
	}
	ans=0;
	for(j=0;j<=W;j++) ans=max(ans,dp[j]);
	printf("%lld\n",ans);
	return 0;
}
