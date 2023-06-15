#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int DIG=20+2;
ll dp[DIG][181][181];
ll gao(ll x,int k)
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
	function<ll(int,int,int,int)> dfs=[&](int pos,int lead,int sum,int limt)->ll
	{
		if(sum>k) return 0;
		if(pos==-1) return !lead&&sum==k;
		if(!limt&&!lead&&dp[pos][k][sum]!=-1) return dp[pos][k][sum];
		ll res=0;
		for(int i=(limt?p[pos]:base-1);~i;i--)
		{
			res+=dfs(pos-1,lead&&i==0&&pos,sum+i,limt&&i==p[pos]); 
		}
		if(!limt&&!lead) dp[pos][k][sum]=res;
		return res;
	};
	return dfs(tot-1,1,0,1);
}
int main()
{
	int i,t;
	ll l,r,ans;
	memset(dp,-1,sizeof dp);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld",&l,&r);
		ans=0;
		for(i=1;i<=9*19;i++)
		{
			ans=(ans+(gao(r,i)-gao(l-1,i))%mod*i)%mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}

