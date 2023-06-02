#include <bits/stdc++.h>
using namespace std;
struct node{int x,w;};
vector<node> mp[305];
int dp[305][305],sz[305];
void dfs(int x)
{
	int i,j;
	sz[x]=0;
	for(auto &to:mp[x])
	{
		dfs(to.x);
		sz[x]+=sz[to.x]+1;
		for(i=sz[x];i;i--)
		{
			for(j=i-1;~j;j--)
			{
				dp[x][i]=max(dp[x][i],dp[x][i-j-1]+dp[to.x][j]+to.w);
			}
		}
	//	printf("%d %d %d\n",x,to.x,dp[x][1]);
	}
}
int main()
{
	int n,m,i,a,b;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) mp[i].clear();
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&a,&b);
		mp[a].push_back({i,b});
	}
	memset(dp,0,sizeof dp);
	dfs(0);
	printf("%d\n",dp[0][m]);
	return 0;
}
