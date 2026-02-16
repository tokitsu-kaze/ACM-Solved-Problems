#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
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
char s[MAX];
int pre[MAX][10],suf[MAX][10];
int main()
{
	int n,i,j,a,b;
	ll ans;
	init_comb(MAX-10);
	scanf("%s",s+1);
	n=strlen(s+1);
	memset(pre[0],0,sizeof pre[0]);
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=9;j++) pre[i][j]=pre[i-1][j];
		pre[i][s[i]-'0']++;
	}
	memset(suf[n+1],0,sizeof suf[n+1]);
	for(i=n;i;i--)
	{
		for(j=0;j<=9;j++) suf[i][j]=suf[i+1][j];
		suf[i][s[i]-'0']++;
	}
	ans=0;
	for(i=n;i;i--)
	{
		if(s[i]=='0') continue;
		a=suf[i][s[i]-'0']-1;
		b=pre[i-1][s[i]-'0'-1];
		ans=(ans+C(a+b,a+1))%mod;
	}
	printf("%lld\n",ans);
	return 0;
}
/*
1111222
C(2,0)*C(4,1)+C(2,1)*C(4,2)+C(2,2)*C(4,3)
C(a,0)*C(b,1)+C(a,1)*C(b,2)+...+C(a,a)*C(b,a+1)
C(a+b,a+1)
*/
