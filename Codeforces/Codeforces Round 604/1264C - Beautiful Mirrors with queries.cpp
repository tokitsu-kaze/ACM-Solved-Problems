#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
const int mod=998244353;
struct Combinatorics
{
	vector<int> inv_e,fac,invfac;
	int last_n;
	Combinatorics(){last_n=0;init(1);}
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
		a=(a%mod+mod)%mod;
		while(b>0)
		{
			if(b&1) res=res*a%mod;
			a=a*a%mod;
			b>>=1;
		}
		return res;
	}
	ll inv(ll x)
	{
		assert(x>=1);
		if(x<=last_n) return inv_e[x];
		else return qpow(x%mod,mod-2);
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
ll p[MAX],mul[MAX],sum[MAX];
ll cal(int l,int r)
{
	return (sum[r-2]-sum[l-1]+mul[l-1]+mod)*comb.inv(mul[r-1])%mod;
}
int main()
{
	int n,q,i,x,l,r;
	ll ans;
	scanf("%d%d",&n,&q);
	mul[0]=1;
	sum[0]=0;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&p[i]);
		p[i]=p[i]*comb.inv(100)%mod;
		mul[i]=mul[i-1]*p[i]%mod;
		sum[i]=(sum[i-1]+mul[i])%mod;
	}
	set<int> s;
	s.insert(1);
	s.insert(n+1);
	ans=cal(1,n+1);
	while(q--)
	{
		scanf("%d",&x);
		l=*(--s.lower_bound(x));
		r=*s.upper_bound(x);
		if(s.count(x))
		{
			ans+=cal(l,r)-cal(l,x)-cal(x,r);
			s.erase(x);
		}
		else
		{
			ans-=cal(l,r)-cal(l,x)-cal(x,r);
			s.insert(x);
		}
		ans=(ans%mod+mod)%mod;
		printf("%lld\n",ans);
	}
	return 0;
}
/*
pi=pi/100
从 i-1 有 pi 概率走到 i；
从 i-1 有 1-pi 概率回到 1，再从 1 走到 i。
dp[i]=pi*(dp[i-1]+1)+(1-pi)*(dp[i-1]+1+dp[i])
-> dp[i]=dp[i-1]*pi+pi+dp[i-1]+1+dp[i]-dp[i-1]*pi-pi-dp[i]*pi
-> 0=dp[i-1]+1-dp[i]*pi
-> dp[i]=(1+dp[i-1])/pi

现在不是回到 1，回到上一个。
考虑把序列按照检查点分成若干段，在n+1处加个哨兵。
根据期望线性性，整段的期望等于每段期望之和。
考虑一段的期望怎么求，沿用easy版本的式子，
发现easy版本答案是 1/p1+1/p1p2+1/p1p2p3+...
接下来用前缀和与前缀积做一做就好了。
*/
