#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=4e5+10;
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
int main()
{
	init_comb(MAX-10);
	int T,n,l,r,x,y,k,any,hf,len;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&l,&r);
		hf=n/2;
		any=min(1-l,r-n);
		ans=any*C(n,hf)%mod;
		if(n&1) ans=(ans+any*C(n,n-hf))%mod;
		for(k=any+1;;k++)
		{
			x=max(1,l+k);
			y=min(n,r-k);
			len=y-x+1;
			if(len<0) break;
			ans=(ans+C(len,hf-(x-1)))%mod;
			if(n&1) ans=(ans+C(len,(n-hf)-(x-1)))%mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
ai-i=-(aj-j)
k=ai-i
一半k一半-k
先选一半，n=奇数哪个是一半都行，多*2

ai!=i   ->   k>=1
1<=k<=min(1-l,r-n) 可以任意选，
这时候只关心位置，所以C(n,n/2)，奇数要加上(n,n-n/2)

中间有一段是只有1种方案，后面又可以任意选。
*/
