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
#include <bitset>
#include <limits>
#include <assert.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define sqr(x) (x)*(x)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef pair<int,ll> PIL;
typedef pair<ll,int> PLI;
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
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=2e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
struct divide_combine_tree
{
	struct RMQ
	{
		#define type int
		int lg[MAX],bin[22];
		type mx[MAX][22],mn[MAX][22];
		void work(int n,type *v)
		{
			int i,j;
			for(i=bin[0]=1;1<<(i-1)<=n;i++) bin[i]=(bin[i-1]<<1);
			for(i=2,lg[1]=0;i<=n;i++) lg[i]=lg[i>>1]+1;
			for(i=1;i<=n;i++) mx[i][0]=mn[i][0]=v[i];
			for(j=1;1<<(j-1)<=n;j++)
			{
				for(i=1;i+bin[j]-1<=n;i++)
				{
					mx[i][j]=max(mx[i][j-1],mx[i+bin[j-1]][j-1]);
					mn[i][j]=min(mn[i][j-1],mn[i+bin[j-1]][j-1]);
				}
			}
		}
		type ask_max(int l,int r)
		{
			int t=lg[r-l+1];
			return max(mx[l][t],mx[r-bin[t]+1][t]);
		}
		type ask_min(int l,int r)
		{
			int t=lg[r-l+1];
			return min(mn[l][t],mn[r-bin[t]+1][t]);
		}
		#undef type
	}rmq;
	struct Segment_Tree
	{
		#define type int
		#define ls (id<<1)
		#define rs (id<<1|1)
		int n,ql,qr;
		type mn[MAX<<2],tag[MAX<<2],qv;
		void mdf(int id,type v){mn[id]+=v,tag[id]+=v;}
		void pushup(int id){mn[id]=min(mn[ls],mn[rs]);}
		void pushdown(int id)
		{
			if(!tag[id]) return;
			mdf(ls,tag[id]);
			mdf(rs,tag[id]);
			tag[id]=0;
		}
		void build(int l,int r,int id)
		{
			tag[id]=mn[id]=0;
			if(l==r) return;
			int mid=(l+r)>>1;
			build(l,mid,ls);
			build(mid+1,r,rs);
			pushup(id);
		}
		void update(int l,int r,int id)
		{
			if(l>=ql&&r<=qr){mdf(id,qv);return;}
			pushdown(id);
			int mid=(l+r)>>1;
			if(ql<=mid) update(l,mid,ls);
			if(qr>mid) update(mid+1,r,rs);
			pushup(id);
		}
		int query(int l,int r,int id)
		{
			if(l==r) return l;
			pushdown(id);
			int mid=(l+r)>>1;
			if(!mn[ls]) return query(l,mid,ls);
			else query(mid+1,r,rs);
		}
		void build(int _n){n=_n;build(1,n,1);}
		void upd(int l,int r,type v){ql=l;qr=r;qv=v;update(1,n,1);}
		type ask(int l,int r){ql=l;qr=r;return query(1,n,1);}
		#undef type
		#undef ls
		#undef rs
	}tr;
	bool check(int l,int r){return rmq.ask_max(l,r)-rmq.ask_min(l,r)==r-l;}
	int st[MAX],st1[MAX],st2[MAX],top,top1,top2,m[MAX];
	int tot,id[MAX],l[MAX],r[MAX],type[MAX];
	struct LCA
	{
		int fa[MAX][22],dep[MAX],n,limt,bin[22];
		VI mp[MAX];
		void init(int _n)
		{
			n=_n;
			for(limt=1;1<<(limt-1)<=n;limt++);
			for(int i=bin[0]=1;1<<(i-1)<=n;i++) bin[i]=(bin[i-1]<<1);
			for(int i=0;i<=n;i++) mp[i].clear();
		}
		void add_edge(int a,int b)
		{
			mp[a].pb(b);
			mp[b].pb(a);
		}
		void dfs(int x,int pre)
		{
			for(int i=1;bin[i]<=dep[x];i++) fa[x][i]=fa[fa[x][i-1]][i-1];
			for(int i=0;i<sz(mp[x]);i++)
			{
				int to=mp[x][i];
				if(to==pre) continue;
				dep[to]=dep[x]+1;
				fa[to][0]=x;
				dfs(to,x);
			}
		}
		void work(int rt)
		{
			dep[rt]=0;
			dfs(rt,0);
		}
		int go(int x,int d)
		{
			for(int i=0;i<=limt&&d;i++)
			{
				if(bin[i]&d)
				{
					d^=bin[i];
					x=fa[x][i];
				}
			}
			return x;
		}
		int lca(int a,int b)
		{
			if(dep[a]<dep[b]) swap(a,b);
			a=go(a,dep[a]-dep[b]);
			if(a==b) return a;
			for(int i=limt;~i;i--)
			{
				if(fa[a][i]!=fa[b][i])
				{
					a=fa[a][i];
					b=fa[b][i];
				}
			}
			return fa[a][0];
		}
	}lca;
	VI mp[MAX];
	void add_edge(int a,int b){mp[a].pb(b);lca.add_edge(a,b);}
	int build(int n,int *a)
	{
		int now,i,tmp;
		tr.build(n);
		rmq.work(n,a);
		for(i=0;i<=2*n;i++)
		{
			mp[i].clear();
			type[i]=0;
		}
		top=top1=top2=0;
		tot=0;
		for(i=1;i<=n;i++)
		{
			while(top1&&a[i]<=a[st1[top1]])
			{
				tr.upd(st1[top1-1]+1,st1[top1],a[st1[top1]]);
				top1--;
			}
			while(top2&&a[i]>=a[st2[top2]])
			{
				tr.upd(st2[top2-1]+1,st2[top2],-a[st2[top2]]);
				top2--;
			}
			tr.upd(st1[top1]+1,i,-a[i]);
			st1[++top1]=i;
			tr.upd(st2[top2]+1,i,a[i]);
			st2[++top2]=i;
			id[i]=++tot;
			l[tot]=r[tot]=i;
			tmp=tr.ask(1,n);
			now=tot;
			while(top&&l[st[top]]>=tmp)
			{
				if(type[st[top]]&&check(m[st[top]],i))
				{
					r[st[top]]=i;
					add_edge(st[top],now);
					now=st[top--];
				}
				else if(check(l[st[top]],i))
				{
					type[++tot]=1;
					l[tot]=l[st[top]];
					r[tot]=i;
					m[tot]=l[now];
					add_edge(tot,st[top--]);
					add_edge(tot,now);
					now=tot;
				}
				else
				{
					add_edge(++tot,now);
					do
					{
						add_edge(tot,st[top--]);
					}while(top&&!check(l[st[top]],i));
					l[tot]=l[st[top]];
					r[tot]=i;
					add_edge(tot,st[top--]);
					now=tot;
				}
			}
			st[++top]=now;
			tr.upd(1,i,-1);
		}
		return st[1];
	}
	void work(int n,int *a)
	{
		int rt,q,L,R,x,y,z;
		lca.init(2*n);
		rt=build(n,a);
	//	debug(rt)
		lca.work(rt);
		scanf("%d",&q);
		while(q--)
		{
			scanf("%d%d",&L,&R);
			x=id[L];
			y=id[R];
			z=lca.lca(x,y);
	//		debug(x,y,z)
			if(type[z])
			{
				L=l[lca.go(x,lca.dep[x]-lca.dep[z]-1)];
				R=r[lca.go(y,lca.dep[y]-lca.dep[z]-1)];
			}
			else
			{
				L=l[z];
				R=r[z];
			}
			printf("%d %d\n",L,R);
		}
	}
}dct;// MAX must *2
int a[MAX];
void go()
{
	int n,i;
	while(~scanf("%d",&n))
	{
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		dct.work(n,a);
	}
} 
