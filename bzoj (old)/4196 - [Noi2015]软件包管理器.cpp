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
void go();
int main(){
	#ifdef tokitsukaze
		freopen("TEST.txt","r",stdin);
	#endif
	go();return 0;
}
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
struct Segment_Tree
{
	#define type int
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr;
	type v[MAX<<2],tag[MAX<<2],qv;
	void pushup(int id)
	{
		v[id]=v[ls]+v[rs];
	}
	void pushdown(int id,int l,int r)
	{
		if(tag[id]==-1) return;
		int mid=(l+r)>>1;
		v[ls]=(mid-l+1)*tag[id];
		v[rs]=(r-mid)*tag[id];
		tag[ls]=tag[rs]=tag[id];
		tag[id]=-1;
	}
	void build(int l,int r,int id)
	{
		tag[id]=-1;
		v[id]=0;
		if(l==r) return;
		int mid=(l+r)>>1;
		build(l,mid,ls);
		build(mid+1,r,rs);
		pushup(id);
	}
	type update(int l,int r,int id)
	{
		int res=0;
		if(l>=ql&&r<=qr)
		{
			tag[id]=qv;
			if(qv==1)
			{
				res=(r-l+1)-v[id];
				v[id]=(r-l+1);
			}
			else
			{
				res=v[id];
				v[id]=0;
			}
			return res;
		}
		pushdown(id,l,r);
		int mid=(l+r)>>1;
		if(ql<=mid) res+=update(l,mid,ls);
		if(qr>mid) res+=update(mid+1,r,rs);
		pushup(id);
		return res;
	}
	void build(int _n){n=_n;build(1,n,1);}
	type upd(int l,int r,int v)
	{
		ql=l;
		qr=r;
		qv=v;
		return update(1,n,1);
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
	int l[MAX],r[MAX];
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
		l[x]=idx[x];
		rnk[idx[x]]=x;
		if(son[x]==-1)
		{
			r[x]=tot;
			return;
		}
		dfs2(son[x],tp);
		for(i=0;i<sz(mp[x]);i++)
		{
			to=mp[x][i];
			if(to!=son[x]&&to!=fa[x]) dfs2(to,to);
		}
		r[x]=tot;
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
	//node
	void init_node()
	{
		tr.build(n);
	}
	type modify_node(int x,int y)
	{  
		type res=0;
		while(top[x]!=top[y])
		{  
			if(deep[top[x]]<deep[top[y]]) swap(x,y);
			res+=tr.upd(idx[top[x]],idx[x],1);
			x=fa[top[x]];
	    }  
	    if(deep[x]>deep[y]) swap(x,y);
	    res+=tr.upd(idx[x],idx[y],1);
	    return res;
	}
	type gao(int x)
	{
		return tr.upd(l[x],r[x],0);
	}
	#undef type
}hld;  //hld.init(n)
void go()
{
	int n,q,x,i,ans;
	char op[11];
	while(~scanf("%d",&n))
	{
		hld.init(n);
		for(i=2;i<=n;i++)
		{
			scanf("%d",&x);
			x++;
			hld.add_edge(x,i);
		}
		hld.work(1);
		hld.init_node();
		scanf("%d",&q);
		while(q--)
		{
			scanf("%s%d",op,&x);
			x++;
			if(op[0]=='i') ans=hld.modify_node(1,x);
			else ans=hld.gao(x);
			printf("%d\n",ans);
		}
	}
}
