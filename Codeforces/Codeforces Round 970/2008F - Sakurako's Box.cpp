#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
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
int a[MAX];
int main()
{
	int t,n,i;
	ll ans,sum;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		sum=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			sum=(sum+a[i])%mod;
		}
		ans=0;
		for(i=1;i<=n;i++)
		{
			sum-=a[i];
			if(sum<0) sum+=mod;
			ans=(ans+a[i]*sum)%mod;
		}
		printf("%lld\n",ans*inv(1LL*n*(n-1)/2%mod)%mod);
	}
	return 0;
}

