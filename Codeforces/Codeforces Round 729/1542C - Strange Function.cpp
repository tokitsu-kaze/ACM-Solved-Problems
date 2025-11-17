#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
const int mod=1e9+7;
int main()
{
	int T;
	ll n,ans,mul,now,i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld",&n);
		ans=0;
		now=n;
		mul=1;
		for(i=2;now>0;i++)
		{
			if(__gcd(mul,i)==i) continue;
			mul=mul/__gcd(mul,i)*i;
			ans+=i*((now-n/mul)%mod);
			ans%=mod;
			now-=now-n/mul;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
