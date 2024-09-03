#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e5+10;
ll dp[MAX][2];
int main()
{
	int n,i;
	ll x;
	scanf("%d",&n);
	memset(dp[0],-0x3f,sizeof dp[0]);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&x);
		dp[i][1]=max({dp[i-1][0]+x,dp[i-1][1],x});
		dp[i][0]=max(dp[i-1][0],dp[i-1][1]+2*x);
	}
	printf("%lld\n",max(dp[n][0],dp[n][1]));
	return 0;
}
