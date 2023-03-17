#include <bits/stdc++.h>
using namespace std;
namespace fastIO{
	#define BUF_SIZE 100000
	#define OUT_SIZE 100000
	#define ll long long
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
	//fwrite->print
	struct Ostream_fwrite{
		char *buf,*p1,*pend;
		Ostream_fwrite(){buf=new char[BUF_SIZE];p1=buf;pend=buf+BUF_SIZE;}
//		void out(char ch){putchar(ch);}
		void out(char ch){if(p1==pend){fwrite(buf,1,BUF_SIZE,stdout);p1=buf;}*p1++=ch;}
		template<class T>void print(T x){
			static char s[33],*s1;s1=s;
			if(!x)*s1++='0';if(x<0)out('-'),x=-x;
			while(x)*s1++=x%10+'0',x/=10;
			while(s1--!=s)out(*s1);
		}
		void print(double x,int y){
			static ll mul[]=
			{1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000,
			10000000000LL,100000000000LL,1000000000000LL,10000000000000LL,
			100000000000000LL,1000000000000000LL,10000000000000000LL,100000000000000000LL};
			if(x<-1e-12)out('-'),x=-x;
			ll x2=(ll)floor(x);if(!y&&x-x2>=0.5)++x2;x-=x2;x*=mul[y];
			ll x3=(ll)floor(x);if(y&&x-x3>=0.5)++x3;print(x2);
			if(y>0){out('.');for(size_t i=1;i<y&&x3*mul[i]<mul[y];out('0'),++i);print(x3);}
		}
		void print(char *s){while(*s)out(*s++);}
		void print(const char *s){while(*s)out(*s++);}
		void flush(){if(p1!=buf){fwrite(buf,1,p1-buf,stdout);p1=buf;}}
		~Ostream_fwrite(){flush();}
	}Ostream;
	template<class T>void print(T x){Ostream.print(x);}
	inline void print(char x){Ostream.out(x);}
	inline void print(char *s){Ostream.print(s);}
	inline void print(string s){Ostream.print(s.c_str());}
	inline void print(const char *s){Ostream.print(s);}
	inline void print(double x,int y){Ostream.print(x,y);}
	template<class T,class... U>void print(const T& h,const U&... t){print(h);print(t...);}
	void println(){print('\n');}
	template<class T,class... U>void println(const T& h,const U&... t){print(h);println(t...);}
	inline void flush(){Ostream.flush();}
	#undef ll
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
const double eps=1e-8;
const int MAX=4e5+10;
const ll mod=1e9+7;
/*********************************head*********************************/
const ll mod1=mod-1;
ll pow2(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1)
		{
			res=res*a;
			if(res>mod) res%=mod;
		}
		a=a*a;
		if(a>mod) a%=mod;
		b>>=1;
	}
	return res;
}
ll inv(ll x){return pow2(x,mod-2);}
struct Fenwick_Tree
{
	#define type ll
	type bit[MAX][2];
	int n;
	void init(int _n){n=_n;mem(bit,0);}
	int lowbit(int x){return x&(-x);}
	void insert(int x,type v)
	{
		for(int i=x;i<=n;i+=lowbit(i))
		{
			bit[i][0]+=v;
			bit[i][1]+=v*(x-1);
		}
	}
	void upd(int l,int r,type v)
	{
		insert(l,v);
		insert(r+1,-v);
	}
	type get(int x)
	{
		type res=0;
		for(int i=x;i;i-=lowbit(i))
		{
			res+=x*bit[i][0]-bit[i][1];
		}
		return res;
	}
	type ask(int l,int r)
	{
		return get(r)-get(l-1);
	}
	#undef type
}tr; 
int p[MAX],tot,prime[MAX];
void init(int n)
{
	int i,j;
	tot=0;
	mem(prime,0);
	prime[1]=1;
	for(i=2;i<=n;i++)
	{
		if(prime[i]) continue;
		p[tot++]=i;
		for(j=i;j<=n;j+=i)
		{
			if(!prime[j]) prime[j]=i;
		}
	}
}
ll invp[333],ans[MAX];
int op[MAX],l[MAX],r[MAX],x[MAX],v[MAX];
void go()
{
	int n,q,i,j,tmp;
	ll cnt;
	char s[55];
	init(300);
	for(i=0;i<tot;i++) invp[i]=inv(p[i]);
	while(read(n,q))
	{
		for(i=1;i<=n;i++) read(v[i]);
		for(i=1;i<=q;i++)
		{
			read(s);
			read(l[i],r[i]);
			if(s[0]=='T') op[i]=0;
			else
			{
				read(x[i]);
				op[i]=1;
			}
			ans[i]=1;
		}
		for(i=0;i<tot;i++)
		{
			tr.init(n);
			for(j=1;j<=n;j++)
			{
				cnt=0;
				tmp=v[j];
				while(tmp%p[i]==0)
				{
					tmp/=p[i];
					cnt++;
				}
				if(cnt) tr.upd(j,j,cnt);
			}
			for(j=1;j<=q;j++)
			{
				if(op[j]==0)
				{
					cnt=tr.ask(l[j],r[j]);
					if(cnt)
					{
						ans[j]*=pow2(p[i],cnt)*(1-invp[i]+mod)%mod;
						ans[j]%=mod;
					}
				}
				else
				{
					cnt=0;
					tmp=x[j];
					while(tmp%p[i]==0)
					{
						tmp/=p[i];
						cnt++;
					}
					tr.upd(l[j],r[j],cnt);
				}
			}
		}
		for(i=1;i<=q;i++)
		{
			if(op[i]==0) println(ans[i]);
		}
	}
}
