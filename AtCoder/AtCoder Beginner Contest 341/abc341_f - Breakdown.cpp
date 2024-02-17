#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=5e3+10;
vector<int> mp[MAX];
int w[MAX],id[MAX];
ll v[MAX],dp[MAX];
ll dfs(int x,int fa)
{
	int i;
	ll v,dp2[MAX];
	if(dp[x]!=-1) return dp[x];
	memset(dp2,0,sizeof dp2);
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		if(w[to]>=w[x]) continue;
		v=dfs(to,x);
		for(i=w[x]-1;i>=w[to];i--) dp2[i]=max(dp2[i],dp2[i-w[to]]+v);
	}
	for(i=0;i<w[x];i++) dp[x]=max(dp[x],dp2[i]+1);
	return dp[x];
}
int main()
{
	int n,m,i,a,b;
	ll ans;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		mp[i].clear();
		id[i]=i;
	}
	while(m--)
	{
		scanf("%d%d",&a,&b);
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	for(i=1;i<=n;i++) scanf("%d",&w[i]);
	for(i=1;i<=n;i++) scanf("%lld",&v[i]);
	sort(id+1,id+1+n,[&](int x,int y){
		return w[x]>w[y];
	});
	ans=0;
	memset(dp,-1,sizeof dp);
	for(i=1;i<=n;i++)
	{
		ans+=v[id[i]]*dfs(id[i],0);
	//	printf("%d %lld %lld\n",id[i],v[id[i]],dfs(id[i],0));
	}
	printf("%lld\n",ans);
	return 0;
}
