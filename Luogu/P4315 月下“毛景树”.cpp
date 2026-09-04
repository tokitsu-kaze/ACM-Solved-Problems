#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
struct Segment_Tree
{
	#define type int
	static const type inf=INF;
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr,qop;
	type a[MAX],tag[MAX<<2],cov[MAX<<2],qv;
	struct node
	{
		type v;
		void init(){}
	}t[MAX<<2],null_node;
	node merge_node(node x,node y)
	{
		node res;
		res.v=max(x.v,y.v);
		return res;
	}
	void pushup(int id){t[id]=merge_node(t[ls],t[rs]);}
	void pushdown(int l,int r,int id)
	{
		int mid=(l+r)>>1;
		if(cov[id])
		{
			t[ls].v=t[rs].v=cov[id];
			cov[ls]=cov[rs]=cov[id];
			tag[ls]=tag[rs]=0;
			cov[id]=0;
		}
		if(tag[id])
		{
			t[ls].v+=tag[id];
			t[rs].v+=tag[id];
			tag[ls]+=tag[id];
			tag[rs]+=tag[id];
			tag[id]=0;
		}
	}
	void build(int l,int r,int id)
	{
		tag[id]=cov[id]=0;
		t[id].init();
		if(l==r)
		{
			t[id].v=a[l];
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
			if(qop==1)
			{
				t[id].v=qv;
				cov[id]=qv;
				tag[id]=0;
			}
			else
			{
				t[id].v+=qv;
				tag[id]+=qv;
			}
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
		return merge_node(query(l,mid,ls),query(mid+1,r,rs));
	}
	void build(int _n)
	{
		n=_n;
		build(1,n,1);
		null_node.init();
	}
	void upd(int l,int r,type v,int op)
	{
		if(l>r) return;
		ql=l;
		qr=r;
		qv=v;
		qop=op;
		update(1,n,1);
	}
	type ask(int l,int r)
	{
		if(l>r) return null_node.v;
		ql=l;
		qr=r;
		return query(1,n,1).v;
	}
	#undef type
	#undef ls
	#undef rs
}tr;
/*
tr.build(n);
tr.upd(l,r,v);
tr.ask(l,r);
Segment_Tree::node res=tr.merge_node(nodex,nodey);
*/
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
	//path
	void init_path()
	{
		tr.a[dfn[rt]]=0;
		for(int i=1;i<n;i++)
		{
			if(dep[e[i].a]<dep[e[i].b]) swap(e[i].a,e[i].b);
			tr.a[dfn[e[i].a]]=e[i].v;
		}
		tr.build(n);
	}
	void upd_edge(int id,type v)
	{
		if(dep[e[id].a]>dep[e[id].b]) tr.upd(dfn[e[id].a],dfn[e[id].a],v,1);
		else tr.upd(dfn[e[id].b],dfn[e[id].b],v,1);
		e[id].v=v;
	}
	void upd_path(int x,int y,type v,int op)
	{  
		while(top[x]!=top[y])
		{
			if(dep[top[x]]<dep[top[y]]) swap(x,y);
			tr.upd(dfn[top[x]],dfn[x],v,op);
			x=fa[top[x]];
		}
	    if(dep[x]>dep[y]) swap(x,y);
	    if(x!=y) tr.upd(dfn[x]+1,dfn[y],v,op);
	}
	type ask_path(int x,int y)
	{  
		type res=0;
		while(top[x]!=top[y])
		{  
			if(dep[top[x]]<dep[top[y]]) swap(x,y);
			res=max(res,tr.ask(dfn[top[x]],dfn[x]));
			x=fa[top[x]];
		}  
	    if(dep[x]>dep[y]) swap(x,y);
	    if(x!=y) res=max(res,tr.ask(dfn[x]+1,dfn[y]));
	    return res;
	}
	#undef type
}hld;
/*
hld.init(n)
hld.add_edge(a,b,v=0);  a <-> b
hld.work(rt);
hld.lca(a,b);
---- path ----
hld.init_path();
hld.upd_edge(id,v);   id:1..n-1
hld.upd_path(a,b,v);
hld.ask_path(a,b);
*/
int main()
{
	int n,i,a,b,c,x;
	char op[11];
	scanf("%d",&n);
	hld.init(n);
	for(i=1;i<n;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		hld.add_edge(a,b,c);
	}
	hld.work(1);
	hld.init_path();
	while(~scanf("%s",op))
	{
		if(op[0]=='S') break;
		if(op[0]=='C')
		{
			if(op[1]=='h')
			{
				scanf("%d%d",&x,&c);
				hld.upd_edge(x,c);
			}
			else
			{
				scanf("%d%d%d",&a,&b,&c);
				hld.upd_path(a,b,c,1);
			}
		}
		else if(op[0]=='A')
		{
			scanf("%d%d%d",&a,&b,&c);
			hld.upd_path(a,b,c,2);
		}
		else
		{
			scanf("%d%d",&a,&b);
			printf("%d\n",hld.ask_path(a,b));
		}
	}
	return 0;
}

