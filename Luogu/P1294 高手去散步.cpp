#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=20+10;
struct node{int to,w;};
vector<node> mp[MAX];
int vis[MAX],ans;
void dfs(int x,int h)
{
	if(vis[x]) return;
	vis[x]=1;
	ans=max(ans,h);
	for(auto &it:mp[x]) dfs(it.to,h+it.w);
	vis[x]=0;
}
int main()
{
	int n,m,i,a,b,c;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) mp[i].clear();
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		mp[a].push_back({b,c});
		mp[b].push_back({a,c});
	}
	memset(vis,0,sizeof vis);
	ans=0;
	for(i=1;i<=n;i++) dfs(i,0);
	printf("%d\n",ans);
	return 0;
}
