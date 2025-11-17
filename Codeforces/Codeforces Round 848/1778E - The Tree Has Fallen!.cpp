#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct Base
{
	#define type int
	#define mx 30
	type d[mx+1],cnt;
	int p[mx+1];
	void init()
	{
		memset(d,0,sizeof(d));
		memset(p,0,sizeof(p));
		cnt=0;
	}
	bool insert(type x,int pos)
	{
		for(int i=mx;~i;i--)
		{
			if(!(x&(1LL<<i))) continue;
			if(!d[i])
			{
				cnt++;
				d[i]=x;
				p[i]=pos;
				break;
			}
			if(p[i]<pos)
			{
				swap(d[i],x);
				swap(p[i],pos);
			}
			x^=d[i];
		}
		return x>0;
	}
	type ask_max(int pos)
	{
		type res=0;
		for(int i=mx;~i;i--)
		{
			if(p[i]>=pos)
			{
				if((res^d[i])>res) res^=d[i];
			}
		}
		return res;
	}
	void merge(Base x)
	{
		for(int i=mx;~i;i--)
		{
			if(x.d[i]) insert(x.d[i],x.p[i]);
		}
	}
}prebs[MAX],sufbs[MAX];
struct Heavy_Light_Decomposition
{
	#define type int
	struct edge{int a,b;type v;};
	vector<int> mp[MAX];
	vector<edge> e;
	int dep[MAX],fa[MAX],sz[MAX],son[MAX];
	int id[MAX],top[MAX],dfn[MAX],tot;
	int n,rt;
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++) mp[i].clear();
		e.clear();
		e.push_back({0,0,0});
	}
	void add_edge(int a,int b,type v=0)
	{
		e.push_back({a,b,v});
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	void dfs1(int x,int pre,int h)
	{
		int i,to;
		dep[x]=h;
		fa[x]=pre;
		sz[x]=1;
		for(i=0;i<mp[x].size();i++)
		{
			to=mp[x][i];
			if(to==pre) continue;
			dfs1(to,x,h+1);
			sz[x]+=sz[to];
			if(son[x]==-1||sz[to]>sz[son[x]]) son[x]=to;
		}
	}
	void dfs2(int x,int tp)
	{
		int i,to;
		dfn[x]=++tot;
		id[dfn[x]]=x;
		top[x]=tp;
		if(son[x]==-1) return;
		dfs2(son[x],tp);
		for(i=0;i<mp[x].size();i++)
		{
			to=mp[x][i];
			if(to!=son[x]&&to!=fa[x]) dfs2(to,to);
		}
	}
	void work(int _rt)
	{
		rt=_rt;
		for(int i=0;i<=n;i++) son[i]=-1;
		tot=0;
		dfs1(rt,0,0);
		dfs2(rt,rt);
	}
	int lca(int x,int y)
	{
		while(top[x]!=top[y])
		{
			if(dep[top[x]]<dep[top[y]]) swap(x,y);
			x=fa[top[x]];
		}
	    if(dep[x]>dep[y]) swap(x,y);
	    return x;
	}
	int find_yson_toward_x(int x,int y)
	{
		while(top[x]!=top[y])
		{
			if(fa[top[x]]==y) return top[x];
			x=fa[top[x]];
		}
	    return son[y];
	}
	//node
	int a[MAX];
	void init_node(type *v)
	{
		int i;
		for(i=1;i<=n;i++) a[dfn[i]]=v[i];
		prebs[0].init();
		for(i=1;i<=n;i++)
		{
			prebs[i]=prebs[i-1];
			prebs[i].insert(a[i],i);
		}
		sufbs[n+1].init();
		for(i=n;i;i--)
		{
			sufbs[i]=sufbs[i+1];
			sufbs[i].insert(a[i],n-i+1);
		}
	}
	type ask(int l,int r)
	{
		return prebs[r].ask_max(l);
	}
	// sub tree
	void change_root(int x){rt=x;}
	type ask_subtree(int x)
	{
		if(x==rt) return ask(1,n);
		if(dfn[rt]>=dfn[x]&&dfn[rt]<=dfn[x]+sz[x]-1)
		{
			x=find_yson_toward_x(rt,x);
			Base tmp=prebs[dfn[x]-1];
			tmp.merge(sufbs[dfn[x]+sz[x]]);
			return tmp.ask_max(0);
		}
		return ask(dfn[x],dfn[x]+sz[x]-1);
	}
	#undef type
}hld;
/*
hld.init(n)
hld.add_edge(a,b,v=0);  a <-> b
hld.work(rt);
hld.init_node(type *v);
---- subtree ----
hld.change_root(rt);
hld.upd_subtree(x,v);
hld.ask_subtree(x);
*/
int v[MAX];
int main()
{
	int T,n,i,a,b,rt,x,q;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&v[i]);
		hld.init(n);
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			hld.add_edge(a,b);
		}
		hld.work(1);
		hld.init_node(v);
		scanf("%d",&q);
		while(q--)
		{
			scanf("%d%d",&rt,&x);
			hld.change_root(rt);
			printf("%d\n",hld.ask_subtree(x));
		}
	}
	return 0;
}
