#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
struct Fenwick_Tree
{
	#define type ll
	type bit[MAX][2];
	int n;
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++)
		{
			bit[i][0]=bit[i][1]=0;
		}
	}
	int lowbit(int x){return x&(-x);}
	void _insert(int x,type v)
	{
		for(int i=x;i<=n;i+=lowbit(i))
		{
			bit[i][0]+=v;
			bit[i][1]+=v*(x-1);
		}
	}
	type get(int x)
	{
		type res=0;
		for(int i=x;i;i-=lowbit(i))
		{
			res+=x*bit[i][0]-bit[i][1];
		}
		return res;
	}
	void upd(int l,int r,type v)
	{
		_insert(l,v);
		_insert(r+1,-v);
	}
	type ask(int l,int r)
	{
		if(l-1<=0) return get(r);
		return get(r)-get(l-1);
	}
	#undef type
}tr;
struct Heavy_Light_Decomposition
{
	#define type ll
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
	void init_node()
	{
		tr.init(n);
	}
	void upd_node(int x,int y,type v)
	{
		while(top[x]!=top[y])
		{
			if(dep[top[x]]<dep[top[y]]) swap(x,y);
			tr.upd(dfn[top[x]],dfn[x],v);
			x=fa[top[x]];
	    }
	    if(dep[x]>dep[y]) swap(x,y);
	    tr.upd(dfn[x],dfn[y],v);
	}
	// sub tree
	void upd_subtree(int x,type v){tr.upd(dfn[x],dfn[x]+sz[x]-1,v);}
	type ask_subtree(int x){return tr.ask(dfn[x],dfn[x]+sz[x]-1);}
	#undef type
}hld;
/*
hld.init(n)
hld.add_edge(a,b,v=0);  a <-> b
hld.work(root);
*/
int main()
{
	int n,m,i,a,b,x,y,z;
	char op[11];
	scanf("%d",&n);
	hld.init(n);
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		hld.add_edge(a+1,b+1);
	}
	hld.work(1);
	hld.init_node();
	scanf("%d",&m);
	while(m--)
	{
		scanf("%s%d",op,&x);
		if(op[0]=='A')
		{
			scanf("%d%d",&y,&z);
			hld.upd_node(x+1,y+1,z);
		}
		else printf("%lld\n",hld.ask_subtree(x+1));
	}
	return 0;
}
