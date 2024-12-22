#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
vector<int> mp[MAX];
int dp[MAX],ans[MAX];
void dfs(int x,int fa)
{
	dp[x]=ans[x]=mp[x].size();
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		dfs(to,x);
		ans[x]=max({ans[x],ans[to],dp[x]+dp[to]-2});
		dp[x]=max(dp[x],dp[to]+(int)mp[x].size()-2);
	}
}
int main()
{
	int T,n,i,a,b;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) mp[i].clear();
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			mp[a].push_back(b);
			mp[b].push_back(a);
		}
		dfs(1,0);
		printf("%d\n",ans[1]);
	}
	return 0;
}
