#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct node{int to,w;};
vector<node> mp[MAX];
ll dp[MAX],ans;
void dfs(int x,int fa)
{
	int to,w;
	ll mx=0;
	dp[x]=0;
	for(auto &it:mp[x])
	{
		to=it.to;
		w=it.w;
		if(to==fa) continue;
		dfs(to,x);
		ans=max(ans,dp[to]+w);
		ans=max(ans,mx+dp[to]+w);
		mx=max(mx,dp[to]+w);
	}
	dp[x]=mx;
}
int main()
{
	int n,i,a,b,c;
	scanf("%d",&n);
	for(i=1;i<=n;i++) mp[i].clear();
	for(i=1;i<n;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		mp[a].push_back({b,c});
		mp[b].push_back({a,c});
	}
	ans=0;
	dfs(1,0);
	printf("%lld\n",ans);
	return 0;
}
