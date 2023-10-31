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
/************* define end  *************/
void println(VI x){for(int i=0;i<sz(x);i++) printf("%d%c",x[i]," \n"[i==sz(x)-1]);}
void println(VL x){for(int i=0;i<sz(x);i++) printf("%lld%c",x[i]," \n"[i==sz(x)-1]);}
template<class T> void read(T *x,int l,int r){for(int i=l;i<=r;i++) read(x[i]);}
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
const int MAX=4e5+10;
const ll mod=998244353;
/*********************************  head  *********************************/
const int DIGIT=9;
const int DEPTH=1000000000;
const int MAXN=10;
typedef ll bignum_t[MAXN+1];
ll read(bignum_t a,istream&is=cin)
{
	char buf[MAXN*DIGIT+1],ch;
	ll i,j;
	memset((void*)a,0,sizeof(bignum_t));
	if(!(is>>buf))return 0;
	for(a[0]=strlen(buf),i=a[0]/2-1;i>=0;i--)
	ch=buf[i],buf[i]=buf[a[0]-1-i],buf[a[0]-1-i]=ch;
	for(a[0]=(a[0]+DIGIT-1)/DIGIT,j=strlen(buf);j<a[0]*DIGIT;buf[j++]='0');
	for(i=1;i<=a[0];i++)
	for(a[i]=0,j=0;j<DIGIT;j++)
	a[i]=a[i]*10+buf[i*DIGIT-1-j]-'0';
	for(;!a[a[0]]&&a[0]>1;a[0]--);
	return 1;
}
void write(const bignum_t a,ostream&os=cout)
{
	ll i,j ;
	for(os<<a[i=a[0]],i--;i;i--)
	os<<setw(DIGIT)<<setfill('0')<<a[i];
}
ll comp(const bignum_t a,const bignum_t b)
{
	ll i ;
	if(a[0]!=b[0]) return a[0]-b[0];
	for(i=a[0];i;i--)
	if(a[i]!=b[i])
	return a[i]-b[i];
	return 0 ;
}
ll comp(const bignum_t a,const ll b)
{
	ll c[12]={1};
	for(c[1]=b;c[c[0]]>=DEPTH;c[c[0]+1]=c[c[0]]/DEPTH,c[c[0]]%=DEPTH,c[0]++);
	return comp(a,c);
}
ll comp(const bignum_t a,const ll c,const ll d,const bignum_t b)
{
	ll i,t=0,O=-DEPTH*2;
	if(b[0]-a[0]<d&&c)
	return 1 ;
	for(i=b[0];i>d;i--)
	{
		t=t*DEPTH+a[i-d]*c-b[i];
		if(t>0)return 1;
		if(t<O)return 0;
	}
	for(i=d;i;i--)
	{
		t=t*DEPTH-b[i];
		if(t>0)return 1;
		if(t<O)return 0;
	}
	return t>0 ;
}
void add(bignum_t a,const bignum_t b)
{
	ll i ;
	for(i=1;i<=b[0];i++)
	if((a[i]+=b[i])>=DEPTH)
	a[i]-=DEPTH,a[i+1]++;
	if(b[0]>=a[0])
	a[0]=b[0];
	else
	for(;a[i]>=DEPTH&&i<a[0];a[i]-=DEPTH,i++,a[i]++);
	a[0]+=(a[a[0]+1]>0);
}
void add(bignum_t a,const ll b)
{
	ll i=1;
	for(a[1]+=b;a[i]>=DEPTH&&i<a[0];a[i+1]+=a[i]/DEPTH,a[i]%=DEPTH,i++);
	for(;a[a[0]]>=DEPTH;a[a[0]+1]=a[a[0]]/DEPTH,a[a[0]]%=DEPTH,a[0]++);
}
void sub(bignum_t a,const bignum_t b)
{
	ll i;
	for(i=1;i<=b[0];i++)
	if((a[i]-=b[i])<0)
	a[i+1]--,a[i]+=DEPTH;
	for(;a[i]<0;a[i]+=DEPTH,i++,a[i]--);
	for(;!a[a[0]]&&a[0]>1;a[0]--);
}
void sub(bignum_t a,const ll b)
{
	ll i=1;
	for(a[1]-=b;a[i]<0;a[i+1]+=(a[i]-DEPTH+1)/DEPTH,a[i]-=(a[i]-DEPTH+1)/DEPTH*DEPTH,i++);
	for(;!a[a[0]]&&a[0]>1;a[0]--);
}
void sub(bignum_t a,const bignum_t b,const ll c,const ll d)
{
	ll i,O=b[0]+d;
	for(i=1+d;i<=O;i++)
	if((a[i]-=b[i-d]*c)<0)
	a[i+1]+=(a[i]-DEPTH+1)/DEPTH,a[i]-=(a[i]-DEPTH+1)/DEPTH*DEPTH ;
	for(;a[i]<0;a[i+1]+=(a[i]-DEPTH+1)/DEPTH,a[i]-=(a[i]-DEPTH+1)/DEPTH*DEPTH,i++);
	for(;!a[a[0]]&&a[0]>1;a[0]--);
}
void mul(bignum_t c,const bignum_t a,const bignum_t b)
{
	ll i,j;
	memset((void*)c,0,sizeof(bignum_t));
	for(c[0]=a[0]+b[0]-1,i=1;i<=a[0];i++)
	for(j=1;j<=b[0];j++)
	if((c[i+j-1]+=a[i]*b[j])>=DEPTH)
	c[i+j]+=c[i+j-1]/DEPTH,c[i+j-1]%=DEPTH;
	for(c[0]+=(c[c[0]+1]>0);!c[c[0]]&&c[0]>1;c[0]--);
}
void mul(bignum_t a,const ll b)
{
	ll i;
	for(a[1]*=b,i=2;i<=a[0];i++)
	{
		a[i]*=b ;
		if(a[i-1]>=DEPTH)
		a[i]+=a[i-1]/DEPTH,a[i-1]%=DEPTH;
	}
	for(;a[a[0]]>=DEPTH;a[a[0]+1]=a[a[0]]/DEPTH,a[a[0]]%=DEPTH,a[0]++);
	for(;!a[a[0]]&&a[0]>1;a[0]--);
}
void mul(bignum_t b,const bignum_t a,const ll c,const ll d)
{
	ll i;
	memset((void*)b,0,sizeof(bignum_t));
	for(b[0]=a[0]+d,i=d+1;i<=b[0];i++)
	if((b[i]+=a[i-d]*c)>=DEPTH)
	b[i+1]+=b[i]/DEPTH,b[i]%=DEPTH ;
	for(;b[b[0]+1];b[0]++,b[b[0]+1]=b[b[0]]/DEPTH,b[b[0]]%=DEPTH);
	for(;!b[b[0]]&&b[0]>1;b[0]--);
}
void div(bignum_t c,bignum_t a,const bignum_t b)
{
	ll h,l,m,i;
	memset((void*)c,0,sizeof(bignum_t));
	c[0]=(b[0]<a[0]+1)?(a[0]-b[0]+2):1 ;
	for(i=c[0];i;sub(a,b,c[i]=m,i-1),i--)
	for(h=DEPTH-1,l=0,m=(h+l+1)>>1;h>l;m=(h+l+1)>>1)
	if(comp(b,m,i-1,a))h=m-1;
	else l=m;
	for(;!c[c[0]]&&c[0]>1;c[0]--);
	c[0]=c[0]>1?c[0]:1;
}
void div(bignum_t a,const ll b,ll&c)
{
	ll i;
	for(c=0,i=a[0];i;c=c*DEPTH+a[i],a[i]=c/b,c%=b,i--);
	for(;!a[a[0]]&&a[0]>1;a[0]--);
}
void sqrt(bignum_t b,bignum_t a)
{
	ll h,l,m,i;
	memset((void*)b,0,sizeof(bignum_t));
	for(i=b[0]=(a[0]+1)>>1;i;sub(a,b,m,i-1),b[i]+=m,i--)
	for(h=DEPTH-1,l=0,b[i]=m=(h+l+1)>>1;h>l;b[i]=m=(h+l+1)>>1)
	if(comp(b,m,i-1,a))h=m-1;
	else l=m;
	for(;!b[b[0]]&&b[0]>1;b[0]--);
	for(i=1;i<=b[0];b[i++]>>=1);
}
ll length(const bignum_t a)
{
	ll t,ret;
	for(ret=(a[0]-1)*DIGIT,t=a[a[0]];t;t/=10,ret++);
	return ret>0?ret:1;
}
ll digit(const bignum_t a,const ll b)
{
	ll i,ret;
	for(ret=a[(b-1)/DIGIT+1],i=(b-1)%DIGIT;i;ret/=10,i--);
	return ret%10;
}
ll zeronum(const bignum_t a)
{
	ll ret,t;
	for(ret=0;!a[ret+1];ret++);
	for(t=a[ret+1],ret*=DIGIT;!(t%10);t/=10,ret++);
	return ret;
}
void comp(ll*a,const ll l,const ll h,const ll d)
{
	ll i,j,t;
	for(i=l;i<=h;i++)
	for(t=i,j=2;t>1;j++)
	while(!(t%j))
	a[j]+=d,t/=j;
}
void convert(ll*a,const ll h,bignum_t b)
{
	ll i,j,t=1;
	memset(b,0,sizeof(bignum_t));
	for(b[0]=b[1]=1,i=2;i<=h;i++)
	if(a[i])
	for(j=a[i];j;t*=i,j--)
	if(t*i>DEPTH)
	mul(b,t),t=1;
	mul(b,t);
}
#define SGN(x) ((x)>0?1:((x)<0?-1:0))
#define ABS(x) ((x)>0?(x):-(x))
ll read(bignum_t a,ll&sgn,istream&is=cin)
{
	char str[MAXN*DIGIT+2],ch,*buf;
	ll i,j;
	memset((void*)a,0,sizeof(bignum_t));
	if(!(is>>str))return 0;
	buf=str,sgn=1;
	if(*buf=='-')sgn=-1,buf++;
	for(a[0]=strlen(buf),i=a[0]/2-1;i>=0;i--)
	ch=buf[i],buf[i]=buf[a[0]-1-i],buf[a[0]-1-i]=ch ;
	for(a[0]=(a[0]+DIGIT-1)/DIGIT,j=strlen(buf);j<a[0]*DIGIT;buf[j++]='0');
	for(i=1;i<=a[0];i++)
	for(a[i]=0,j=0;j<DIGIT;j++)
	a[i]=a[i]*10+buf[i*DIGIT-1-j]-'0';
	for(;!a[a[0]]&&a[0]>1;a[0]--);
	if(a[0]==1&&!a[1])sgn=0;
	return 1;
}
struct bigint
{
	bignum_t num;
	ll sgn;
	bigint(ll v){*this = v;}
	inline bigint()
	{
		memset(num,0,sizeof(bignum_t));
		num[0]=1;
		sgn=0;
	}
	inline ll operator!()
	{
		return num[0]==1&&!num[1];
	}
	inline bigint&operator=(const bigint&a)
	{
		memcpy(num,a.num,sizeof(bignum_t));
		sgn=a.sgn;
		return*this;
	}
	inline bigint&operator=(const ll a)
	{
		memset(num,0,sizeof(bignum_t));
		num[0]=1;
		sgn=SGN (a);
		add(num,sgn*a);
		return*this;
	}
	inline bigint&operator+=(const bigint&a)
	{
		if(sgn==a.sgn)add(num,a.num);
		else if(sgn&&a.sgn)
		{
			ll ret=comp(num,a.num);
			if(ret>0)sub(num,a.num);
			else if(ret<0)
			{
				bignum_t t;
				memcpy(t,num,sizeof(bignum_t));
				memcpy(num,a.num,sizeof(bignum_t));
				sub (num,t);
				sgn=a.sgn;
			}
			else memset(num,0,sizeof(bignum_t)),num[0]=1,sgn=0;
		}
		else if(!sgn) memcpy(num,a.num,sizeof(bignum_t)),sgn=a.sgn;
		return*this;
	}
	inline bigint&operator+=(const ll a)
	{
		if(sgn*a>0)add(num,ABS(a));
		else if(sgn&&a)
		{
			ll  ret=comp(num,ABS(a));
			if(ret>0)sub(num,ABS(a));
			else if(ret<0)
			{
				bignum_t t;
				memcpy(t,num,sizeof(bignum_t));
				memset(num,0,sizeof(bignum_t));
				num[0]=1;
				add(num,ABS (a));
				sgn=-sgn;
				sub(num,t);
			}
			else memset(num,0,sizeof(bignum_t)),num[0]=1,sgn=0 ;
		}
		else if(!sgn) sgn=SGN(a),add(num,ABS(a));
		return*this;
	}
	inline bigint operator+(const bigint&a)
	{
		bigint ret;
		memcpy(ret.num,num,sizeof(bignum_t));
		ret.sgn=sgn;
		ret+=a;
		return ret;
	}
	inline bigint operator+(const ll a)
	{
		bigint ret;
		memcpy(ret.num,num,sizeof (bignum_t));
		ret.sgn=sgn;
		ret+=a;
		return ret;
	}
	inline bigint&operator-=(const bigint&a)
	{

	}
	inline bigint&operator-=(const ll a)
	{

	}
	inline bigint operator-(const bigint&a)
	{

	}
	inline bigint operator-(const ll a)
	{

	}
	inline bigint&operator*=(const bigint&a)
	{

	}
	inline bigint&operator*=(const ll a)
	{

	}
	inline bigint operator*(const bigint&a)
	{

	}
	inline bigint operator*(const ll a)
	{

	}
	inline bigint&operator/=(const bigint&a)
	{

	}
	inline bigint&operator/=(const ll a)
	{

	}
	inline bigint operator/(const bigint&a)
	{

	}
	inline bigint operator/(const ll a)
	{

	}
	inline bigint&operator%=(const bigint&a)
	{

	}
	inline ll operator%=(const ll a)
	{

	}
	inline bigint operator%(const bigint&a)
	{

	}
	inline ll operator%(const ll a)
	{

	}
	inline ll operator[](const ll a)
	{
		return digit(num,a);
	}
	friend inline istream&operator>>(istream&is,bigint&a)
	{
		read(a.num,a.sgn,is);
		return is;
	}
	friend inline ostream&operator<<(ostream&os,const bigint&a)
	{
		if(a.sgn<0) os<<'-';
		write(a.num,os);
		return os;
	}
	friend inline bigint sqrt(const bigint&a)
	{
		
	}
	friend inline bigint sqrt(const bigint&a,bigint&b)
	{
		
	}
	inline ll length()
	{
		return :: length(num);
	}
	inline ll zeronum()
	{
		return :: zeronum(num);
	}
};
bigint dp[61][61][61];
void go()
{
	int n,i,j,k;
	while(read(n))
	{
		dp[0][0][0]=1;
		for(i=0;i<=n;i++)
		{
			for(j=0;j<=i;j++)
			{
				for(k=0;k<=j;k++)
				{
					if(i||j||k) dp[i][j][k]=0;
					if(i) dp[i][j][k]+=dp[i-1][j][k];
					if(j) dp[i][j][k]+=dp[i][j-1][k];
					if(k) dp[i][j][k]+=dp[i][j][k-1];
				}
			}
		}
		cout<<dp[n][n][n]<<"\n";
		puts("");
	}
}
