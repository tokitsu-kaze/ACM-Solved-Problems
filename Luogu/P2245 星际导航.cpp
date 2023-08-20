#include <bits/stdc++.h>
using namespace std;
const int MAX=2e5+10;
struct Disjoint_Set_Union
{
	int pre[MAX];
	void init(int n)
	{
		int i;
		for(i=1;i<=n;i++) pre[i]=i;
	}
	int find(int x)
	{
		if(pre[x]!=x) pre[x]=find(pre[x]);
		return pre[x];
	}
	bool merge(int a,int b)
	{
		int ra,rb;
		ra=find(a);
		rb=find(b);
		if(ra!=rb)
		{
			pre[ra]=rb;
			return 1;
		}
		return 0;
	}
}dsu;
struct LCA
{
	static const int N=MAX;
	static const int LOGN=log2(N)+3;
	int fa[N][LOGN],dep[N],limt,bin[LOGN];
	void dfs(int x,int pre,vector<int> mp[])
	{
		int i;
		for(i=1;bin[i]<=dep[x];i++) fa[x][i]=fa[fa[x][i-1]][i-1];
		for(auto &to:mp[x])
		{
			if(to==pre) continue;
			dep[to]=dep[x]+1;
			fa[to][0]=x;
			dfs(to,x,mp);
		}
	}
	void work(int n,vector<int> mp[])
	{
		int i;
		for(limt=1;(1<<(limt-1))<n;limt++);
		for(i=bin[0]=1;i<=limt;i++) bin[i]=(bin[i-1]<<1);
		for(i=0;i<=n;i++) memset(fa[i],0,sizeof fa[i]);
		for(i=1;i<=n;i++)
		{
			if(dsu.find(i)==i)
			{
				dep[i]=0;
				dfs(i,-1,mp);
			}
		}
	}
	int go(int x,int d)
	{
		for(int i=0;i<=limt&&d;i++)
		{
			if(bin[i]&d)
			{
				d^=bin[i];
				x=fa[x][i];
			}
		}
		return x;
	}
	int lca(int x,int y)
	{
		if(dep[x]<dep[y]) swap(x,y);
		x=go(x,dep[x]-dep[y]);
		if(x==y) return x;
		for(int i=limt;~i;i--)
		{
			if(fa[x][i]!=fa[y][i])
			{
				x=fa[x][i];
				y=fa[y][i];
			}
		}
		return fa[x][0];
	}
}lca;
/*
O(nlogn)-O(logn)
lca.work(n,root,mp);
*/
struct Kruskal_Tree
{
	#define type int
	#define inf INF
	struct edge{int x,y;type w;};
	vector<edge> e;
	void init(){e.clear();}
	void add_edge(int a,int b,type w){e.push_back({a,b,w});}
	int build_kruskal_tree(int n,vector<int> *mp,type *w)
	{
		int rt,x,y,i;
		for(i=1;i<=2*n-1;i++)
		{
			mp[i].clear();
			w[i]=0;
		}
		dsu.init(2*n-1);
		sort(e.begin(),e.end(),[&](edge x,edge y){
			return x.w<y.w;
		});
		rt=n;
		for(auto &it:e)
		{
			x=dsu.find(it.x);
			y=dsu.find(it.y);
			if(x==y) continue;
			rt++;
			w[rt]=it.w;
			mp[rt].push_back(x);
			mp[rt].push_back(y);
			dsu.merge(x,rt);
			dsu.merge(y,rt);
		}
		return rt;
	}
	#undef type
	#undef inf
}krsk;
vector<int> mp[MAX];
int w[MAX];
int main()
{
	int n,m,i,a,b,c,q;
	scanf("%d%d",&n,&m);
	krsk.init();
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		krsk.add_edge(a,b,c);
	}
	krsk.build_kruskal_tree(n,mp,w);
	lca.work(2*n-1,mp);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&a,&b);
		if(dsu.find(a)!=dsu.find(b)) puts("impossible");
		else printf("%d\n",w[lca.lca(a,b)]);
	}
	return 0;
}
