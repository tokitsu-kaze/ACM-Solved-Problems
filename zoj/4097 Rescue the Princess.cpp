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
const ll mod=998244353;
/*********************************  head  *********************************/
struct LCA
{
	#define type int
	struct node{int to;type w;node(){}node(int _to,type _w):to(_to),w(_w){}};
	type dis[MAX];
	int path[2*MAX],deep[2*MAX],first[MAX],len[MAX],tot,n;
	int dp[2*MAX][22];
	vector<node> mp[MAX];
	void dfs(int x,int pre,int h)
	{
		int i;
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
	void add(int a,int b,type w=1)
	{
		mp[a].pb(node(b,w));
		mp[b].pb(node(a,w));
	}
	void work(int rt)
	{
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

namespace Tarjan
{
	int bcc,top,tot,n;
	vector<int> mp[MAX];
	vector<PII > bridge;
	int low[MAX],dfn[MAX],belong[MAX],fa[MAX];
	int stk[MAX];
	void dfs(int x,int pre)
	{
		int to,i,tmp,k,son;
		stk[top++]=x;
		low[x]=dfn[x]=++tot;
		fa[x]=pre;
		son=k=0;
		for(auto to:mp[x])
		{
			if(to==pre&&!k) 
			{
				k++;
				continue;
			}
			if(!dfn[to])
			{
				son++;
				dfs(to,x);
				low[x]=min(low[x],low[to]);
			}
			else low[x]=min(low[x],dfn[to]);
		}
		if(low[x]==dfn[x])
		{
			bcc++;
			do
			{
				tmp=stk[--top];
				belong[tmp]=bcc;
			}while(tmp!=x);
		}
	}
	void work(int _n,vector<int> e[])
	{
		n=_n;
		for(int i=1;i<=n;i++)
		{
			mp[i]=e[i];
			low[i]=dfn[i]=fa[i]=stk[i]=0;
		}
		bcc=top=tot=0;
		bridge.clear();
		for(int i=1;i<=n;i++)
		{
			if(!dfn[i]) dfs(i,i);
		}
	}
	void rebuild(vector<int> e[]) 
	{
		int i,t;
		for(i=1;i<=n;i++) e[i].clear();
		for(i=1;i<=n;i++)
		{
			t=fa[i];
			if(belong[i]!=belong[t])
			{
				lca.add(belong[i],belong[t]);
				e[belong[i]].pb(belong[t]);
				e[belong[t]].pb(belong[i]);
			}
		}
	}
}
int flag[MAX];
VI mp[MAX];
void dfs(int x,int fa)
{
	if(flag[x]) return;
	flag[x]=1;
	for(auto to:mp[x])
	{
		if(to==fa) continue;
		dfs(to,fa);
	}
}
void go()
{
	int t,n,m,q,i,a,b,c;
	read(t);
	while(t--)
	{
		read(n,m,q);
		for(i=1;i<=n;i++)
		{
			mp[i].clear();
			flag[i]=0;
		}
		while(m--)
		{
			read(a,b);
			mp[a].pb(b);
			mp[b].pb(a);
		}
		Tarjan::work(n,mp);
		lca.init(Tarjan::bcc+1);
		Tarjan::rebuild(mp);
		for(i=1;i<=Tarjan::bcc;i++)
		{
			if(flag[i]) continue;
			lca.add(Tarjan::bcc+1,i);
			dfs(i,0);
		}
		lca.work(Tarjan::bcc+1);
		while(q--)
		{
			read(a,b,c);
			a=Tarjan::belong[a];
			b=Tarjan::belong[b];
			c=Tarjan::belong[c];
			if(lca.lca_root(Tarjan::bcc+1,a,c)==Tarjan::bcc+1||lca.lca_root(Tarjan::bcc+1,b,c)==Tarjan::bcc+1) puts("No");
			else if(a==lca.lca_root(a,b,c)) puts("Yes");
			else puts("No");
		}
	}
}

