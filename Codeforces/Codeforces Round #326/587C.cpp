#include <bits/stdc++.h>
using namespace std;
namespace fastIO{
	#define BUF_SIZE 100000
	#define OUT_SIZE 100000
	#define ll long long
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
	//fwrite->print
	struct Ostream_fwrite{
		char *buf,*p1,*pend;
		Ostream_fwrite(){buf=new char[BUF_SIZE];p1=buf;pend=buf+BUF_SIZE;}
//		void out(char ch){putchar(ch);}
		void out(char ch){if(p1==pend){fwrite(buf,1,BUF_SIZE,stdout);p1=buf;}*p1++=ch;}
		template<class T>void print(T x){
			static char s[33],*s1;s1=s;
			if(!x)*s1++='0';if(x<0)out('-'),x=-x;
			while(x)*s1++=x%10+'0',x/=10;
			while(s1--!=s)out(*s1);
		}
		void print(double x,int y){
			static ll mul[]=
			{1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000,
			10000000000LL,100000000000LL,1000000000000LL,10000000000000LL,
			100000000000000LL,1000000000000000LL,10000000000000000LL,100000000000000000LL};
			if(x<-1e-12)out('-'),x=-x;
			ll x2=(ll)floor(x);if(!y&&x-x2>=0.5)++x2;x-=x2;x*=mul[y];
			ll x3=(ll)floor(x);if(y&&x-x3>=0.5)++x3;print(x2);
			if(y>0){out('.');for(size_t i=1;i<y&&x3*mul[i]<mul[y];out('0'),++i);print(x3);}
		}
		void print(char *s){while(*s)out(*s++);}
		void print(const char *s){while(*s)out(*s++);}
		void flush(){if(p1!=buf){fwrite(buf,1,p1-buf,stdout);p1=buf;}}
		~Ostream_fwrite(){flush();}
	}Ostream;
	template<class T>void print(T x){Ostream.print(x);}
	inline void print(char x){Ostream.out(x);}
	inline void print(char *s){Ostream.print(s);}
	inline void print(string s){Ostream.print(s.c_str());}
	inline void print(const char *s){Ostream.print(s);}
	inline void print(double x,int y){Ostream.print(x,y);}
	template<class T,class... U>void print(const T& h,const U&... t){print(h);print(t...);}
	void println(){print('\n');}
	template<class T,class... U>void println(const T& h,const U&... t){print(h);println(t...);}
	inline void flush(){Ostream.flush();}
	#undef ll
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
void println(VI x){for(int i=0;i<sz(x);i++) print(x[i]," \n"[i==sz(x)-1]);}
void println(VL x){for(int i=0;i<sz(x);i++) printf("%lld%c",x[i]," \n"[i==sz(x)-1]);}
template<class T> void read(T *x,int l,int r){for(int i=l;i<=r;i++) read(x[i]);}
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
const ll mod=998244353;
/*********************************  head  *********************************/
void merge(priority_queue<int> &res,priority_queue<int> a)
{
	if(sz(res)<sz(a)) swap(res,a);
	while(sz(a))
	{
		res.push(a.top());
		a.pop();
		if(sz(res)>10) res.pop();
	}
}
struct Segment_Tree
{
	#define type priority_queue<int>
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr;
	type a[MAX];
	type v[MAX<<2],res;
	void pushup(int id)
	{
		merge(v[id],v[ls]);
		merge(v[id],v[rs]);
	}
	void build(int l,int r,int id)
	{
		while(sz(v[id])) v[id].pop();
		if(l==r)
		{
			v[id]=a[l];
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,ls);
		build(mid+1,r,rs);
		pushup(id);
	}
	void query(int l,int r,int id)
	{
		if(l>=ql&&r<=qr)
		{
			merge(res,v[id]);
			return;
		}
		int mid=(l+r)>>1;
		if(ql<=mid) query(l,mid,ls);
		if(qr>mid) query(mid+1,r,rs);
	}
	void build(int _n){n=_n;build(1,n,1);}
	type ask(int l,int r)
	{
		ql=l;
		qr=r;
		while(!res.empty()) res.pop();
		query(1,n,1);
		return res;
	}
	#undef type
	#undef ls
	#undef rs
}tr;
struct HLD
{
	#define type int
	struct node{int to;type w;node(){}node(int _to,type _w):to(_to),w(_w){}};
	int deep[MAX],fa[MAX],size[MAX],son[MAX];
	int rnk[MAX],top[MAX],idx[MAX],tot;
	int n,rt;
	int head[MAX],tot1;
	struct edge
	{
		int to,v,next;
	}mp[MAX<<1];
	void init(int _n)
	{
		n=_n;
		mem(head,-1);
		tot1=0;
	}
	void add_edge(int a,int b,type v=0)
	{
		mp[tot1].v=v;  
		mp[tot1].to=b;
		mp[tot1].next=head[a];  
		head[a]=tot1++;
		mp[tot1].v=v;  
		mp[tot1].to=a;
		mp[tot1].next=head[b];  
		head[b]=tot1++;
	}
	void dfs1(int x,int pre,int h)  
	{
		int i,to;
		deep[x]=h;
		fa[x]=pre;
		size[x]=1;
		for(i=head[x];~i;i=mp[i].next)
		{
			to=mp[i].to;
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
		for(i=head[x];~i;i=mp[i].next)
		{
			to=mp[i].to;
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
	priority_queue<int> query_node(int x,int y)
	{  
		priority_queue<int> res;
		while(top[x]!=top[y])
		{  
			if(deep[top[x]]<deep[top[y]]) swap(x,y);
			merge(res,tr.ask(idx[top[x]],idx[x]));
			x=fa[top[x]];
	    }  
	    if(deep[x]>deep[y]) swap(x,y);
	    merge(res,tr.ask(idx[x],idx[y]));
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
	int n,m,q,i,a,b,c;
	while(read(n,m,q))
	{
		hld.init(n);
		for(i=1;i<n;i++)
		{
			read(a,b);
			hld.add_edge(a,b);
		}
		hld.work(1);
		for(i=1;i<=n;i++)
		{
			while(sz(tr.a[i])) tr.a[i].pop();
		}
		for(i=1;i<=m;i++)
		{
			read(a);
			if(sz(tr.a[hld.idx[a]])>=10) continue;
			tr.a[hld.idx[a]].push(i);
		}
		hld.init_node();
		VI res;
		priority_queue<int> tmp;
		while(q--)
		{
			read(a,b,c);
			tmp=hld.query_node(a,b);
			res.clear();
			c=min(sz(tmp),c);
			if(!c)
			{
				println(0);
				continue;
			}
			while(sz(tmp)>c) tmp.pop();
			for(i=1;i<=c;i++)
			{
				res.pb(tmp.top());
				tmp.pop();
			}
			reverse(all(res));
			print(c," ");
			println(res);
		}
	}
}
