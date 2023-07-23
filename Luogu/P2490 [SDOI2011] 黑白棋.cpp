#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int MAX=1e4+10;
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
ll dp[22][MAX];
int main()
{
	int n,k,d,i,j,s,mx;
	ll ans;
	init(MAX-10);
	scanf("%d%d%d",&n,&k,&d);
	assert(k%2==0);
	mx=0;
	while((1<<mx)<n) mx++;
	memset(dp,0,sizeof dp);
	dp[0][0]=1;
	for(s=1;s<=mx;s++)
	{
		for(i=0;i<=n-k;i++)
		{
			for(j=0;i-j*(1<<(s-1))>=0&&j<=k/2;j+=(d+1))
			{
				dp[s][i]=(dp[s][i]+dp[s-1][i-j*(1<<(s-1))]*C(k/2,j))%mod;
			}
		}
	}
	ans=0;
	for(i=0;i<=n-k;i++) ans=(ans+dp[mx][i]*C(n-k/2-i,k/2))%mod;
	printf("%lld\n",(C(n,k)-ans+mod)%mod);
	return 0;
}
/*
P2490 [SDOI2011] 黑白棋
转化成k-nim: 每一位都要满足1的总个数是(d+1)的倍数，先手必败 
dp[s][i]表示0~s-1位都满足条件，使用了i个石子的方案数
转移枚举(d+1)倍数
答案=总的-必败 
*/
