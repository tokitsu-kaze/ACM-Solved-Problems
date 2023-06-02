#include <bits/stdc++.h>
using namespace std;
struct node{int x,w;};
vector<node> mp[105];
int dp[105][105],sz[105];
void dfs(int x,int fa)
{
	int i,j;
	sz[x]=0;
	for(auto &to:mp[x])
	{
		if(to.x==fa) continue;
		dfs(to.x,x);
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
	int n,k,i,a,b,c;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++) mp[i].clear();
	for(i=1;i<n;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		mp[a].push_back({b,c});
		mp[b].push_back({a,c});
	}
	memset(dp,0,sizeof dp);
	dfs(1,0);
	printf("%d\n",dp[1][k]);
	return 0;
}
