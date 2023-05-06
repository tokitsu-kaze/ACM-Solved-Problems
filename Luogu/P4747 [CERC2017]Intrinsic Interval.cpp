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
struct Permutation_Tree
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
	void work(int n,int *a)// a[1..n]
	{
		int rt,q,L,R,x,y,z;
		lca.init(2*n);
		rt=build(n,a);
	//	debug(rt)
		lca.work(rt);
		read(q);
		while(q--)
		{
			read(L,R);
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
	while(read(n))
	{
		read(a,1,n);
		dct.work(n,a);
	}
}
