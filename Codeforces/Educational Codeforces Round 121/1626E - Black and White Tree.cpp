#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
vector<int> mp[MAX];
int c[MAX],tag[MAX],dp[MAX],sz[MAX],ans[MAX];
void dfs0(int x,int fa)
{
	sz[x]=c[x];
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		dfs0(to,x);
		sz[x]+=sz[to];
		if(sz[to]>1 && dp[to]) dp[x]=1;
	}
}
void dfs(int x,int fa)
{
	int cnt=0;
	for(auto &to:mp[x])
	{
		if(sz[to]>1 && dp[to]) cnt++;
//		printf("%d %d %d %d\n",x,to,sz[to],dp[to]);
	}
	if(cnt>0) ans[x]=1;
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		dp[x]=0;
		if(sz[to]>1 && dp[to]) cnt--;
		if(cnt>0 || tag[x]) dp[x]=1;
		sz[x]-=sz[to];
		sz[to]+=sz[x];
		dfs(to,x);
		sz[to]-=sz[x];
		sz[x]+=sz[to];
		if(sz[to]>1 && dp[to]) cnt++;
		if(cnt>0 || tag[x]) dp[x]=1;
	}
}
int main()
{
	int n,i,a,b;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
		mp[i].clear();
		ans[i]=dp[i]=tag[i]=0;
	}
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	for(i=1;i<=n;i++)
	{
		if(c[i]==0) continue;
		ans[i]=1;
		for(auto &to:mp[i]) ans[to]=tag[to]=dp[to]=1;
	}
	dfs0(1,0);
	dfs(1,0);
	for(i=1;i<=n;i++) printf("%d%c",ans[i]," \n"[i==n]);
	return 0;
}
/*
先考虑判定性问题，如何判断一个点是否能走到黑点。
画出样例，考虑顶点4。
感觉从上往下推并不好推，考虑从黑点往上推。
一个黑点 x 的 fa[x] 的子树里如果黑点数>=2，说明可以从 fa[x] 走到 x。
换句话说，如果后继节点可以走到黑点，并且当前点的子树中，黑点数>=2，才能往下走。
然后就直接换根维护子树黑点数即可。
*/
