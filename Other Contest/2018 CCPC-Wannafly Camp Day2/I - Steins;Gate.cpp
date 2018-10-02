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
int p[MAX],tot,prime[MAX];
void init(int n)
{
	int i,j;
	tot=0;
	mem(prime,0);
	prime[1]=1;
	for(i=2;i<=n;i++)
	{
		if(!prime[i]) prime[i]=p[tot++]=i;
		for(j=0;j<tot&&p[j]*i<=n;j++)
		{
			prime[i*p[j]]=p[j];
			if(i%p[j]==0) break;
		}
	}
}
ll pow2(ll a,ll b,ll p)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a%p;
		a=a*a%p;
		b>>=1;
	}
	return res;
}
int tp[MAX];
int find_root(int x)
{
	int f,phi=x-1;
	for(int i=0;phi&&i<tot;i++)
	{
		if(phi%p[i]==0)
		{
			tp[++tp[0]]=p[i];
			while(phi%p[i]==0) phi/=p[i];
		}
	}
	for(int g=2;g<=x-1;g++)
	{
		f=1;
		for(int i=1;i<=tp[0];i++)
		{
			if(pow2(g,(x-1)/tp[i],x)==1)
			{
				f=0;
				break;
			}
		}
		if(f) return g;
	}
	return 0;
}
int I[MAX];
void get_I(int p)
{
	int g,now;
	g=find_root(p);
	now=1;
	for(int i=1;i<p;i++)
	{
		now=now*g%p;
		I[now]=i;
	}
}
namespace FFT
{
	#define rep(i,a,b) for(int i=(a);i<=(b);i++)
	const double pi=acos(-1);
	const int maxn=1<<19;
	struct cp
	{
		double a,b;
		cp(){}
		cp(double _x,double _y){a=_x,b=_y;}
		cp operator +(const cp &o)const{return (cp){a+o.a,b+o.b};}
		cp operator -(const cp &o)const{return (cp){a-o.a,b-o.b};}
		cp operator *(const cp &o)const{return (cp){a*o.a-b*o.b,b*o.a+a*o.b};}
		cp operator *(const double &o)const{return (cp){a*o,b*o};}
		cp operator !()const{return (cp){a,-b};}
	}x[maxn],y[maxn],z[maxn],w[maxn];
	void fft(cp x[],int k,int v)
	{
		int i,j,l;
		for(i=0,j=0;i<k;i++)
		{
			if(i>j)swap(x[i],x[j]);
			for(l=k>>1;(j^=l)<l;l>>=1);
		}
		w[0]=(cp){1,0};
		for(i=2;i<=k;i<<=1)
		{
			cp g=(cp){cos(2*pi/i),(v?-1:1)*sin(2*pi/i)};
			for(j=(i>>1);j>=0;j-=2)w[j]=w[j>>1];
			for(j=1;j<i>>1;j+=2)w[j]=w[j-1]*g;
			for(j=0;j<k;j+=i)
			{
				cp *a=x+j,*b=a+(i>>1);
				for(l=0;l<i>>1;l++)
				{
					cp o=b[l]*w[l];
					b[l]=a[l]-o;
					a[l]=a[l]+o;
				}
			}
		}
		if(v)for(i=0;i<k;i++)x[i]=(cp){x[i].a/k,x[i].b/k};
	}
	void mul(ll *a,ll *b,ll *c,int l1,int l2)
	{
		if(l1<128&&l2<128)
		{
			rep(i,0,l1+l2)a[i]=0;
			rep(i,0,l1)rep(j,0,l2)a[i+j]+=b[i]*c[j];
			return;
		}
		int K;
		for(K=1;K<=l1+l2;K<<=1);
		rep(i,0,l1)x[i]=cp(b[i],0);
		rep(i,0,l2)y[i]=cp(c[i],0);
		rep(i,l1+1,K)x[i]=cp(0,0);
		rep(i,l2+1,K)y[i]=cp(0,0);
		fft(x,K,0);fft(y,K,0);
		rep(i,0,K)z[i]=x[i]*y[i];
		fft(z,K,1);
		rep(i,0,l1+l2)a[i]=(ll)(z[i].a+0.5);
	}
};
ll a[MAX<<1],x[MAX],res[MAX<<1];
void go()
{
	init(200000);
	int n,i,p;
	ll cnt;
	while(read(n,p))
	{
		get_I(p);
		mem(a,0);
		cnt=0;
		for(i=1;i<=n;i++)
		{
			read(x[i]);
			if(x[i]%p) a[I[x[i]%p]%(p-1)]++;
			else cnt++;
		}
		mem(res,0);
		FFT::mul(res,a,a,p-1,p-1);
		for(i=p-1;i<2*p;i++) res[i-(p-1)]+=res[i];
		for(i=1;i<=n;i++)
		{
			if(x[i]>=p) puts("0");
			else if(x[i]==0) printf("%lld\n",cnt*(n-cnt)*2+cnt*cnt);
			else printf("%lld\n",res[I[x[i]]%(p-1)]);
		}
	}
}