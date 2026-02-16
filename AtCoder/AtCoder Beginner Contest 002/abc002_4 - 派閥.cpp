#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1440+10;
int vis[15][15],n,ans;
vector<int> now;
void dfs(int x)
{
	if(x==n+1)
	{
		for(auto &x:now)
		{
			for(auto &y:now)
			{
				if(!vis[x][y]) return;
			}
		}
		ans=max(ans,(int)now.size());
		return;
	}
	dfs(x+1);
	now.push_back(x);
	dfs(x+1);
	now.pop_back();
}
int main()
{
	int m,i,a,b;
	scanf("%d%d",&n,&m);
	memset(vis,0,sizeof vis);
	while(m--)
	{
		scanf("%d%d",&a,&b);
		vis[a][b]=vis[b][a]=1;
	}
	for(i=1;i<=n;i++) vis[i][i]=1;
	ans=1;
	dfs(1);
	printf("%d\n",ans);
	return 0;
}
