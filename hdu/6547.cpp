#include <bits/stdc++.h>
using namespace std;
namespace fastIO{
	#define BUF_SIZE 100000
	#define OUT_SIZE 100000
	//fread->read
	bool IOerror=0;
//  inline char nc(){char ch=getchar();if(ch==-1)IOerror=1;return ch;}
	inline char nc(){
		static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE;
		if(p1==pend){
			p1=buf;pend=buf+fread(buf,1,BUF_SIZE,stdin);
			if(pend==p1){IOerror=1;return -1;}
		}
		return *p1++;
	}
	inline bool blank(char ch){return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';}
	template<class T> inline bool read(T &x){
		bool sign=0;char ch=nc();x=0;
		for(;blank(ch);ch=nc());
		if(IOerror)return false;
		if(ch=='-')sign=1,ch=nc();
		for(;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
		if(sign)x=-x;
		return true;
	}
	inline bool read(double &x){
		bool sign=0;char ch=nc();x=0;
		for(;blank(ch);ch=nc());
		if(IOerror)return false;
		if(ch=='-')sign=1,ch=nc();
		for(;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
		if(ch=='.'){
			double tmp=1; ch=nc();
			for(;ch>='0'&&ch<='9';ch=nc())tmp/=10.0,x+=tmp*(ch-'0');
		}
		if(sign)x=-x;
		return true;
	}
	inline bool read(char *s){
		char ch=nc();
		for(;blank(ch);ch=nc());
		if(IOerror)return false;
		for(;!blank(ch)&&!IOerror;ch=nc())*s++=ch;
		*s=0;
		return true;
	}
	inline bool read(char &c){
		for(c=nc();blank(c);c=nc());
		if(IOerror){c=-1;return false;}
		return true;
	}
	template<class T,class... U>bool read(T& h,U&... t){return read(h)&&read(t...);}
	#undef OUT_SIZE
	#undef BUF_SIZE
};
using namespace fastIO;
/************* debug begin *************/
string to_string(string s){return '"'+s+'"';}
string to_string(const char* s){return to_string((string)s);}
string to_string(const bool& b){return(b?"true":"false");}
template<class T>string to_string(T x){ostringstream sout;sout<<x;return sout.str();}
template<class A,class B>string to_string(pair<A,B> p){return "("+to_string(p.first)+", "+to_string(p.second)+")";}
template<class A>string to_string(const vector<A> v){
	int f=1;string res="{";for(const auto x:v){if(!f)res+= ", ";f=0;res+=to_string(x);}res+="}";
	return res;
}
void debug_out(){puts("");}
template<class T,class... U>void debug_out(const T& h,const U&... t){cout<<" "<<to_string(h);debug_out(t...);}
#ifdef tokitsukaze
#define debug(...) cout<<"["<<#__VA_ARGS__<<"]:",debug_out(__VA_ARGS__);
#else
#define debug(...) 233;
#endif
/*************  debug end  *************/
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define sqr(x) (x)*(x)
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef pair<int,ll> PIL;
typedef pair<ll,int> PLI;
typedef vector<int> VI;
typedef vector<ll> VL;
/************* define end  *************/
void read(int *x,int l,int r){for(int i=l;i<=r;i++) read(x[i]);}
void read(ll *x,int l,int r){for(int i=l;i<=r;i++) read(x[i]);}
void read(double *x,int l,int r){for(int i=l;i<=r;i++) read(x[i]);}
void println(VI x){for(int i=0;i<sz(x);i++) printf("%d%c",x[i]," \n"[i==sz(x)-1]);}
void println(VL x){for(int i=0;i<sz(x);i++) printf("%lld%c",x[i]," \n"[i==sz(x)-1]);}
void println(int *x,int l,int r){for(int i=l;i<=r;i++) printf("%d%c",x[i]," \n"[i==r]);}
void println(ll *x,int l,int r){for(int i=l;i<=r;i++) printf("%lld%c",x[i]," \n"[i==r]);}
/*************** IO end  ***************/
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
struct Segment_Tree
{
	#define type ll
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr;
	type a[MAX],v[MAX<<2],tag[MAX<<2],qv,mx[MAX<<2];
	void pushup(int id)
	{
		v[id]=v[ls]+v[rs];
		mx[id]=max(mx[ls],mx[rs]);
	}
	void pushdown(int id)
	{
		if(!tag[id]) return;
		
	}
	void build(int l,int r,int id)
	{
		mx[id]=tag[id]=0;
		if(l==r)
		{
			v[id]=mx[id]=a[l];
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,ls);
		build(mid+1,r,rs);
		pushup(id);
	}
	void update(int l,int r,int id)
	{
		if(l==r)
		{
			v[id]=(ll)sqrt(v[id]);
			mx[id]=v[id];
			return;
		}
		if(mx[id]<=1) return;
		pushdown(id);
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls);
		if(qr>mid) update(mid+1,r,rs);
		pushup(id);
	}
	type res;
	void query(int l,int r,int id)
	{
		if(l>=ql&&r<=qr)
		{
			res+=v[id];
			return;
		}
		pushdown(id);
		int mid=(l+r)>>1;
		if(ql<=mid) query(l,mid,ls);
		if(qr>mid) query(mid+1,r,rs);
	}
	void build(int _n){n=_n;build(1,n,1);}
	void upd(int l,int r)
	{
		ql=l;
		qr=r;
		update(1,n,1);
	}
	type ask(int l,int r)
	{
		ql=l;
		qr=r;
		res=0;
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
	int tmpv[MAX];
	void init_node()
	{
		for(int i=1;i<=n;i++) tr.a[idx[i]]=tmpv[i];
		tr.build(n);
	}
	void modify_node(int x,int y)
	{  
		while(top[x]!=top[y])
		{  
			if(deep[top[x]]<deep[top[y]]) swap(x,y);
			tr.upd(idx[top[x]],idx[x]);
			x=fa[top[x]];
		}  
		if(deep[x]>deep[y]) swap(x,y);
		tr.upd(idx[x],idx[y]);
	}
	type query_node(int x,int y)
	{  
		type res=0;
		while(top[x]!=top[y])
		{  
			if(deep[top[x]]<deep[top[y]]) swap(x,y);
			res+=tr.ask(idx[top[x]],idx[x]);
			x=fa[top[x]];
		}  
		if(deep[x]>deep[y]) swap(x,y);
		res+=tr.ask(idx[x],idx[y]);
		return res;
	}
	#undef type
}hld;
/***********attention!************/
//hld.init(n)
//hld.add_edge(): undirected edge.
/*********************************/
void go()
{
	int n,q,i,a,b,op;
	while(read(n,q))
	{
		hld.init(n);
		read(hld.tmpv,1,n);
		for(i=1;i<n;i++)
		{
			read(a,b);
			hld.add_edge(a,b);
		}
		hld.work(1);
		hld.init_node();
		while(q--)
		{
			read(op,a,b);
			if(op==0) hld.modify_node(a,b);
			else printf("%lld\n",hld.query_node(a,b));
		}
	}
}
