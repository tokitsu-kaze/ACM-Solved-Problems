#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e4+10;
const int K=20;
int dp[MAX][K+5];
vector<int> mp[MAX];
void dfs(int x,int fa)
{
	int i,j,mn;
	memset(dp[x],0,sizeof dp[x]);
	for(i=1;i<=K;i++) dp[x][i]=i;
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		dfs(to,x);
		for(i=1;i<=K;i++)
		{
			mn=INF;
			for(j=1;j<=K;j++)
			{
				if(j==i) continue;
				mn=min(mn,dp[to][j]);
			}
			dp[x][i]+=mn;
		}
	}
}
int main()
{
	int n,i,a,b,ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++) mp[i].clear();
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	dfs(1,0);
	ans=INF;
	for(i=1;i<=K;i++) ans=min(ans,dp[1][i]);
	printf("%d\n",ans);
	return 0;
}
