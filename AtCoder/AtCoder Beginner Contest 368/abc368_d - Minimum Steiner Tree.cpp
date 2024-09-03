#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e5+10;
int dp[MAX];
bool tag[MAX];
vector<int> mp[MAX];
void dfs(int x,int fa)
{
	dp[x]=0;
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		dfs(to,x);
		dp[x]+=dp[to];
	}
	if(tag[x] || dp[x]) dp[x]++;
}
int main()
{
	int n,k,i,a,b;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
	{
		mp[i].clear();
		tag[i]=0;
	}
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	for(i=1;i<=k;i++)
	{
		scanf("%d",&a);
		tag[a]=1;
	}
	dfs(a,0);
	printf("%d\n",dp[a]);
	return 0;
}
