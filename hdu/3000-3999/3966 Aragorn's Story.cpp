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
const int MAX=5e4+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
vector<int> mp[MAX];
int deep[MAX],fa[MAX],sz[MAX],son[MAX];
int rnk[MAX],top[MAX],tid[MAX],tot;
void init()
{
	mem(son,-1);
	tot=0;
}
void dfs1(int x,int pre,int h)  
{
	int i,to;
	deep[x]=h;
	fa[x]=pre;
	sz[x]=1;
	for(i=0;i<sz(mp[x]);i++)
	{
		to=mp[x][i];
		if(to==pre) continue;
		dfs1(to,x,h+1);
		sz[x]+=sz[to];
		if(son[x]==-1||sz[to]>sz[son[x]]) son[x]=to;
	}
}
void dfs2(int x,int tp)
{
	int i,to;
	top[x]=tp;
	tid[x]=++tot;
	rnk[tid[x]]=x;
	if(son[x]==-1) return;
	dfs2(son[x],tp);
	for(i=0;i<sz(mp[x]);i++)
	{
		to=mp[x][i];
		if(to!=son[x]&&to!=fa[x]) dfs2(to,to);
	}
}
struct node
{
	int l,r,mid,sum,tag;
	node(){}
	node(int a,int b)
	{
		l=a;
		r=b;
		sum=0;
		tag=0;
		mid=(l+r)>>1;
	}
}tr[4*MAX];
int v[MAX];
void build(int l,int r,int id)
{
	int mid;
	tr[id]=node(l,r);
	if(l==r)
	{ 
		tr[id].sum=v[rnk[l]];
		return;
	}
	mid=tr[id].mid;
	build(l,mid,id<<1);
	build(mid+1,r,id<<1|1);
	tr[id].sum=tr[id<<1].sum+tr[id<<1|1].sum;
}
void pushdown(int id)
{
	tr[id<<1].tag+=tr[id].tag;
	tr[id<<1|1].tag+=tr[id].tag;
	tr[id<<1].sum+=tr[id].tag;
	tr[id<<1|1].sum+=tr[id].tag;
	tr[id].tag=0;
}
void update(int l,int r,int id,int v)
{
	int mid;
	if(l<=tr[id].l&&r>=tr[id].r)
	{
		tr[id].sum+=v;
		tr[id].tag+=v;
		return;
	}
	if(tr[id].tag) pushdown(id);
	mid=tr[id].mid;
	if(r<=mid) update(l,r,id<<1,v);
	else if(l>=mid+1) update(l,r,id<<1|1,v);
	else
	{
		update(l,mid,id<<1,v);
		update(mid+1,r,id<<1|1,v);
	}
	tr[id].sum=max(tr[id<<1].sum,tr[id<<1|1].sum);
}
int query(int l,int r,int id)
{
	int mid;
	if(l==tr[id].l&&r==tr[id].r)
	{
		return tr[id].sum;
	}
	if(tr[id].tag) pushdown(id);
	mid=tr[id].mid;
	if(r<=mid) return query(l,r,id<<1);
	else if(l>=mid+1) return query(l,r,id<<1|1);
	else return query(l,mid,id<<1)+query(mid+1,r,id<<1|1);
}
void modify(int x,int y,int val)
{  
	while(top[x]!=top[y])
	{  
		if(deep[top[x]]<deep[top[y]]) swap(x,y);
		update(tid[top[x]],tid[x],1,val);
		x=fa[top[x]];
    }  
    if(deep[x]>deep[y]) swap(x,y);
    update(tid[x],tid[y],1,val);
}
void go()
{
	int n,m,q,i,x,y,w,a,b;
	char op[11];
	while(read(n,m,q))
	{
		for(i=1;i<=n;i++)
		{
			mp[i].clear();
			read(v[i]);
		}
		while(m--)
		{
			read(a,b);
			mp[a].pb(b);
			mp[b].pb(a);
		}
		init();
		dfs1(1,0,0);
		dfs2(1,1);
		build(1,n,1);
		while(q--)
		{
			read(op);
			if(op[0]=='Q')
			{
				read(x);
				printf("%d\n",query(tid[x],tid[x],1));
			}
			else
			{
				read(x,y,w);
				if(op[0]=='D') w*=-1;
				modify(x,y,w);
			}
		}
	}
}
