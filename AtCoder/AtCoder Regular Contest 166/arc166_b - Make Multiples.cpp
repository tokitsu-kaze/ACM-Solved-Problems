#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
ll a[MAX],dp[MAX][1<<3];
int main()
{
	int n,i,s,j;
	ll x[3],lcm;
	scanf("%d%lld%lld%lld",&n,&x[0],&x[1],&x[2]);
	for(i=1;i<=n;i++) scanf("%lld",&a[i]);
	memset(dp,0x3f,sizeof dp);
	dp[0][0]=0;
	for(i=1;i<=n;i++)
	{
		for(s=1;s<(1<<3);s++)
		{
			lcm=0;
			for(j=0;j<3;j++)
			{
				if(!((s>>j)&1)) continue;
				if(lcm==0) lcm=x[j];
				else lcm=lcm/__gcd(lcm,x[j])*x[j];
			}
			for(j=0;j<(1<<3);j++)
			{
				dp[i][j]=min(dp[i][j],dp[i-1][j]);
				if((j|s)==j) continue;
				dp[i][j|s]=min(dp[i][j|s],dp[i-1][j]+(a[i]+lcm-1)/lcm*lcm-a[i]);
			}
		}
	}
	printf("%lld\n",dp[n][(1<<3)-1]);
	return 0;
}
