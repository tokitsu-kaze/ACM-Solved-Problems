#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
const int DIG=60+2;
const int mod=998244353;
ll dp[DIG][62];
ll gao(ll n,int x,int k)
{
	memset(dp,-1,sizeof dp);
	const int base=2;
	int p[DIG],tot=0;
	if(n==-1) return 0;
	while(1)
	{
		p[tot++]=n%base;
		n/=base;
		if(!n) break;
	}
	if(x>=tot) return 0;
	ll ans=0;
	function<ll(int,int,int,int)> dfs=[&](int pos,int lead,int sta,int limt)->ll
	{
		if(sta>k) return 0;
		if(pos==-1) return sta==k;
		if(!limt&&!lead&&dp[pos][sta]!=-1) return dp[pos][sta];
		ll res=0;
		for(int i=(limt?p[pos]:base-1);~i;i--)
		{
			if(pos==x)
			{
				if(i!=1) continue;
			}
			ll tmp=dfs(pos-1,lead&&i==0&&pos,sta+i,limt&&i==p[pos]);
			res+=tmp;
		}
		if(!limt&&!lead) dp[pos][sta]=res;
		return res;
	};
	return dfs(tot-1,1,0,1)%mod;
}
int main()
{
	int T,k,i;
	ll n,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%d",&n,&k);
		ans=0;
		for(i=0;i<=60;i++) ans=(ans+(1LL<<i)%mod*gao(n,i,k))%mod;
		printf("%lld\n",ans);
	}
	return 0;
}
