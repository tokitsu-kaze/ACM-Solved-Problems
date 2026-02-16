#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
vector<int> mp[MAX];
int dp[MAX][2];
void dfs(int x,int fa)
{
	dp[x][0]=0;
	dp[x][1]=1;
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		dfs(to,x);
		dp[x][0]+=dp[to][1];
		dp[x][1]+=min(dp[to][0],dp[to][1]);
	}
}
int main()
{
	int n,i,x,k,y;
	scanf("%d",&n);
	for(i=1;i<=n;i++) mp[i].clear();
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		x++;
		scanf("%d",&k);
		while(k--)
		{
			scanf("%d",&y);
			y++;
			mp[x].push_back(y);
			mp[y].push_back(x);
		}
	}
	dfs(1,0);
	printf("%d\n",min(dp[1][0],dp[1][1]));
	return 0;
}
