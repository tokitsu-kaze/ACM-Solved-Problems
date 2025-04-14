#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
const int mod=998244353;
//x is a prime if prime[x]==x(x>=2)
int p[MAX],tot,prime[MAX];
void init_prime(int n)
{
	int i,j;
	tot=0;
	memset(prime,0,sizeof prime);
	prime[1]=1;
	for(i=2;i<=n;i++)
	{
		if(!prime[i]) prime[i]=p[tot++]=i;
		for(j=0;j<tot&&p[j]*i<=n;j++)
		{
			prime[i*p[j]]=p[j];
			if(i%p[j]==0) break;
		}
	}
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
ll dp[2][2025];
int main()
{
	init_prime(MAX-10);
	init_comb(MAX-10);
	int n,i,j,f,tot,x,cnti;
	scanf("%d",&n);
	map<int,int> cnt;
	for(i=1;i<=2*n;i++)
	{
		scanf("%d",&x);
		cnt[x]++;
	}
	memset(dp,0,sizeof dp);
	f=0;
	dp[f][0]=1;
	tot=0;
	for(auto &it:cnt)
	{
		f^=1;
		memset(dp[f],0,sizeof dp[f]);
		i=it.first;
		cnti=it.second;
		if(prime[i]==i && i!=1) tot++;
		for(j=0;j<=min(tot,n);j++)
		{
			dp[f][j]=dp[!f][j]*invfac[cnti]%mod;
			if(prime[i]!=i || i==1) continue;
			if(j>0) dp[f][j]+=dp[!f][j-1]*invfac[cnti-1];
			dp[f][j]%=mod;
		}
/*		for(j=0;j<=min(tot,n);j++)
		{
			printf("%d %d %lld\n",i,j,dp[f][j]);
		}*/
	}
	printf("%lld\n",dp[f][n]*fac[n]%mod);
	return 0;
}
