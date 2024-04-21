#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
vector<int> mp[MAX];
ll dp[MAX],v[MAX],ans;
void dfs(int x,int fa)
{
	dp[x]=v[x];
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		dfs(to,x);
		dp[x]+=max(0ll,dp[to]);
	}
	ans=max(ans,dp[x]);
}
int main()
{
	int n,i,x,y;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		mp[i].clear();
		scanf("%lld",&v[i]);
	}
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		mp[x].push_back(y);
		mp[y].push_back(x);
	}
	ans=0;
	dfs(1,0);
	printf("%lld\n",ans);
	return 0;
}
