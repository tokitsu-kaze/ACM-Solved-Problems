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
#include <assert.h>
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
const int MAX=1e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
struct Fenwick_Tree
{
	#define type int
	type bit[MAX];
	int n;
	void init(int _n){n=_n;mem(bit,0);}
	int lowbit(int x){return x&(-x);}
	void insert(int x,type v)
	{
		while(x<=n)
		{
			bit[x]+=v;
			x+=lowbit(x);
		}
	}
	type get(int x)
	{
		type res=0;
		while(x)
		{
			res+=bit[x];
			x-=lowbit(x);
		}
		return res;
	}
	type query(int l,int r)
	{
		return get(r)-get(l-1);
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
		tr.init(n);
		for(int i=1;i<n;i++)
		{
			if(deep[e[i].a]<deep[e[i].b]) swap(e[i].a,e[i].b);
			tr.insert(idx[e[i].a],e[i].v);
		}
	}
	void update(int l,int r,int val)
	{
		assert(l==r);
		tr.insert(l,-tr.query(l,r)+val);
	} 
	void modify_edge(int id,type val)
	{
		if(deep[e[id].a]>deep[e[id].b]) update(idx[e[id].a],idx[e[id].a],val);
		else update(idx[e[id].b],idx[e[id].b],val);
	}
	type query_path(int x,int y)
	{  
		type res=0;
		while(top[x]!=top[y])
		{  
			if(deep[top[x]]<deep[top[y]]) swap(x,y);
			res+=tr.query(idx[top[x]],idx[x]);
			x=fa[top[x]];
	    }  
	    if(deep[x]>deep[y]) swap(x,y);
	    if(x!=y) res+=tr.query(idx[x]+1,idx[y]);
	    return res;
	}
	#undef type
}hld;  //hld.init(n)
void go()
{
	int n,m,s,i,op,a,b,c;
	while(~scanf("%d%d%d",&n,&m,&s))
	{
		hld.init(n);
		for(i=1;i<n;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			hld.add_edge(a,b,c);
		} 
		hld.work(1);
		hld.init_path();
		while(m--)
		{
			scanf("%d",&op);
			if(op==1)
			{
				scanf("%d%d",&a,&b);
				hld.modify_edge(a,b);
			}
			else
			{
				scanf("%d",&a);
				printf("%d\n",hld.query_path(s,a));
				s=a;
			}
		}
	}
}
