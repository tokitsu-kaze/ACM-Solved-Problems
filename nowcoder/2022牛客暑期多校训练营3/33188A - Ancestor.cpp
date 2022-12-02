#include <bits/stdc++.h>
using namespace std;
namespace fastIO{
	#define BUF_SIZE 100000
	#define OUT_SIZE 100000
	//fread->read
	bool IOerror=0;
	//inline char nc(){char ch=getchar();if(ch==-1)IOerror=1;return ch;} 
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
	inline bool read_line(char *s){
		char ch=nc();
		for(;blank(ch);ch=nc());
		if(IOerror)return false;
		for(;ch!='\n'&&!IOerror;ch=nc())*s++=ch;
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
typedef vector<PII > VPII;
/************* define end  *************/
void read(int *x,int l,int r){for(int i=l;i<=r;i++) read(x[i]);}
void read(ll *x,int l,int r){for(int i=l;i<=r;i++) read(x[i]);}
void read(double *x,int l,int r){for(int i=l;i<=r;i++) read(x[i]);}
void println(VI x){for(int i=0;i<sz(x);i++) printf("%d%c",x[i]," \n"[i==sz(x)-1]);}
void println(VL x){for(int i=0;i<sz(x);i++) printf("%lld%c",x[i]," \n"[i==sz(x)-1]);}
void println(int *x,int l,int r){for(int i=l;i<=r;i++) printf("%d%c",x[i]," \n"[i==r]);}
void println(ll *x,int l,int r){for(int i=l;i<=r;i++) printf("%lld%c",x[i]," \n"[i==r]);}
/*************** IO end  ***************/
void assert_lr(ll x,ll l,ll r) {assert(x>=l&&x<=r);};
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
//O(nlogn)-O(logn) 
struct LCA
{
	int fa[MAX][22],dep[MAX],n,limt,bin[22];
	VI mp[MAX];
	void init(int _n)
	{
		n=_n;
		for(limt=1;1<<(limt-1)<=n;limt++);
		for(int i=bin[0]=1;1<<(i-1)<=n;i++) bin[i]=(bin[i-1]<<1);
		for(int i=0;i<=n;i++)
		{
			mp[i].clear();
			mem(fa[i],0);
		}
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
}la,lb;
int x[MAX],a[MAX],b[MAX];
int prea[MAX],sufa[MAX],preb[MAX],sufb[MAX];
void go()
{
	int n,k,i,fa,ans;
	while(read(n,k))
	{
		read(x,1,k);
		read(a,1,n);
		la.init(n);
		for(i=2;i<=n;i++)
		{
			read(fa);
			la.add_edge(fa,i);
		}
		read(b,1,n);
		lb.init(n);
		for(i=2;i<=n;i++)
		{
			read(fa);
			lb.add_edge(fa,i);
		}
		la.work(1);
		lb.work(1);
		prea[1]=x[1];
		preb[1]=x[1];
		for(i=2;i<=k;i++)
		{
			prea[i]=la.lca(prea[i-1],x[i]);
			preb[i]=lb.lca(preb[i-1],x[i]);
		}
		sufa[k]=x[k];
		sufb[k]=x[k];
		for(i=k-1;i;i--)
		{
			sufa[i]=la.lca(sufa[i+1],x[i]);
			sufb[i]=lb.lca(sufb[i+1],x[i]);
		}
		ans=0;
		for(i=1;i<=k;i++)
		{
			if(i==1) ans+=a[sufa[i+1]]>b[sufb[i+1]];
			else if(i==k) ans+=a[prea[i-1]]>b[preb[i-1]];
			else ans+=a[la.lca(prea[i-1],sufa[i+1])]>b[lb.lca(preb[i-1],sufb[i+1])];
		}
		printf("%d\n",ans);
	}
}
