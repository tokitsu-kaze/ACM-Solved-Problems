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
	int n,m,i,a,b,q,op,x;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) mp[i].clear();
	while(m--)
	{
		scanf("%d%d",&a,&b);
		mp[b].push_back(a);
	}
	memset(vis,0,sizeof vis);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&op,&x);
		if(op==1) dfs(x);
		else
		{
			if(vis[x]) puts("Yes");
			else puts("No");
		}
	}
	return 0;
}
