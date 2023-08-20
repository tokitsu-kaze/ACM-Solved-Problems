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
const int MAX=1e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
struct node
{
	ll l,r,mid,sum,tag;
	node(){}
	node(ll a,ll b)
	{
		l=a;
		r=b;
		sum=0;
		tag=0;
		mid=(l+r)>>1;
	}
}tr[4*MAX];
ll a[MAX];
void build(ll l,ll r,ll id)
{
	ll mid;
	tr[id]=node(l,r);
	if(l==r)
	{ 
		tr[id].sum=a[l];
		return;
	}
	mid=tr[id].mid;
	build(l,mid,id<<1);
	build(mid+1,r,id<<1|1);
	tr[id].sum=max(tr[id<<1].sum,tr[id<<1|1].sum);
}
void pushdown(ll id)
{
	tr[id<<1].tag+=tr[id].tag;
	tr[id<<1|1].tag+=tr[id].tag;
	tr[id<<1].sum+=tr[id].tag;
	tr[id<<1|1].sum+=tr[id].tag;
	tr[id].tag=0;
}
void update(ll l,ll r,ll id,ll v)
{
	ll mid;
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
ll query(ll l,ll r,ll id)
{
	ll mid;
	if(l==tr[id].l&&r==tr[id].r)
	{
		return tr[id].sum;
	}
	if(tr[id].tag) pushdown(id);
	mid=tr[id].mid;
	if(r<=mid) return query(l,r,id<<1);
	else if(l>=mid+1) return query(l,r,id<<1|1);
	else return max(query(l,mid,id<<1),query(mid+1,r,id<<1|1));
}
vector<ll> mp[MAX];
ll v[MAX],tot,l[MAX],r[MAX],dis[MAX];
void dfs(ll x,ll pre)
{
	ll i,to;
	if(pre!=-1) dis[x]+=dis[pre];
	dis[x]+=v[x];
	tot++;
	l[x]=tot;
	a[tot]=dis[x];
	for(i=0;i<sz(mp[x]);i++)
	{
		to=mp[x][i];
		if(to==pre) continue;
		dfs(to,x);
	}
	r[x]=tot;
}
void go()
{
	ll t,n,m,i,c,d,op,x,y,cas=1;
	read(t);
	while(t--)
	{
		read(n,m);
		for(i=1;i<=n;i++) mp[i].clear();
		for(i=0;i<n-1;i++)
		{
			read(c,d);
			c++;
			d++;
			mp[c].pb(d);
			mp[d].pb(c);
		}
		for(i=1;i<=n;i++) read(v[i]);
		tot=0;
		mem(dis,0);
		dfs(1,0);
		build(1,n,1);
		printf("Case #%lld:\n",cas++);
		while(m--)
		{
			read(op,x);
			x++;
			if(op==0)
			{
				read(y);
				update(l[x],r[x],1,y-v[x]);
				v[x]=y;
			}
			else if(op==1)
			{
				printf("%lld\n",query(l[x],r[x],1));
			}
		}
	}
} 
