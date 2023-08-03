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
const double eps=1e-8;
const int MAX=1e5+10;
const int mod=1e9+7;
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
	void add_edge(int a,int b,type w=1)
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
	#undef type
}lca;
struct Fenwick_Tree
{
	#define type ll
	type bit[MAX][2];
	int n;
	void init(int _n){n=_n;mem(bit,0);}
	int lowbit(int x){return x&(-x);}
	void insert(int x,type v)
	{
		for(int i=x;i<=n;i+=lowbit(i))
		{
			bit[i][0]+=v;
			bit[i][1]+=v*(x-1);
		}
	}
	void upd(int l,int r,type v)
	{
		insert(l,v);
		insert(r+1,-v);
	}
	type get(int x)
	{
		type res=0;
		for(int i=x;i;i-=lowbit(i))
		{
			res+=x*bit[i][0]-bit[i][1];
		}
		return res;
	}
	type ask(int l,int r)
	{
		return get(r)-get(l-1);
	}
	#undef type
}bit;
int l[MAX],r[MAX],dfn[MAX],eid[MAX],tot;
ll val[MAX];
struct edge{int to;ll w;int id;};
vector<edge> mp[MAX];
void dfs(int x,int fa,ll now)
{
	l[x]=++tot;
	dfn[tot]=x;
//	debug(x,tot)
	bit.upd(l[x],l[x],now);
	for(auto to:mp[x])
	{
		if(to.to==fa) continue;
		val[to.to]=to.w;
		eid[to.id]=to.to;
		dfs(to.to,x,now+to.w);
	}
	r[x]=tot;
}
struct Segment_Tree
{
	#define type ll
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr;
	type v[MAX<<2],qv,tag[MAX<<2];
	PII node[MAX<<2];
	void up(type &mx,PII &res,int a,int b)
	{
		int lc=lca.lca(dfn[a],dfn[b]);
	//	debug(dfn[a],dfn[b],lc,l[lc])
		type tmp=bit.ask(a,a)+bit.ask(b,b)-2*bit.ask(l[lc],l[lc]);
	//	debug(dfn[a],dfn[b],lc,tmp)
	//	debug(a,bit.ask(a,a))
	//	debug(b,bit.ask(b,b))
	//	debug(l[lc],bit.ask(l[lc],l[lc]))
		if(tmp>mx)
		{
			mx=tmp;
			res=MP(a,b);
		}
	}
	void pushup(int id)
	{
		v[id]=0;
		up(v[id],node[id],node[ls].fi,node[rs].fi);
		up(v[id],node[id],node[ls].fi,node[rs].se);
		up(v[id],node[id],node[ls].se,node[rs].fi);
		up(v[id],node[id],node[ls].se,node[rs].se);
		up(v[id],node[id],node[ls].fi,node[ls].se);
		up(v[id],node[id],node[rs].fi,node[rs].se);
	}
	void pushdown(int id)
	{
		if(!tag[id]) return;
		v[ls]+=tag[id];
		v[rs]+=tag[id];
		tag[ls]+=tag[id];
		tag[rs]+=tag[id];
		tag[id]=0;
	}
	void build(int l,int r,int id)
	{
		tag[id]=0;
		if(l==r)
		{
			v[id]=0;
			node[id]=MP(l,l);
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,ls);
		build(mid+1,r,rs);
		pushup(id);
	}
	void update(int l,int r,int id)
	{
		if(l>=ql&&r<=qr)
		{
			v[id]+=qv;
			tag[id]+=qv;
			return;
		}
		pushdown(id);
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls);
		if(qr>mid) update(mid+1,r,rs);
		pushup(id);
	}
	void build(int _n){n=_n;build(1,n,1);}
	void upd(int x,type v)
	{
		bit.upd(l[x],r[x],v-val[x]);
		ql=l[x];
		qr=r[x];
		qv=v-val[x];
		update(1,n,1);
		val[x]=v;
	}
	#undef type
	#undef ls
	#undef rs
}tr;
void go()
{
	int n,q,i,a,b;
	ll p,w,ans;
	read(n,q,p);
	for(i=1;i<=n;i++) mp[i].clear();
	lca.init(n);
	for(i=0;i<n-1;i++)
	{
		read(a,b,w);
		mp[a].pb(edge{b,w,i});
		mp[b].pb(edge{a,w,i});
		lca.add_edge(a,b);
	}
	lca.work(1);
	tot=0;
	val[1]=0;
	bit.init(n);
	dfs(1,0,0);
	tr.build(n);
	ans=0;
//	debug(tr.v[1])
	while(q--)
	{
		read(a,w);
		a=(a+ans)%(n-1);
		w=(w+ans)%p;
		tr.upd(eid[a],w);
		ans=tr.v[1];
		printf("%lld\n",ans);
	}
}

// https://codeforces.com/contest/1192/problem/B

