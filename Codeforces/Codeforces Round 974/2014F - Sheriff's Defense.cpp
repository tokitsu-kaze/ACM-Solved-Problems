#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int v[MAX],c;
ll dp[MAX][2];
vector<int> mp[MAX];
void dfs(int x,int fa)
{
	dp[x][0]=0;
	dp[x][1]=v[x];
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		dfs(to,x);
		dp[x][0]+=max(dp[to][0],dp[to][1]);
		dp[x][1]+=max(dp[to][0],dp[to][1]-2*c);
	}
}
int main()
{
	int T,n,i,a,b;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&c);
		for(i=1;i<=n;i++) mp[i].clear();
		for(i=1;i<=n;i++) scanf("%d",&v[i]);
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			mp[a].push_back(b);
			mp[b].push_back(a);
		}
		dfs(1,0);
		printf("%lld\n",max(dp[1][0],dp[1][1]));
	}
	return 0;
}
