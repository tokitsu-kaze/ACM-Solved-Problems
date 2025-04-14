#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
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
int a[MAX],p[MAX];
ll dp[2][1024];
int main()
{
	const int tot=1e4;
	int T,n,i,j,f;
	ll ans,e,fm;
	fm=inv(1e4);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=n;i++) scanf("%d",&p[i]);
		f=0;
		memset(dp,0,sizeof dp);
		dp[f][0]=1;
		for(i=1;i<=n;i++)
		{
			f^=1;
			for(j=0;j<1024;j++)
			{
				dp[f][j]=(dp[!f][j]*(tot-p[i])+dp[!f][j^a[i]]*p[i])%mod*fm%mod;
			}
		}
		ans=0;
		for(i=0;i<1024;i++)
		{
			ans=(ans+1LL*i*i*dp[f][i])%mod;
//			cout<<i<<" "<<dp[f][i]<<endl;
		}
		printf("%lld\n",ans);
	}
	return 0;
}

