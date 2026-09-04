#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
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
	int get_len(int a,int b){return dep[a]+dep[b]-2*dep[lca(a,b)];}
}lca;
/*
O(nlogn)-O(logn)
lca.work(n,root,mp);
*/
vector<int> mp[MAX];
int a[MAX],ans[MAX];
void dfs(int x,int fa)
{
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		dfs(to,x);
		ans[x]+=ans[to];
	}
}
int main()
{
	int n,i,x,y,z;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		mp[i].clear();
		ans[i]=0;
	}
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		mp[x].push_back(y);
		mp[y].push_back(x);
	}
	lca.work(n,1,mp);
	for(i=1;i<n;i++)
	{
		z=lca.lca(a[i],a[i+1]);
		ans[a[i]]++;
		ans[a[i+1]]++;
		ans[z]--;
		ans[lca.fa[0][z]]--;
	}
	dfs(1,0);
	ans[a[1]]++;
	for(i=1;i<=n;i++) printf("%d\n",ans[i]-1);
	return 0;
}
