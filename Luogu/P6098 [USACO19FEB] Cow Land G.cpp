#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
struct Fenwick_Tree
{
	#define type int
	type bit[MAX];
	int n;
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++) bit[i]=0;
	}
	void init(int _n,type *a)
	{
		n=_n;
		for(int i=1;i<=n;i++)
		{
			a[i]^=a[i-1];
			bit[i]=a[i]^a[i-lowbit(i)];
		}
	}
	int lowbit(int x){return x&(-x);}
	type get(int x)
	{
		type res=0;
		while(x)
		{
			res^=bit[x];
			x-=lowbit(x);
		}
		return res;
	}
	void upd(int x,type v)
	{
		while(x<=n)
		{
			bit[x]^=v;
			x+=lowbit(x);
		}
	}
	type ask(int l,int r)
	{
		if(l>r) return 0;
		if(l-1<=0) return get(r);
		return get(r)^get(l-1);
	}
	#undef type
}tr;
struct Heavy_Light_Decomposition
{
	#define type int
	struct edge{int a,b;type v;};
	struct node{int to;type w;};
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
	int LCA(int x,int y)
	{
		while(top[x]!=top[y])
		{
			if(dep[top[x]]<dep[top[y]]) swap(x,y);
			x=fa[top[x]];
	    }
	    if(dep[x]>dep[y]) swap(x,y);
	    return x;
	}
	//node
	void init_node(type *v)
	{
		tr.init(n);
		for(int i=1;i<=n;i++) tr.upd(dfn[i],v[i]);
	}
	type ask_node(int x,int y)
	{
		type res=0;
		while(top[x]!=top[y])
		{
			if(dep[top[x]]<dep[top[y]]) swap(x,y);
			res^=tr.ask(dfn[top[x]],dfn[x]);
			x=fa[top[x]];
	    }
	    if(dep[x]>dep[y]) swap(x,y);
	    res^=tr.ask(dfn[x],dfn[y]);
	    return res;
	}
	#undef type
}hld;
/*
hld.init(n)
hld.add_edge(a,b,v=0);  a <-> b
hld.work(root);
*/
int v[MAX];
int main()
{
	int n,q,i,a,b,op,x,y;
	scanf("%d%d",&n,&q);
	hld.init(n);
	for(i=1;i<=n;i++) scanf("%d",&v[i]);
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		hld.add_edge(a,b);
	}
	hld.work(1);
	hld.init_node(v);
	while(q--)
	{
		scanf("%d%d%d",&op,&x,&y);
		if(op==1)
		{
			tr.upd(hld.dfn[x],v[x]^y);
			v[x]=y;
		}
		else printf("%d\n",hld.ask_node(x,y));
	}
	return 0;
}
