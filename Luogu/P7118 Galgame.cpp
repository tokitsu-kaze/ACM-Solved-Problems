#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e6+10;
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
int ls[MAX],rs[MAX],sz[MAX],ca[MAX],ans;
void getsz(int x)
{
	if(!x) return;
	getsz(ls[x]);
	getsz(rs[x]);
	sz[x]=sz[ls[x]]+sz[rs[x]]+1;
}
void dfs(int x,int k)
{
	if(!x) return;
	int i;
	if(sz[ls[x]]<sz[rs[x]])
	{
		for(i=0;i<sz[ls[x]];i++)
		{
			ans=(ans+1LL*k*ca[i]%mod*ca[sz[x]-i-1])%mod;
		}
	}
	else
	{
		ans=(ans+1LL*k*ca[sz[x]])%mod;
		for(i=sz[ls[x]];i<sz[x];i++)
		{
			ans=(ans-1LL*k*ca[i]%mod*ca[sz[x]-i-1])%mod;
			if(ans<0) ans+=mod;
		}
	}
	dfs(ls[x],1LL*k*ca[sz[rs[x]]]%mod);
	dfs(rs[x],k);
}
int main()
{
	int n,i;
	scanf("%d",&n);
	init_comb(2*n);
	ca[0]=1;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&ls[i],&rs[i]);
		ca[i]=(C(2*i,i)-C(2*i,i-1)+mod)%mod;
	}
	ans=0;
	for(i=1;i<n;i++) ans=(ans+ca[i])%mod;
	sz[0]=0;
	getsz(1);
	dfs(1,1);
	printf("%d\n",ans);
	return 0;
}
