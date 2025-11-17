#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e5+10;
vector<int> mp[MAX];
int k;
ll dp[MAX][6][3],v[MAX];
void dfs(int x,int fa)
{
	int i,j;
	ll mx[6][3];
	memset(mx,-0x3f,sizeof mx);
	for(i=0;i<=k;i++) mx[i][0]=0;
	mx[0][1]=dp[x][0][1]=v[x];
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		dfs(to,x);
		for(i=0;i<=k;i++)
		{
			for(j=0;j<=i;j++)
			{
				dp[x][i][0]=max(dp[x][i][0],mx[i-j][0]+max(dp[to][j][0],dp[to][j][2]));
				if(j>0) dp[x][i][0]=max(dp[x][i][0],mx[i-j][0]+dp[to][j-1][1]);
				if(i-j-1>=0) dp[x][i][0]=max(dp[x][i][0],mx[i-j-1][0]+dp[to][j][1]);
				
				dp[x][i][1]=max(dp[x][i][1],mx[i-j][0]+dp[to][j][1]+v[x]);
				dp[x][i][1]=max(dp[x][i][1],mx[i-j][1]+max(dp[to][j][0],dp[to][j][2]));
				
				dp[x][i][2]=max(dp[x][i][2],mx[i-j][2]+max(dp[to][j][0],dp[to][j][2]));
				if(j>0) dp[x][i][2]=max(dp[x][i][2],mx[i-j][1]+dp[to][j-1][1]);
				if(j>0) dp[x][i][2]=max(dp[x][i][2],mx[i-j][2]+dp[to][j-1][1]);
				if(i-j-1>=0) dp[x][i][2]=max(dp[x][i][2],mx[i-j-1][1]+dp[to][j][1]);
				if(i-j-1>=0) dp[x][i][2]=max(dp[x][i][2],mx[i-j-1][2]+dp[to][j][1]);
			}
		}
		for(i=0;i<=k;i++)
		{
			mx[i][0]=max(mx[i][0],dp[x][i][0]);
			mx[i][1]=max(mx[i][1],dp[x][i][1]);
			mx[i][2]=max(mx[i][2],dp[x][i][2]);
		}
	}
}

int main()
{
	int n,i,a,b;
	ll ans;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
	{
		mp[i].clear();
		scanf("%lld",&v[i]);
		memset(dp[i],-0x3f,sizeof dp[i]);
	}
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	dfs(1,0);
	ans=0;
	for(i=0;i<=k;i++)
	{
		ans=max({ans,dp[1][i][0],dp[1][i][2]});
		if(i>0) ans=max(ans,dp[1][i-1][1]);
	}
	printf("%lld\n",ans);
	return 0;
}
/*
4 2
1 2 4 8
1 2
1 3
1 4
*/
