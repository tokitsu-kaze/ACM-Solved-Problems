#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
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
int a[MAX];
int main()
{
	init_comb(MAX-10);
	int n,i,cntl,cntr,cnt;
	ll sum,ans;
	scanf("%d",&n);
	sum=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	if(sum%n) return 0*puts("0");
	sum/=n;
	cntl=cntr=cnt=0;
	map<int,int> mpl,mpr,mp;
	for(i=1;i<=n;i++)
	{
		mp[a[i]]++;
		if(a[i]<sum)
		{
			cntl++;
			mpl[a[i]]++;
		}
		else if(a[i]>sum)
		{
			cntr++;
			mpr[a[i]]++;
		}
		else cnt++;
	}
	if(cntl<=1 || cntr<=1)
	{
		ans=fac[n];
		for(auto &it:mp) ans=ans*invfac[it.second]%mod;
		printf("%lld\n",ans);
		return 0;
	}
	ans=2LL*fac[cntl]*fac[cntr]%mod;
	for(auto &it:mpl) ans=ans*invfac[it.second]%mod;
	for(auto &it:mpr) ans=ans*invfac[it.second]%mod;
	printf("%lld\n",C(n,cnt)*ans%mod);
	return 0;
}
/*
每个点要么是源要么是汇。
手玩发现源汇肯定各在一边，感觉并不难发现。
源汇内部随便排，然后可以交换位置所以要*2。
不是源也不是汇的点可以任意插入。
最后特判一下源或者汇<=1个时，随便排。
*/
