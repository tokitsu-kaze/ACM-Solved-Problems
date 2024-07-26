#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e7+10;
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
	int t,n,i,cnt[33],sum,odd;
	ll fz,fm,ans,inv2;
	char s[3];
	init_comb(MAX-10);
	inv2=inv(2);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		sum=0;
		odd=0;
		for(i=1;i<=n;i++)
		{
			scanf("%s%d",s,&cnt[i]);
			sum+=cnt[i];
			odd+=(cnt[i]&1);
		}
		fm=fac[sum];
		for(i=1;i<=n;i++) fm=fm*invfac[cnt[i]]%mod;
		fz=fac[sum/2];
		for(i=1;i<=n;i++) fz=fz*invfac[cnt[i]/2]%mod;
		if(sum&1)
		{
			if(odd>1) fz=0;
			ans=(1+fz*inv(fm)%mod)*inv2%mod;
		}
		else
		{
			if(odd>0) fz=0;
			ans=(1-fz*inv(fm)%mod+mod)*inv2%mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
