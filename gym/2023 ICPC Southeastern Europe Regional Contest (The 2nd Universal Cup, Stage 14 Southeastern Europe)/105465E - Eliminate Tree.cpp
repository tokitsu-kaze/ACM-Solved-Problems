#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
vector<int> mp[MAX];
int dp[MAX][2];
void dfs(int x,int fa)
{
	int sum=0;
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		dfs(to,x);
		sum+=dp[to][0];
	}
	dp[x][1]=sum;
	dp[x][0]=sum+2;
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		dp[x][0]=min(dp[x][0],sum-dp[to][0]+dp[to][1]+1);
	}
}
int main()
{
	int n,i,a,b;
	scanf("%d",&n);
	for(i=1;i<=n;i++) mp[i].clear();
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	dfs(1,0);
	printf("%d\n",dp[1][0]);
	return 0;
}
/*
dp[x][0/1] 删除以x为子树的代价，不保留/保留x
- 如果不保留 x：
要么出边都不保留，然后多一次操作；
要么出边恰好有一个保留。
- 如果保留 x：
出边都不保留
*/
