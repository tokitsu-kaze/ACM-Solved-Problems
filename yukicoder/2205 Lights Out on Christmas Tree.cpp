#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
const int MAX=2e5+10;
vector<int> mp[MAX];
int col[MAX],ans;
void dfs(int x,int fa)
{
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		dfs(to,x);
		if(col[to]==0)
		{
			col[to]^=1;
			col[x]^=1;
			ans++;
		}
	}
}
int main()
{
	int n,i,a,b;
	scanf("%d",&n);
	for(i=1;i<=n;i++) mp[i].clear();
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	for(i=1;i<=n;i++) scanf("%d",&col[i]);
	ans=0;
	dfs(1,0);
	if(col[1]==0) ans=-1;
	printf("%d\n",ans);
	return 0;
}
