#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[36][36][36];
vector<int> p;
ll dfs(int pos,int lead,int a,int b,int limt)
{
	if(pos==-1) return a>=b;
	if(!limt&&!lead&&dp[pos][a][b]!=-1) return dp[pos][a][b];
	ll res=0;
	for(int i=(limt?p[pos]:1);~i;i--)
	{
		res+=dfs(pos-1,lead&&i==0&&pos,a+(b&&i==0),b+(i==1),limt&&i==p[pos]); 
	}
	if(!limt&&!lead) dp[pos][a][b]=res;
	return res;
}
ll gao(ll x)
{
	if(x==-1) return 0;
	p.clear();
	while(1)
	{
		p.push_back(x%2);
		x/=2;
		if(!x) break;
	}
	return dfs(p.size()-1,1,0,0,1);
}
int main()
{
	ll l,r;
	memset(dp,-1,sizeof dp);
	scanf("%lld%lld",&l,&r);
	printf("%lld\n",gao(r)-gao(l-1));
	return 0;
}
