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
const int MAX=1e5+10;
const ll mod=998244353;
/*********************************  head  *********************************/
struct Tonelli_Shanks
{
	ll mul2(ll a,ll b,ll p)
	{
		ll res=0;
		a%=p;
		while(b)
		{
			if(b&1)
			{
				res+=a;
				if(res>=p) res-=p;
			}
			a+=a;
			if(a>=p) a-=p;
			b>>=1;
		}
		return res;
	}
	ll pow2(ll a,ll b,ll p)
	{
		ll res=1;
		while(b)
		{
			if(b&1) res=mul2(res,a,p);
			a=mul2(a,a,p);
			b>>=1;
		}
		return res;
	}
	ll sqrt(ll n,ll p)
	{
	    if(p==2) return (n&1)?1:-1;
	    if(pow2(n,p>>1,p)!=1) return -1;
	    if(p&2) return pow2(n,(p+1)>>2,p);
	    ll q,z,c,r,t,tmp,s,i,m;
	    s=__builtin_ctzll(p^1);
	    q=p>>s;
		z=2;
	    for(;pow2(z,p>>1,p)==1;z++);
	    c=pow2(z,q,p);
		r=pow2(n,(q+1)>>1,p);
		t=pow2(n,q,p);
	    for(m=s;t!=1;)
		{
	        for(i=0,tmp=t;tmp!=1;i++) tmp=tmp*tmp%p;
	        for(;i<--m;) c=c*c%p;
	        r=r*c%p;
	        c=c*c%p;
	        t=t*c%p;
	    }
	    return r;
	}
}ts;
int prime[MAX],phi[MAX],tot;
bool flag[MAX];
void init(int n)  
{  
	int i,j,k;
	tot=0;  
	mem(flag,0);
	phi[0]=0;
	phi[1]=1;
	for(i=2;i<=n;i++)  
	{  
		if(!flag[i])  
		{  
			prime[tot++]=i;  
			phi[i]=i-1;
		}  
		for(j=0;j<tot&&i*prime[j]<=n;j++)  
		{  
			k=i*prime[j];
			flag[k]=1;
			if(i%prime[j]==0)
			{  
				phi[k]=phi[i]*prime[j];
				break;
			}
			else phi[k]=phi[i]*(prime[j]-1);
		}
	}
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
		res.resize(l1);
	}
};//NTT::getwn();
ll pow2(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
int f[MAX];
ll tmp[MAX];
void go()
{
	init(MAX-10);
	NTT::getwn();
	ll sq2=ts.sqrt(2,mod);
	int t,n,i;
	ll ans;
	read(t);
	while(t--)
	{
		read(n);
		mem(f,0);
		for(i=1;i<=n;i++) f[phi[i]]++;
		VI x(n+1),y(n+1);
		y[0]=1;
		for(i=1;i<=n;i++)
		{
			tmp[i]=pow2(sq2,1ll*i*i);
			x[i]=1ll*i*f[i]%mod*tmp[i]%mod;
			y[i]=pow2(tmp[i],mod-2);
		}
		VI res;
		NTT::mul(res,x,y);
		ans=0;
		for(i=1;i<=n;i++)
		{
			ans+=1ll*i*f[i]%mod*tmp[i]%mod*res[i];
			ans%=mod;
		}
		ans=ans*2%mod;
		for(i=1;i<=n;i++)
		{
			ans-=1ll*f[i]*f[i]%mod*i%mod*i%mod*pow2(2,1ll*i*i);
			ans%=mod;
		}
		if(ans<0) ans+=mod;
		printf("%lld\n",ans);
	}
}
