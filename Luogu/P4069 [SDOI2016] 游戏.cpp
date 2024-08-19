#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
struct LiChao_Segment_Tree
{
	#define type ll
	static const type inf=123456789123456789ll;
	#define ls (id<<1)
	#define rs (id<<1|1)
	static const int MIN_TAG=0;
	static const int MAX_TAG=1;
	int TAG;
	#define init_val (TAG==MIN_TAG?inf:-inf)
	struct line{type k,b;}sg[MAX<<2];
	type v[MAX<<2],a[MAX];
	bool ext[MAX<<2];
	int ql,qr,n;
	type cal(const line &l,const int &x){return l.k*a[x]+l.b;}
	int sgn(const type &x){return x==0?0:(x>0?1:-1);}
	int cmp_min(const type &x,const type &y){return sgn(y-x);}
	int cmp_max(const type &x,const type &y){return sgn(x-y);}
	int cmp(const type &x,const type &y){return TAG==MIN_TAG?cmp_min(x,y):cmp_max(x,y);}
	type ckres(const type &x,const type &y){return TAG==MIN_TAG?min(x,y):max(x,y);}
	void build(int l,int r,int id)
	{
		ext[id]=0;
		v[id]=init_val;
		sg[id]={0,init_val};
		if(l==r) return;
		int mid=(l+r)>>1;
		build(l,mid,ls);
		build(mid+1,r,rs);
	}
	void pushup(int id)
	{
		v[id]=ckres(v[id],v[ls]);
		v[id]=ckres(v[id],v[rs]);
	}
	void pushdown(int l,int r,int id,line qv)
	{
		int cl,cr,mid;
		if(!ext[id])
		{
			ext[id]=1;
			sg[id]=qv;
			goto pushdown_end;
		}
		mid=(l+r)>>1;
		if(cmp(cal(qv,mid),cal(sg[id],mid))==1) swap(qv,sg[id]);
		cl=cmp(cal(qv,l),cal(sg[id],l));
		cr=cmp(cal(qv,r),cal(sg[id],r));
		if(cl>=0&&cr>=0)
		{
			sg[id]=qv;
			goto pushdown_end;
		}
		if(cl==1) pushdown(l,mid,ls,qv);
		else if(cr==1) pushdown(mid+1,r,rs,qv);
		pushdown_end:
		v[id]=ckres(cal(sg[id],l),cal(sg[id],r));
		if(l!=r) pushup(id);
	}
	void update(int l,int r,int id,line qv)
	{
		if(l>=ql&&r<=qr)
		{
			pushdown(l,r,id,qv);
			return;
		}
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls,qv);
		if(qr>mid) update(mid+1,r,rs,qv);
		v[id]=ckres(cal(sg[id],l),cal(sg[id],r));
		pushup(id);
	}
	type res;
	void query(int l,int r,int id)
	{
		if(l>=ql&&r<=qr)
		{
			res=ckres(v[id],res);
			return;
		}
		res=ckres(res,cal(sg[id],max(l,ql)));
		res=ckres(res,cal(sg[id],min(r,qr)));
		int mid=(l+r)>>1;
		if(ql<=mid) query(l,mid,ls);
		if(qr>mid) query(mid+1,r,rs);
	}
	void build(int _n,int _TAG){n=_n;TAG=_TAG;build(1,n,1);}
	void upd(int l,int r,type k,type b)
	{
		ql=l;
		qr=r;
		update(1,n,1,{k,b});
	}
	type ask(int l,int r)
	{
		ql=l;
		qr=r;
		res=init_val;
		query(1,n,1);
		return res;
	}
	void dfs(int l,int r,int id)
	{
		cout<<l<<" "<<r<<" "<<sg[id].k<<" "<<sg[id].b<<endl;
		if(l==r) return;
		int mid=(l+r)>>1;
		dfs(l,mid,ls);
		dfs(mid+1,r,rs);
	}
	#undef type
	#undef init_val
	#undef ls
	#undef rs
}tr;
/*
upd:O(log^2), ask:O(log)
tr.build(n,LiChao_Segment_Tree::MIN_TAG);
tr.build(n,LiChao_Segment_Tree::MAX_TAG);
tr.upd(l,r,k,b);
tr.ask(l,r);
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
	void init_node(type *v)
	{
		for(int i=1;i<=n;i++) tr.a[dfn[i]]=v[i];
		tr.build(n,LiChao_Segment_Tree::MIN_TAG);
	}
	void upd_node(int x,int y,type k,type b)
	{
		while(top[x]!=top[y])
		{
			if(dep[top[x]]<dep[top[y]]) swap(x,y);
			tr.upd(dfn[top[x]],dfn[x],k,b);
			x=fa[top[x]];
		}
	    if(dep[x]>dep[y]) swap(x,y);
	    tr.upd(dfn[x],dfn[y],k,b);
	}
	type ask_node(int x,int y)
	{
		type res=123456789123456789ll;
		while(top[x]!=top[y])
		{
			if(dep[top[x]]<dep[top[y]]) swap(x,y);
			res=min(res,tr.ask(dfn[top[x]],dfn[x]));
			x=fa[top[x]];
		}
	    if(dep[x]>dep[y]) swap(x,y);
	    res=min(res,tr.ask(dfn[x],dfn[y]));
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
hld.init_node(type *v);
hld.upd_node(a,b,v);
hld.ask_node(a,b);
*/
struct edge{int to;ll w;};
vector<edge> mp[MAX];
ll dis[MAX];
void dfs(int x,int fa)
{
	for(auto &it:mp[x])
	{
		int to=it.to;
		ll w=it.w;
		if(to==fa) continue;
		dis[to]=dis[x]+w;
		dfs(to,x);
	}
}
int main()
{
	int n,m,i,op,s,t,lca,w,a,b;
	scanf("%d%d",&n,&m);
	hld.init(n);
	for(i=1;i<=n;i++) mp[i].clear();
	for(i=1;i<n;i++)
	{
		scanf("%d%d%d",&a,&b,&w);
		hld.add_edge(a,b);
		mp[a].push_back({b,w});
		mp[b].push_back({a,w});
	}
	hld.work(1);
	dis[1]=0;
	dfs(1,0);
	hld.init_node(dis);
	while(m--)
	{
		scanf("%d",&op);
		scanf("%d%d",&s,&t);
		if(op==1)
		{
			scanf("%d%d",&a,&b);
			lca=hld.lca(s,t);
			hld.upd_node(s,lca,-a,1LL*a*dis[s]+b);
			hld.upd_node(lca,t,a,1LL*a*(dis[s]-2LL*dis[lca])+b);
		}
		else printf("%lld\n",hld.ask_node(s,t));
	}
	return 0;
}
