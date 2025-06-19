#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int v[MAX];
ll ans[MAX];
vector<int> mp[MAX];
void dfs(int x,int fa,int f,ll a,ll b)
{
	if(f)
	{
		a=max(0LL,a+v[x]);
		b=max(0LL,b-v[x]);
		ans[x]=a;
	}
	else
	{
		a=max(0LL,a-v[x]);
		b=max(0LL,b+v[x]);
		ans[x]=b;
	}
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		dfs(to,x,f^1,a,b);
	}
}
int main()
{
	int T,n,i,a,b;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&v[i]);
			mp[i].clear();
			ans[i]=0;
		}
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			mp[a].push_back(b);
			mp[b].push_back(a);
		}
		dfs(1,0,0,0,0);
		for(i=1;i<=n;i++) printf("%lld%c",ans[i]," \n"[i==n]);
	}
	return 0;
}
