#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
struct edge{int to,w;};
vector<edge> mp[MAX];
int v[MAX];
ll ans;
void dfs(int x,int fa)
{
	for(auto &it:mp[x])
	{
		if(it.to==fa) continue;
		dfs(it.to,x);
		ans+=1LL*abs(v[it.to])*it.w;
		v[x]+=v[it.to];
	}
}
int main()
{
	int n,i,a,b,c;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&v[i]);
		mp[i].clear();
	}
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
