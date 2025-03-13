#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=12;
const int mod=998244353;
struct edge{int to;ll w;};
vector<edge> mp[MAX];
int vis[MAX],n;
ll ans;
void dfs(int x,ll now)
{
	if(vis[x]) return;
	if(x==n)
	{
		ans=min(ans,now);
		return;
	}
	vis[x]=1;
	for(auto &it:mp[x]) dfs(it.to,now^it.w);
	vis[x]=0;
}
int main()
{
	int m,i,a,b;
	ll w;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) mp[i].clear();
	while(m--)
	{
		scanf("%d%d%lld",&a,&b,&w);
		mp[a].push_back({b,w});
		mp[b].push_back({a,w});
	}
	ans=4e18;
	memset(vis,0,sizeof vis);
	dfs(1,0);
	printf("%lld\n",ans);
	return 0;
}
