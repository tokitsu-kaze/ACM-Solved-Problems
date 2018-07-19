#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=2e5+10;
const ll mod=1e9+7;
vector<int> mp[MAX];
int v[MAX],ans[MAX],g1[MAX];
set<int> g[MAX];
set<int> ::iterator it;
void dfs(int x,int pre)
{
	int i;
	for(it=g[pre].begin();it!=g[pre].end();it++)
	{
		int temp=__gcd(*it,v[x]);
		ans[x]=max(ans[x],temp);
		g[x].insert(temp);
	}
	g[x].insert(g1[pre]);
	ans[x]=max(ans[x],g1[pre]);
	g1[x]=__gcd(v[x],g1[pre]);
	ans[x]=max(ans[x],g1[x]);
	for(i=0;i<sz(mp[x]);i++)
	{
		if(mp[x][i]!=pre)
		{
			dfs(mp[x][i],x);
		}
	}
}
int main()
{
	int n,i,a,b;
	while(~scanf("%d",&n))
	{
		for(i=1;i<=n;i++)
		{
			scanf("%d",&v[i]);
			mp[i].clear();
			g[i].clear();
			g1[i]=0;
			ans[i]=0;
		} 
		for(i=1;i<=n-1;i++)
		{
			scanf("%d%d",&a,&b);
			mp[a].pb(b);
			mp[b].pb(a);
		}
		g[0].clear();
		g1[0]=0;
		g[0].insert(0);
		dfs(1,0);
		for(i=1;i<=n;i++)
		{
			if(i==n) printf("%d\n",ans[i]);
			else printf("%d ",ans[i]);
		}
	}
	return 0;
}