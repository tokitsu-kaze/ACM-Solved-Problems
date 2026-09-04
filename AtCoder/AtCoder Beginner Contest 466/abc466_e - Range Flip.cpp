#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX],b[MAX];
ll dp[MAX][2][22];
int main()
{
	int n,k,i,j;
	ll ans;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
	memset(dp,-0x3f,sizeof dp);
	dp[1][1][0]=a[1];
	dp[1][0][1]=b[1];
	for(i=2;i<=n;i++)
	{
		for(j=0;j<=2*k;j++)
		{
			dp[i][0][j]=dp[i-1][0][j];
			dp[i][1][j]=dp[i-1][1][j];
			if(j>=1)
			{
				dp[i][0][j]=max(dp[i][0][j],dp[i-1][1][j-1]);
				dp[i][1][j]=max(dp[i][1][j],dp[i-1][0][j-1]);
			}
			dp[i][0][j]+=b[i];
			dp[i][1][j]+=a[i];
		}
	}
	ans=0;
	for(j=0;j<=2*k;j++) ans=max({ans,dp[n][0][j],dp[n][1][j]});
	printf("%lld\n",ans);
	return 0;
}
