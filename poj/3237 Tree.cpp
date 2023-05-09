#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define len(x) (int) x.length()
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
void go();
int main(){
	#ifdef tokitsukaze
		freopen("TEST.txt","r",stdin);
	#endif
	go();return 0;
}
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e6+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
struct Segment_Tree
{
	#define type int
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr,op;
	type a[MAX],mx[MAX<<2],mn[MAX<<2],tag[MAX<<2],qv;
	void pushup(int id)
	{
		mx[id]=max(mx[ls],mx[rs]);
		mn[id]=min(mn[ls],mn[rs]);
	}
	void pushdown(int id)
	{
		if(!tag[id]) return;
		tag[ls]^=1;
		tag[rs]^=1;
		mn[ls]*=-1;
		mn[rs]*=-1;
		mx[ls]*=-1;
		mx[rs]*=-1;
		swap(mn[ls],mx[ls]);
		swap(mn[rs],mx[rs]);
		tag[id]=0;
	}
	void build(int l,int r,int id)
	{
		tag[id]=0;
		mx[id]=-INF;
		mn[id]=INF;
		if(l==r)
		{
			mx[id]=mn[id]=a[l];
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
			if(op)
			{
				tag[id]^=1;
				mn[id]*=-1;
				mx[id]*=-1;
				swap(mn[id],mx[id]);
			}
			else mn[id]=mx[id]=qv;
			return;
		}
		pushdown(id);
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls);
		if(qr>mid) update(mid+1,r,rs);
		pushup(id);
	}
	type query(int l,int r,int id)
	{
		type res=-INF;
		if(l>=ql&&r<=qr) return mx[id];
		pushdown(id);
		int mid=(l+r)>>1;
		if(ql<=mid) res=max(res,query(l,mid,ls));
		if(qr>mid) res=max(res,query(mid+1,r,rs));
		return res;
	}
	void build(int _n){n=_n;build(1,n,1);}
	void upd(int l,int r,int v)
	{
		op=0;
		ql=l;
		qr=r;
		qv=v;
		update(1,n,1);
	}
	void rev(int l,int r)
	{
		op=1;
		ql=l;
		qr=r;
		update(1,n,1);
	}
	type ask(int l,int r)
	{
		ql=l;
		qr=r;
		return query(1,n,1);
	}
	#undef type
}tr;
struct HLD
{
	#define type int
	struct edge{int a,b;type v;edge(int _a,int _b,type _v=0):a(_a),b(_b),v(_v){}};
	vector<int> mp[MAX];
	vector<edge> e;
	int deep[MAX],fa[MAX],size[MAX],son[MAX];
	int rnk[MAX],top[MAX],idx[MAX],tot;
	int n,rt;
	void init(int _n)
	{
		n=_n;
		for(int i=1;i<=n;i++) mp[i].clear();
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
	//path
	void init_path()
	{
		tr.a[idx[rt]]=0;
		for(int i=1;i<n;i++)
		{
			if(deep[e[i].a]<deep[e[i].b]) swap(e[i].a,e[i].b);
			tr.a[idx[e[i].a]]=e[i].v;
		}
		tr.build(n);
	}
	void modify_edge(int id,type val)
	{
		if(deep[e[id].a]>deep[e[id].b]) tr.upd(idx[e[id].a],idx[e[id].a],val);
		else tr.upd(idx[e[id].b],idx[e[id].b],val);
	}
	void modify_path(int x,int y)
	{  
		while(top[x]!=top[y])
		{  
			if(deep[top[x]]<deep[top[y]]) swap(x,y);
			tr.rev(idx[top[x]],idx[x]);
			x=fa[top[x]];
	    }  
	    if(deep[x]>deep[y]) swap(x,y);
	    if(x!=y) tr.rev(idx[x]+1,idx[y]);
	}
	type query_path(int x,int y)
	{  
		type res=-INF;
		while(top[x]!=top[y])
		{  
			if(deep[top[x]]<deep[top[y]]) swap(x,y);
			res=max(res,tr.ask(idx[top[x]],idx[x]));
			x=fa[top[x]];
	    }  
	    if(deep[x]>deep[y]) swap(x,y);
	    if(x!=y) res=max(res,tr.ask(idx[x]+1,idx[y]));
	    return res;
	}
	#undef type
}hld;  //hld.init(n)
void go()
{
	int t,n,i,a,b,c;
	char op[33];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		hld.init(n);
		for(i=1;i<n;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			hld.add_edge(a,b,c);
		}
		hld.work(1);
		hld.init_path();
		while(scanf("%s",op)&&op[0]!='D')
		{
			scanf("%d%d",&a,&b);
			if(op[0]=='C') hld.modify_edge(a,b);
			else if(op[0]=='N') hld.modify_path(a,b);
			else printf("%d\n",hld.query_path(a,b));
		}
	}
}
