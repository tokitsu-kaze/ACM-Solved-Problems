#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
vector<int> mp[MAX];
int sz[MAX],k,n;
ll ans;
void dfs(int x,int fa)
{
	sz[x]=1;
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		dfs(to,x);
		sz[x]+=sz[to];
	}
	if(sz[x]>=k) ans+=n-sz[x]+1;
	else ans++;
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		if(n-sz[to]>=k) ans+=sz[to];
	}
}
int main()
{
	int T,i,a,b;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;i++) mp[i].clear();
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			mp[a].push_back(b);
			mp[b].push_back(a);
		}
		ans=0;
		dfs(1,0);
		printf("%lld\n",ans);
	}
	return 0;
}
