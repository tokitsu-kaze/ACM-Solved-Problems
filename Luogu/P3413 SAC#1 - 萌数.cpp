#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int DIG=1e3+10;
ll dp[DIG][11][11][2];
ll gao(string x)
{
	const int base=10;
	int i,p[DIG],tot=0;
	for(i=x.size()-1;~i;i--) p[tot++]=x[i]-'0';
	function<ll(int,int,int,int,int,int)> dfs=[&]
		(int pos,int lead,int ppre,int pre,int sta,int limt)->ll
	{
		if(pos==-1) return !lead&&sta;
		if(!limt&&!lead&&dp[pos][ppre][pre][sta]!=-1) return dp[pos][ppre][pre][sta];
		ll res=0;
		for(int i=(limt?p[pos]:base-1);~i;i--)
		{
			res+=dfs(pos-1,lead&&i==0&&pos,
					lead?10:pre,lead&&i==0&&pos?10:i,sta|(i==pre)|(i==ppre),
					limt&&i==p[pos]);
			res%=mod;
		}
		if(!limt&&!lead) dp[pos][ppre][pre][sta]=res;
		return res;
	};
	return dfs(tot-1,1,10,10,0,1);
}
int main()
{
	int i;
	string l,r;
	cin>>l>>r;
	for(i=l.size()-1;~i;i--)
	{
		if(l[i]=='0') l[i]='9';
		else
		{
			l[i]--;
			break;
		}
	}
	if(l[0]=='0') l=l.substr(1);
	memset(dp,-1,sizeof dp);
	printf("%lld\n",(gao(r)-gao(l)+mod)%mod);
	return 0;
}
