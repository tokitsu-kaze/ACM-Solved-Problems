#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e5+10;
const int mod=1e9+7;
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
int a[MAX],b[MAX];
int dp[4005][4005];
const int delta=2000;
int main()
{
	int n,i,j;
	ll ans;
	init_comb(8000);
	scanf("%d",&n);
	memset(dp,0,sizeof dp);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
		dp[-a[i]+delta][-b[i]+delta]++;
	}
	for(i=0;i<=4000;i++)
	{
		for(j=0;j<=4000;j++)
		{
			if(i>0) dp[i][j]+=dp[i-1][j];
			if(j>0) dp[i][j]+=dp[i][j-1];
			dp[i][j]%=mod;
		}
	}
	ans=0;
	for(i=1;i<=n;i++) ans=(ans+dp[a[i]+delta][b[i]+delta])%mod;
	for(i=1;i<=n;i++) ans=(ans-C(2*a[i]+2*b[i],2*a[i])+mod)%mod;
	printf("%lld\n",ans*inv(2)%mod);
	return 0;
}
