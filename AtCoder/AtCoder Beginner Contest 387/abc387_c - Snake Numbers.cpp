#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=3e5+10;
const int mod=1e9+7;
const int DIG=20+2;
ll dp[DIG][11];
ll gao(ll x)
{
	const int base=10;
	int p[DIG],tot=0;
	if(x==-1) return 0;
	while(1)
	{
		p[tot++]=x%base;
		x/=base;
		if(!x) break;
	}
	function<ll(int,int,int,int)> dfs=[&](int pos,int lead,int sta,int limt)->ll
	{
		if(pos==0 && lead) return 0;
		if(pos==-1) return !lead;
		if(!limt&&!lead&&dp[pos][sta]!=-1) return dp[pos][sta];
		ll res=0;
		for(int i=(limt?p[pos]:base-1);~i;i--)
		{
			if(lead)
			{
				if(i==0) res+=dfs(pos-1,lead,sta,limt&&i==p[pos]);
				else res+=dfs(pos-1,0,i,limt&&i==p[pos]);
			}
			else
			{
				if(i<sta) res+=dfs(pos-1,lead&&i==0&&pos,sta,limt&&i==p[pos]);
			}
		}
		if(!limt&&!lead) dp[pos][sta]=res;
		return res;
	};
	return dfs(tot-1,1,0,1);
}
int main()
{
	memset(dp,-1,sizeof dp);
	ll l,r;
	scanf("%lld%lld",&l,&r);
	printf("%lld\n",gao(r)-gao(l-1));
	return 0;
}
