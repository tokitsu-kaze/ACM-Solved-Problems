#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
const int mod=998244353;
int main()
{
	ll n,x,l,r,ans,inv2;
	inv2=(mod+1)/2;
	scanf("%lld",&n);
	x=n%mod;
	ans=(1+x)*x%mod*inv2%mod;
	for(l=1;l<=n;l=r+1)
	{
		r=n/(n/l);
		ans-=((r-l+1)%mod)*((n/l)%mod);
		ans%=mod;
	}
	if(ans<0) ans+=mod;
	printf("%lld\n",ans);
	return 0;
}
