#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int DIG=20+2;
ll dp[DIG][181][181];
ll gao(ll x,int mod)
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
	function<ll(int,int,int,int,int)> dfs=[&](int pos,int lead,int sum,int ret,int limt)->ll
	{
		if(sum>mod) return 0;
		if(pos==-1) return !lead&&sum==mod&&ret==0;
		if(!limt&&!lead&&dp[pos][sum][ret]!=-1) return dp[pos][sum][ret];
		ll res=0;
		for(int i=(limt?p[pos]:base-1);~i;i--)
		{
			res+=dfs(pos-1,lead&&i==0&&pos,sum+i,(ret*10+i)%mod,limt&&i==p[pos]); 
		}
		if(!limt&&!lead) dp[pos][sum][ret]=res;
		return res;
	};
	return dfs(tot-1,1,0,0,1);
}
int main()
{
	int i;
	ll l,r,ans;
	scanf("%lld%lld",&l,&r);
	ans=0;
	for(i=1;i<=9*19;i++)
	{
		memset(dp,-1,sizeof dp);
		ans+=gao(r,i)-gao(l-1,i);
	}
	printf("%lld\n",ans);
	return 0;
}

