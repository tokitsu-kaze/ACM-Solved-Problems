#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
const int mod=1e9+7;
vector<int> mp[MAX];
ll dp[MAX][2];
void dfs(int x,int fa)
{
	dp[x][0]=dp[x][1]=1;
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		dfs(to,x);
		dp[x][0]=(dp[x][0]*dp[to][0]+dp[x][0]*dp[to][1])%mod;
		dp[x][1]=dp[x][1]*dp[to][0]%mod;
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
	printf("%lld\n",(dp[1][0]+dp[1][1])%mod);
	return 0;
}
