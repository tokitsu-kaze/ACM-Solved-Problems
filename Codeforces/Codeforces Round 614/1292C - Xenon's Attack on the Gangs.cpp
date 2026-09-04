#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3000+10;
vector<int> mp[MAX];
int sz[MAX][MAX],fa[MAX][MAX];
ll dp[MAX][MAX];
void dfs0(int rt,int x,int pre)
{
	sz[rt][x]=1;
	fa[rt][x]=pre;
	for(auto &to:mp[x])
	{
		if(to==pre) continue;
		dfs0(rt,to,x);
		sz[rt][x]+=sz[rt][to];
	}
}
ll dfs(int x,int y)
{
	if(x==y) return 0;
	if(dp[x][y]!=-1) return dp[x][y];
	dp[x][y]=max(dfs(x,fa[x][y]),dfs(fa[y][x],y))+1LL*sz[y][x]*sz[x][y];
	return dp[x][y];
}
int main()
{
	int n,i,j,a,b;
	ll ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++) mp[i].clear();
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	for(i=1;i<=n;i++) dfs0(i,i,0);
	memset(dp,-1,sizeof dp);
	ans=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++) ans=max(ans,dfs(i,j));
	}
	printf("%lld\n",ans);
	return 0;
}
/*
路径mex，每填一个数，贡献增加两个端点size之积。
考虑枚举哪条边填0，dp状态O(n^2)，转移还要O(n^2) ，这样是O(n^5)的。
考虑换一种转移形式，从往外扩变成往里缩，这样每次可以O(1)转移。
然后发现也不用枚举哪条边填0了，直接记忆化一下，复杂度降至O(n^2)。
求端点子树size可以直接O(n^2)预处理，处理每个点为根所有子树的size。
这题就是，换个姿势，复杂度降了好几次方。
*/
