#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=3e5+10;
const int DIG=11;
int flag[11];
ll dp[DIG][MAX];
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
	function<ll(int,int,int,int)> dfs=[&](int pos,int lead,int ret,int limt)->ll
	{
		if(pos==-1) return !lead&&ret==0;
		if(!limt&&!lead&&dp[pos][ret]!=-1) return dp[pos][ret];
		ll res=0;
		for(int i=(limt?p[pos]:base-1);~i;i--)
		{
			if(lead)
			{
				if(i!=0&&!flag[i]) continue;
			}
			else
			{
				if(!flag[i]) continue;
			}
			res+=dfs(pos-1,lead&&i==0&&pos,(ret*10+i)%mod,limt&&i==p[pos]); 
		}
		if(!limt&&!lead) dp[pos][ret]=res;
		return res;
	};
	return dfs(tot-1,1,0,1);
}
int ck(ll x)
{
	string tmp=to_string(x);
	for(auto &it:tmp)
	{
		if(!flag[it-'0']) return 0;
	}
	return 1;
}
int main()
{
	ll x,l,r,i,ans;
	scanf("%lld%lld%lld",&x,&l,&r);
	string s;
	cin>>s;
	memset(flag,0,sizeof flag);
	for(auto &it:s) flag[it-'0']=1;
	if(x>=MAX)
	{
		ans=0;
		for(i=max(x,l/x*x);i<=r;i+=x)
		{
			if(i>=l && ck(i)) ans++;
		}
	}
	else
	{
		memset(dp,-1,sizeof dp);
		ans=gao(r,x)-gao(l-1,x);
	}
	printf("%lld\n",ans);
	return 0;
}

