#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=4e6+10;
const ll mod=998244353;
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
	int t,n,i,a,b,c,d;
	ll ans;
	init(MAX-10);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if(a==0&&b==0)
		{
			if(c==0||d==0) puts("1");
			else puts("0");
			continue;
		}
		ans=0;
		if(a==b)
		{
			ans=(ans+C(a+d-1,d)*C(b+c,c))%mod;
			ans=(ans+C(a+d,d)*C(b+c-1,c))%mod;
		}
		else if(abs(a-b)==1)
		{
			ans=(ans+C(max(a,b)+d-1,d)*C(max(a,b)+c-1,c))%mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
1-2
2-1

1-3
4-1

3-2
2-4

3-3

4-4

1-2-1-2-1
2-1-2-1-2

1-3-2-4
4-1-3-2
2-4-1-3
3-2-4-1

2-4-1-2-4-1-2-4-1-2-4-1-2-4-1
4-1-2-4-1-2-4-1-2-4-1-2-4-1-2-4


3-2-4-1-3-2-4

*/
