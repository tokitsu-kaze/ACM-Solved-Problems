#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
const ll mod=1e9+7;
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
ll fac[MAX],invfac[MAX];
void init(int n)
{
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	invfac[n]=inv(fac[n]);
	for(int i=n-1;~i;i--) invfac[i]=invfac[i+1]*(i+1)%mod;
}
ll C(ll n,ll m)
{
	if(m>n||m<0||n<0) return 0;
	return fac[n]*invfac[m]%mod*invfac[n-m]%mod;
}
ll A(ll n,ll m)
{
	if(m>n||m<0||n<0) return 0;
	return fac[n]*invfac[n-m]%mod;
}
int main()
{
	int t,n,m,k,i,a,b,c;
	ll s,x,y,ans,add;
	init(MAX-10);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&k);
		s=0;
		for(i=1;i<=m;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			s+=c;
		}
		s%=mod;
		x=inv((1ll*n*(n-1)/2)%mod);
		y=(1ll*n*(n-1)/2-1)%mod*x%mod;
		ans=0;
		for(i=1;i<=k;i++)
		{
			add=(1ll*i*(i-1)/2)%mod;
			ans=(ans+C(k,i)*qpow(x,i)%mod*qpow(y,k-i)%mod*s%mod*i)%mod;
			ans=(ans+C(k,i)*qpow(x,i)%mod*qpow(y,k-i)%mod*add%mod*m)%mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
x=1 / (n*(n-1)/2)
y=(n*(n-1)/2-1) / (n*(n-1)/2)
\sum{j=1}{m} \sum{i=1}{k} C(k,i)*(x^i)*(y^{k-i})*(f[j]*i+i*(i-1)/2)
=m*(i*(i-1)/2) \sum{i=1}{k} C(k,i)*(x^i)*(y^{k-i})
+sum*i* \sum{i=1}{k} C(k,i)*(x^i)*(y^{k-i})
*/
