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
struct LCA
{
	int fa[MAX][22],dep[MAX],n,limt,bin[22],dfn[MAX],tot;
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
		tot=0;
	}
	void add_edge(int a,int b)
	{
		mp[a].pb(b);
		mp[b].pb(a);
	}
	void dfs(int x,int pre)
	{
		dfn[x]=++tot;
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
struct Virtual_Tree
{
	int st[MAX],top;
	int build_vtree(vector<int> &a,VI vtree_mp[])// return root 
	{
		int now_lca;
	    sort(all(a),[&](int x,int y){return lca.dfn[x]<lca.dfn[y];});
	    a.erase(unique(all(a)),a.end());
	    assert(sz(a)>0);
	    top=0;
	    st[top++]=a[0];
	    VI tmp;
	    for(int i=1;i<sz(a);i++)
	    {
	        if(top==0)
	        {
	        	st[top++]=a[i];
				continue;
			}
	        now_lca=lca.lca(a[i],st[top-1]);
	        while(top>1&&lca.dfn[st[top-2]]>=lca.dfn[now_lca])
	        {
	        	vtree_mp[st[top-2]].pb(st[top-1]);
				top--;
			}
	        if(now_lca!=st[top-1])
			{
				vtree_mp[now_lca].pb(st[top-1]);
				st[top-1]=now_lca;
				tmp.push_back(now_lca);
			}
	        st[top++]=a[i];
	    }
	    while(top>1)
	    {
	    	vtree_mp[st[top-2]].pb(st[top-1]);
			top--;
		}
	    for(auto it:tmp) a.push_back(it);
	    return st[0];
	}
	void clear_vtree(vector<int> &a,VI vtree_mp[])
	{
		for(auto it:a) vtree_mp[it].clear();
	}
}vt; // need lca and dfn
VI mp[MAX];
void go()
{
	int n,i,a,b,q,k,x,lc,ok,rt;
	while(read(n))
	{
		lca.init(n);
		for(i=1;i<n;i++)
		{
			read(a,b);
			lca.add_edge(a,b);
		}
		lca.work(1);
		for(i=1;i<=n;i++) mp[i].clear();
		read(q);
		while(q--)
		{
			read(k);
			VI qst;
			while(k--)
			{
				read(x);
				qst.pb(x);
			}
			int rt=vt.build_vtree(qst,mp);
			ok=1;
			for(auto it:qst)
			{
				if(sz(mp[it])>2) ok=0;
				if(sz(mp[it])==2&&it!=rt) ok=0;
		//		debug(it,mp[it])
			}
			if(ok) puts("YES");
			else puts("NO");
			vt.clear_vtree(qst,mp);
		}
	}
}

