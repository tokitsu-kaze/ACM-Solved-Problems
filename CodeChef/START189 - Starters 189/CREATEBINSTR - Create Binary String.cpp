#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
ll dp[105][105];
int main()
{
	int T,n,a,b,c,d,i,j;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		memset(dp,0,sizeof dp);
		scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);
		for(i=1;i<=n;i++)
		{
			for(j=0;j<=i;j++)
			{
				if(j<i) dp[i][j]=max(dp[i][j],dp[i-1][j]+b+j*c);
				if(j>0) dp[i][j]=max(dp[i][j],dp[i-1][j-1]+a+(i-j)*d);
			}
		}
		ans=0;
		for(j=0;j<=n;j++)
		{
			ans=max(ans,dp[n][j]);
//			printf("%d %lld\n",j,dp[n][j]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}

