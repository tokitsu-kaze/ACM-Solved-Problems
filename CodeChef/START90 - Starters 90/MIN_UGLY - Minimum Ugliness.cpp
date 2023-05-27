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
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define sqr(x) ((x)*(x))
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef pair<int,ll> PIL;
typedef pair<ll,int> PLI;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VS> VVS;
typedef vector<VPII> VVPII;
/************* define end  *************/
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
/********* gp_hash_table end  **********/
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
const int MAX=2e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
// O(nlogn)-O(1)
struct LCA
{
	#define type int
	struct node{int to;type w;node(){}node(int _to,type _w):to(_to),w(_w){}};
	type dis[MAX];
	int path[2*MAX],deep[2*MAX],first[MAX],len[MAX],tot,n,dfn[MAX],dfn_tot;
	int dp[2*MAX][22];
	vector<node> mp[MAX];
	void dfs(int x,int pre,int h)
	{
		int i;
		dfn[x]=++dfn_tot;
		path[++tot]=x;
		first[x]=tot;
		deep[tot]=h;
		for(i=0;i<mp[x].size();i++)
		{
			int to=mp[x][i].to;
			if(to==pre) continue;
			dis[to]=dis[x]+mp[x][i].w;
			len[to]=len[x]+1;
			dfs(to,x,h+1);
			path[++tot]=x;
			deep[tot]=h;
		}
	}
	void ST(int n)
	{
		int i,j,x,y;
		for(i=1;i<=n;i++) dp[i][0]=i;
		for(j=1;(1<<j)<=n;j++)
		{
			for(i=1;i+(1<<j)-1<=n;i++)
			{
				x=dp[i][j-1];
				y=dp[i+(1<<(j-1))][j-1];
				dp[i][j]=deep[x]<deep[y]?x:y;
			}
		}
	}
	int query(int l,int r)
	{
		int len,x,y;
		len=(int)log2(r-l+1); 
		x=dp[l][len];
		y=dp[r-(1<<len)+1][len];
		return deep[x]<deep[y]?x:y;
	}
	int lca(int x,int y)
	{
		int l,r,pos;
		l=first[x];
		r=first[y];
		if(l>r) swap(l,r);
		pos=query(l,r);
		return path[pos];
	} 
	type get_dis(int a,int b){return dis[a]+dis[b]-2*dis[lca(a,b)];}
	int get_len(int a,int b){return len[a]+len[b]-2*len[lca(a,b)];}
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++)
		{
			dis[i]=0;
			len[i]=0;
			mp[i].clear();
		}
	}
	void add_edge(int a,int b,type w=1)
	{
		mp[a].pb(node(b,w));
		mp[b].pb(node(a,w));
	}
	void work(int rt)
	{
		dfn_tot=0;
		tot=0;
		dfs(rt,0,0);
		ST(2*n-1);
	}
	int lca_root(int rt,int a,int b)
	{
		int fa,fb;
		fa=lca(a,rt);
		fb=lca(b,rt);
		if(fa==fb) return lca(a,b);
		else
		{
			if(get_dis(fa,rt)<get_dis(fb,rt)) return fa;
			else return fb;
		}
	}
	#undef type
}lca;
/*
lca.init(n);
lca.add_edge(a,b,w) undirected edge.
lca.work(rt);
*/
struct node{int id,w;};
struct Virtual_Tree
{
	int st[MAX],top;
	int build_vtree(VI &a,vector<node> vtree_mp[])// return root 
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
				vtree_mp[st[top-2]].pb({st[top-1],lca.get_len(st[top-2],st[top-1])});
				vtree_mp[st[top-1]].pb({st[top-2],lca.get_len(st[top-2],st[top-1])});
				top--;
			}
			if(now_lca!=st[top-1])
			{
				vtree_mp[now_lca].pb({st[top-1],lca.get_len(now_lca,st[top-1])});
				vtree_mp[st[top-1]].pb({now_lca,lca.get_len(now_lca,st[top-1])});
				st[top-1]=now_lca;
				tmp.push_back(now_lca);
			}
			st[top++]=a[i];
		}
		while(top>1)
		{
			vtree_mp[st[top-2]].pb({st[top-1],lca.get_len(st[top-2],st[top-1])});
			vtree_mp[st[top-1]].pb({st[top-2],lca.get_len(st[top-2],st[top-1])});
			top--;
		}
		for(auto it:tmp) a.push_back(it);
		return st[0];
	}
	void clear_vtree(VI &a,vector<node> vtree_mp[])
	{
		for(auto &it:a) vtree_mp[it].clear();
	}
}vt; // need lca and dfn
vector<node> mp[MAX];
int mx,rt;
void dfs(int x,int fa,int h)
{
	for(auto &to:mp[x])
	{
		if(to.id==fa) continue;
		dfs(to.id,x,h+to.w);
	}
	if(h>mx)
	{
		rt=x;
		mx=h;
	}
}
void go()
{
	int t,n,q,i,a,b,k,x;
	read(t);
	while(t--)
	{
		read(n,q);
		for(i=1;i<=n;i++) mp[i].clear();
		lca.init(n);
		for(i=1;i<n;i++)
		{
			read(a,b);
			lca.add_edge(a,b);
		}
		lca.work(1);
		while(q--)
		{
			read(k);
			VI tmp(k);
			for(auto &it:tmp) read(it);
			rt=vt.build_vtree(tmp,mp);
			mx=0;
			dfs(rt,0,0);
			mx=0;
			dfs(rt,0,0);
			printf("%d\n",(mx+1)/2);
			vt.clear_vtree(tmp,mp);
		}
	}
}

