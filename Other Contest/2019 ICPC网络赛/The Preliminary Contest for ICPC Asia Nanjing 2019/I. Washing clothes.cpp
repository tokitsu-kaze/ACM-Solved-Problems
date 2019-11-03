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
const int MAX=1e6+10;
const ll mod=998244353;
/*********************************  head  *********************************/
struct LiChao_Segment_Tree
{
	#define type ll
	#define inf -LLINF
	#define ls (id<<1)
	#define rs (id<<1|1)
	#define cmp max
	struct line
	{
		type k,b;
		void init(type _k=0,type _b=0){k=_k;b=_b;}
	}sg[MAX<<2];
	type v[MAX<<2];
	bool ext[MAX<<2];
	int ql,qr,n;
	type cal(line l,int x){return l.k*x+l.b;}
	void pushup(int id)
	{
		v[id]=cmp(v[id],v[ls]);
		v[id]=cmp(v[id],v[rs]);
	}
	void build(int l,int r,int id)
	{
		ext[id]=0;
		sg[id].init();
		v[id]=inf;
		if(l==r) return;
		int mid=(l+r)>>1;
		build(l,mid,ls);
		build(mid+1,r,rs);
	}
	void update(int l,int r,int id,line qv)
	{
		if(l>=ql&&r<=qr)
		{
			if(!ext[id])
			{
				ext[id]=1;
				sg[id]=qv;
			}
			else if(cal(qv,l)>=cal(sg[id],l)&&cal(qv,r)>=cal(sg[id],r)) sg[id]=qv;
			else if(cal(qv,l)>cal(sg[id],l)||cal(qv,r)>cal(sg[id],r))
			{
				int mid=(l+r)>>1;
				if(cal(qv,mid)>cal(sg[id],mid)) swap(qv,sg[id]);
				if(cal(qv,l)>cal(sg[id],l)) update(l,mid,ls,qv);
				else update(mid+1,r,rs,qv);
			}
			v[id]=cmp(cal(sg[id],l),cal(sg[id],r));
			if(l!=r) pushup(id);
			//if ask min, change '>' to '<'
		}
		else
		{
			int mid=(l+r)>>1;
			if(ql<=mid) update(l,mid,ls,qv);
			if(qr>mid) update(mid+1,r,rs,qv);
			v[id]=cmp(cal(sg[id],l),cal(sg[id],r));
			if(l!=r) pushup(id);
		}
	}
	type res;
	void query(int l,int r,int id)
	{
		if(l>=ql&&r<=qr)
		{
			res=cmp(res,v[id]);
			return;
		}
		res=cmp(res,cal(sg[id],max(l,ql)));
		res=cmp(res,cal(sg[id],min(r,qr)));
		int mid=(l+r)>>1;
		if(ql<=mid) query(l,mid,ls);
		if(qr>mid) query(mid+1,r,rs);
	}
	void build(int _n){n=_n;build(1,n,1);}
	void upd(int l,int r,type k,type b)
	{
		ql=l;
		qr=r;
		line qv;
		qv.init(k,b);
		update(1,n,1,qv);
	}
	type ask(int l,int r)
	{
		ql=l;
		qr=r;
		res=inf;
		query(1,n,1);
		return res;
	}
	#undef type
	#undef ls
	#undef rs
	#undef cmp
	#undef inf
}tr;
ll a[MAX];
void go()
{
	int n,y,i,ta,tb;
	while(read(n,y))
	{
		read(a,1,n);
		sort(a+1,a+1+n);
		tr.build(y);
		for(i=1;i<=n;i++)
		{
			ta=min(y,y/(n-i+1));
			tb=max(1,(y+n-i)/(n-i+1));
			if(ta>=1) tr.upd(1,ta,n-i+1,a[i]);
			if(tb<=y) tr.upd(tb,y,0,a[i]+y);
		}
		for(i=1;i<=y;i++) printf("%lld%c",tr.ask(i,i)," \n"[i==y]);
	}
}
