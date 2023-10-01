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
const int MAX=5e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
struct Segment_Tree
{
	#define type int
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr;
	type a[MAX],mx[MAX<<2],len[MAX<<2],tag[MAX<<2];
	type lv1[MAX<<2],rv1[MAX<<2],v1[MAX<<2],md1[MAX<<2],mx1[MAX<<2];
	type lv0[MAX<<2],rv0[MAX<<2],v0[MAX<<2],md0[MAX<<2],mx0[MAX<<2];
	
	void pushup(int id)
	{
		v1[id]=v1[ls]+v1[rs];
		v0[id]=v0[ls]+v0[rs];
		
		lv1[id]=lv1[ls];
		if(v1[ls]==len[ls]) lv1[id]=v1[ls]+lv1[rs];
		rv1[id]=rv1[rs];
		if(v1[rs]==len[rs]) rv1[id]=v1[rs]+rv1[ls];
		lv0[id]=lv0[ls];
		if(v0[ls]==len[ls]) lv0[id]=v0[ls]+lv0[rs];
		rv0[id]=rv0[rs];
		if(v0[rs]==len[rs]) rv0[id]=v0[rs]+rv0[ls];
		
		md1[id]=rv1[ls]+lv1[rs];
		md0[id]=rv0[ls]+lv0[rs];
		
		mx1[id]=max({mx1[ls],mx1[rs],md1[id],lv1[id],rv1[id]});
		mx0[id]=max({mx0[ls],mx0[rs],md0[id],lv0[id],rv0[id]});
	}
	void pushdown(int l,int r,int id)
	{
		if(tag[id])
		{
			swap(v1[ls],v0[ls]);
			swap(lv1[ls],lv0[ls]);
			swap(rv1[ls],rv0[ls]);
			swap(md1[ls],md0[ls]);
			swap(mx1[ls],mx0[ls]);
			tag[ls]^=1;
			
			swap(v1[rs],v0[rs]);
			swap(lv1[rs],lv0[rs]);
			swap(rv1[rs],rv0[rs]);
			swap(md1[rs],md0[rs]);
			swap(mx1[rs],mx0[rs]);
			tag[rs]^=1;
			
			tag[id]=0;
		}
	}
	void build(int l,int r,int id)
	{
		tag[id]=0;
		len[id]=r-l+1;
		if(l==r)
		{
			if(a[l]) mx1[id]=md1[id]=lv1[id]=rv1[id]=v1[id]=1;
			else mx0[id]=md0[id]=lv0[id]=rv0[id]=v0[id]=1;
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
			swap(v1[id],v0[id]);
			swap(lv1[id],lv0[id]);
			swap(rv1[id],rv0[id]);
			swap(md1[id],md0[id]);
			swap(mx1[id],mx0[id]);
			tag[id]^=1;
			return;
		}
		pushdown(l,r,id);
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls);
		if(qr>mid) update(mid+1,r,rs);
		pushup(id);
	}
	type res,rmx;
	void query(int l,int r,int id)
	{
		if(l>=ql&&r<=qr)
		{
			res=max(res,mx1[id]);
			res=max(res,rmx+lv1[id]);
			if(v1[id]==len[id]) rmx=rmx+v1[id];
			else rmx=rv1[id];
			rmx=max(rmx,rv1[id]);
			return;
		}
		pushdown(l,r,id);
		int mid=(l+r)>>1;
		if(ql<=mid) query(l,mid,ls);
		if(qr>mid) query(mid+1,r,rs);
	}
	void build(int _n){n=_n;build(1,n,1);}
	void upd(int l,int r)
	{
		ql=l;
		qr=r;
		update(1,n,1);
	}
	type ask(int l,int r)//init res
	{
		ql=l;
		qr=r;
		res=-INF;
		rmx=0;
		query(1,n,1);
		return res;
	}
	#undef type
	#undef ls
	#undef rs
}tr;
char s[MAX];
void go()
{
	int n,q,i,l,r,op;
	while(read(n,q))
	{
		read(s+1);
		for(i=1;i<=n;i++) tr.a[i]=s[i]-'0';
		tr.build(n);
		while(q--)
		{
			read(op,l,r);
			if(op==1) tr.upd(l,r);
			else printf("%d\n",tr.ask(l,r));
		}
	}
}
