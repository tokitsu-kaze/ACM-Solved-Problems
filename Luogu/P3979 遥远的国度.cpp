#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
const ll mod=998244353;
struct Segment_Tree
{
	#define type int
	#define ls (id<<1)
	#define rs (id<<1|1)
	struct node
	{
		type mn;
		void init()
		{
			mn=INT_MAX;
		}
	}t[MAX<<2],null_node;
	int n,ql,qr,qop;
	type a[MAX],tag[MAX<<2],qv;
	node merge(node x,node y)
	{
		node res;
		res.mn=min(x.mn,y.mn);
		return res;
	}
	void pushup(int id){t[id]=merge(t[ls],t[rs]);}
	void pushdown(int l,int r,int id)
	{
		if(!tag[id]) return;
		int mid=(l+r)>>1;
		t[ls].mn=t[id].mn;
		t[rs].mn=t[id].mn;
		tag[ls]=tag[rs]=1;
		tag[id]=0;
	}
	void build(int l,int r,int id)
	{
		tag[id]=0;
		t[id].init();
		if(l==r)
		{
			t[id].mn=a[l];
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,ls);
		build(mid+1,r,rs);
		pushup(id);
	}
	void update(int l,int r,int id)
	{
		if(l>=ql&&r<=qr)
		{
			t[id].mn=qv;
			tag[id]=1;
			return;
		}
		pushdown(l,r,id);
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls);
		if(qr>mid) update(mid+1,r,rs);
		pushup(id);
	}
	node query(int l,int r,int id)
	{
		if(l>=ql&&r<=qr) return t[id];
		pushdown(l,r,id);
		int mid=(l+r)>>1;
		if(qr<=mid) return query(l,mid,ls);
		if(ql>mid) return query(mid+1,r,rs);
		return merge(query(l,mid,ls),query(mid+1,r,rs));
	}
	void build(int _n)
	{
		n=_n;
		build(1,n,1);
		null_node.init();
	}
	void upd(int l,int r,type v)
	{
		if(l>r) return;
		ql=l;
		qr=r;
		qv=v;
		update(1,n,1);
	}
	node ask(int l,int r)
	{
		if(l>r) return null_node;
		ql=l;
		qr=r;
		return query(1,n,1);
	}
	#undef type
	#undef ls
	#undef rs
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
	void init_node(type *v)
	{
		for(int i=1;i<=n;i++) tr.a[dfn[i]]=v[i];
		tr.build(n);
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
	void change_root(int x){rt=x;}
	void upd_subtree(int x,type v)
	{
		if(x==rt) tr.upd(1,n,v);
		if(dfn[rt]>=dfn[x]&&dfn[rt]<=dfn[x]+sz[x]-1)
		{
			x=find_yson_toward_x(rt,x);
			tr.upd(1,dfn[x]-1,v);
			tr.upd(dfn[x]+sz[x],n,v);
		}
		tr.upd(dfn[x],dfn[x]+sz[x]-1,v);
	}
	type ask_subtree(int x)
	{
		if(x==rt) return tr.ask(1,n).mn;
		if(dfn[rt]>=dfn[x]&&dfn[rt]<=dfn[x]+sz[x]-1)
		{
			x=find_yson_toward_x(rt,x);
			return tr.merge(tr.ask(1,dfn[x]-1),
							tr.ask(dfn[x]+sz[x],n)).mn;
		}
		return tr.ask(dfn[x],dfn[x]+sz[x]-1).mn;
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
	int n,m,i,op,a,b,c,rt;
	scanf("%d%d",&n,&m);
	hld.init(n);
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		hld.add_edge(a,b);
	}
	for(i=1;i<=n;i++) scanf("%d",&v[i]);
	scanf("%d",&rt);
	hld.work(rt);
	hld.init_node(v);
	while(m--)
	{
		scanf("%d%d",&op,&a);
		if(op==1) hld.change_root(a);
		else if(op==2)
		{
			scanf("%d%d",&b,&c);
			hld.upd_node(a,b,c);
		}
		else printf("%d\n",hld.ask_subtree(a));
	}
	return 0;
}
