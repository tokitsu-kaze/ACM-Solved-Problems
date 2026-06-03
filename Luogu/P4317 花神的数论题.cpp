#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
const int mod=10000007;
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
namespace DIGDP
{
	const int base=2;
	const int DIG=60+2;
	int p[DIG],tot;
	ll dp[DIG][DIG];
	ll dfs(int pos,int lead,int sta,int limt,int k)
	{
		if(sta>k) return 0;
		if(pos==-1) return sta==k;
		if(!limt&&!lead&&dp[pos][sta]!=-1) return dp[pos][sta];
		ll res=0;
		for(int i=(limt?p[pos]:base-1);~i;i--)
		{
			res+=dfs(pos-1,lead&&i==0&&pos,sta+i,limt&&i==p[pos],k);
		}
		if(!limt&&!lead) dp[pos][sta]=res;
		return res;
	}
	ll gao(ll x,int k)
	{
		if(x==-1) return 0;
		memset(dp,-1,sizeof dp);
		tot=0;
		while(1)
		{
			p[tot++]=x%base;
			x/=base;
			if(!x) break;
		}
		return dfs(tot-1,1,0,1,k);
	}
}
int main()
{
	int i;
	ll x,ans;
	scanf("%lld",&x);
	ans=1;
	for(i=1;i<=60;i++) ans=(ans*qpow(i,DIGDP::gao(x,i)))%mod;
	printf("%lld\n",ans);
	return 0;
}
