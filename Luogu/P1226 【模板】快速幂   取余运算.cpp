#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll qpow(ll a,ll b,ll mod)
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
	ll a,b,mod;
	scanf("%lld%lld%lld",&a,&b,&mod);
	printf("%lld^%lld mod %lld=%lld\n",a,b,mod,qpow(a,b,mod));
	return 0;
}
