#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
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
int x[MAX],y[MAX],z[MAX],d[MAX],cnt[MAX],n,m;
int l[MAX],r[MAX],dfn;
void dfs(int x,int fa)
{
	l[x]=++dfn;
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		dfs(to,x);
	}
	r[x]=dfn;
}
int ck(int mx)
{
	int i,j,c,tot;
	tot=0;
	for(i=0;i<=n;i++) cnt[i]=0;
	for(i=1;i<=m;i++)
	{
		if(d[i]<=mx) continue;
		if(2*mx<d[i]) return 0;
		tot++;
		for(j=0;j<2;j++)
		{
			if(lca.get_len(x[i],z[i])>mx)
			{
				c=lca.go(x[i],mx);
				cnt[l[c]]++;
				cnt[r[c]+1]--;
			}
			else
			{
				c=lca.go(y[i],d[i]-mx-1);
				cnt[1]++;
				cnt[l[c]]--;
				cnt[r[c]+1]++;
			}
			swap(x[i],y[i]);
		}
	}
	for(i=1;i<=n;i++)
	{
		cnt[i]+=cnt[i-1];
		if(cnt[i]==2*tot) return 1;
	}
	return 0;
}
int main()
{
	int i,a,b,l,r,mid;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) mp[i].clear();
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	dfs(1,0);
	lca.work(n,1,mp);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		d[i]=lca.get_len(x[i],y[i]);
		z[i]=lca.lca(x[i],y[i]);
	}
	l=0;
	r=n;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(ck(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d\n",l);
	return 0;
}
/*
二分答案，如果 mid 超过这对点的距离，那可以不用考虑这一对点。
对于不满足的每一对点，看哪些点能当 lca。再根据这些点当 lca，看哪些点能当根。
如果一对点同时考虑，会发现比较复杂，此时可以将一对点分开考虑。
最后假设有 tot 对点要考虑，那么被覆盖的次数就是 2*tot。
发现能当根的是一些子树，使用dfs序更新即可。
*/
