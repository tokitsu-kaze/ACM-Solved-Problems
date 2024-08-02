#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=4e6+10;
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
int dp[2005][2005];
int main()
{
	int n,k,i,j;
	scanf("%d%d",&n,&k);
	if(k==1) return 0*puts("1");
	init_comb(n*k);
	memset(dp,0,sizeof dp);
	for(i=1;i<=n;i++) dp[i][0]=1;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++)
		{
			dp[i][j]=(dp[i-1][j]+1LL*dp[i][j-1]*(n-j+1)%mod
				*C(n*k-(j-1)*(k-1)-i-1,k-2))%mod;
		}
	}
	printf("%d\n",dp[n][n]);
	return 0;
}
