#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
const int mod=1e9+7;
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
ll inv(ll x){return qpow(x,mod-2);}
int main()
{
	int T,n,i,x;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		ans=1LL*(n-1)*n%mod*(n+1)%mod*inv(3)%mod;
		ans=(ans+1LL*n*(n+1)%mod*(2*n+1)%mod*inv(6))%mod;
		ans=ans*2022%mod;
		printf("%lld\n",ans);
	}
	return 0;
}
/*
1 2 3
2 4 6
3 6 9

1*1
1*2
2*2
2*3
3*3
*/
