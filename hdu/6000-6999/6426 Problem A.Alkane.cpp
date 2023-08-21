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
//const ll mod=998244353;
/*********************************  head  *********************************/
namespace NTT
{
	const ll g=3;
	const ll mod=998244353;
	ll wn[35];
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
	void getwn()
	{
	    for(int i=0;i<25;i++) wn[i]=pow2(g,(mod-1)/(1LL<<i));
	}
	void ntt(ll *a,int len,int f)
	{
		ll i,j=0,t,k,w,id;
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
				for(k=0,w=1;k<i;k++,w=w*wn[id]%mod)
				{
					ll x=a[j+k],y=w*a[j+k+i]%mod;
					a[j+k]=(x+y)%mod;
					a[j+k+i]=(x-y+mod)%mod;
				}
			}
		}
		if(f)
		{
			for(i=1,j=len-1;i<j;i++,j--) swap(a[i],a[j]);
			ll inv=pow2(len,mod-2);
			for(i=0;i<len;i++) a[i]=a[i]*inv%mod;
		}
	}
};//NTT::getwn(); 
using namespace NTT;
ll inv2,inv3,inv6,inv24;
ll a[MAX],b[MAX],p[MAX],q[MAX];
ll tmp[MAX],c1[MAX],c2[MAX],c3[MAX],c4[MAX],now[MAX];
void cdq(int l,int r)
{
	if(l==r) return;
	int mid=(l+r)>>1;
	cdq(l,mid);
	int len,i;
	for(len=1;len<=2*(r-l);len<<=1);
	for(i=0;i<=len;i++) tmp[i]=c1[i]=c2[i]=0;
	for(i=l;i<=mid;i++) tmp[i-l]=a[i];
	for(i=0;i<=r-l;i++) c1[i]=a[i];
	for(i=0;i*2<=r-l;i++) c2[i*2]=a[i];
	ntt(tmp,len,0);ntt(c1,len,0);ntt(c2,len,0);
	for(i=0;i<=len;i++) now[i]=tmp[i]*c1[i]%mod*c1[i]%mod;
	ntt(now,len,1);
	for(i=mid+1;i<=r;i++) a[i]=(a[i]+now[i-l-1]*(l?inv2:inv6)%mod)%mod;
	for(i=0;i<=len;i++) now[i]=tmp[i]*c2[i]%mod;
	ntt(now,len,1);
	for(i=mid+1;i<=r;i++) a[i]=(a[i]+now[i-l-1]*inv2%mod)%mod;
	for(i=l;i*3+1<=r;i++)
	{
		if(i*3+1>=mid+1) (a[i*3+1]+=a[i]*inv3%mod)%=mod;
	}
	cdq(mid+1,r);
}
void go()
{
	int i,t,len,n;
	getwn();
	n=100000;
	inv2=pow2(2,mod-2);
	inv3=pow2(3,mod-2);
	inv6=pow2(6,mod-2);
	inv24=pow2(24,mod-2);
	for(i=0;i<=n;i++) a[i]=b[i]=0;
	a[0]=1;
	cdq(0,n);
	for(len=1;len<=4*n;len<<=1);
	for(i=0;i<=len;i++) c1[i]=c2[i]=c3[i]=c4[i]=0;
	for(i=0;i<=n;i++)
	{
		c1[i]=a[i];
		c2[i*2]=a[i];
		c3[i*3]=a[i];
		c4[i*4]=a[i];
	}
	ntt(c1,len,0);ntt(c2,len,0);ntt(c3,len,0);ntt(c4,len,0);
	for(i=0;i<=len;i++)
	{
		p[i]=0;
		p[i]=(p[i]+pow2(c1[i],4))%mod;
		p[i]=(p[i]+3*pow2(c2[i],2))%mod;
		p[i]=(p[i]+6*pow2(c1[i],2)%mod*c2[i])%mod;
		p[i]=(p[i]+8*c1[i]%mod*c3[i]%mod)%mod;
		p[i]=(p[i]+6*c4[i])%mod;
		p[i]=p[i]*inv24%mod;
	}
	ntt(p,len,1);
	for(i=n;i;i--) p[i]=p[i-1];
	p[0]=0;
	for(i=0;i<=len;i++)
	{
		q[i]=0;
		q[i]=(q[i]+pow2((c1[i]-1+mod)%mod,2))%mod;
		q[i]=(q[i]+c2[i]-1+mod)%mod;
		q[i]=q[i]*inv2%mod;
	}
	ntt(q,len,1);
	for(i=1;i<=n;i++)
	{
		b[i]=(b[i]+((p[i]-q[i])%mod+mod)%mod)%mod;
		b[i<<1]+=a[i];
	}
	read(t);
	while(t--)
	{
		read(n);
		printf("%lld %lld\n",b[n],a[n]);
	}
}
