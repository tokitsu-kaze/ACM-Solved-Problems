#include <bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
vector<int> mp[105];
int v[105],sum_dis[105];
void dfs(int x,int fa,int dis,int w)
{
	sum_dis[x]+=dis*w;
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		dfs(to,x,dis+1,w);
	}
}
int main()
{
	int n,i,w,a,b,ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++) mp[i].clear();
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d",&v[i],&a,&b);
		if(a)
		{
			mp[i].push_back(a);
			mp[a].push_back(i);
		}
		if(b)
		{
			mp[i].push_back(b);
			mp[b].push_back(i);
		}
	}
	memset(sum_dis,0,sizeof sum_dis);
	for(i=1;i<=n;i++) dfs(i,0,0,v[i]);
	ans=INF;
	for(i=1;i<=n;i++) ans=min(ans,sum_dis[i]);
	printf("%d\n",ans);
	return 0;
}
