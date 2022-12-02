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
ll pow2(ll a,ll b)
{
	ll res=1;
	while(b>0)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
ll inv(ll x){return pow2(x,mod-2);}
ll fac[MAX],invfac[MAX];
void init(int n)
{
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	invfac[n]=inv(fac[n]);
	for(int i=n-1;~i;i--) invfac[i]=invfac[i+1]*(i+1)%mod;
}
ll C(ll n,ll m)
{
	if(m>n||m<0||n<0) return 0;
	return fac[n]*invfac[m]%mod*invfac[n-m]%mod;
}
namespace NTT
{
	const int g=3;
	const int p=998244353;
	int wn[35];
	int pow2(int a,int b)
	{
		int res=1;
		while(b)
		{
			if(b&1) res=1ll*res*a%p;
			a=1ll*a*a%p;
			b>>=1;
		}
		return res;
	}
	void getwn()
	{
		for(int i=0;i<25;i++) wn[i]=pow2(g,(p-1)/(1LL<<i));
	}
	void ntt(VI &a,int len,int f)
	{
		int i,j=0,t,k,w,id;
		for(i=1;i<len-1;i++)
		{
			for(t=len;j^=t>>=1,~j&t;);
			if(i<j) swap(a[i],a[j]);
		}
		for(i=1,id=1;i<len;i<<=1,id++)
		{
			t=i<<1;
			for(j=0;j<len;j+=t)
			{
				for(k=0,w=1;k<i;k++,w=1ll*w*wn[id]%p)
				{
					int x=a[j+k],y=1ll*w*a[j+k+i]%p;
					a[j+k]=x+y;
					if(a[j+k]>=p) a[j+k]-=p;
					a[j+k+i]=x-y;
					if(a[j+k+i]<0) a[j+k+i]+=p;
				}
			}
		}
		if(f)
		{
			for(i=1,j=len-1;i<j;i++,j--) swap(a[i],a[j]);
			int inv=pow2(len,p-2);
			for(i=0;i<len;i++) a[i]=1ll*a[i]*inv%p;
		}
	}
	void qpow(VI &a,int b)//limt: sz(a)*b is small
	{
		int len,i,l1;
		l1=sz(a);
		for(len=1;len<=(l1+1)*b-1;len<<=1);
		a.resize(len+1);
		for(i=l1;i<=len;i++) a[i]=0;
		ntt(a,len,0);
		for(i=0;i<len;i++) a[i]=pow2(a[i],b);
		ntt(a,len,1);
		a.resize((l1+1)*b-1);
	}
	void mul(VI &res,VI a,VI b)
	{
		int len,i,l1,l2;
		l1=sz(a);
		l2=sz(b);
		for(len=1;len<=l1+l2;len<<=1);
		a.resize(len+1);
		b.resize(len+1);
		for(i=l1+1;i<=len;i++) a[i]=0;
		for(i=l2+1;i<=len;i++) b[i]=0;
		ntt(a,len,0);ntt(b,len,0);
		res.resize(len);
		for(i=0;i<len;i++) res[i]=1ll*a[i]*b[i]%p;
		ntt(res,len,1);
		res.resize(l1+5);
	}
};//NTT::getwn();
void go()
{
	int n,k,i,ans;
	NTT::getwn();
	init(1e6);
	while(read(n,k))
	{
        assert(n>=k&&n<=1000000);
        assert(k==2||k==3||k==4);
		VI a(n+1,0),tmp(n+1,0),g(n+1,0),A(n+1,0);
		ans=pow2(n,n-2);
		for(i=0;i<=n;i++)
		{
			tmp[i]=a[i]=1ll*pow2(i+1,i-1)*invfac[i]%mod;
			A[i]=pow2(i,i)*invfac[i]%mod;
		}
		VI res,res1;
		NTT::mul(res,a,tmp);
		g=res;
		if(k==2)
		{
			ans=(ans-1ll*res[n-2]%mod*fac[n-2]%mod+mod)%mod;
		}
		else if(k==3)
		{
			ans=(ans-2ll*res[n-2]%mod*fac[n-2]%mod+mod)%mod;
			NTT::mul(res,g,tmp);
			ans=(ans+1ll*res[n-3]%mod*fac[n-3]%mod)%mod;
		}
		else if(k==4)
		{
			ans=(ans-3ll*res[n-2]%mod*fac[n-2]%mod+mod)%mod;
			NTT::mul(res,g,tmp);
			ans=(ans+2ll*res[n-3]%mod*fac[n-3]%mod)%mod;
			NTT::mul(res,g,g);
			ans=(ans-1ll*res[n-4]%mod*fac[n-4]%mod+mod)%mod;
			NTT::mul(res,g,A);
			NTT::mul(res,g,res);
			ans=(ans+4ll*res[n-4]%mod*fac[n-4]%mod)%mod;
		}
		printf("%d\n",ans);
	}
}

