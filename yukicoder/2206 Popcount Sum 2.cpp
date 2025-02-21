#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int mod=998244353;
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
struct binomial_prefix_sum
{
	static const int B=450;
	int table[MAX/B+1][MAX];
	void init(int n)
	{
		int i,j;
		init_comb(n);
		for(i=0;i*B<=n;i++)
		{
			table[i][0]=1;
			for(j=1;j<=n;j++)
			{
				table[i][j]=table[i][j-1]+C(i*B,j);
				if(table[i][j]>=mod) table[i][j]-=mod;
			}
		}
	}
	ll get_sum(int n,int m)
	{
		int now=n/B;
		ll res=table[now][m];
		now*=B;
		while(now<n)
		{
			res=2LL*res-C(now,m);
			if(res>=mod) res-=mod;
			else if(res<0) res+=mod;
			now++;
		}
		return res;
	}
}binomsum;
/*
f(n,m)=sum{C(n,k=0..m)}
f(n+1,m)=2*f(n,m)-C(n,m)

O(n sqrt n) - O(sqrt n)
binomsum.init(n);
binomsum.get_sum(n,m); -> sum{C(n,k=0..m)}
*/
int main()
{
	binomsum.init(2e5);
	int T,n,m;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		printf("%lld\n",(qpow(2,n)-1+mod)
				*binomsum.get_sum(n-1,m-1)%mod);
	}
	return 0;
}
