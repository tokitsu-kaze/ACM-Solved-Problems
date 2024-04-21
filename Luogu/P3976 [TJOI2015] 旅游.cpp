#include <bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int MAX=5e4+10;
struct Segment_Tree
{
	#define type int
	static const type inf=INF;
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr,qop;
	type a[MAX],tag[MAX<<2],qv;
	struct node
	{
		type mx,mn,mxlr,mxrl;
		void init(){mx=mxlr=mxrl=-inf,mn=inf;}
	}t[MAX<<2],null_node;
	node merge_node(node x,node y)
	{
		node res;
		res.mx=max(x.mx,y.mx);
		res.mn=min(x.mn,y.mn);
		res.mxlr=max({x.mxlr,y.mxlr,-x.mn+y.mx});
		res.mxrl=max({x.mxrl,y.mxrl,x.mx-y.mn});
		return res;
	}
	void pushup(int id){t[id]=merge_node(t[ls],t[rs]);}
	void maintain(int id,type v)
	{
		t[id].mx+=v;
		t[id].mn+=v;
		tag[id]+=v;
	}
	void pushdown(int l,int r,int id)
	{
		if(!tag[id]) return;
		int mid=(l+r)>>1;
		maintain(ls,tag[id]);
		maintain(rs,tag[id]);
		tag[id]=0;
	}
	void build(int l,int r,int id)
	{
		tag[id]=0;
		t[id].init();
		if(l==r)
		{
			t[id]={a[l],a[l],-inf};
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
			maintain(id,qv);
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
	void init_node(type *v)
	{
		for(int i=1;i<=n;i++) tr.a[dfn[i]]=v[i];
		tr.build(n);
	}
	struct dfn_node{int l,r;};
	type ask_node(int x,int y,type v)
	{
		int f,dfnx,dfny,dfnlca;
		dfnx=dfn[x];
		dfny=dfn[y];
		if(dfnx<dfny) f=0;
		else f=1;
		Segment_Tree::node nl,nr;
		vector<dfn_node> resl,resr,tmp;
		while(top[x]!=top[y])
		{
			if(dep[top[x]]<dep[top[y]]) swap(x,y);
			tmp.push_back({dfn[top[x]],dfn[x]});
			x=fa[top[x]];
		}
		if(dep[x]>dep[y]) swap(x,y);
	    tmp.push_back({dfn[x],dfn[y]});
	    dfnlca=dfn[x];
	    for(auto &it:tmp)
	    {
	    	if(f==0)
	    	{
	    		if(it.l>=min(dfnx,dfnlca)&&it.l<=max(dfnx,dfnlca)
				 &&it.r>=min(dfnx,dfnlca)&&it.r<=max(dfnx,dfnlca)) resl.push_back(it);
	   	 		else resr.push_back(it);
			}
			else
			{
				if(it.l>=min(dfny,dfnlca)&&it.l<=max(dfny,dfnlca)
				 &&it.r>=min(dfny,dfnlca)&&it.r<=max(dfny,dfnlca)) resr.push_back(it);
	   	 		else resl.push_back(it);
			}
		}
	    sort(resl.begin(),resl.end(),[](dfn_node x,dfn_node y){
	    	return x.l<y.l;
		});
		sort(resr.begin(),resr.end(),[](dfn_node x,dfn_node y){
	    	return x.l<y.l;
		});
		nl.init();
		nr.init();
		for(auto &it:resl) nl=tr.merge_node(nl,tr.ask(it.l,it.r));
		for(auto &it:resr) nr=tr.merge_node(nr,tr.ask(it.l,it.r));
		for(auto &it:tmp) tr.upd(it.l,it.r,v);
	    return max({nl.mxrl,nr.mxlr,-nl.mn+nr.mx,0});
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
int w[MAX];
int main()
{
	int n,i,a,b,v,q;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&w[i]);
	hld.init(n);
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		hld.add_edge(a,b);
	}
	hld.work(1);
	hld.init_node(w);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d%d",&a,&b,&v);
		printf("%d\n",hld.ask_node(a,b,v));
	}
	return 0;
}
