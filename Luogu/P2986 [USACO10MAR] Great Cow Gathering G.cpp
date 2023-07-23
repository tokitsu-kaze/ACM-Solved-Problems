#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
struct node{int id;ll w;};
vector<node> mp[MAX];
ll v[MAX],sum[MAX],dp[MAX];
void dfs1(int x,int fa)
{
	sum[x]=v[x];
	dp[x]=0;
	for(auto &to:mp[x])
	{
		if(to.id==fa) continue;
		dfs1(to.id,x);
		sum[x]+=sum[to.id];
		dp[x]+=dp[to.id]+sum[to.id]*to.w;
	}
}
ll ans,tot;
void dfs(int x,int fa)
{
//	printf("%d %lld\n",x,dp[x]);
	ans=min(ans,dp[x]);
	for(auto &to:mp[x])
	{
		if(to.id==fa) continue;
		dp[to.id]=dp[x]-sum[to.id]*to.w+(tot-sum[to.id])*to.w;
		dfs(to.id,x);
	}
}
int main()
{
	int n,i,a,b,c;
	scanf("%d",&n);
	tot=0;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&v[i]);
		tot+=v[i];
	}
	for(i=1;i<n;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		mp[a].push_back({b,c});
		mp[b].push_back({a,c});
	}
	dfs1(1,0);
	ans=LLINF;
	dfs(1,0);
	printf("%lld\n",ans);
	return 0;
}
