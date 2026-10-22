#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5000+10;
const int mod=998244353;
struct Combinatorics
{
	vector<int> inv_e,fac,invfac;
	int last_n;
	Combinatorics(){last_n=0;}
	void init(int n)
	{
		if(n<=last_n) return;
		inv_e.resize(n+1);
		fac.resize(n+1);
		invfac.resize(n+1);
		if(last_n==0)
		{
			inv_e[1]=1;
			fac[0]=fac[1]=1;
			invfac[0]=invfac[1]=1;
			last_n=1;
		}
		for(int i=last_n+1;i<=n;i++)
		{
			inv_e[i]=1LL*(mod-mod/i)*inv_e[mod%i]%mod;
			fac[i]=1LL*fac[i-1]*i%mod;
			invfac[i]=1LL*invfac[i-1]*inv_e[i]%mod;
		}
		last_n=n;
	}
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
	ll inv(int x)
	{
		if(x<=last_n) return inv_e[x];
		else return qpow(x,mod-2);
	}
	ll C(int n,int m)
	{
		if(m>n||m<0||n<0) return 0;
		return 1LL*fac[n]*invfac[m]%mod*invfac[n-m]%mod;
	}
	ll A(int n,int m)
	{
		if(m>n||m<0||n<0) return 0;
		return 1LL*fac[n]*invfac[n-m]%mod;
	}
}comb;
int main()
{
	ll n,ans;
	scanf("%lld",&n);
	ans=comb.qpow(4,n);
	ans-=3*comb.qpow(3,n);
	ans+=3*comb.qpow(2,n);
	ans-=1;
	ans=(ans%mod+mod)%mod;
	printf("%lld\n",ans);
	return 0;
}
/*
01, 10, 11 都至少要出现一次。
*/
