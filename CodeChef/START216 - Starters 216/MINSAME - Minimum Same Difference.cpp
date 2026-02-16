#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
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
ll d[MAX];
int main()
{
	int T,n,k,x;
	ll now,sd,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		now=1;
		sd=k;
		for(x=1;x<=n;x++)
		{
			now=now*sd%mod;
			sd=max(0LL,sd-1);
			d[x]=now*qpow(k-(x-1),n-x)%mod;
		}
		for(x=1;x<n;x++) d[x]=(d[x]-d[x+1]+mod)%mod;
		ans=0;
		for(x=1;x<n;x++) ans=(ans+d[x]*x)%mod;
		printf("%lld\n",ans);
	}
	return 0;
}
/*
枚举 f(A)=x，考虑计算 i-j>=x 的方案数 d(x)
a1有k种，a2有(k-1)种...
a[x+1]有k-(x-1)种
i-j=x的方案数为 d(x)-d(x+1) 
*/
