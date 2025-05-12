#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct LCA
{
	static const int N=MAX;
	static const int LOG=log2(N)+2;
	int fa[LOG][N],dep[N];
	vector<int> *mp;
	void dfs(int x,int pre)
	{
		int i;
		fa[0][x]=pre;
		for(i=1;i<LOG;i++) fa[i][x]=fa[i-1][fa[i-1][x]];
		for(auto &to:mp[x])
		{
			if(to==pre) continue;
			dep[to]=dep[x]+1;
			dfs(to,x);
		}
	}
	void work(int n,int root,vector<int> *_mp)
	{
		mp=_mp;
		for(int j=0;j<LOG;j++) fa[j][0]=0;
		dep[root]=0;
		dfs(root,0);
	}
	int go(int x,int d)
	{
		for(int i=0;i<LOG;i++)
		{
			if((d>>i)&1) x=fa[i][x];
		}
		return x;
	}
	int lca(int x,int y)
	{
		if(dep[x]<dep[y]) swap(x,y);
		x=go(x,dep[x]-dep[y]);
		if(x==y) return x;
		for(int i=LOG-1;~i;i--)
		{
			if(fa[i][x]!=fa[i][y])
			{
				x=fa[i][x];
				y=fa[i][y];
			}
		}
		return fa[0][x];
	}
}lca;
/*
O(nlogn)-O(logn)
lca.work(n,root,mp);
*/
vector<int> mp[MAX];
int ra[MAX],rb[MAX];
void dfs(int x,int fa)
{
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		dfs(to,x);
		ra[x]|=ra[to];
		rb[x]|=rb[to];
	}
}
int main()
{
	int n,d,i,a,b,m,ans;
	scanf("%d%d",&n,&d);
	for(i=1;i<=n;i++)
	{
		mp[i].clear();
		ra[i]=rb[i]=0;
	}
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	lca.work(n,1,mp);
	scanf("%d",&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d",&a);
		ra[a]=1;
		rb[lca.go(a,d)]=1;
	}
	scanf("%d",&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d",&a);
		rb[a]=1;
		ra[lca.go(a,d)]=1;
	}
	dfs(1,0);
	ans=0;
	for(i=2;i<=n;i++)
	{
		if(ra[i]) ans+=2;
		if(rb[i]) ans+=2;
	}
	printf("%d\n",ans);
	return 0;
}
