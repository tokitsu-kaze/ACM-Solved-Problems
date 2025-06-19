#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
const int mod=1e9+7;
ll pw2[MAX];
int dep[MAX],lca_dep;
vector<int> mp[MAX],res;
void dfs(int x,int fa)
{
	int f=0;
	dep[x]=dep[fa]+1;
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		dfs(to,x);
		f=1;
	}
	if((mp[x].size()==3) || (mp[x].size()==2 && x==1)) lca_dep=dep[x];
	if(f==0) res.push_back(dep[x]);
}
int main()
{
	int T,n,i,a,b;
	pw2[0]=1;
	for(i=1;i<MAX;i++) pw2[i]=pw2[i-1]*2%mod;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) mp[i].clear();
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			mp[a].push_back(b);
			mp[b].push_back(a);
		}
		res.clear();
		dep[0]=0;
		dfs(1,0);
		if(res.size()>2)
		{
			puts("0");
			continue;
		}
		if(res.size()==1) printf("%lld\n",pw2[n]);
		else
		{
			a=res[0];
			b=res[1];
			if(a<b) swap(a,b);
			if(a==b) printf("%lld\n",2*pw2[lca_dep]%mod);
			else printf("%lld\n",pw2[lca_dep]*(pw2[a-b]+pw2[a-b-1])%mod);
		}
	}
	return 0;
}
