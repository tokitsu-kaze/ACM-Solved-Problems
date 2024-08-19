#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define sqr(x) (x)*(x)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef pair<int,ll> PIL;
typedef pair<ll,int> PLI;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII > VPII;
void go();
int main(){
	#ifdef tokitsukaze
		freopen("TEST.txt","r",stdin);
	#endif
	go();return 0;
}
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
ll dis[MAX];
int now[MAX];
struct LiChao_Segment_Tree
{
	#define type ll
	static const type inf=123456789123456789ll;
	#define ls (id<<1)
	#define rs (id<<1|1)
	struct line
	{
		type k,b;
		void init(type _k=0,type _b=0){k=_k;b=_b;}
	}sg[MAX<<2];
	type v[MAX<<2];
	bool ext[MAX<<2];
	int ql,qr,n;
	type cal(line l,int x){return l.k*dis[now[x]]+l.b;}
	void pushup(int id)
	{
		v[id]=min(v[id],v[ls]);
		v[id]=min(v[id],v[rs]);
	}
	void build(int l,int r,int id)
	{
		ext[id]=1;
		sg[id].init(0,inf);
		v[id]=inf;
		if(l==r) return;
		int mid=(l+r)>>1;
		build(l,mid,ls);
		build(mid+1,r,rs);
	}
	void update(int l,int r,int id,line qv)
	{
		if(l>=ql&&r<=qr)
		{
			if(!ext[id])
			{
				ext[id]=1;
				sg[id]=qv;
			}
			else if(cal(qv,l)<=cal(sg[id],l)&&cal(qv,r)<=cal(sg[id],r)) sg[id]=qv;
			else if(cal(qv,l)<cal(sg[id],l)||cal(qv,r)<cal(sg[id],r))
			{
				int mid=(l+r)>>1;
				if(cal(qv,mid)<cal(sg[id],mid)) swap(qv,sg[id]);
				if(cal(qv,l)<cal(sg[id],l)) update(l,mid,ls,qv);
				else update(mid+1,r,rs,qv);
			}
			v[id]=min(cal(sg[id],l),cal(sg[id],r));
			if(l!=r) pushup(id);
			//if ask min, change '>' to '<'
		}
		else
		{
			int mid=(l+r)>>1;
			if(ql<=mid) update(l,mid,ls,qv);
			if(qr>mid) update(mid+1,r,rs,qv);
			v[id]=min(cal(sg[id],l),cal(sg[id],r));
			if(l!=r) pushup(id);
		}
	}
	type res;
	void query(int l,int r,int id)
	{
		if(l>=ql&&r<=qr)
		{
			res=min(res,v[id]);
			return;
		}
		res=min(res,cal(sg[id],max(l,ql)));
		res=min(res,cal(sg[id],min(r,qr)));
		int mid=(l+r)>>1;
		if(ql<=mid) query(l,mid,ls);
		if(qr>mid) query(mid+1,r,rs);
	}
	void build(int _n){n=_n;build(1,n,1);}
	void upd(int l,int r,type k,type b)
	{
		ql=l;
		qr=r;
		line qv;
		qv.init(k,b);
		update(1,n,1,qv);
	}
	type ask(int l,int r)
	{
		ql=l;
		qr=r;
		res=inf;
		query(1,n,1);
		return res;
	}
	#undef type
	#undef ls
	#undef rs
}tr;
struct HLD
{
	#define type ll
	struct edge{int a,b;type v;edge(int _a,int _b,type _v=0):a(_a),b(_b),v(_v){}};
	struct node{int to;type w;node(){}node(int _to,type _w):to(_to),w(_w){}};
	vector<int> mp[MAX];
	vector<edge> e;
	int deep[MAX],fa[MAX],size[MAX],son[MAX];
	int rnk[MAX],top[MAX],idx[MAX],tot;
	int n,rt;
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++) mp[i].clear();
		e.clear();
		e.pb(edge(0,0));
	}
	void add_edge(int a,int b,type v=0)
	{
		e.pb(edge(a,b,v));
		mp[a].pb(b);
		mp[b].pb(a);
	}
	void dfs1(int x,int pre,int h)  
	{
		int i,to;
		deep[x]=h;
		fa[x]=pre;
		size[x]=1;
		for(i=0;i<sz(mp[x]);i++)
		{
			to=mp[x][i];
			if(to==pre) continue;
			dfs1(to,x,h+1);
			size[x]+=size[to];
			if(son[x]==-1||size[to]>size[son[x]]) son[x]=to;
		}
	}
	void dfs2(int x,int tp)
	{
		int i,to;
		top[x]=tp;
		idx[x]=++tot;
		rnk[idx[x]]=x;
		if(son[x]==-1) return;
		dfs2(son[x],tp);
		for(i=0;i<sz(mp[x]);i++)
		{
			to=mp[x][i];
			if(to!=son[x]&&to!=fa[x]) dfs2(to,to);
		}
	}
	void work(int _rt) 
	{
		int i;
		rt=_rt;
		mem(son,-1);
		tot=0;
		dfs1(rt,0,0);
		dfs2(rt,rt);
	}
	int LCA(int x,int y)
	{
		while(top[x]!=top[y])
		{  
			if(deep[top[x]]<deep[top[y]]) swap(x,y);
			x=fa[top[x]];
	    }  
	    if(deep[x]>deep[y]) swap(x,y);
	    return x;
	}
	//node
	void init_node()
	{
		tr.build(n);
	}
	void modify_node(int x,int y,type k,type b)
	{  
		while(top[x]!=top[y])
		{  
			if(deep[top[x]]<deep[top[y]]) swap(x,y);
			tr.upd(idx[top[x]],idx[x],k,b);
			x=fa[top[x]];
	    }  
	    if(deep[x]>deep[y]) swap(x,y);
		tr.upd(idx[x],idx[y],k,b);
	}
	type query_node(int x,int y)
	{  
		type res=123456789123456789ll;
		while(top[x]!=top[y])
		{  
			if(deep[top[x]]<deep[top[y]]) swap(x,y);
			res=min(res,tr.ask(idx[top[x]],idx[x]));
			x=fa[top[x]];
	    }  
	    if(deep[x]>deep[y]) swap(x,y);
	    res=min(res,tr.ask(idx[x],idx[y]));
	    return res;
	}
	#undef type
}hld;
vector<PLL > mp[MAX];
void dfs(int x,int fa)
{
	PLL to;
	for(int i=0;i<sz(mp[x]);i++)
	{
		to=mp[x][i];
		if(to.fi==fa) continue;
		dis[to.fi]=dis[x]+to.se;
		dfs(to.fi,x);
	}
}
void go()
{
	int n,m,i,op,s,t,lca;
	ll w,a,b;
	while(~scanf("%d%d",&n,&m))
	{
		hld.init(n);
		for(i=1;i<=n;i++) mp[i].clear();
		for(i=1;i<n;i++)
		{
			scanf("%lld%lld%lld",&a,&b,&w);
			hld.add_edge(a,b);
			mp[a].pb(MP(b,w));
			mp[b].pb(MP(a,w));
		}
		hld.work(1);
		for(i=1;i<=n;i++) now[i]=hld.rnk[i];
		dis[1]=0;
		dfs(1,0);
		hld.init_node();
		while(m--)
		{
			scanf("%d",&op);
			scanf("%d%d",&s,&t);
			if(op==1)
			{
				scanf("%lld%lld",&a,&b);
				lca=hld.LCA(s,t);
				hld.modify_node(s,lca,-a,a*dis[s]+b);
				hld.modify_node(lca,t,a,a*(dis[s]-2*dis[lca])+b);
			}
			else
			{
				printf("%lld\n",hld.query_node(s,t));
			}
		}
	} 
}
