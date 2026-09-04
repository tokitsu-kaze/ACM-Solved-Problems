#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
vector<int> mp[MAX],res;
int pre[MAX],col[MAX],vis[MAX];
void dfs(int x,int fa,int c)
{
	vis[x]=1;
	if(res.size()>0) return;
	pre[x]=fa;
	col[x]=c;
	for(auto &to:mp[x])
	{
		if(res.size()>0) return;
		if(to==fa) continue;
		if(vis[to])
		{
			if(col[to]==col[x])
			{
				int now=x;
				while(1)
				{
					res.push_back(now);
					if(now==to) break;
					now=pre[now];
				}
				return;
			}
		}
		else dfs(to,x,c^1);
	}
}
int main()
{
	int T,n,m,i,a,b;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
		{
			mp[i].clear();
			col[i]=vis[i]=0;
		}
		while(m--)
		{
			scanf("%d%d",&a,&b);
			mp[a].push_back(b);
			mp[b].push_back(a);
		}
		res.clear();
		dfs(1,0,0);
		if(res.size()==0) puts("-1");
		else
		{
			printf("%d\n",(int)res.size());
			for(i=0;i<res.size();i++) printf("%d%c",res[i]," \n"[i+1==res.size()]);
		}
	}
	return 0;
}
