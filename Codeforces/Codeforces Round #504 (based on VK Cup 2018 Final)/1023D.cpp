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
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
void go();
int main(){
	#ifdef tokitsukaze
		freopen("TEST.txt","r",stdin);
	#endif
	go();return 0;
}
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=2e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
int res[MAX];
struct Segment_Tree
{
	#define type int
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr;
	type v[MAX<<2],tag[MAX<<2],qv;
	void pushdown(int id)
	{
		if(!tag[id]) return;
		tag[ls]=tag[rs]=tag[id];
		v[ls]=v[rs]=tag[id];
		tag[id]=0;
	}
	void build(int l,int r,int id)
	{
		tag[id]=0;
		v[id]=0;
		if(l==r) return;
		int mid=(l+r)>>1;
		build(l,mid,ls);
		build(mid+1,r,rs);
	}
	void update(int l,int r,int id)
	{
		if(l>=ql&&r<=qr)
		{
			v[id]=qv;
			tag[id]=qv;
			return;
		}
		pushdown(id);
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls);
		if(qr>mid) update(mid+1,r,rs);
	}
	void build(int _n){n=_n;build(1,n,1);}
	void upd(int l,int r,int v)
	{
		ql=l;
		qr=r;
		qv=v;
		update(1,n,1);
	}
	void dfs(int l,int r,int id)
	{
		if(l==r)
		{
			res[l]=v[id];
			return;
		}
		pushdown(id);
		int mid=(l+r)>>1;
		dfs(l,mid,ls);
		dfs(mid+1,r,rs);
	}
	#undef type
	#undef ls
	#undef rs
}tr;
int l[MAX],r[MAX],a[MAX];
void go()
{
	int n,q,i,flag;
	while(read(n,q))
	{
		mem(l,0x3f);
		mem(r,-0x3f);
		VI z;
		for(i=1;i<=n;i++)
		{
			read(a[i]);
			if(a[i])
			{
				l[a[i]]=min(l[a[i]],i);
				r[a[i]]=max(r[a[i]],i);
			}
			else z.pb(i);
		}
		tr.build(n);
		for(i=1;i<=q;i++)
		{
			if(l[i]>r[i]) continue;
			tr.upd(l[i],r[i],i);
		}
		tr.dfs(1,n,1);
		flag=0;
		if(!sz(z))
		{
			for(i=1;i<=n;i++) flag|=(res[i]!=a[i]);
			if(l[q]>r[q]) flag=1;
			if(flag) puts("NO");
			else
			{
				puts("YES");
				for(i=1;i<=n;i++) printf("%d%c",a[i]," \n"[i==n]);
			}
			continue;
		}
		if(sz(z)==n)
		{
			puts("YES");
			for(i=1;i<=n;i++) printf("%d%c",q," \n"[i==n]);
			continue;
		}
		for(i=1;i<=n;i++)
		{
			if(res[i])
			{
				if(!a[i]) a[i]=res[i];
				if(res[i]!=a[i]) flag=1;
			}
			else
			{
				if(!a[i]) a[i]=a[i-1];
			}
		}
		for(i=n;i;i--)
		{
			if(!a[i]) a[i]=a[i+1];
		}
		if(l[q]>r[q]) a[z[0]]=q;
		if(flag) puts("NO");
		else
		{
			puts("YES");
			for(i=1;i<=n;i++) printf("%d%c",a[i]," \n"[i==n]);
		}
	}
}
