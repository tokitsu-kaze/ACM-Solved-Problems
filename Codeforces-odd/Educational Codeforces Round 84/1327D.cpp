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
const double eps=1e-8;
const int MAX=2e5+10;
const ll mod=998244353;
/*********************************  head  *********************************/
/*
int p[MAX],c[MAX],tmp[MAX],a[MAX];
void gao(int n)
{
	int i;
	for(i=1;i<=n;i++) tmp[i]=a[p[i]];
	for(i=1;i<=n;i++) p[i]=tmp[i];
}
void go()
{
	int t,n,i;
	read(t);
	while(t--)
	{
		read(n);
		debug(n)
		read(p,1,n);
		read(c,1,n);
		for(i=1;i<=n;i++) a[i]=p[i];
		for(i=1;i<n;i++)
		{
			gao(n);
			println(p,1,n);
		}
	}
}
*/
VI res;
int p[MAX],c[MAX],flag[MAX];
int ck(int k,int n)
{
	int i,j,ok;
	for(i=1;i<=k;i++)
	{
		ok=1;
		for(j=i+k;j<=n;j+=k)
		{
			if(c[res[j]]!=c[res[j-k]])
			{
				ok=0;
				break;
			}
		}
		if(ok) return 1;
	}
	return 0;
}
void go()
{
	int t,n,i,j,ans,now,tot,sq;
	read(t);
	while(t--)
	{
		read(n);
		read(p,1,n);
		read(c,1,n);
		for(i=1;i<=n;i++) flag[i]=0;
		ans=INF;
		for(i=1;i<=n;i++)
		{
			if(flag[i]) continue;
			res.clear();
			res.pb(0);
			res.pb(i);
			flag[i]=1;
			now=i;
			while(1)
			{
				now=p[now];
				if(flag[now]) break;
				res.pb(now);
				flag[now]=1;
			}
	//		debug(res)
			tot=sz(res)-1;
			sq=sqrt(tot+0.5);
			for(j=1;j<=sq;j++)
			{
				if(tot%j) continue;
				if(ans>j&&ck(j,tot)) ans=min(ans,j);
				if(ans>tot/j&&ck(tot/j,tot)) ans=min(ans,tot/j);
			}
		}
		printf("%d\n",ans);
	}
}

