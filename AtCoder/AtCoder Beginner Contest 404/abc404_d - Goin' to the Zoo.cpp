#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
vector<int> mp[12];
int n,m,c[12],cnt[105];
ll ans;
void dfs(int x,ll now)
{
	int i;
	if(x==n+1)
	{
		for(i=1;i<=m;i++)
		{
			if(cnt[i]<2) return;
		}
		ans=min(ans,now);
		return;
	}
	dfs(x+1,now);
	for(auto &it:mp[x]) cnt[it]++;
	dfs(x+1,now+c[x]);
	for(auto &it:mp[x]) cnt[it]++;
	dfs(x+1,now+c[x]+c[x]);
	for(auto &it:mp[x]) cnt[it]-=2;
}
int main()
{
	int i,j,k,x;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
		mp[i].clear();
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d",&k);
		for(j=1;j<=k;j++)
		{
			scanf("%d",&x);
			mp[x].push_back(i);
		}
	}
	ans=LLINF;
	dfs(1,0);
	printf("%lld\n",ans);
	return 0;
}
