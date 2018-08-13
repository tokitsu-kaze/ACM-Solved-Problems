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
ll ans[MAX][2];
struct HLD
{
	#define type ll
	struct edge{int a,b;type v;edge(int _a,int _b,type _v=0):a(_a),b(_b),v(_v){}};
	vector<int> mp[MAX];
	vector<edge> e;
	int deep[MAX],fa[MAX],size[MAX],son[MAX];
	int rnk[MAX],top[MAX],idx[MAX],tot;
	int n,rt;
	void update(int l,int r,ll val,int flag)
	{
		ans[l][flag]+=val;
		ans[r+1][flag]-=val;
	}
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
	//node
	void modify_node(int x,int y,type val)
	{  
		while(top[x]!=top[y])
		{  
			if(deep[top[x]]<deep[top[y]]) swap(x,y);
			update(idx[top[x]],idx[x],val,0);
			x=fa[top[x]];
	    }  
	    if(deep[x]>deep[y]) swap(x,y);
	    update(idx[x],idx[y],val,0);
	}
	//path
	void init_path()
	{
		for(int i=1;i<n;i++)
		{
			if(deep[e[i].a]<deep[e[i].b]) swap(e[i].a,e[i].b);
		}
	}
	void modify_path(int x,int y,type val)
	{
		while(top[x]!=top[y])
		{  
			if(deep[top[x]]<deep[top[y]]) swap(x,y);
			update(idx[top[x]],idx[x],val,1);
			x=fa[top[x]];
	    }  
	    if(deep[x]>deep[y]) swap(x,y);
	    if(x!=y) update(idx[x]+1,idx[y],val,1);
	}
}hld;
ll res[MAX][2];
void go()
{
	int t,cas=1,a,b,c,n,q,i;
	char op[12];
	read(t);
	while(t--)
	{
		read(n,q);
		for(i=1;i<=n;i++) mem(ans[i],0);
		hld.init(n);
		for(i=1;i<n;i++)
		{
			read(a,b);
			hld.add_edge(a,b);
		}
		hld.work(1);
		hld.init_path();
		while(q--)
		{
			read(op,a,b,c);
			if(op[3]=='1') hld.modify_node(a,b,c);
			else hld.modify_path(a,b,c);
		}
		for(i=2;i<=n;i++)
		{
			ans[i][0]+=ans[i-1][0];
			ans[i][1]+=ans[i-1][1];
		}
		for(i=1;i<=n;i++)
		{
			res[i][0]=ans[hld.idx[i]][0];
			if(i!=n) res[i][1]=ans[hld.idx[hld.e[i].a]][1];
		}
		print("Case #",cas++,":\n");
		for(i=1;i<=n;i++) print(res[i][0]," \n"[i==n]);
		if(n>1) print(res[1][1]);
		for(i=2;i<n;i++) print(" ",res[i][1]);
		println();
	}
}
