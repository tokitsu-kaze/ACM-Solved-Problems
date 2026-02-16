#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
const int mod=998244353;
int dp[MAX],a[505];
int main()
{
	int n,i,j,s;
	ll x;
	scanf("%d",&n);
	s=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		s+=a[i];
	}
	if(s&1)
	{
		puts("0");
		return 0;
	}
	memset(dp,0,sizeof dp);
	dp[0]=1;
	for(i=1;i<=n;i++)
	{
		for(j=s;j>=a[i];j--) dp[j]=(dp[j]+dp[j-a[i]])%mod;
	}
	x=dp[s/2];
	printf("%lld\n",(x*x%mod-2*x%mod+mod)%mod);
	return 0;
}
