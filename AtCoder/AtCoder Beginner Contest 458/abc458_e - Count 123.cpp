#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e6+10;
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
	init_comb(3e6);
	int a,b,c,i;
	ll ans;
	scanf("%d%d%d",&a,&b,&c);
	ans=0;
	for(i=1;i<=b+1;i++)
	{
		ans=(ans+C(b+1,i)*C(a-1,i-1)%mod*C(c+(b+1-i)-1,(b+1-i)-1))%mod;
//		printf("%d %lld\n",i,ans);
	}
	printf("%lld\n",ans);
	return 0;
}
/*
把2放好，枚举1插入多少个空，3插入剩下的空。
*/
