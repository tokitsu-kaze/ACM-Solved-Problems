#include <bits/stdc++.h>
using namespace std;
namespace fastIO{
	#define BUF_SIZE 100000
	#define OUT_SIZE 100000
	//fread->read
	bool IOerror=0;
//	inline char nc(){char ch=getchar();if(ch==-1)IOerror=1;return ch;} 
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
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
using namespace __gnu_cxx;
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
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
struct Segment_Tree
{
	#define type ull
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr,op;
	type v[MAX<<2],tag[MAX<<2],qv,mul[MAX<<2];
	void pushup(int id)
	{
		v[id]=v[ls]+v[rs];
	}
	void pushdown(int id,int l,int r)
	{
		if(mul[id]!=1)
		{
			mul[ls]*=mul[id];
			mul[rs]*=mul[id];
			v[ls]*=mul[id];
			v[rs]*=mul[id];
			tag[ls]*=mul[id];
			tag[rs]*=mul[id];
			mul[id]=1;
		}
		if(tag[id])
		{
			tag[ls]+=tag[id];
			tag[rs]+=tag[id];
			ll mid=(l+r)>>1;
			v[ls]+=(mid-l+1)*tag[id];
			v[rs]+=(r-mid)*tag[id];
			tag[id]=0;
		}
		
	}
	void build(int l,int r,int id)
	{
		tag[id]=v[id]=0;
		mul[id]=1;
		if(l==r) return;
		int mid=(l+r)>>1;
		build(l,mid,ls);
		build(mid+1,r,rs);
		pushup(id);
	}
	void update(int l,int r,int id)
	{
		if(l>=ql&&r<=qr)
		{
			if(op==1)//mul
			{
				v[id]*=qv;
				mul[id]*=qv;
				tag[id]*=qv;
			}
			else if(op==2)//add
			{
				v[id]+=(r-l+1)*qv;
				tag[id]+=qv;
			}
			else//mul(-1) add-1
			{
				v[id]*=-1;
				mul[id]*=-1;
				tag[id]*=-1;
				v[id]+=(r-l+1)*(-1);
				tag[id]+=(-1);
			}
			return;
		}
		pushdown(id,l,r);
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls);
		if(qr>mid) update(mid+1,r,rs);
		pushup(id);
	}
	type query(int l,int r,int id)
	{
		type res=0;
		if(l>=ql&&r<=qr) return v[id];
		pushdown(id,l,r);
		int mid=(l+r)>>1;
		if(ql<=mid) res+=query(l,mid,ls);
		if(qr>mid) res+=query(mid+1,r,rs);
		return res;
	}
	void build(int _n){n=_n;build(1,n,1);}
	void upd(int l,int r,type v,int _op)
	{
		ql=l;
		qr=r;
		qv=v;
		op=_op;
		update(1,n,1);
	}
	type ask(int l,int r)
	{
		ql=l;
		qr=r;
		return query(1,n,1);
	}
	#undef type
	#undef ls
	#undef rs
}tr;
struct HLD
{
	#define type ull
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
	//node
	void init_node()
	{
		tr.build(n);
	}
	void modify_node(int x,int y,type val,int op)
	{  
		while(top[x]!=top[y])
		{  
			if(deep[top[x]]<deep[top[y]]) swap(x,y);
			tr.upd(idx[top[x]],idx[x],val,op);
			x=fa[top[x]];
	    }  
	    if(deep[x]>deep[y]) swap(x,y);
	    tr.upd(idx[x],idx[y],val,op);
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
}hld;  //hld.init(n)
void go()
{
	int n,i,q,a,b,op;
	ull x;
	while(read(n))
	{
		hld.init(n);
		for(i=2;i<=n;i++)
		{
			read(q);
			hld.add_edge(i,q);
		}
		hld.work(1);
		hld.init_node();
		read(q);
		while(q--)
		{
			read(op,a,b);
			if(op==4) printf("%llu\n",hld.query_node(a,b));
			else
			{
				if(op!=3) read(x);
				else x=0;
				hld.modify_node(a,b,x,op);
			}
		}
	}
} 