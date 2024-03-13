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
const int MAX=1e6+10;
const ll mod=998244353;
/*********************************  head  *********************************/
/*
ll qpow(ll a,ll b)
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
ll inv(ll x){return qpow(x,mod-2);}
int mo[MAX],prime[MAX],tot;
bool flag[MAX];
void initmo(int n)
{
	int i,j;
	mem(flag,0);
	mem(mo,0);
	tot=0;
	mo[1]=1;
	for(i=2;i<=n;i++)
	{
		if(!flag[i])
		{
			prime[tot++]=i;
			mo[i]=-1;
		}
		for(j=0;j<tot&&prime[j]*i<=n;j++)
		{
			flag[i*prime[j]]=1;
			if(i%prime[j]==0)
			{
				mo[prime[j]*i]=0;
				break;
			}
			mo[prime[j]*i]=-mo[i];
		}
	}
}
void go()
{
	int n,i;
	while(cin>>n)
	{
		initmo(n);
		ll ans=1;
		for(i=1;i<=n;i++)
		{
			if(n%i==0)
			{
				if(mo[n/i]==-1) ans=ans*inv(i)%mod;
				else ans=ans*mo[n/i]*i%mod;
			}
		}
		debug(ans)
	}
}
*/
struct Montgomery
{
	#define i64 int64_t
	#define u64 uint64_t
	#define u128 __uint128_t
	u64 mod,R;
	void set_mod(u64 p)
	{
		mod=R=p;
		for(int i=0;i<5;i++) R*=2-mod*R;
	}
    u64 mul_add(u64 a,u64 b,u64 c)
	{
	    u128 d=u128(a)*b;
		u64 e=c+mod+(d>>64);
		u64 f=u64(d)*R;
		u64 g=(u128(f)*mod)>>64;
	    return e-g;
	}
    u64 mul(u64 a,u64 b) {return mul_add(a,b,0);}
	#undef i64
	#undef u64
	#undef u128
};
// m.set_mod(p);
ll qpow(ll a,ll b,ll p)
{
	ll res=1;
	while(b>0)
	{
		if(b&1) res=(__int128)res*a%p;
		a=(__int128)a*a%p;
		b>>=1;
	}
	return res;
}
bool miller_rabin(ll n,const initializer_list<ll>& as)
{
	int e=__builtin_ctzll(n-1);
	return all_of(as.begin(),as.end(),[&](ll it)
	{
		if(n<=it) return true;
		ll z=qpow(it,(n-1)>>e,n);  // it^(t*2^e)
		if(z==1||z==n-1) return true;
		for(int i=0;i<e-1;i++)
		{
			z=__int128(z)*z%n;
			if(z==1) return false;
			if(z==n-1) return true;
		}
		return false;
	});
}
bool is_prime(ll n)
{
	if(n<=2) return n==2;
	if(!(n&1)) return false;
	if(n<4759123141LL) return miller_rabin(n,{2,7,61});
	return miller_rabin(n,{2,325,9375,28178,450775,9780504,1795265022});
}
ll pollard_rho(ll n)
{
	Montgomery m;
	m.set_mod(n);
	if(!(n&1)) return 2;
	int i,j,k;
	ll q1,q2,g1,g2,w1,w2,x1,x2,y1,y2,z1,z2,g,c,x,z;
    constexpr ll c1=1;
    constexpr ll c2=2;
    constexpr ll M=512;
    w1=1,w2=2;
retry:
    z1=w1,z2=w2;
    for(i=M;;i<<=1)
	{
	    x1=z1+n,x2=z2+n;
	    for(j=0;j<i;j+=M)
		{
			y1=z1,y2=z2;
		    q1=1,q2=2;
		    for(k=0;k<M;k++)
			{
				z1=m.mul_add(z1,z1,c1);
				z2=m.mul_add(z2,z2,c2);
				q1=m.mul(q1,(x1-z1));
				q2=m.mul(q2,(x2-z2));
			}
		    g=__gcd((ll)m.mul(q1,q2),n);
		    if(g==1) continue;
		    if(g!=n) return g;
			g1=__gcd(q1,n);
		    g2=__gcd(q2,n);
		    if(g1!=1) c=c1,x=x1,z=y1,g=g1;
		    else c=c2,x=x2,z=y2,g=g2;
		    if(g==n)
			{
			    do{
				    z=m.mul_add(z,z,c);
				    g=__gcd(n,x-z);
				}while(g==1);
			}
		    if(g!=n) return g;
		    w1+=2,w2+=2;
		    goto retry;
		}
	}
}
void find_fac(ll n,vector<ll>& res)
{
	if(n<=1) return;
    if(is_prime(n)) {res.push_back(n); return;}
    ll p=pollard_rho(n);
    find_fac(p,res);
    find_fac(n/p,res);
}
vector<ll> factorize(ll n)
{
    vector<ll> res;
    find_fac(n,res);
    return res;
}
ll ans[2020];
void go()
{
	int t,cas,i;
	ll n;
	read(t);
	for(cas=1;cas<=t;cas++)
	{
		read(n);
		if(n==1)
		{
			ans[cas]=1;
			continue;
		}
		auto fac=factorize(n);
	//	debug(fac)
		sort(all(fac));
		fac.resize(unique(all(fac))-fac.begin());
		if(sz(fac)==1) ans[cas]=fac[0]%mod;
		else ans[cas]=1;
		end:;
	}
	println(ans,1,t);
}
