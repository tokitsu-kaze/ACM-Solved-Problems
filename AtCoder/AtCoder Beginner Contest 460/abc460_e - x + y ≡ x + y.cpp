#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
const int mod=998244353;
int main()
{
	int T,m;
	ll n,ans,pre,cnt;
	ull sd;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%d",&n,&m);
		pre=0;
		sd=9;
		ans=0;
		while(1)
		{
			cnt=((((__int128_t) n)*__gcd(sd,1ULL*m)/m)%mod);
			ans=(ans+((min(sd,1ULL*n)-pre)%mod)*cnt)%mod;
			if(sd>=n) break;
			pre=sd;
			sd=sd*10+9;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
