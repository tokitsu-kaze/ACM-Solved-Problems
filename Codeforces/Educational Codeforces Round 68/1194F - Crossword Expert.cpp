#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
const int mod=1e9+7;
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
int t[MAX];
ll sum[MAX],p[MAX],inv2[MAX];
int main()
{
	int n,m,i,j;
	ll T,now,ans;
	scanf("%d%lld",&n,&T);
	comb.init(n);
	sum[0]=0;
	inv2[0]=1;
	inv2[1]=(mod+1)/2;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&t[i]);
		sum[i]=sum[i-1]+t[i];
		if(i>1) inv2[i]=inv2[i-1]*inv2[1]%mod;
	}
	j=0;
	now=1;
	for(i=1;i<=n;i++)
	{
		if(sum[i]>T)
		{
			p[i]=0;
			break;
		}
		m=min(T-sum[i],1LL*i);
		now=(2*now%mod-comb.C(i-1,j)+mod)%mod;
		while(j<m) now=(now+comb.C(i,++j))%mod;
		while(j>m) now=(now-comb.C(i,j--)+mod)%mod;
		p[i]=inv2[i]*now%mod;
	}
	ans=0;
	p[0]=1;
	p[n+1]=0;
	for(i=0;i<=n;i++)
	{
		if(sum[i]>T) break;
		ans=(ans+i*(p[i]-p[i+1]+mod))%mod;
	}
	printf("%lld\n",ans);
	return 0;
}
/*
时间做个前缀和，考虑恰好做 i 个题的概率。
求出不少于 i 个题的概率 P(x>=i)，容斥一下，期望为：sum{i*(P(x>=i+1)-P(x>=i))}
P(x>=i) = (1/2^i)*sum{C(i,j)}, 0<=j<=min(T-sum[i],i)
发现 i 递增，j 递减。类似莫队求组合数的转移，双指针扫 j。
公式是：sum{C(n+1,i=0..m)}=2*(sum{C(n,i=0..m)})-C(n,m)
*/
