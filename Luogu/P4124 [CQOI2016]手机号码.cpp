#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int DIG=13+2;
ll dp[DIG][DIG][2][2][2];
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
	function<ll(int,int,int,int,int,int,int,int)> dfs=[&](int pos,int lead,int pre,int cnt,int ok,int f4,int f8,int limt)->ll
	{
		if(lead)
		{
			pre=10;
			cnt=0;
		}
		if(cnt>=3) ok=1;
		if(pos==-1) return !lead&&ok&&!(f4&&f8);
		if(!limt&&!lead&&dp[pos][cnt][ok][f4][f8]!=-1) return dp[pos][cnt][ok][f4][f8];
		ll res=0;
		for(int i=(limt?p[pos]:base-1);~i;i--)
		{
			res+=dfs(pos-1,
					 lead&&i==0&&pos,
					 i,
					 i==pre?cnt+1:1,
					 ok,
					 f4|(i==4),
					 f8|(i==8),
					 limt&&i==p[pos]); 
		}
		if(!limt&&!lead) dp[pos][cnt][ok][f4][f8]=res;
		return res;
	};
	return dfs(tot-1,1,10,0,0,0,0,1);
}
int main()
{
	ll l,r;
	scanf("%lld%lld",&l,&r);
	memset(dp,-1,sizeof dp);
	printf("%lld\n",gao(r)-gao(l-1));
	return 0;
}

