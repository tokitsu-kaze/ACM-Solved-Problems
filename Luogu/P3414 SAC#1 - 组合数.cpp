#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int mod=6662333;
const int MAX=2e5+10;
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
	ll n;
	scanf("%lld",&n);
	printf("%lld\n",qpow(2,n-1));
	return 0;
}
