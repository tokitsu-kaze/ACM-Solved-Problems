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
const int MAX=1e6+10;
//const ll mod=1e9+7;
/*********************************  head  *********************************/
typedef long long i64;
typedef unsigned long long u64;
typedef __uint128_t u128;
const int word_bits=sizeof(u64)*8;
struct FastMod
{
	static u64 mod,inv,r2;
	u64 x;
	FastMod():x(0){}
	FastMod(u64 n):x(init(n)){}
	static u64 modulus(){return mod;}
	static u64 init(u64 w){return reduce(u128(w)*r2);}
	static void set_mod(u64 m)
	{
		mod=m;
		assert(mod&1);
		inv=m;
		for(int i=0;i<5;i++) inv*=2-inv*m;
		r2=-u128(m)%m;
	}
	static u64 reduce(u128 x)
	{
		u64 y=u64(x>>word_bits)-u64((u128(u64(x)*inv)*mod)>>word_bits);
		return i64(y)<0?y+mod:y;
	}
	FastMod& operator+=(FastMod rhs)
	{
		x+=rhs.x-mod;
		if(i64(x)<0) x+=mod;
		return *this;
	}
	FastMod operator+(FastMod rhs)const {return FastMod(*this)+=rhs;}
	FastMod& operator*=(FastMod rhs)
	{
		x=reduce(u128(x)*rhs.x);
		return *this;
	}
	FastMod operator*(FastMod rhs)const {return FastMod(*this)*=rhs;}
	u64 get()const {return reduce(x);}
}a[MAX];
u64 FastMod::mod,FastMod::inv,FastMod::r2;
// FastMod::set_mod(p);
void go()
{
	int t,i;
	read(t);
	ull p,k,mm0,mm1,cc,a0,a1;
	while(t--)
	{
		read(a0,a1,mm0,mm1,cc,p,k);
		FastMod::set_mod(p);
		FastMod m0(mm0),m1(mm1),c(cc),ans(1);
		a[0]=a0,a[1]=a1;
		ans=a[0]*a[1];
		for(i=2;i<=k;i++)
		{
			a[i]=m0*a[i-1]+m1*a[i-2]+c;
			ans*=a[i];
		}
		printf("%llu\n",ans.get());
	}
}