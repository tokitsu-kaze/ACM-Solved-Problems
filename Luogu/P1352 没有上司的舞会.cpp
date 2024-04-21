#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
vector<int> mp[MAX];
int dp[MAX][2],v[MAX],in[MAX];
void dfs(int x)
{
	dp[x][0]=0;
	dp[x][1]=v[x];
	for(auto &to:mp[x])
	{
		dfs(to);
		dp[x][1]+=dp[to][0];
		dp[x][0]+=max(dp[to][0],dp[to][1]);
	}
}
int main()
{
	int n,i,x,y,rt;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		mp[i].clear();
		in[i]=0;
		scanf("%d",&v[i]);
	}
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		mp[y].push_back(x);
		in[x]++;
	}
	rt=1;
	for(i=1;i<=n;i++)
	{
		if(in[i]==0) rt=i;
	}
	dfs(rt);
	printf("%d\n",max(dp[rt][0],dp[rt][1]));
	return 0;
}
