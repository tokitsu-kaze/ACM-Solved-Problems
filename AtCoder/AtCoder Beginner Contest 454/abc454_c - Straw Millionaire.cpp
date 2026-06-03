#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
vector<int> mp[MAX];
int vis[MAX];
void dfs(int x)
{
	if(vis[x]) return;
	vis[x]=1;
	for(auto &to:mp[x]) dfs(to);
}
int main()
{
	int n,m,i,a,b,ans;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		mp[i].clear();
		vis[i]=0;
	}
	while(m--)
	{
		scanf("%d%d",&a,&b);
		mp[a].push_back(b);
	}
	dfs(1);
	ans=0;
	for(i=1;i<=n;i++) ans+=vis[i];
	printf("%d\n",ans);
	return 0;
}
