#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2000+10;
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
struct PolySum
{
	ll cal_n(int d,int *x,int *y,ll n) // O(d^2)
	{
		int i,j;
		ll ans,fz,fm;
		n%=mod;
		ans=0;
		for(i=0;i<=d;i++)
		{
			fz=y[i];
			fm=1;
			for(j=0;j<=d;j++)
			{
				if(i==j)continue;
				fz=fz*(n-x[j]+mod)%mod;
				fm=fm*(x[i]-x[j]+mod)%mod;
			}
			ans=(ans+fz*comb.inv(fm))%mod;
		}
		return ans;
	}
	ll cal_n(int d,int *y,ll n) // O(d)
	{
		if(n<=d) return y[n];
		n%=mod;
		int i;
		ll ans,fz,invfm,t;
		vector<int> pre(d+1),suf(d+2);
		pre[0]=suf[d+1]=1;
		for(i=1;i<=d;i++) pre[i]=1LL*pre[i-1]*(n-i+1+mod)%mod;
		for(i=d;i>=0;i--) suf[i]=1LL*suf[i+1]*(n-i+mod)%mod;
		ans=0;
		comb.init(d);
		for(i=0;i<=d;i++)
		{
			fz=1LL*pre[i]*suf[i+1]%mod;
			invfm=1LL*comb.invfac[i]*comb.invfac[d-i]%mod;
			t=y[i]*fz%mod*invfm%mod;
			if((d-i)&1) ans=(ans-t+mod)%mod;
			else ans=(ans+t)%mod;
		}
		return ans;
	}
	ll polysum(int d,int *y,ll n) // O(d)
	{
		int i;
		vector<int> tmp(d+2);
		for(i=0;i<=d;i++) tmp[i]=y[i];
		tmp[d+1]=cal_n(d,tmp.data(),d+1);
		for(i=1;i<=d+1;i++) tmp[i]=(tmp[i-1]+tmp[i])%mod;
		return cal_n(d+1,tmp.data(),n);
	}
	ll qpolysum(int d,int *y,ll r,ll n) // O(d)
	{
		r=(r%mod+mod)%mod;
		if(r==0) return y[0];
		if(r==1) return polysum(d,y,n);
		int i,sgn;
		ll invr,sumb,sumk,c0,t,ans;
		vector<int> k(d+2),b(d+2);
		comb.init(d+1);
		invr=comb.inv(r);
		k[0]=1;
		b[0]=0;
		for(i=1;i<=d+1;i++)
		{
			k[i]=k[i-1]*invr%mod;
			b[i]=(b[i-1]+y[i-1])%mod*invr%mod;
		}
		sumk=sumb=0;
		for(i=0;i<=d+1;i++)
		{
			t=1LL*comb.invfac[i]*comb.invfac[d+1-i]%mod;
			sgn=(i&1)?(-1):1;
			sumk=(sumk+sgn*k[i]*t)%mod;
			sumb=(sumb+sgn*b[i]*t)%mod;
		}
		if(sumk<0) sumk+=mod;
		if(sumb<0) sumb+=mod;
		c0=comb.inv(sumk)*(mod-sumb)%mod;
		vector<int> c(d+1);
		for(i=0;i<=d;i++) c[i]=(k[i]*c0+b[i])%mod;
		ans=(cal_n(d,c.data(),n+1)*comb.qpow(r,n+1)%mod-c0+mod)%mod;
		return ans;
	}
}lg;
/*
lg.cal_n(d,x,y,n) // (x[0],y[0])..(x[d],y[d]) -> y[n]
lg.cal_n(d,y,n) // y[0].. y[d] -> y[n]
lg.polysum(d,y,n) // y[0]..y[d] -> \sum_{i=0}^{n} y[i]
lg.qpolysum(d,y,r,n) // y[0]..y[d] -> \sum_{i=0}^{n} y[i]*r^i
*/
int x[MAX],y[MAX];
int main()
{
	int n,k,i;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++) scanf("%d%d",&x[i],&y[i]);
	printf("%lld\n",lg.cal_n(n-1,x,y,k));
	return 0;
}
