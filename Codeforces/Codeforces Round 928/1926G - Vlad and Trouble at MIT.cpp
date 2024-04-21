#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
char s[MAX];
vector<int> mp[MAX];
int dp[MAX][2];
void dfs(int x)
{
	if(s[x]=='C') dp[x][0]=dp[x][1]=0;
	else if(s[x]=='S') dp[x][0]=0,dp[x][1]=INF;
	else if(s[x]=='P') dp[x][1]=0,dp[x][0]=INF;
	for(auto &to:mp[x])
	{
		dfs(to);
		if(s[to]=='C')
		{
			if(dp[x][0]!=INF) dp[x][0]+=min(dp[to][0],dp[to][1]+1);
			if(dp[x][1]!=INF) dp[x][1]+=min(dp[to][1],dp[to][0]+1);
		}
		else if(s[to]=='S')
		{
			if(dp[x][1]!=INF) dp[x][1]+=min(dp[to][0],dp[to][1])+1;
			if(dp[x][0]!=INF) dp[x][0]+=dp[to][0];
		}
		else if(s[to]=='P')
		{
			if(dp[x][0]!=INF) dp[x][0]+=min(dp[to][0],dp[to][1])+1;
			if(dp[x][1]!=INF) dp[x][1]+=dp[to][1];
		}
	}
//	printf("%d %d %d\n",x,dp[x][0],dp[x][1]);
}
int main()
{
	int t,n,i,fa;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<=n;i++) mp[i].clear();
		for(i=2;i<=n;i++)
		{
			scanf("%d",&fa);
			mp[fa].push_back(i);
		}
		scanf("%s",s+1);
		dfs(1);
		printf("%d\n",min(dp[1][0],dp[1][1]));
	}
	return 0;
}
