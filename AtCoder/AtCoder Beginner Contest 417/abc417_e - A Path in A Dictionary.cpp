#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1000+10;
vector<int> mp[MAX],res;
int y,ok,vis[MAX],tag[MAX];
void dfs(int x)
{
	if(tag[x]||vis[x]) return;
	vis[x]=1;
	if(x==y) ok=1;
	if(ok) return;
	for(auto &to:mp[x]) dfs(to);
}
int main()
{
	int T,n,m,i,x,t,a,b;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d",&n,&m,&x,&y);
		for(i=1;i<=n;i++)
		{
			mp[i].clear();
			tag[i]=0;
		}
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&a,&b);
			mp[a].push_back(b);
			mp[b].push_back(a);
		}
		for(i=1;i<=n;i++) sort(mp[i].begin(),mp[i].end());
		vector<int> res;
		while(1)
		{
			res.push_back(x);
			tag[x]=1;
			if(x==y) break;
			for(auto &to:mp[x])
			{
				if(tag[to]) continue;
				ok=0;
				memset(vis,0,sizeof vis);
				dfs(to);
				if(ok)
				{
					x=to;
					break;
				}
			}
		}
		for(i=0;i<res.size();i++) printf("%d%c",res[i]," \n"[i+1==res.size()]);
	}
	return 0;
}

