#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
using namespace std;
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
typedef long long ll;
typedef unsigned long long ull;
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
#define VI vector<int>
#define VL vector<ll>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=2e5+10;
const ll mod=998244353;
namespace NTT
{
	const ll g=3;
	const ll p=998244353;
	ll wn[23];
	ll pow2(ll a,ll b)
	{
		ll res=1;
		while(b)
		{
			if(b&1) res=res*a%p;
			a=a*a%p;
			b>>=1;
		}
		return res;
	}
	void getwn()
	{
	    for(int i=0;i<20;i++) wn[i]=pow2(g,(p-1)/(1LL<<i));
	}
	void ntt(VL &a,int len,int f)
	{
		ll i,j=0,t,k,w,id;
		for(i=1;i<len-1;i++)
		{
			for(t=len;j^=t>>=1,~j&t;);
			if(i<j) swap(a[i],a[j]);
		}
		for(i=1,id=1;i<len;i<<=1,id++)
		{
			t=i<<1;
			for(j=0;j<len;j+=t)
			{
				for(k=0,w=1;k<i;k++,w=w*wn[id]%p)
				{
					ll x=a[j+k],y=w*a[j+k+i]%p;
					a[j+k]=x+y;
					if(a[j+k]>=p) a[j+k]-=p;
					a[j+k+i]=x-y;
					if(a[j+k+i]<0) a[j+k+i]+=p;
				}
			}
		}
		if(f)
		{
			for(i=1,j=len-1;i<j;i++,j--) swap(a[i],a[j]);
			ll inv=pow2(len,p-2);
			for(i=0;i<len;i++) a[i]=a[i]*inv%p;
		}
	}
	void mul(VL &c,VL a,VL b,int l1,int l2)
	{
		int len,i;
		for(len=1;len<=l1+l2;len<<=1);
		a.resize(len+1);
		b.resize(len+1);
		for(i=l1+1;i<=len;i++) a[i]=0;
		for(i=l2+1;i<=len;i++) b[i]=0;
		ntt(a,len,0);ntt(b,len,0);
		c.resize(len);
		for(i=0;i<len;i++) c[i]=a[i]*b[i]%p;
		ntt(c,len,1);
		c.resize(l1+l2+1);
	}
};
ll pow2(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
ll inv(ll x)
{
	return pow2(x,mod-2);
}
ll fac[MAX];
void init(int n)
{
	ll i;
	fac[0]=1;
	for(i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
}
ll C(int n,int m)
{
	if(m>n||m<0) return 0;
	return fac[n]*inv(fac[m]*fac[n-m]%mod)%mod;
}
VL dp[MAX];
ll a[MAX],b[MAX];
int main()
{
	ll t,i,j,x,n,m,sum;
	init(MAX-10);
	while(~scanf("%lld",&n))
	{
		assert(n>=1&&n<=100000);
		NTT::getwn();
		sum=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
			sum+=a[i];
			assert(a[i]>=1&&a[i]<=200000);
		}
		assert(sum>=1&&sum<=200000);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&b[i]);
			assert(b[i]>=1&&b[i]<=100000);
		}
		set<PLL > s;
		for(i=0;i<n;i++)
		{
			dp[i].clear();
			dp[i].pb((pow2(2,b[i])-1+mod)%mod);
			for(j=1;j<=a[i];j++) dp[i].pb(C(a[i],j));
			s.insert(MP(a[i]+1,i));
		}
		m=n;
		while(sz(s)>1)
		{
			i=(*s.begin()).se;
			s.erase(s.begin());
			j=(*s.begin()).se;
			s.erase(s.begin());
			NTT::mul(dp[m],dp[i],dp[j],sz(dp[i])-1,sz(dp[j])-1);
			s.insert(MP(sz(dp[m]),m));
			m++;
		}
		j=(*s.begin()).se;
		for(i=0;i<=sum;i++) printf("%lld%c",dp[j][i]," \n"[i==sum]);
	}
	return 0;
}
