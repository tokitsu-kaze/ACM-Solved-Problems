#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e4+10;
const int mod=998244353;
struct Segment_Tree
{
	#define type ll
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr,qop;
	type a[MAX],tag[MAX<<2],qv;
	struct node
	{
		type ts,v;
		void init(){ts=v=0;}
	}t[MAX<<2],null_node;
	node merge_node(node x,node y)
	{
		node res;
		res.ts=(x.ts+y.ts)%mod;
		res.v=(x.v+y.v)%mod;
		return res;
	}
	void pushup(int id){t[id]=merge_node(t[ls],t[rs]);}
	void pushdown(int l,int r,int id)
	{
		if(!tag[id]) return;
		int mid=(l+r)>>1;
		t[ls].v=(t[ls].v+tag[id]*t[ls].ts)%mod;
		t[rs].v=(t[rs].v+tag[id]*t[rs].ts)%mod;
		tag[ls]+=tag[id];
		tag[rs]+=tag[id];
		tag[id]=0;
	}
	void build(int l,int r,int id)
	{
		tag[id]=0;
		t[id].init();
		if(l==r)
		{
			t[id].ts=a[l];
			t[id].v=0;
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
			t[id].v=(t[id].v+qv*t[id].ts)%mod;
			tag[id]+=qv;
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
	void upd(int l,int r,type v)
	{
		if(l>r) return;
		ql=l;
		qr=r;
		qv=v;
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
	void init_node(type *depk)
	{
		int i;
		for(i=1;i<=n;i++) tr.a[dfn[i]]=depk[i];
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
	type ask_node(int x,int y)
	{
		type res=0;
		while(top[x]!=top[y])
		{
			if(dep[top[x]]<dep[top[y]]) swap(x,y);
			res=(res+tr.ask(dfn[top[x]],dfn[x]))%mod;
			x=fa[top[x]];
	    }
	    if(dep[x]>dep[y]) swap(x,y);
	    res=(res+tr.ask(dfn[x],dfn[y]))%mod;
	    return res;
	}
	#undef type
}hld;
/*
hld.init(n)
hld.add_edge(a,b,v=0);  a <-> b
hld.work(rt);
hld.lca(a,b);
---- node ----
hld.init_node();
hld.upd_node(a,b,v);
hld.ask_node(a,b);
*/
ll qpow(ll a,int b)
{
	ll res=1;
	while(b>0)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
struct node{int x,id;};
vector<int> mp[MAX];
vector<node> qst[MAX];
int dep[MAX],k;
ll ans[MAX],depk[MAX];
void dfs(int x,int fa)
{
	dep[x]=dep[fa]+1;
	depk[x]=(qpow(dep[x],k)-qpow(dep[x]-1,k)+mod)%mod;
	for(auto &to:mp[x]) dfs(to,x);
}
int main()
{
	int n,q,i,fa,x,y;
	scanf("%d%d%d",&n,&q,&k);
	hld.init(n);
	for(i=1;i<=n;i++)
	{
		mp[i].clear();
		qst[i].clear();
		ans[i]=0;
	}
	for(i=2;i<=n;i++)
	{
		scanf("%d",&fa);
		mp[fa].push_back(i);
		hld.add_edge(fa,i);
	}
	dep[0]=0;
	dfs(1,0);
	hld.work(1);
	hld.init_node(depk);
	for(i=1;i<=q;i++)
	{
		scanf("%d%d",&x,&y);
		qst[x].push_back({y,i});
	}
	for(i=1;i<=n;i++)
	{
		hld.upd_node(1,i,1);
		for(auto &it:qst[i]) ans[it.id]=hld.ask_node(1,it.x);
	}
	for(i=1;i<=q;i++) printf("%lld\n",ans[i]);
	return 0;
}
