#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
const int mod=998244353;
vector<int> mp[MAX];
int v[MAX],sz[MAX],s;
ll ans[MAX],res;
void dfs0(int x,int fa)
{
	sz[x]=1;
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		dfs0(to,x);
		sz[x]+=sz[to];
		res+=1LL*sz[to]*(v[x]^v[to]);
	}
}
void dfs(int x,int fa)
{
	ans[x]=res;
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		sz[x]-=sz[to];
		res+=1LL*sz[x]*(v[x]^v[to]);
		res-=1LL*sz[to]*(v[x]^v[to]);
		sz[to]+=sz[x];
		dfs(to,x);
		sz[to]-=sz[x];
		res-=1LL*sz[x]*(v[x]^v[to]);
		res+=1LL*sz[to]*(v[x]^v[to]);
		sz[x]+=sz[to];
	}
}
int main()
{
	int T,n,i,a,b;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			mp[i].clear();
			ans[i]=0;
			scanf("%d",&v[i]);
		}
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			mp[a].push_back(b);
			mp[b].push_back(a);
		}
		res=0;
		dfs0(1,0);
		dfs(1,0);
		for(i=1;i<=n;i++) printf("%lld%c",ans[i]," \n"[i==n]);
	}
	return 0;
}

