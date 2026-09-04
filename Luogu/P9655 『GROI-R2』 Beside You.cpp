#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
vector<int> mp[MAX];
char s[MAX];
int ans,tagadd[MAX],tagmv[MAX];
map<int,int> dp[MAX];
void dfs(int x,int fa)
{
	int pos;
	tagadd[x]=tagmv[x]=0;
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		dfs(to,x);
		if(dp[x].size()<dp[to].size())
		{
			swap(dp[x],dp[to]);
			swap(tagadd[x],tagadd[to]);
			swap(tagmv[x],tagmv[to]);
		}
		for(auto &it:dp[to])
		{
			pos=it.first+tagmv[to]-tagmv[x];
			if(!dp[x].count(pos)) dp[x][pos]-=tagadd[x];
			dp[x][pos]+=it.second+tagadd[to];
		}
		dp[to].clear();
	}
	if(s[x]==')') tagmv[x]++;
	else tagmv[x]--;
	tagadd[x]++;
	if(s[x]==')' && !dp[x].count(1-tagmv[x])) dp[x][1-tagmv[x]]=1-tagadd[x];
	while(!dp[x].empty() && (*dp[x].begin()).first+tagmv[x]<0) dp[x].erase(dp[x].begin());
	if(dp[x].count(-tagmv[x])) ans=max(ans,dp[x][-tagmv[x]]+tagadd[x]);
}
int main()
{
	int n,i,a,b;
	scanf("%d",&n);
	scanf("%s",s+1);
	for(i=1;i<=n;i++)
	{
		mp[i].clear();
		dp[i].clear();
	}
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	ans=0;
	dfs(1,0);
	printf("%d\n",ans);
	return 0;
}
/*
一棵根为 1 的有根树，每个节点是左右括号之一，
求最大的子连通块满足：
连通块根节点到任意一个叶子的路径都满足括号匹配。

把 ) 看成 1，( 看成-1，自底向上做前缀和。
对于值域，维护子树内前缀和对应的值的最大点数。
每次合并子树时，发现需要支持：单点修改，整体平移，整体加1。
线段树合并没有办法维护整体平移。
只会启发式合并，用map维护，2个log。这能过吗？
*/
