#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
const int mod=1e9+7;
struct Segment_Tree
{
	#define type int
	static const int LOG=31;
	struct node
	{
		type mx,sum;
		void init(){mx=sum=0;}
	}t[MAX*LOG],null_node;
	int root[MAX],ls[MAX*LOG],rs[MAX*LOG],rt,tot,ql,qr;
	type qv,n[MAX],tag[MAX*LOG];
	Segment_Tree &operator[](const int _rt){this->rt=_rt;return *this;}
	void init()
	{
		rt=1;
		tot=0;
		t[0].init();
		ls[0]=rs[0]=0;
		null_node.init();
	}
	void build(int _n)
	{
		n[rt]=_n;
		root[rt]=0;
	}
	int newnode()
	{
		t[++tot].init();
		ls[tot]=rs[tot]=0;
		tag[tot]=0;
		return tot;
	}
	node merge(node x,node y)
	{
		node res;
		res.mx=max(x.mx,y.mx);
		res.sum=x.sum+y.sum;
		return res;
	}
	void pushup(int id){t[id]=merge(t[ls[id]],t[rs[id]]);}
	void pushdown(int l,int r,int id)
	{
		if(!tag[id]) return;
		if(!ls[id]) ls[id]=newnode();
		if(!rs[id]) rs[id]=newnode();
		
		
		tag[id]=0;
	}
	void update(int l,int r,int &id)
	{
		if(!id) id=newnode();
		if(l>=ql&&r<=qr)
		{
			t[id].mx=t[id].sum=qv;
			return;
		}
		pushdown(l,r,id);
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls[id]);
		if(qr>mid) update(mid+1,r,rs[id]);
		pushup(id);
	}
	node query(int l,int r,int id)
	{
		if(!id) return null_node;
		if(l>=ql&&r<=qr) return t[id];
		pushdown(l,r,id);
		int mid=(l+r)>>1;
		if(qr<=mid) return query(l,mid,ls[id]);
		if(ql>mid) return query(mid+1,r,rs[id]);
		return merge(query(l,mid,ls[id]),query(mid+1,r,rs[id]));
	}
	void upd(int l,int r,type v)
	{
		ql=l;
		qr=r;
		qv=v;
		update(1,n[rt],root[rt]);
	}
	node ask(int l,int r)
	{
		ql=l;
		qr=r;
		return query(1,n[rt],root[rt]);
	}
	#undef type
}tr;
/*
tr.init();
tr.build(n);
*/
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
	//node
	void init_node(type *w,int *col)
	{
		int i;
		tr.init();
		for(i=1;i<=(int)1e5;i++) tr[i].build(1e5);
		for(i=1;i<=n;i++) tr[col[i]].upd(dfn[i],dfn[i],w[i]);
	}
	Segment_Tree::node ask_node(int x,int y,int col)
	{
		Segment_Tree::node res=tr.null_node;
		while(top[x]!=top[y])
		{
			if(dep[top[x]]<dep[top[y]]) swap(x,y);
			res=tr.merge(res,tr[col].ask(dfn[top[x]],dfn[x]));
			x=fa[top[x]];
	    }
	    if(dep[x]>dep[y]) swap(x,y);
	    res=tr.merge(res,tr[col].ask(dfn[x],dfn[y]));
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
int w[MAX],c[MAX];
int main()
{
	int n,q,i,a,b,x,y,pos;
	char op[5];
	scanf("%d%d",&n,&q);
	hld.init(n);
	for(i=1;i<=n;i++) scanf("%d%d",&w[i],&c[i]);
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		hld.add_edge(a,b);
	}
	hld.work(1);
	hld.init_node(w,c);
	while(q--)
	{
		scanf("%s%d%d",op,&x,&y);
		if(op[1]=='C')
		{
			pos=hld.dfn[x];
			tr[c[x]].upd(pos,pos,0);
			c[x]=y;
			tr[c[x]].upd(pos,pos,w[x]);
		}
		else if(op[1]=='W')
		{
			pos=hld.dfn[x];
			w[x]=y;
			tr[c[x]].upd(pos,pos,w[x]);
		}
		else
		{
			Segment_Tree::node res=hld.ask_node(x,y,c[x]);
			if(op[1]=='S') printf("%d\n",res.sum);
			else printf("%d\n",res.mx);
		}
	}
	return 0;
}
