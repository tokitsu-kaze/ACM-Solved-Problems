#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
const int mod=998244353;
int main()
{
	ll n,m,s,i,ans;
	scanf("%lld%lld",&n,&m);
	ans=0;
	for(i=0;i<61;i++)
	{
		if(!((m>>i)&1)) continue;
		s=1LL<<(i+1);
		ans=(ans+n/s*(1LL<<i)+max(0LL,n%s-(1LL<<i)+1))%mod;
	}
	printf("%lld\n",ans);
	return 0;
}

