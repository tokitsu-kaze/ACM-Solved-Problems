#include <bits/stdc++.h>
using namespace std;
const int MAX=3e5+10;
vector<int> mp[MAX];
int dp[MAX],ans;
void dfs(int x,int fa)
{
	dp[x]=mp[x].size()+1;
	vector<int> tmp;
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		dfs(to,x);
		tmp.push_back(dp[to]);
	}
	sort(tmp.begin(),tmp.end());
	reverse(tmp.begin(),tmp.end());
	if(tmp.size()>0) dp[x]+=tmp[0]-2;
	ans=max(ans,dp[x]);
	if(tmp.size()>1)
	{
		ans=max(ans,tmp[0]+tmp[1]+(int)mp[x].size()-3);
	}
}
int main()
{
	int n,m,i,a,b;
	scanf("%d%d",&n,&m);
	assert(n-1==m);
	for(i=1;i<=n;i++) mp[i].clear();
	while(m--)
	{
		scanf("%d%d",&a,&b);
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	ans=0;
	dfs(1,0);
//	for(i=1;i<=n;i++) printf("debug: %d %d\n",i,dp[i]);
	printf("%d\n",ans);
	return 0;
}
