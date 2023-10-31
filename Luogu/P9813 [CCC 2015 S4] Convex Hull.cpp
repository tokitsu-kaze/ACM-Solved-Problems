#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int MAX=2e3+10;
struct node{int to,t,h;};
vector<node> mp[MAX];
int k,dp[MAX][205],ans,s,t;
void dfs(int x,int nowt,int nowh)
{
	if(nowh>=k) return;
	if(nowt>ans) return;
	if(dp[x][nowh]<nowt) return;
	dp[x][nowh]=nowt;
	if(x==t) ans=min(ans,nowt);
	for(auto &it:mp[x]) dfs(it.to,nowt+it.t,nowh+it.h);
}
int main()
{
	int n,m,i,a,b,h;
	scanf("%d%d%d",&k,&n,&m);
	for(i=1;i<=n;i++)
	{
		mp[i].clear();
		memset(dp[i],0x3f,sizeof dp[i]);
	}
	while(m--)
	{
		scanf("%d%d%d%d",&a,&b,&t,&h);
		mp[a].push_back({b,t,h});
		mp[b].push_back({a,t,h});
	}
	scanf("%d%d",&s,&t);
	ans=INF;
	dfs(s,0,0);
	if(ans==INF) ans=-1;
	printf("%d\n",ans);
	return 0;
}
