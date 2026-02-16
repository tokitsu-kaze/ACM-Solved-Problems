#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
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
int cnt[MAX],a[MAX];
int main()
{
	init_comb(MAX-10);
	int n,d,i,j;
	ll ans;
	scanf("%d%d",&n,&d);
	memset(cnt,0,sizeof cnt);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		cnt[a[i]]++;
	}
	sort(a+1,a+1+n);
	ans=1;
	for(i=2,j=1;i<=n;i++)
	{
		while(a[j]+d<a[i]) j++;
		ans=ans*(i-j+1)%mod;
	}
	for(i=1;i<MAX;i++) ans=ans*invfac[cnt[i]]%mod;
	printf("%lld\n",ans);
	return 0;
}
