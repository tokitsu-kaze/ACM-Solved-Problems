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
const int MAX=2.5e6+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
namespace HASH
{
	#define type int
	int m,k;
	vector<type> sd,p;
	vector<vector<type>> tmp;
	void set(vector<type> _sd,vector<type> _p)
	{
		sd=_sd;
		p=_p;
		assert(sd.size()==p.size());
		k=sd.size();
	}
	void init(int _m)
	{
		int i,j;
		m=_m;
		tmp.resize(k);
		for(j=0;j<k;j++)
		{
			tmp[j].resize(m+1);
			tmp[j][0]=1;
			for(i=1;i<=m;i++) tmp[j][i]=1ll*tmp[j][i-1]*sd[j]%p[j];
		}
	}
	struct hash_table
	{
		vector<vector<type>> ha;
		void work(char *s,int n)
		{
			int i,j;
			assert(n<=m);
			ha.resize(k);
			for(j=0;j<k;j++)
			{
				ha[j].resize(n+1);
				ha[j][0]=0;
				for(i=1;i<=n;i++) ha[j][i]=(1ll*ha[j][i-1]*sd[j]+s[i])%p[j];
			}
		}
		pair<type,type> get(int l,int r)
		{
			vector<type> res(k);
			for(int j=0;j<k;j++)
			{
				res[j]=(ha[j][r]-1ll*ha[j][l-1]*tmp[j][r-l+1])%p[j];
				if(res[j]<0) res[j]+=p[j];
			}
			return {res[0],res[1]};
		}
	};
	#undef type
}
HASH::hash_table ha;
/*
HASH::set({131,233},{402653189,805306457});
HASH::init(m);
ha.work(s,n);   // n<=m
*/
char a[MAX],b[MAX];
void go()
{
	int t,n,m,i;
	ll ans;
	read(t);
	while(t--)
	{
		read(a+1);
		read(b+1);
		n=strlen(a+1);
		m=strlen(b+1);
		HASH::set({131,233},{402653189,805306457});
		HASH::init(m);
		ha.work(b,m);
		map<pair<int,int>,int> mp;
		for(i=1;i+n-1<=m;i++) mp[ha.get(i,i+n-1)]++;
		for(i=n+1;i<2*n;i++) a[i]=a[i-n];
		ha.work(a,2*n-1);
		ans=0;
		for(i=1;i<=n;i++)
		{
			auto res=ha.get(i,i+n-1);
			if(mp.count(res)) ans+=mp[res];
		}
		printf("%lld\n",ans);
	}
}
