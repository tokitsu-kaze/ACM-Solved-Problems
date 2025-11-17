#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
vector<int> mp[MAX];
int v[MAX];
ll dp[MAX][4],ans;
void dfs(int x,int fa)
{
	int i;
	ll tmp;
	memset(dp[x],-0x3f,sizeof dp[x]);
	dp[x][0]=v[x];
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		dfs(to,x);
		tmp=max({dp[to][0],
				 dp[to][1]-v[to],
				 dp[to][2]+v[to],
				 dp[to][3]});
		dp[x][3]=max(dp[x][3],dp[x][3]+tmp);
		dp[x][3]=max(dp[x][3],dp[x][2]+v[x]+tmp);
		dp[x][2]=max(dp[x][2],dp[x][1]-v[x]+tmp);
		dp[x][1]=max(dp[x][1],dp[x][0]+tmp);
	}
	for(i=0;i<=3;i++) ans=max(ans,dp[x][i]);
}
int main()
{
	int T,n,i,a,b;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&v[i]);
			mp[i].clear();
		}
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			mp[a].push_back(b);
			mp[b].push_back(a);
		}
		ans=0;
		dfs(1,0);
		printf("%lld\n",ans);
	}
	return 0;
}
