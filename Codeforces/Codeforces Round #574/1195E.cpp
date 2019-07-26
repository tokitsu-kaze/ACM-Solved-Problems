#include <bits/stdc++.h>
using namespace std;
namespace fastIO{
	#define BUF_SIZE 100000
	#define OUT_SIZE 100000
	//fread->read
	bool IOerror=0;
//  inline char nc(){char ch=getchar();if(ch==-1)IOerror=1;return ch;}
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
const int MAX=3000+10;
const ll mod=998244353;
/*********************************  head  *********************************/
struct Monotone_queue
{
	#define type int
	type v[MAX][2];//0 is min, 1 is max
	int p[MAX][2];
	int l[2],r[2];
	void clear()
	{
		l[0]=r[0]=0;
		l[1]=r[1]=0;
	}
	void insert(type x,int pos)
	{
		while(r[0]-l[0]&&v[r[0]-1][0]>=x) r[0]--;
		v[r[0]][0]=x;
		p[r[0]++][0]=pos;
		while(r[1]-l[1]&&v[r[1]-1][1]<=x) r[1]--;
		v[r[1]][1]=x;
		p[r[1]++][1]=pos;
	}
	void erase(int pos)
	{
		while(r[0]-l[0]&&p[l[0]][0]<=pos) l[0]++;
		while(r[1]-l[1]&&p[l[1]][1]<=pos) l[1]++;
	}
	type get_min(){return v[l[0]][0];}
	type get_max(){return v[l[1]][1];}
	#undef type
}dq;
ll mp[3030][3030],h[3030][3030];
void go()
{
	int a,b,i,j,n,m;
	ll g,x,y,z,ans;
	while(read(n,m,a,b))
	{
		read(g,x,y,z);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				mp[i][j]=g;
				g=(g*x+y)%z;
			}
		}
		for(i=1;i<=n;i++)
		{
			dq.clear();
			for(j=1;j<=m;j++)
			{
				dq.insert(mp[i][j],j);
				dq.erase(j-b);
				if(j>=b) h[i][j]=dq.get_min();
			}
		}
		ans=0;
		for(j=b;j<=m;j++)
		{
			dq.clear();
			for(i=1;i<=n;i++)
			{
				dq.insert(h[i][j],i);
				dq.erase(i-a);
				if(i>=a) ans+=dq.get_min();
			}
		}
		printf("%lld\n",ans);
	}
}

