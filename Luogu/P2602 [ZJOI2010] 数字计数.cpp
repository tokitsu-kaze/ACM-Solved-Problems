#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int DIG=13+2;
ll dp[DIG][DIG];
ll gao(ll x,int now,int k)
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
	function<ll(int,int,int,int)> dfs=[&](int pos,int lead,int cnt,int limt)->ll
	{
		if(lead) cnt=0;
		if(cnt>k) return 0;
		if(pos==-1) return !lead&&cnt==k;
		if(!limt&&!lead&&dp[pos][cnt]!=-1) return dp[pos][cnt];
		ll res=0;
		for(int i=(limt?p[pos]:base-1);~i;i--)
		{
			res+=dfs(pos-1,lead&&i==0&&pos,cnt+(i==now),limt&&i==p[pos]); 
		}
		if(!limt&&!lead) dp[pos][cnt]=res;
		return res;
	};
	return dfs(tot-1,1,0,1);
}
int main()
{
	int i,j;
	ll l,r,ans;
	scanf("%lld%lld",&l,&r);
	for(i=0;i<=9;i++)
	{
		ans=0;
		for(j=1;j<=12;j++)
		{
			memset(dp,-1,sizeof dp);
			ans+=(gao(r,i,j)-gao(l-1,i,j))*j;
		}
		printf("%lld%c",ans," \n"[i==9]);
	}
	return 0;
}
