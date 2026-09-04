#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int DIG=21+2;
ll dp[DIG][12];
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
	function<ll(int,int,int,int)> dfs=[&](int pos,int lead,int pre,int limt)->ll
	{
		if(lead) pre=10;
		if(pos==-1) return !lead;
		if(!limt&&!lead&&dp[pos][pre]!=-1) return dp[pos][pre];
		ll res=0;
		for(int i=(limt?p[pos]:base-1);~i;i--)
		{
			if(pre!=10 && abs(i-pre)>k) continue;
			res+=dfs(pos-1,lead&&i==0&&pos,i,limt&&i==p[pos]); 
		}
		if(!limt&&!lead) dp[pos][pre]=res;
		return res;
	};
	return dfs(tot-1,1,10,1);
}
int main()
{
	int k;
	ll l,r;
	scanf("%lld%lld%d",&l,&r,&k);
	memset(dp,-1,sizeof dp);
	printf("%lld\n",gao(r,k)-gao(l-1,k));
	return 0;
}

