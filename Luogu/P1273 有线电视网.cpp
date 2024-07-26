#include <bits/stdc++.h>
using namespace std;
const int MAX=3000+10;
struct node{int to,w;};
vector<node> mp[MAX];
int v[MAX],dp[MAX][MAX],n,m,sz[MAX];
void dfs(int x)
{
	int i,j;
	memset(dp[x],-0x3f,sizeof dp[x]);
	dp[x][0]=0;
	sz[x]=0;
	if(x>=n-m+1)
	{
		dp[x][1]=v[x];
		sz[x]=1;
	}
	for(auto &it:mp[x])
	{
		dfs(it.to);
		for(i=sz[x]+sz[it.to];i>=0;i--)
		{
			for(j=1;j<=sz[it.to]&&i-j>=0;j++)
			{
				dp[x][i]=max(dp[x][i],dp[x][i-j]+dp[it.to][j]-it.w);
			}
		}
		sz[x]+=sz[it.to];
	}
}
int main()
{
	int i,x,y,k,ans;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n-m;i++)
	{
		mp[i].clear();
		v[i]=0;
		scanf("%d",&k);
		while(k--)
		{
			scanf("%d%d",&x,&y);
			mp[i].push_back({x,y});
		}
	}
	for(i=n-m+1;i<=n;i++) scanf("%d",&v[i]);
	dfs(1);
	ans=0;
	for(i=m;i;i--)
	{
//		printf("%d %d\n",i,dp[1][i]);
		if(dp[1][i]>=0)
		{
			ans=i;
			break;
		}
	}
	printf("%d\n",ans);
	return 0;
}
