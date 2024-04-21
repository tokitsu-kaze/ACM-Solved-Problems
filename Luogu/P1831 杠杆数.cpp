#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int DIG=20+2;
ll dp[DIG][3605];
ll gao(ll x,int mid)
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
	function<ll(int,int,int,int)> dfs=[&](int pos,int lead,int limt,int now)->ll
	{
		if(now<0) return 0;
		if(pos<mid&&lead) return 0;
		if(pos==-1) return !lead&&now==0;
		if(!limt&&!lead&&dp[pos][now]!=-1) return dp[pos][now];
		ll res=0;
		for(int i=(limt?p[pos]:base-1);~i;i--)
		{
			res+=dfs(pos-1,lead&&i==0&&pos,limt&&i==p[pos],now+i*(pos-mid));
		}
		if(!limt&&!lead) dp[pos][now]=res;
		return res;
	};
	return dfs(tot-1,1,1,0);
}
int main()
{
	int i;
	ll l,r,ans;
	scanf("%lld%lld",&l,&r);
	ans=0;
	for(i=0;i<=20;i++)
	{
		memset(dp,-1,sizeof dp);
		ans+=gao(r,i)-gao(l-1,i);
	}
	printf("%lld\n",ans);
	return 0;
}
