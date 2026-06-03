#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
const int mod=1e9+7;
int dp[2][MAX],sum[MAX];
int main()
{
	int n,k,i,j,x,f;
	scanf("%d%d",&n,&k);
	f=0;
	memset(dp[f],0,sizeof dp[f]);
	dp[f][0]=1;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		f^=1;
		memset(dp[f],0,sizeof dp[f]);
		sum[0]=dp[!f][0];
		for(j=1;j<=k;j++) sum[j]=(sum[j-1]+dp[!f][j])%mod;
		for(j=0;j<=x;j++) dp[f][j]=sum[j];
		for(j=x+1;j<=k;j++) dp[f][j]=(sum[j]-sum[j-x-1]+mod)%mod;
	}
	printf("%d\n",dp[f][k]);
	return 0;
}
