#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=200+10;
int a[MAX],b[MAX];
ll dp[MAX][MAX];
int main()
{
	int n,m,k,i,j,l;
	ll ans;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
	memset(dp,0,sizeof dp);
	ans=0;
	for(i=1;i<=n;i++)
	{
		dp[i][b[i]]=a[i];
		for(j=i-1;i-j<=k && j>=1;j--)
		{
			for(l=m;l>=b[i];l--)
			{
				dp[i][l]=max(dp[i][l],dp[j][l-b[i]]+a[i]);
			}
		}
		for(l=0;l<=m;l++) ans=max(ans,dp[i][l]);
	}
	printf("%lld\n",ans);
	return 0;
}
