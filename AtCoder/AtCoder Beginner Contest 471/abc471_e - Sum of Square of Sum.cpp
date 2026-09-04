#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
const int mod=998244353;
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
int fac[MAX],invfac[MAX];
void init_comb(int n)
{
	assert(n<MAX);
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%mod;
	invfac[n]=inv(fac[n]);
	for(int i=n-1;~i;i--) invfac[i]=1ll*invfac[i+1]*(i+1)%mod;
}
ll C(int n,int m)
{
	if(m>n||m<0||n<0) return 0;
	return 1ll*fac[n]*invfac[m]%mod*invfac[n-m]%mod;
}
ll A(int n,int m)
{
	if(m>n||m<0||n<0) return 0;
	return 1ll*fac[n]*invfac[n-m]%mod;
}
int main()
{
	int n,k,i,x;
	ll s,s2;
	scanf("%d%d",&n,&k);
	init_comb(n);
	s=s2=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		s=(s+x)%mod;
		s2=(s2+1LL*x*x)%mod;
	}
	if(k==1)
	{
		printf("%lld\n",s2);
		return 0;
	}
	printf("%lld\n",(C(n-1,k-1)*s2+C(n-2,k-2)*(s*s%mod-s2+mod))%mod);
	return 0;
}
