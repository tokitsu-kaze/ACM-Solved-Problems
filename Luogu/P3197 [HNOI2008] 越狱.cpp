#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e4+10;
const int mod=100003;
ll qpow(ll a,ll b)
{
	ll res=1;
	while(b>0)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
int main()
{
	ll n,m;
	scanf("%lld%lld",&m,&n);
	printf("%lld\n",((qpow(m,n)-m*qpow(m-1,n-1))%mod+mod)%mod);
	return 0;
}
