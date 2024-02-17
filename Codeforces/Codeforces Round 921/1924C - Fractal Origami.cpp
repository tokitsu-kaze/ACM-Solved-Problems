#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=999999893;
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
	int t,n;
	ll tmp,fz,fm;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		if(n&1)
		{
			tmp=(qpow(2,(n+1)/2)-2+mod)%mod;
			fz=tmp*(-2+mod)%mod;
			fm=inv(((tmp*tmp%mod-qpow(2,n+2))%mod+mod)%mod);
			printf("%lld\n",fz*fm%mod);
		}
		else
		{
			tmp=(qpow(2,(n+2)/2)-2+mod)%mod;
			fz=tmp*(-2+mod)%mod;
			fm=inv(((tmp*tmp%mod-qpow(2,n+1))%mod+mod)%mod);
			printf("%lld\n",fz*fm%mod);
		}
	}
	return 0;
}
/*
t=sqrt(2)
fz=t^(n+2)+t^(n+1)-2t-2
fm=t^(n+2)+t^(n+1)-2
*/
