#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
vector<int> mp[MAX];
int fa[MAX],a[MAX],b[MAX],sz[MAX];
ll sum[MAX];
void dfs(int x,int pre)
{
	fa[x]=pre;
	sz[x]=1;
	for(auto &to:mp[x])
	{
		if(to==pre) continue;
		dfs(to,x);
		sz[x]+=sz[to];
	}
}
void dfs2(int x,int pre)
{
	for(auto &to:mp[x])
	{
		if(to==pre) continue;
		sum[to]+=sum[x];
		dfs2(to,x);
	}
}
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		mp[i].clear();
		sum[i]=0;
	}
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
		mp[a[i]].push_back(b[i]);
		mp[b[i]].push_back(a[i]);
	}
	dfs(1,0);
	for(i=1;i<n;i++)
	{
		if(fa[a[i]]==b[i]) swap(a[i],b[i]);
		if(sz[b[i]]>n-sz[b[i]]) sum[b[i]]+=i;
		else
		{
			sum[1]+=i;
			sum[b[i]]-=i;
		}
	}
	dfs2(1,0);
	for(i=1;i<=n;i++) printf("%lld%c",sum[i]," \n"[i==n]);
	return 0;
}
