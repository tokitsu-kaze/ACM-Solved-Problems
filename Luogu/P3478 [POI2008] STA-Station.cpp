#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e6+10;
vector<int> mp[MAX];
int sz[MAX],n,pos;
ll now,ans;
void dfs0(int x,int fa)
{
	sz[x]=1;
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		dfs0(to,x);
		sz[x]+=sz[to];
	}
	now+=sz[x];
}
void dfs(int x,int fa)
{
	if(ans<now)
	{
		ans=now;
		pos=x;
	}
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		now+=-sz[to]+(n-sz[to]);
		dfs(to,x);
		now-=-sz[to]+(n-sz[to]);
	}
}
int main()
{
	int i,a,b;
	scanf("%d",&n);
	for(i=1;i<=n;i++) mp[i].clear();
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	now=0;
	dfs0(1,0);
	ans=now;
	pos=1;
	dfs(1,0);
	printf("%lld\n",pos);
	return 0;
}
